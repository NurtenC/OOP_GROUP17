/**
 * @mainpage Expense Tracker Application
 *
 * @section intro Introduction
 * The Expense Tracker is an application designed to manage personal finances.
 * It allows users to track incomes and expenses, view summaries, and generate reports.
 *
 * @section features Features
 * - Manage incomes and expenses
 * - Generate detailed financial reports
 * - Easy-to-use graphical user interface
 *
 * @section usage Usage
 * Compile code with make
 * Launch the application.
 * Add incomes and expenses.
 * View financial summaries and reports.
 *
 */

#include "GuiManager.h"
#include "ExpenseTracker.h"


int main() {
    
    ExpenseTracker expenseTracker;               // Instance of ExpenseTracker to manage expenses.
    GuiManager guiManager(&expenseTracker);      // Instance of GuiManager to handle the GUI.

    guiManager.run();                            // Launches the GUI application.

    return 0;                                    // Returns 0 upon successful execution.
}
