#include <bits/stdc++.h>
#include "CommonEnum/SeatCategory.hpp"
#include "ConcretePaymentStrategies/DebitCardStrategy.hpp"
#include "ConcreteLockProviders/SeatLockProvider.hpp"
#include "Controllers/MovieController.hpp"
#include "Controllers/TheatreController.hpp"
#include "Controllers/ShowController.hpp"
#include "Controllers/BookingController.hpp"
#include "Controllers/PaymentController.hpp"
#include "CoreClasses/User.hpp"
#include "Services/MovieService.hpp"
#include "Services/TheatreService.hpp"
#include "Services/ShowService.hpp"
#include "Services/BookingService.hpp"
#include "Services/PaymentService.hpp"
#include "Services/SeatAvailabilityService.hpp"

using namespace std;

int main() {
    try {
        cout << "\n=== Movie Booking System Initialization ===\n";

        // Initialize services
        PaymentStrategy* strategy = new DebitCardStrategy();
        auto movieService = make_shared<MovieService>();
        auto theatreService = make_shared<TheatreService>();
        auto showService = make_shared<ShowService>();

        auto seatLockProvider = make_shared<SeatLockProvider>(600);
        auto bookingService = make_shared<BookingService>(seatLockProvider.get());
        auto seatAvailabilityService = make_shared<SeatAvailabilityService>(bookingService.get(), seatLockProvider.get());
        auto paymentService = make_shared<PaymentService>(strategy, bookingService.get());

        // Controllers
        MovieController movieController(movieService);
        TheatreController theatreController(theatreService.get());
        ShowController showController(seatAvailabilityService.get(), showService.get(), theatreService.get(), movieService.get());
        BookingController bookingController(showService.get(), bookingService.get(), theatreService.get());
        PaymentController paymentController(paymentService.get());

        // Step 1: Create theatre
        cout << "\n[Step 1] Creating a theatre...\n";
        int theatreId = theatreController.createTheatre("PVR Cinemas");
        cout << "[✓] Theatre created with ID: " << theatreId << endl;

        // Step 2: Create screen
        cout << "\n[Step 2] Creating a screen in the theatre...\n";
        int screenId = theatreController.createScreenInTheatre("Screen 1", theatreId);
        cout << "[✓] Screen created with ID: " << screenId << endl;

        // Step 3: Create seats
        cout << "\n[Step 3] Creating seats...\n";
        for (int row = 1; row <= 5; row++) {
            SeatCategory category;
            if (row == 1) category = SeatCategory::PLATINUM;
            else if (row <= 3) category = SeatCategory::GOLD;
            else category = SeatCategory::SILVER;

            for (int seatNum = 1; seatNum <= 10; seatNum++) {
                int seatId = theatreController.createSeatInScreen(row, category, screenId);
                cout << "  [Seat] Row " << row << ", Seat ID: " << seatId
                     << ", Category: " << static_cast<int>(category) << endl;
            }
        }

        // Step 4: Create movie
        cout << "\n[Step 4] Creating a movie...\n";
        int movieId = movieController.createMovie("Inception", 150);
        cout << "[✓] Movie created with ID: " << movieId << endl;

        // Step 5: Create show
        cout << "\n[Step 5] Creating a show...\n";
        auto now = chrono::system_clock::now();
        int showId = showController.createShow(movieId, screenId, now, 150);
        cout << "[✓] Show created with ID: " << showId << endl;

        // Step 6: Check available seats
        cout << "\n[Step 6] Checking available seats...\n";
        auto availableSeats = showController.getAvailableSeats(showId);
        cout << "  Available Seats: ";
        for (int seatId : availableSeats) cout << seatId << " ";
        cout << "\n  Total: " << availableSeats.size() << endl;

        // Step 7: Create user
        cout << "\n[Step 7] Creating user John Doe...\n";
        User user("John Doe", "john.doe@example.com");
        cout << "[✓] User created: " << user.getUserName() << " (" << user.getUserEmail() << ")\n";

        // Step 8: Book seats
        cout << "\n[Step 8] Booking seats 1, 2, 3...\n";
        vector<int> seatsToBook = {1, 2, 3};
        string bookingId = bookingController.createBooking(user, showId, seatsToBook);
        cout << "[✓] Booking created with ID: " << bookingId << endl;

        // Step 9: Process payment
        cout << "\n[Step 9] Processing payment...\n";
        paymentController.processPayment(bookingId, user);
        cout << "[✓] Payment successful!\n";

        // Step 10: Check booking status
        cout << "\n[Step 10] Verifying booking status...\n";
        Booking* booking = bookingService->getBooking(bookingId);
        cout << "  Booking Status: " << static_cast<int>(booking->getBookingStatus()) << endl;
        cout << "  Confirmed: " << (booking->isConfirmed() ? "Yes" : "No") << endl;

        // Step 11: Check available seats again
        cout << "\n[Step 11] Checking available seats after booking...\n";
        auto availableAfter = showController.getAvailableSeats(showId);
        cout << "  Available Seats: ";
        for (int id : availableAfter) cout << id << " ";
        cout << "\n  Total: " << availableAfter.size() << endl;

        // Step 12: Simulate concurrent bookings
        cout << "\n[Step 12] Simulating concurrent bookings...\n";

        thread t1([&]() {
            try {
                string bookingId1 = bookingController.createBooking(user, showId, {5, 6, 7});
                cout << "[Thread-1] User1 booking succeeded: ID = " << bookingId1 << endl;
            } catch (exception& e) {
                cerr << "[Thread-1] User1 booking failed: " << e.what() << endl;
            }
        });

        thread t2([&]() {
            try {
                User user2("Jane Doe", "jane.doe@example.com");
                string bookingId2 = bookingController.createBooking(user2, showId, {7, 8, 9});
                cout << "[Thread-2] User2 booking succeeded: ID = " << bookingId2 << endl;
            } catch (exception& e) {
                cerr << "[Thread-2] User2 booking failed: " << e.what() << endl;
            }
        });

        t1.join();
        t2.join();

        // Step 13: Final seat availability
        cout << "\n[Step 13] Final available seats after concurrent attempts...\n";
        auto finalSeats = showController.getAvailableSeats(showId);
        cout << "  Remaining Seats: ";
        for (int id : finalSeats) cout << id << " ";
        cout << "\n  Total: " << finalSeats.size() << endl;

        cout << "\n=== Program Finished ===\n";

    } catch (exception& e) {
        cerr << "[!] Error: " << e.what() << endl;
    }

    return 0;
}
