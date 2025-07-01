#pragma once
#include <bits/stdc++.h>
using namespace std;

#include "Movie.hpp"
#include "Screen.hpp"

class Show {
private:
    int id;                                         // Unique ID of the show
    Movie movie;                                    // Movie being shown
    Screen screen;                                  // Screen where the movie is played
    chrono::system_clock::time_point startTime;     // Start time of the show
    int durationInMinutes;                          // Duration in minutes

public:
    Show() = default;  // Default constructor
    // Constructor
    Show(int id, const Movie& movie, const Screen& screen,
         chrono::system_clock::time_point startTime, int durationInMinutes)
        : id(id), movie(movie), screen(screen), startTime(startTime), durationInMinutes(durationInMinutes) {}

    // Getters
    int getId() const {
        return id;
    }

    Movie getMovie() const {
        return movie;
    }

    Screen getScreen() const {
        return screen;
    }

    chrono::system_clock::time_point getStartTime() const {
        return startTime;
    }

    int getDurationInMinutes() const {
        return durationInMinutes;
    }
};
