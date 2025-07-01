#pragma once
#include <vector>
#include <string>

using namespace std;

class Theatre;  // ✅ Forward declaration instead of including "Theatre.hpp"
#include "Seat.hpp"

class Screen {
public:
    int id;
    string name;
    Theatre* theatre;       
    vector<Seat> seats;

public:
    Screen() = default; 

    Screen(int id, const string& name, Theatre* theatre)
        : id(id), name(name), theatre(theatre) {}

    void addSeat(const Seat& seat) {
        seats.push_back(seat);
    }

    int getScreenId() const {
        return id;
    }

    const vector<Seat>& getSeats() const {
        return seats;
    }

    Theatre* getTheatre() const {
        return theatre;
    }
};
