# 🎬 Movie Ticket Booking System (C++)

This is a multi-threaded C++ implementation of a **Movie Ticket Booking System** using core OOP principles and design patterns like Strategy, Controller-Service, and Factory.

It simulates the real-world workflow of a multiplex cinema: theatre creation, screen & seat allocation, movie & show management, ticket booking, payment handling, and concurrent booking conflict resolution.

---

## 📦 Features

- 🎭 Theatre and Screen management
- 🎟️ Seat creation with row/category support (Platinum/Gold/Silver)
- 🎞️ Movie and Show scheduling
- 👥 User booking and ticketing
- 🔐 Seat Locking mechanism with timeout
- 💳 Payment processing using Strategy Pattern
- 🔄 Handles **concurrent booking conflicts**

---

## 🧱 Tech Stack

- **C++17**
- **CMake**
- Multithreading (`std::thread`)
- Object-Oriented Programming
- Design Patterns (Strategy, Controller, Singleton, Factory)

---

## 🚀 How to Run

### 🛠️ Prerequisites
- Linux/macOS
- C++ Compiler (G++ 11+)
- `cmake` installed (`sudo apt install cmake` on Ubuntu)

---

### ⚙️ Build Steps

```bash
# Clone the repo or download the code
cd path/to/Booking-System/

# Create build directory
mkdir build && cd build

# Run CMake to generate build files
cmake ..

# Compile the project
make
```

---
## Program Output
```
=== Movie Booking System Initialization ===

[Step 1] Creating a theatre...
[✓] Theatre created with ID: 1

[Step 2] Creating a screen in the theatre...
[✓] Screen created with ID: 1

[Step 3] Creating seats...
  [Seat] Row 1, Seat ID: 1, Category: 2
  [Seat] Row 1, Seat ID: 2, Category: 2
  [Seat] Row 1, Seat ID: 3, Category: 2
  [Seat] Row 1, Seat ID: 4, Category: 2
  [Seat] Row 1, Seat ID: 5, Category: 2
  [Seat] Row 1, Seat ID: 6, Category: 2
  [Seat] Row 1, Seat ID: 7, Category: 2
  [Seat] Row 1, Seat ID: 8, Category: 2
  [Seat] Row 1, Seat ID: 9, Category: 2
  [Seat] Row 1, Seat ID: 10, Category: 2
  [Seat] Row 2, Seat ID: 11, Category: 1
  [Seat] Row 2, Seat ID: 12, Category: 1
  [Seat] Row 2, Seat ID: 13, Category: 1
  [Seat] Row 2, Seat ID: 14, Category: 1
  [Seat] Row 2, Seat ID: 15, Category: 1
  [Seat] Row 2, Seat ID: 16, Category: 1
  [Seat] Row 2, Seat ID: 17, Category: 1
  [Seat] Row 2, Seat ID: 18, Category: 1
  [Seat] Row 2, Seat ID: 19, Category: 1
  [Seat] Row 2, Seat ID: 20, Category: 1
  [Seat] Row 3, Seat ID: 21, Category: 1
  [Seat] Row 3, Seat ID: 22, Category: 1
  [Seat] Row 3, Seat ID: 23, Category: 1
  [Seat] Row 3, Seat ID: 24, Category: 1
  [Seat] Row 3, Seat ID: 25, Category: 1
  [Seat] Row 3, Seat ID: 26, Category: 1
  [Seat] Row 3, Seat ID: 27, Category: 1
  [Seat] Row 3, Seat ID: 28, Category: 1
  [Seat] Row 3, Seat ID: 29, Category: 1
  [Seat] Row 3, Seat ID: 30, Category: 1
  [Seat] Row 4, Seat ID: 31, Category: 0
  [Seat] Row 4, Seat ID: 32, Category: 0
  [Seat] Row 4, Seat ID: 33, Category: 0
  [Seat] Row 4, Seat ID: 34, Category: 0
  [Seat] Row 4, Seat ID: 35, Category: 0
  [Seat] Row 4, Seat ID: 36, Category: 0
  [Seat] Row 4, Seat ID: 37, Category: 0
  [Seat] Row 4, Seat ID: 38, Category: 0
  [Seat] Row 4, Seat ID: 39, Category: 0
  [Seat] Row 4, Seat ID: 40, Category: 0
  [Seat] Row 5, Seat ID: 41, Category: 0
  [Seat] Row 5, Seat ID: 42, Category: 0
  [Seat] Row 5, Seat ID: 43, Category: 0
  [Seat] Row 5, Seat ID: 44, Category: 0
  [Seat] Row 5, Seat ID: 45, Category: 0
  [Seat] Row 5, Seat ID: 46, Category: 0
  [Seat] Row 5, Seat ID: 47, Category: 0
  [Seat] Row 5, Seat ID: 48, Category: 0
  [Seat] Row 5, Seat ID: 49, Category: 0
  [Seat] Row 5, Seat ID: 50, Category: 0

[Step 4] Creating a movie...
[✓] Movie created with ID: 1

[Step 5] Creating a show...
[✓] Show created with ID: 1

[Step 6] Checking available seats...
Size of allSeats: 50
  Available Seats: 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40 41 42 43 44 45 46 47 48 49 50 
  Total: 50

[Step 7] Creating user John Doe...
[✓] User created: John Doe (john.doe@example.com)

[Step 8] Booking seats 1, 2, 3...
[✓] Booking created with ID: 1

[Step 9] Processing payment...
[PaymentService] Starting payment process for Booking ID: 1
[PaymentService] Booking found for ID: 1, User: john.doe@example.com
[PaymentService] Invoking payment strategy...
[DebitCard] Validating card details...
[DebitCard] Checking balance...
[DebitCard] Processing transaction...
[PaymentService] Payment successful. Confirming booking...
[PaymentService] Booking confirmed for user: john.doe@example.com
[✓] Payment successful!

[Step 10] Verifying booking status...
  Booking Status: 1
  Confirmed: Yes

[Step 11] Checking available seats after booking...
Size of allSeats: 50
  Available Seats: 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40 41 42 43 44 45 46 47 48 49 50 
  Total: 47

[Step 12] Simulating concurrent bookings...
[Thread-2] User2 booking succeeded: ID = 2
[Thread-1] User1 booking failed: Seat 7 is already locked

[Step 13] Final available seats after concurrent attempts...
Size of allSeats: 50
  Remaining Seats: 4 5 6 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40 41 42 43 44 45 46 47 48 49 50 
  Total: 44

=== Program Finished ===
