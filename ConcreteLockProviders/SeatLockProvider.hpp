#pragma once
#include <bits/stdc++.h>
using namespace std;

#include "../CoreClasses/Seat.hpp"
#include "../CoreClasses/SeatLock.hpp"
#include "../CoreClasses/Show.hpp"
#include "../CoreClasses/User.hpp"
#include "../Interfaces/ISeatLockProvider.hpp"

/*
    1. shared_mutex
    used shared_mutex to allow multiple readers and single writer
    this allows multiple threads to read the locked seats concurrently
    while ensuring that only one thread can lock or unlock seats at a time.

    2. unique_lock
    used unique_lock to lock the showLocks mutex when modifying the seat locks
    this ensures that only one thread can modify the locks for a show at a time.
    No reader can read while a writer is modifying the locks.

    3. shared_lock
    used shared_lock to allow multiple threads to read the seat locks concurrently
    this allows multiple threads to check the locked seats without blocking each other.

*/

class SeatLockProvider : public ISeatLockProvider
{
    int lockTimeout;
    unordered_map<int, unordered_map<int, SeatLock>> locks; // showId -> (seatId -> SeatLock)
    unordered_map<int, shared_mutex> showLocks;             // showId -> mutex

public:
    SeatLockProvider(int timeout) : lockTimeout(timeout) {}

    // Lock multiple seats for a show by a user
    void lockSeats(const Show& show, const vector<Seat>& seats, const User& user) override
    {
        auto &seatLocks = locks[show.getId()];
        unique_lock<shared_mutex> lock(showLocks[show.getId()]);

        // Check if any seat is already locked and not expired
        for (auto &seat : seats)
        {
            if (seatLocks.count(seat.getSeatId()) && !seatLocks[seat.getSeatId()].isLockExpired())
            {
                throw runtime_error("Seat " + to_string(seat.getSeatId()) + " is already locked");
            }
        }

        auto now = chrono::system_clock::now();
        for (auto &seat : seats)
        {
            seatLocks[seat.getSeatId()] = SeatLock(seat, show, lockTimeout, now, user);
        }
    }

    // Unlock seats if user owns the lock
    void unlockSeats(const Show &show, const vector<Seat> &seats, const User &user) override
    {
        auto &seatLocks = locks[show.getId()];
        unique_lock<shared_mutex> lock(showLocks[show.getId()]);

        for (auto &seat : seats)
        {
            if (seatLocks.count(seat.getSeatId()) && seatLocks[seat.getSeatId()].getLockedBy().getUserEmail() == user.getUserEmail())
            {
                seatLocks.erase(seat.getSeatId());
            }
        }
    }

    // Check if user holds valid lock
    bool validateLock(const Show &show, const Seat &seat, const User &user) override
    {
        auto &seatLocks = locks[show.getId()];
        shared_lock<shared_mutex> lock(showLocks[show.getId()]);

        if (!seatLocks.count(seat.getSeatId()))
            return false;
        SeatLock &sl = seatLocks[seat.getSeatId()];
        return !sl.isLockExpired() && sl.getLockedBy().getUserEmail() == user.getUserEmail();
    }

    // Return all currently locked seats
    vector<Seat> getLockedSeats(const Show &show) override
    {
        vector<Seat> res;
        auto &seatLocks = locks[show.getId()];
        shared_lock<shared_mutex> lock(showLocks[show.getId()]);

        for (auto &[seatId, sl] : seatLocks)
        {
            if (!sl.isLockExpired())
                res.push_back(sl.getSeat());
        }
        return res;
    }
};
