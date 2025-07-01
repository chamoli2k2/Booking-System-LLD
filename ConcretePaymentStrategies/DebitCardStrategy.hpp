#pragma once
#include "../Interfaces/PaymentStrategy.hpp"
#include<bits/stdc++.h>

class DebitCardStrategy : public PaymentStrategy {
public:
    bool processPayment() override {
        // Here Business Logic will come
        // Currently just simulating the process
        cout << "[DebitCard] Validating card details...\n";
        cout << "[DebitCard] Checking balance...\n";
        cout << "[DebitCard] Processing transaction...\n";
        return true;
    }
};
