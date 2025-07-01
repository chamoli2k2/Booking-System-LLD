#pragma once
#include <bits/stdc++.h>
using namespace std;

#include "Screen.hpp"

class Theatre {
private:
    int id;                    
    string name;               
    vector<Screen> screens;    

public:
    Theatre() = default;  

    // Constructor
    Theatre(int id, const string& name) : id(id), name(name) {}

    // Add a screen to the theatre
    void addScreen(const Screen& screen) {
        screens.push_back(screen);
    }

    // Getters
    int getTheatreId() const {
        return id;
    }

    vector<Screen> getScreens() const {
        return screens;
    }

    string getName() const {
        return name;
    }
};
