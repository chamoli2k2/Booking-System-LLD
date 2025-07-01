#pragma once
#include <bits/stdc++.h>
using namespace std;

#include "../CoreClasses/Screen.hpp"
#include "../CoreClasses/Seat.hpp"
#include "../CoreClasses/Theatre.hpp"
#include "../CommonEnum/SeatCategory.hpp"

class TheatreService {
private:
    unordered_map<int, Theatre> theatres;
    unordered_map<int, Screen> screens;
    unordered_map<int, Seat> seats;

    int theatreCounter;
    int screenCounter;
    int seatCounter;

public:
    TheatreService() : theatreCounter(0), screenCounter(0), seatCounter(0) {}

    // Retrieve seat by ID
    Seat& getSeat(int seatId) {
        if (!seats.count(seatId)) {
            throw runtime_error("Seat with ID " + to_string(seatId) + " not found.");
        }
        return seats[seatId];
    }

    // Retrieve theatre by ID
    Theatre& getTheatre(int theatreId) {
        if (!theatres.count(theatreId)) {
            throw runtime_error("Theatre with ID " + to_string(theatreId) + " not found.");
        }
        return theatres[theatreId];
    }

    // Retrieve screen by ID
    Screen& getScreen(int screenId) {
        if (!screens.count(screenId)) {
            throw runtime_error("Screen with ID " + to_string(screenId) + " not found.");
        }
        return screens[screenId];
    }

    // Create a new theatre
    Theatre createTheatre(const string& theatreName) {
        int theatreId = ++theatreCounter;
        Theatre theatre(theatreId, theatreName);
        theatres[theatreId] = theatre;
        return theatre;
    }

    // Create and link screen to theatre
    Screen createScreenInTheatre(const string& screenName, Theatre& theatre) {
        Screen screen = createScreen(screenName, theatre);
        theatre.addScreen(screen);
        return screen;
    }

    // Create and link seat to screen
    Seat createSeatInScreen(int rowNo, SeatCategory seatCategory, Screen& screen) {
        int seatId = ++seatCounter;
        Seat seat(seatId, rowNo, seatCategory);
        seats[seatId] = seat;
        screen.addSeat(seat);
        return seat;
    }

private:
    // Internal screen creation logic
    Screen createScreen(const string& screenName, Theatre& theatre) {
        int screenId = ++screenCounter;
        Screen screen(screenId, screenName, &theatre);
        screens[screenId] = screen;
        return screen;
    }
};
