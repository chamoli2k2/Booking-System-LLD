#pragma once
#include <bits/stdc++.h>
using namespace std;

#include "../CommonEnum/SeatCategory.hpp"
#include "../CoreClasses/Screen.hpp"
#include "../CoreClasses/Theatre.hpp"
#include "../Services/TheatreService.hpp"

class TheatreController {
private:
    TheatreService* theatreService;

public:
    // Constructor to inject TheatreService
    TheatreController(TheatreService* service) : theatreService(service) {}

    // Create a new theatre and return its ID
    int createTheatre(const string& theatreName) {
        return theatreService->createTheatre(theatreName).getTheatreId();
    }

    // Create a new screen in a theatre
    int createScreenInTheatre(const string& screenName, int theatreId) {
        Theatre theatre = theatreService->getTheatre(theatreId);
        return theatreService->createScreenInTheatre(screenName, theatre).getScreenId();
    }

    // Create a seat in a screen
    int createSeatInScreen(int rowNo, SeatCategory seatCategory, int screenId) {
        Screen& screen = theatreService->getScreen(screenId);
        return theatreService->createSeatInScreen(rowNo, seatCategory, screen).getSeatId();
    }
};
