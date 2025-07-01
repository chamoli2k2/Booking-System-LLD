#pragma once
#include <bits/stdc++.h>
using namespace std;

class Movie {
private:
    int movieId;
    string movieName;
    int movieDurationInMinutes;

public:
    Movie() = default; 
    // Constructor
    Movie(int id, const string& name, int duration)
        : movieId(id), movieName(name), movieDurationInMinutes(duration) {}

    // Getters
    int getMovieId() const {
        return movieId;
    }

    string getMovieName() const {
        return movieName;
    }

    int getMovieDuration() const {
        return movieDurationInMinutes;
    }
};
