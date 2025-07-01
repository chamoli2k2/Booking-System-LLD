#pragma once
#include <bits/stdc++.h>
using namespace std;

#include "../CoreClasses/Movie.hpp"
#include "../CoreClasses/Screen.hpp"
#include "../CoreClasses/Seat.hpp"
#include "../CoreClasses/Show.hpp"
#include "../Services/SeatAvailabilityService.hpp"
#include "../Services/ShowService.hpp"
#include "../Services/TheatreService.hpp"
#include "../Services/MovieService.hpp"

class ShowController {
private:
    SeatAvailabilityService* seatAvailabilityService;
    ShowService* showService;
    TheatreService* theatreService;
    MovieService* movieService;

public:
    // Constructor to inject all required services
    ShowController(SeatAvailabilityService* seatService, ShowService* showServ,
                   TheatreService* theatreServ, MovieService* movieServ)
        : seatAvailabilityService(seatService), showService(showServ),
          theatreService(theatreServ), movieService(movieServ) {}

    // Create a show using provided movie, screen, start time and duration
    int createShow(int movieId, int screenId, chrono::system_clock::time_point startTime,
                   int durationInSeconds) {
        Screen screen = theatreService->getScreen(screenId);
        Movie movie = movieService->getMovie(movieId);
        return showService->createShow(movie, screen, startTime, durationInSeconds).getId();
    }

    // Get available seat IDs for a specific show
    vector<int> getAvailableSeats(int showId) {
        Show show = showService->getShow(showId);
        vector<Seat> availableSeats = seatAvailabilityService->getAvailableSeats(show);
        vector<int> seatIds;
        for (auto& seat : availableSeats) {
            seatIds.push_back(seat.getSeatId());
        }
        return seatIds;
    }
};
