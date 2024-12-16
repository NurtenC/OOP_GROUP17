#include "GuiManager.h"
#include "ExpenseTracker.h"

int main() {
    
    ExpenseTracker expenseTracker;
    GuiManager guiManager(&expenseTracker);

    guiManager.run();

    return 0;
}
