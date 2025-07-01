#pragma once
#include <bits/stdc++.h>
using namespace std;

#include "../CoreClasses/Booking.hpp"
#include "../CoreClasses/Seat.hpp"
#include "../CoreClasses/Show.hpp"
#include "../CoreClasses/User.hpp"
#include "../Interfaces/ISeatLockProvider.hpp"

class BookingService {
private:
    unordered_map<string, Booking*> showBookings; // bookingId -> Booking*
    ISeatLockProvider* seatLockProvider;
    atomic<int> bookingIdCounter;

public:
    BookingService(ISeatLockProvider* seatLockProvider)
        : seatLockProvider(seatLockProvider), bookingIdCounter(1) {}

    Booking* getBooking(const string& bookingId) {
        if (showBookings.find(bookingId) == showBookings.end()) {
            throw runtime_error("No Booking exists for the ID: " + bookingId);
        }
        return showBookings[bookingId];
    }

    vector<Booking*> getAllBookings(const Show& show) {
        vector<Booking*> res;
        for (auto& [id, booking] : showBookings) {
            if (booking->getShow().getId() == show.getId()) {
                res.push_back(booking);
            }
        }
        return res;
    }

    Booking* createBooking(const User& user, const Show& show, const vector<Seat>& seats) {
        if (isAnySeatAlreadyBooked(show, seats)) {
            throw runtime_error("Seat already booked");
        }

        seatLockProvider->lockSeats(show, seats, user);

        string bookingId = to_string(bookingIdCounter++);
        Booking* booking = new Booking(bookingId, show, user, seats);

        showBookings[bookingId] = booking;
        return booking;
    }

    vector<Seat> getBookedSeats(const Show& show) {
        vector<Seat> booked;
        for (auto& booking : getAllBookings(show)) {
            if (booking->isConfirmed()) {
                for (auto& seat : booking->getSeatsBooked()) {
                    booked.push_back(seat);
                }
            }
        }
        return booked;
    }

    void confirmBooking(Booking* booking, const User& user) {
        if (booking->getUser().getUserEmail() != user.getUserEmail()) {
            throw runtime_error("Cannot confirm a booking made by another user");
        }

        for (auto& seat : booking->getSeatsBooked()) {
            if (!seatLockProvider->validateLock(booking->getShow(), seat, user)) {
                throw runtime_error("Acquired Lock is either invalid or has expired");
            }
        }

        booking->confirmBooking();
    }

private:
    bool isAnySeatAlreadyBooked(const Show& show, const vector<Seat>& seats) {
        vector<Seat> booked = getBookedSeats(show);
        unordered_set<int> bookedIds;
        for (auto& seat : booked) bookedIds.insert(seat.getSeatId());
        for (auto& seat : seats) {
            if (bookedIds.count(seat.getSeatId())) return true;
        }
        return false;
    }
};
