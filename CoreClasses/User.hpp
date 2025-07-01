#pragma once
#include <bits/stdc++.h>
using namespace std;

class User {
private:
    string name;          
    string emailAddress;  

public:
    User() = default;  
    // Constructor
    User(const string& name, const string& emailAddress)
        : name(name), emailAddress(emailAddress) {}

    // Getters
    string getUserName() const {
        return name;
    }

    string getUserEmail() const {
        return emailAddress;
    }
};
