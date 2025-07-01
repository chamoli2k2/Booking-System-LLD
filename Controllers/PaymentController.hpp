#pragma once
#include <bits/stdc++.h>
using namespace std;

#include "../CoreClasses/User.hpp"
#include "../Services/PaymentService.hpp"

class PaymentController {
private:
    PaymentService* paymentService;

public:
    // Constructor to initialize the PaymentService dependency
    PaymentController(PaymentService* service)
        : paymentService(service) {}

    // Function to process payment
    void processPayment(const string& bookingId, const User& user) {
        paymentService->processPayment(bookingId, user);
    }
};
