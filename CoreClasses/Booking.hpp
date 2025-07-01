#pragma once
#include <bits/stdc++.h>
using namespace std;

#include "../CommonEnum/BookingStatus.hpp"
#include "Seat.hpp"
#include "Show.hpp"
#include "User.hpp"

class Booking {
private:
    string id;                      // Unique booking ID
    Show show;                      // The show this booking is for
    vector<Seat> seatsBooked;       // List of booked seats
    User user;                      // User who made the booking
    BookingStatus bookingStatus;    // Current status of booking

public:
    // ✅ Default constructor
    Booking() = default;
    // Constructor
    Booking(const string& id, const Show& show, const User& user, const vector<Seat>& seatsBooked)
        : id(id), show(show), user(user), seatsBooked(seatsBooked), bookingStatus(BookingStatus::CREATED) {}

    // Check if booking is confirmed
    bool isConfirmed() const {
        return bookingStatus == BookingStatus::CONFIRMED;
    }

    // Confirm the booking
    void confirmBooking() {
        if (bookingStatus != BookingStatus::CREATED) {
            throw runtime_error("Cannot confirm a booking that is not in the Created state.");
        }
        bookingStatus = BookingStatus::CONFIRMED;
    }

    // Expire the booking
    void expireBooking() {
        if (bookingStatus != BookingStatus::CREATED) {
            throw runtime_error("Cannot expire a booking that is not in the Created state.");
        }
        bookingStatus = BookingStatus::EXPIRED;
    }

    // Getters
    string getId() const {
        return id;
    }

    Show getShow() const {
        return show;
    }

    vector<Seat> getSeatsBooked() const {
        return seatsBooked;
    }

    User getUser() const {
        return user;
    }

    BookingStatus getBookingStatus() const {
        return bookingStatus;
    }
};
