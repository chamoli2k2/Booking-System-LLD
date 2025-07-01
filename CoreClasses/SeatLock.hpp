#pragma once
#include <bits/stdc++.h>
using namespace std;

#include "Seat.hpp"
#include "Show.hpp"
#include "User.hpp"

class SeatLock {
private:
    Seat seat;                   
    Show show;                  
    int timeoutInSeconds;        // Lock timeout in seconds
    chrono::system_clock::time_point lockTime;  // Lock acquisition time
    User lockedBy;               

public:
    SeatLock() = default; 
    // Constructor
    SeatLock(Seat seat, Show show, int timeout, chrono::system_clock::time_point lockTime, User user)
        : seat(seat), show(show), timeoutInSeconds(timeout), lockTime(lockTime), lockedBy(user) {}

    // Check if lock has expired
    bool isLockExpired() const {
        auto expiryTime = lockTime + chrono::seconds(timeoutInSeconds);
        return chrono::system_clock::now() > expiryTime;
    }

    // Getters and Setters
    Seat getSeat() const {
        return seat;
    }

    void setSeat(const Seat& s) {
        seat = s;
    }

    Show getShow() const {
        return show;
    }

    void setShow(const Show& sh) {
        show = sh;
    }

    int getTimeoutInSeconds() const {
        return timeoutInSeconds;
    }

    void setTimeoutInSeconds(int timeout) {
        timeoutInSeconds = timeout;
    }

    chrono::system_clock::time_point getLockTime() const {
        return lockTime;
    }

    void setLockTime(chrono::system_clock::time_point time) {
        lockTime = time;
    }

    User getLockedBy() const {
        return lockedBy;
    }

    void setLockedBy(const User& u) {
        lockedBy = u;
    }
};
