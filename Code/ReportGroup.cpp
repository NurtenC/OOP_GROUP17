#include "ReportGroup.h"
#include <fl/Fl_Button.H>

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
    expenseReportList->callback(expenseReportListCallback, this);
    
    Fl_Button *incomeReportList = new Fl_Button(650, 480, 145, 30, "List");
    incomeReportList->color(fl_rgb_color(0x4f, 0x3b, 0x78));
    incomeReportList->labelcolor(FL_WHITE);
    incomeReportList->color2(fl_rgb_color(0xff, 0xd3, 0xb6));
    incomeReportList->align(FL_ALIGN_CENTER | FL_ALIGN_INSIDE);
    incomeReportList->labelsize(15);
    incomeReportList->callback(incomeReportListCallback, this);

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

//getting filtered expense list and update table with this list
void ReportGroup::expenseReportListCallback(Fl_Widget*, void* data)
{
    ReportGroup* reportGroup = static_cast<ReportGroup*>(data);
    reportGroup->filteredExpenses = reportGroup->filterExpenses();
    reportGroup->expenseTable->updateTable(&reportGroup->filteredExpenses);
}

//getting filtered income list and update table with this list
void ReportGroup::incomeReportListCallback(Fl_Widget*, void* data)
{
    ReportGroup* reportGroup = static_cast<ReportGroup*>(data);
    reportGroup->filteredIncomes = reportGroup->filterIncomes();
    reportGroup->incomeTable->updateTable(&reportGroup->filteredIncomes);
}

//function to check if categories matched
static bool matchesCategory(const Expense& expene, const std::string& selectedCategory)
{
    if (selectedCategory == "All") {
        return true;
    }
    return (expene.getCategoryAsString() == selectedCategory);
}

static bool inSelectedTimeRange(const Date& expenseDate, 
                                const std::string& chosenTimeInterval,
                                std::chrono::system_clock::time_point applicationsCurrentTime)
{
    // If "All" is selected, include all expenses, so return true.
    if (chosenTimeInterval == "All") {
        return true;
    }
    // Initialize a new tm structure for the expense date, using now_tm as a template.
    std::tm expenseDate_timeStruct;

    // Populate the tm structure with the expense date's year, month, and day.
    // Adjust for tm_year (years since 1900) and tm_mon (0-based months).
    expenseDate_timeStruct.tm_year = expenseDate.getYear() - 1900;
    expenseDate_timeStruct.tm_mon  = expenseDate.getMonth() - 1;
    expenseDate_timeStruct.tm_mday = expenseDate.getDay();

    // Zero out hour, minute, and second to focus only on the day.
    expenseDate_timeStruct.tm_hour = 0; 
    expenseDate_timeStruct.tm_min  = 0;
    expenseDate_timeStruct.tm_sec  = 0;

    // Convert the adjusted tm structure back to time_t format.
    std::time_t expenseDate_time_t = std::mktime(&expenseDate_timeStruct);

    // If the conversion fails, return false.
    if (expenseDate_time_t == -1) {
        return false;
    }

    // Convert the expense time_t back to a time_point for comparisons.
    std::chrono::system_clock::time_point expense_systemTime = std::chrono::system_clock::from_time_t(expenseDate_time_t);

    // Check if the expense date falls within the chosen time range.
    if (chosenTimeInterval == "Last Day") {
        std::chrono::system_clock::time_point interval = applicationsCurrentTime - std::chrono::hours(24); // 24 hours ago
        return expense_systemTime >= interval; // Expense is within the last day.
    }
    else if (chosenTimeInterval == "Last Week") {
        std::chrono::system_clock::time_point interval = applicationsCurrentTime - std::chrono::hours(24 * 7); // 7 days ago
        return expense_systemTime >= interval; // Expense is within the last week.
    }
    else if (chosenTimeInterval == "Last Month") {
        std::chrono::system_clock::time_point interval = applicationsCurrentTime - std::chrono::hours(24 * 30); // 30 days ago
        return expense_systemTime >= interval; // Expense is within the last month.
    }
    else if (chosenTimeInterval == "Last 3-Month") {
        std::chrono::system_clock::time_point interval = applicationsCurrentTime - std::chrono::hours(24 * 90); // 90 days ago
        return expense_systemTime >= interval; // Expense is within the last 3 months.
    }
    else if (chosenTimeInterval == "Last 6-Month") {
        std::chrono::system_clock::time_point interval = applicationsCurrentTime - std::chrono::hours(24 * 180); // 180 days ago
        return expense_systemTime >= interval; // Expense is within the last 6 months.
    }
    else if (chosenTimeInterval == "Last Year") {
        std::chrono::system_clock::time_point interval = applicationsCurrentTime - std::chrono::hours(24 * 365); // 365 days ago
        return expense_systemTime >= interval; // Expense is within the last year.
    }
    return true;
}

std::vector<Expense> ReportGroup::filterExpenses()
{
    std::vector<Expense> filteredExpenses; // Create a vector to store filtered expenses.

    // Get all expenses from the expense tracker.
    std::vector<Expense>* allExpenses = guiManager->getExpenseTracker()->getExpenses();

    // If there are no expenses, return an empty result.
    if (!allExpenses) {
        return filteredExpenses;
    }

    // Get the selected category from the GUI category choice widget.
    int categoryIndex = expenseReportCategory->value();
    std::string selectedCategory = expenseReportCategory->text(categoryIndex);

    // Get the selected time interval from the GUI time choice widget.
    int timeIndex = expenseReportTime->value();
    std::string selectedTime = expenseReportTime->text(timeIndex);

    // Get the current time from the expense tracker.
    std::chrono::system_clock::time_point applicationsCurrentTime = guiManager->getExpenseTracker()->getTime();

    // Loop through all expenses to apply the filters.
    for (Expense& expense : *allExpenses) {
        // Include the expense if it matches both the selected category and time range.
        if (matchesCategory(expense, selectedCategory) &&
            inSelectedTimeRange(expense.getDate(), selectedTime, applicationsCurrentTime)) 
        {
            filteredExpenses.push_back(expense); // Add the matching expense to the result.
        }
    }

    // Return the filtered expenses.
    return filteredExpenses;
}


std::vector<Income> ReportGroup::filterIncomes()
{
    // Create a vector to store filtered incomes.
    std::vector<Income> filteredIncomes;

    // Get all incomes from the expense tracker.
    std::vector<Income>* allIncomes = guiManager->getExpenseTracker()->getIncomes();

    // If no incomes are found, return an empty result.
    if (!allIncomes) {
        return filteredIncomes;
    }

    // Get the selected time interval from the income report time choice widget.
    int timeIndex = incomeReportTime->value();
    std::string selectedTime = incomeReportTime->text(timeIndex);

    // Get the current time from the tracker.
    std::chrono::system_clock::time_point applicationsCurrentTime = guiManager->getExpenseTracker()->getTime();

    // Loop through all incomes to apply the time filter.
    for (Income& income : *allIncomes) {
        // Check if the income date falls within the selected time range.
        if (inSelectedTimeRange(income.getDate(), selectedTime, applicationsCurrentTime)) {
            filteredIncomes.push_back(income); // Add the matching income to the result.
        }
    }

    // Return the filtered incomes.
    return filteredIncomes;
}
