#include "ReportGroup.h"
ReportGroup::ReportGroup(int x, int y, int w, int h, GuiManager *manager)
    : Fl_Group(x, y, w, h), guiManager(manager)
{
    expenseTable = new ExpenseTable(180, 30, 400, 400, nullptr);
    end();
}

void ReportGroup::update()
{
    if (expenseTable != nullptr)
    {
        std::vector<Expense> *expenses = guiManager->getExpenseTracker()->getExpenses();
        expenseTable->updateTable(expenses);
    }
}
