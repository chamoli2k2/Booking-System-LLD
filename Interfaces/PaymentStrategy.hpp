#pragma once
#include<bits/stdc++.h>
using namespace std;

class PaymentStrategy {
public:
    virtual bool processPayment() = 0;
    virtual ~PaymentStrategy() = default;
};
