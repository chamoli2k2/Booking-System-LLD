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
