#pragma once
#include <bits/stdc++.h>
using namespace std;

#include "../CoreClasses/Show.hpp"
#include "../CoreClasses/Movie.hpp"
#include "../CoreClasses/Screen.hpp"

class ShowService {
private:
    unordered_map<int, Show> shows;     // Map to store all shows
    int showCounter;                    // To generate unique show IDs

public:
    ShowService() : showCounter(0) {}

    // Retrieve a show by its ID
    Show& getShow(int showId) {
        if (!shows.count(showId)) {
            throw runtime_error("Show with ID " + to_string(showId) + " not found.");
        }
        return shows[showId];
    }

    // Create and return a new show
    Show createShow(const Movie& movie, const Screen& screen, const chrono::system_clock::time_point& startTime, int durationInSeconds) {
        int showId = ++showCounter;
        Show newShow(showId, movie, screen, startTime, durationInSeconds);
        shows[showId] = newShow;
        return newShow;
    }

    // Get all shows for a specific screen
    vector<Show> getShowsForScreen(const Screen& screen) {
        vector<Show> result;
        for (const auto& [id, show] : shows) {
            if (show.getScreen().getScreenId() == screen.getScreenId()) {
                result.push_back(show);
            }
        }
        return result;
    }
};
