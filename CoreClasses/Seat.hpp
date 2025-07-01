#pragma once
#include <bits/stdc++.h>
using namespace std;

#include "../CommonEnum/SeatCategory.hpp"  

class Seat {
private:
    int seatId;             
    int row;                 
    SeatCategory seatCategory;  
public:
    Seat() = default;  
    // Constructor
    Seat(int seatId, int row, SeatCategory category)
        : seatId(seatId), row(row), seatCategory(category) {}

    // Getters
    int getSeatId() const {
        return seatId;
    }

    int getRow() const {
        return row;
    }

    SeatCategory getSeatCategory() const {
        return seatCategory;
    }

    // For unordered_map or set comparisons (optional)
    bool operator==(const Seat& other) const {
        return seatId == other.seatId;
    }

    // Hash function if used in unordered_map/set
    struct Hash {
        size_t operator()(const Seat& s) const {
            return hash<int>()(s.seatId);
        }
    };
};
