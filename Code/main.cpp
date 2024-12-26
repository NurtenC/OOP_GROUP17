/**
 * @file main.cpp
 * @brief Entry point for the Expense Tracker application.
 *
 * This file initializes the ExpenseTracker and GuiManager classes,
 * then starts the graphical user interface for the application.
 */

#include "GuiManager.h"
#include "ExpenseTracker.h"

/**
 * @brief The main function initializes the ExpenseTracker and GuiManager,
 *        then starts the GUI application.
 *
 * @return Exit status of the application.
 */
int main() {
    
    ExpenseTracker expenseTracker;               ///< Instance of ExpenseTracker to manage expenses.
    GuiManager guiManager(&expenseTracker);      ///< Instance of GuiManager to handle the GUI.

    guiManager.run();                            ///< Launches the GUI application.

    return 0;                                    ///< Returns 0 upon successful execution.
}
