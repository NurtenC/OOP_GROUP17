#include "ReportGroup.h"
#include <Fl/Fl_Button.H>

ReportGroup::ReportGroup(int x, int y, int w, int h, GuiManager *manager)
    : Fl_Group(x, y, w, h), guiManager(manager)
{
    expenseTable = new ExpenseTable(180, 20, 400, 270, nullptr);
    incomeTable = new IncomeTable(180, 320, 400, 270, nullptr);

    expenseReportCategory = new Fl_Choice(650, 40, 145, 30, "Category:");
    expenseReportCategory->labelcolor(fl_rgb_color(0x0c, 0x00, 0x5a));
    expenseReportCategory->color2(FL_WHITE);

    expenseReportCategory->add("All");
    expenseReportCategory->add("Grocery");
    expenseReportCategory->add("Health");
    expenseReportCategory->add("Entertainment");
    expenseReportCategory->add("Education");
    expenseReportCategory->add("Transportation");
    expenseReportCategory->add("Personal Care");
    expenseReportCategory->add("Clothes");
    expenseReportCategory->add("Tax");
    expenseReportCategory->add("Bill");
    expenseReportCategory->add("Rent");
    expenseReportCategory->value(0);

    expenseReportTime = new Fl_Choice(650, 100, 145, 30, "Duration:");
    expenseReportTime->labelcolor(fl_rgb_color(0x0c, 0x00, 0x5a));
    expenseReportTime->color2(FL_WHITE);

    expenseReportTime->add("All");
    expenseReportTime->add("Last Day");
    expenseReportTime->add("Last Week");
    expenseReportTime->add("Last Month");
    expenseReportTime->add("Last 3-Month");
    expenseReportTime->add("Last 6-Month");
    expenseReportTime->add("Last Year");
    expenseReportTime->value(0);

    incomeReportTime = new Fl_Choice(650, 400, 145, 30, "Duration:");
    incomeReportTime->labelcolor(fl_rgb_color(0x0c, 0x00, 0x5a));
    incomeReportTime->color2(FL_WHITE);

    incomeReportTime->add("All");
    incomeReportTime->add("Last Day");
    incomeReportTime->add("Last Week");
    incomeReportTime->add("Last Month");
    incomeReportTime->add("Last 3-Month");
    incomeReportTime->add("Last 6-Month");
    incomeReportTime->add("Last Year");
    incomeReportTime->value(0);

    Fl_Button *expenseReportList = new Fl_Button(650, 180, 145, 30, "List");
    expenseReportList->color(fl_rgb_color(0x4f, 0x3b, 0x78));
    expenseReportList->labelcolor(FL_WHITE);
    expenseReportList->color2(fl_rgb_color(0xff, 0xd3, 0xb6));
    expenseReportList->align(FL_ALIGN_CENTER | FL_ALIGN_INSIDE);
    expenseReportList->labelsize(15);
    // expenseReportList->callback(, this);

    Fl_Button *incomeReportList = new Fl_Button(650, 480, 145, 30, "List");
    incomeReportList->color(fl_rgb_color(0x4f, 0x3b, 0x78));
    incomeReportList->labelcolor(FL_WHITE);
    incomeReportList->color2(fl_rgb_color(0xff, 0xd3, 0xb6));
    incomeReportList->align(FL_ALIGN_CENTER | FL_ALIGN_INSIDE);
    incomeReportList->labelsize(15);
    // incomeReportList->callback(, this);

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