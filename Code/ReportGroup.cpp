/**
 * @file ReportGroup.cpp
 * @brief Implements the ReportGroup class for generating and displaying reports within the GUI.
 */

#include "ReportGroup.h"
#include <FL/Fl_Button.H>
#include <FL/fl_ask.H>
#include <sstream>
#include <iomanip>
#include "ExpenseTracker.h"

/**
 * @brief Constructs a ReportGroup object.
 *
 * Initializes the reporting interface with tables for expenses and incomes, along with
 * choice widgets for filtering reports by category and duration. Sets up buttons for
 * listing the reports and handles callbacks for user interactions.
 *
 * @param x The x-coordinate of the group.
 * @param y The y-coordinate of the group.
 * @param w The width of the group.
 * @param h The height of the group.
 * @param manager Pointer to the GuiManager instance managing the GUI.
 */
ReportGroup::ReportGroup(int x, int y, int w, int h, GuiManager *manager)
    : Fl_Group(x, y, w, h), guiManager(manager)
{
    // Initialize Expense Table
    expenseTable = new ExpenseTable(180, 20, 400, 270, nullptr);
    
    // Initialize Income Table
    incomeTable = new IncomeTable(180, 320, 400, 270, nullptr);

    // Expense Report Category Choice
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

    // Expense Report Time Choice
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

    // Income Report Time Choice
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

    // Expense Report List Button
    Fl_Button *expenseReportList = new Fl_Button(650, 180, 145, 30, "List");
    expenseReportList->color(fl_rgb_color(0x4f, 0x3b, 0x78));
    expenseReportList->labelcolor(FL_WHITE);
    expenseReportList->color2(fl_rgb_color(0xff, 0xd3, 0xb6));
    expenseReportList->align(FL_ALIGN_CENTER | FL_ALIGN_INSIDE);
    expenseReportList->labelsize(15);
    // TODO: Assign a callback function to handle expense report listing
    // expenseReportList->callback(expenseReportListCallback, this);

    // Income Report List Button
    Fl_Button *incomeReportList = new Fl_Button(650, 480, 145, 30, "List");
    incomeReportList->color(fl_rgb_color(0x4f, 0x3b, 0x78));
    incomeReportList->labelcolor(FL_WHITE);
    incomeReportList->color2(fl_rgb_color(0xff, 0xd3, 0xb6));
    incomeReportList->align(FL_ALIGN_CENTER | FL_ALIGN_INSIDE);
    incomeReportList->labelsize(15);
    // TODO: Assign a callback function to handle income report listing
    // incomeReportList->callback(incomeReportListCallback, this);

    end(); // End of Fl_Group
}

/**
 * @brief Updates the expense and income tables with the latest data.
 *
 * Retrieves the latest expenses and incomes from the ExpenseTracker instance and updates
 * the corresponding tables to reflect any changes.
 */
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
