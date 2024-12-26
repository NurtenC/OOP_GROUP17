

#include "GuiManager.h"
#include "ExpenseTracker.h"


int main() {
    
    ExpenseTracker expenseTracker;               // Instance of ExpenseTracker to manage expenses.
    GuiManager guiManager(&expenseTracker);      // Instance of GuiManager to handle the GUI.

    guiManager.run();                            // Launches the GUI application.

    return 0;                                    // Returns 0 upon successful execution.
}
