#pragma once
#include <bits/stdc++.h>
using namespace std;

#include "../Interfaces/PaymentStrategy.hpp"
#include "BookingService.hpp"
#include "../CoreClasses/User.hpp"
#include "../CoreClasses/Booking.hpp"

class PaymentService {
private:
    unordered_map<string, int> bookingFailures; // bookingId -> failure count
    PaymentStrategy* paymentStrategy;           // Strategy pattern (e.g., DebitCardStrategy)
    BookingService* bookingService;             // Pointer to BookingService

public:
    PaymentService(PaymentStrategy* strategy, BookingService* bookingSvc)
        : paymentStrategy(strategy), bookingService(bookingSvc) {}

    // Called when payment fails
    void processPaymentFailed(const string& bookingId, const User& user) {
    cout << "[PaymentService] Processing payment failure for booking ID: " << bookingId << endl;

    Booking* booking = bookingService->getBooking(bookingId);
    if (!booking) {
        cerr << "[PaymentService][Error] Booking not found for ID: " << bookingId << " during failure handling." << endl;
        return;
    }

    if (booking->getUser().getUserEmail() != user.getUserEmail()) {
        cerr << "[PaymentService][Error] User mismatch. Cannot report payment failure." << endl;
        throw runtime_error("Only the booking owner can report payment failure.");
    }

    bookingFailures[bookingId]++;
    cout << "[PaymentService] Payment failure recorded for Booking ID: " << bookingId << endl;
}



    // Main payment processing function
    void processPayment(const string& bookingId, const User& user) {
    cout << "[PaymentService] Starting payment process for Booking ID: " << bookingId << endl;

    Booking* booking = bookingService->getBooking(bookingId);
    if (!booking) {
        cerr << "[PaymentService][Error] Booking not found for ID: " << bookingId << endl;
        return;
    }

    cout << "[PaymentService] Booking found for ID: " << bookingId << ", User: " << booking->getUser().getUserEmail() << endl;

    if (!paymentStrategy) {
        cerr << "[PaymentService][Error] Payment strategy is NULL." << endl;
        return;
    }

    cout << "[PaymentService] Invoking payment strategy..." << endl;

    if (paymentStrategy->processPayment()) {
        cout << "[PaymentService] Payment successful. Confirming booking..." << endl;
        bookingService->confirmBooking(booking, user);
        cout << "[PaymentService] Booking confirmed for user: " << user.getUserEmail() << endl;
    } else {
        cout << "[PaymentService] Payment failed. Handling failure..." << endl;
        processPaymentFailed(bookingId, user);
    }
}

};
