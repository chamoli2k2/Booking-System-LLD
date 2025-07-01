#pragma once
#include <bits/stdc++.h>
using namespace std;

#include "../CoreClasses/Movie.hpp"

class MovieService {
private:
    unordered_map<int, Movie> movies;
    atomic<int> movieCounter;  // Atomic counter for thread-safe ID generation

public:
    MovieService() : movieCounter(0) {}

    Movie getMovie(int movieId) {
        if (movies.find(movieId) == movies.end()) {
            throw runtime_error("Movie with ID " + to_string(movieId) + " not found.");
        }
        return movies[movieId];
    }

    Movie createMovie(const string& movieName, int durationInMinutes) {
        int movieId = ++movieCounter;
        Movie movie(movieId, movieName, durationInMinutes);
        movies[movieId] = movie;
        return movie;
    }
};
