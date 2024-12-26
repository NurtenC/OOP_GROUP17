#pragma once
#include <FL/Fl_Group.H>
#include <FL/Fl_Input.H>
#include "GuiManager.h"
#include "ExpenseTable.h"
#include "IncomeTable.h"
#include <FL/Fl_Choice.H>

class ReportGroup : public Fl_Group{
public:
    ReportGroup(int x, int y, int w, int h, GuiManager* manager);
    void update();
    
    std::vector<Expense> filterExpenses();
    std::vector<Income> filterIncomes();

    static void expenseReportListCallback(Fl_Widget*, void*);
    static void incomeReportListCallback(Fl_Widget*, void*);

private:
    GuiManager* guiManager;
    ExpenseTable* expenseTable;
    IncomeTable* incomeTable;
    Fl_Choice* expenseReportCategory;
    Fl_Choice* expenseReportTime;
    Fl_Choice* incomeReportTime;
    std::vector<Expense> filteredExpenses;
    std::vector<Income> filteredIncomes;
};