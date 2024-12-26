===================================================================================
# README - CENG201 Project: Expense Tracker

## Project Overview:
This project, named "Expense Tracker," is developed as part of the CENG201 course assignment. 
It provides functionality for managing expenses and incomes through a user-friendly GUI. 
The application is implemented using C++ with FLTK library for GUI components.

## Group Members:
- Nurten Çiftçioğlu
- Mustafa Kamal Mustafa Mustafa
- Furkan Demir
- Mehmet Emre Yıldız
- Berat Mut

## Features:
- **User Registration and Login System:** Securely register and login to manage your personal finances.
- **Expense Management:** Add and manage expenses with categories and descriptions.
- **Income Management:** Track and manage incomes with descriptions.
- **Report Generation:** Generate reports for expenses and incomes based on time and categories.
- **Budget Tracking:** Monitor budgets and receive alerts when exceeding predefined limits.

## Build Instructions:
This project uses `g++` as the compiler and follows standard C++11 conventions. 
Ensure that the FLTK library is installed and configured on your system before proceeding.

### Steps to Build:
1. Clone the repository and navigate to the project directory.
2. Ensure the `FLTK` library is installed on your system.
3. Run `make` in the terminal to build the project.
4. Execute the generated `ExpenseTracker` binary to run the application.

## Steps to Compile and Run:
1. Install FLTK Library:
Ensure that the FLTK library is installed on your system. On Ubuntu, you can install it using:
```bash
sudo apt-get install libfltk1.3-dev
```
2. Clean Build:
To remove all compiled files and the generated binary, run:
```bash
make clean 
```

3. Compile the Program:
Open a terminal in the directory containing the source code and the Makefile, then run:
```bash
make
```
This will compile the source code and produce an executable named *ExpenseTracker.exe*.

4. Run the Application:
After successful compilation, run the application using:
```bash
./ExpenseTracker.exe
```
