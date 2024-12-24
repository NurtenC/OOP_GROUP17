#include "ReportGroup.h"
ReportGroup::ReportGroup(int x, int y, int w, int h, GuiManager *manager)
    : Fl_Group(x, y, w, h), guiManager(manager)
{
    expenseTable = new ExpenseTable(180, 20, 400, 270, nullptr);
    incomeTable = new IncomeTable(180, 320, 400, 270, nullptr);
    end();
}

void ReportGroup::update()
{
    if (expenseTable != nullptr)
    {
        std::vector<Expense> *expenses = guiManager->getExpenseTracker()->getExpenses();
        expenseTable->updateTable(expenses);
    }
    if (incomeTable != nullptr)
    {
        std::vector<Income> *incomes = guiManager->getExpenseTracker()->getIncomes();
        incomeTable->updateTable(incomes);
    }
}
