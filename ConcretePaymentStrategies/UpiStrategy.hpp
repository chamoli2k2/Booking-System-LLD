#pragma once
#include "../Interfaces/PaymentStrategy.hpp"

class UpiStrategy : public PaymentStrategy {
public:
    bool processPayment() override {
        // Here Business Logic will come
        // Currently just simulating the process
        cout<<"[UPI] Validating UPI ID...\n";
        cout<<"[UPI] Checking balance...\n";
        cout<<"[UPI] Processing transaction...\n";
        return true;
    }
};
