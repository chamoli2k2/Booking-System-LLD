#pragma once
#include <bits/stdc++.h>
using namespace std;

#include "../Services/MovieService.hpp"

class MovieController
{
private:
    shared_ptr<MovieService> movieService;

public:
    MovieController(shared_ptr<MovieService> movieService)
        : movieService(movieService) {}

    int createMovie(const string &movieName, int durationInMinutes)
    {
        return movieService->createMovie(movieName, durationInMinutes).getMovieId();
    }
};
