#pragma once
#include <bits/stdc++.h>
using namespace std;

#include "../CoreClasses/User.hpp"
#include "../CoreClasses/Seat.hpp"
#include "../CoreClasses/Show.hpp"
#include "../Services/ShowService.hpp"
#include "../Services/BookingService.hpp"
#include "../Services/TheatreService.hpp"

class BookingController {
private:
    ShowService* showService;
    BookingService* bookingService;
    TheatreService* theatreService;

public:
    BookingController(ShowService* showService, BookingService* bookingService, TheatreService* theatreService)
        : showService(showService), bookingService(bookingService), theatreService(theatreService) {}

    string createBooking(const User& user, int showId, const vector<int>& seatIds) {
        // Get show object
        Show show = showService->getShow(showId);
        
        vector<Seat> seats;
        for (int seatId : seatIds) {
            Seat seat = theatreService->getSeat(seatId);
            seats.push_back(seat);
        }

        Booking* booking = bookingService->createBooking(user, show, seats);
        return booking->getId();
    }
};
