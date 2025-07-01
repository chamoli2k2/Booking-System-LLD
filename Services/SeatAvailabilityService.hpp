#pragma once
#include <bits/stdc++.h>
using namespace std;

#include "../CoreClasses/Seat.hpp"
#include "../CoreClasses/Show.hpp"
#include "../Services/BookingService.hpp"
#include "../Interfaces/ISeatLockProvider.hpp"

class SeatAvailabilityService {
private:
    BookingService* bookingService;                // For checking booked seats
    ISeatLockProvider* seatLockProvider;           // For checking locked seats

public:
    // Constructor to initialize dependencies
    SeatAvailabilityService(BookingService* bookingSvc, ISeatLockProvider* lockProvider)
        : bookingService(bookingSvc), seatLockProvider(lockProvider) {}

    // Get all available (not booked or locked) seats
    vector<Seat> getAvailableSeats(const Show& show) {
        vector<Seat> allSeats = show.getScreen().getSeats();          // All seats in screen
        cout<<"Size of allSeats: "<<allSeats.size()<<endl;
        vector<Seat> unavailableSeats = getUnavailableSeats(show);    // Booked + locked

        unordered_set<int> unavailableSeatIds;
        for (auto& seat : unavailableSeats) unavailableSeatIds.insert(seat.getSeatId());

        vector<Seat> availableSeats;
        for (auto& seat : allSeats) {
            if (!unavailableSeatIds.count(seat.getSeatId())) {
                availableSeats.push_back(seat);
            }
        }

        return availableSeats;
    }

private:
    // Combine booked and locked seats
    vector<Seat> getUnavailableSeats(const Show& show) {
        vector<Seat> unavailable = bookingService->getBookedSeats(show);
        vector<Seat> locked = seatLockProvider->getLockedSeats(show);

        unavailable.insert(unavailable.end(), locked.begin(), locked.end());
        return unavailable;
    }
};
