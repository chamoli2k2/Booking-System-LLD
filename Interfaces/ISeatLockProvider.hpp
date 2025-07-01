#pragma once
#include <bits/stdc++.h>
using namespace std;

#include "../CoreClasses/Seat.hpp"
#include "../CoreClasses/Show.hpp"
#include "../CoreClasses/User.hpp"

class ISeatLockProvider {
public:
    virtual void lockSeats(const Show& show, const vector<Seat>& seats, const User& user) = 0;

    virtual void unlockSeats(const Show& show, const vector<Seat>& seats, const User& user) = 0;

    virtual bool validateLock(const Show& show, const Seat& seat, const User& user) = 0;

    virtual vector<Seat> getLockedSeats(const Show& show) = 0;

    virtual ~ISeatLockProvider() = default;
};
