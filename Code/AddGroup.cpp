
#include "AddGroup.h"
#include <FL/fl_ask.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Input.H>
#include <sstream>
#include <iomanip>
#include <chrono>
#include <ctime>

void open_calendar(Fl_Widget *widget, void *data) {
    Fl_Window *calendar_window = new Fl_Window(200, 200, "Select Date");
    calendar_window->begin();

    Fl_Input *date_input = static_cast<Fl_Input *>(data);

    Fl_Input *day_input = new Fl_Input(50, 50, 100, 30, "Day:");
    Fl_Input *month_input = new Fl_Input(50, 100, 100, 30, "Month:");
    Fl_Button *ok_button = new Fl_Button(50, 150, 100, 30, "OK");

    ok_button->callback([](Fl_Widget *btn, void *data) {
        Fl_Input **inputs = static_cast<Fl_Input **>(data);
        Fl_Input *date_input = inputs[0];
        Fl_Input *day_input = inputs[1];
        Fl_Input *month_input = inputs[2];

        std::string day = day_input->value();
        std::string month = month_input->value();

        if (!day.empty() && !month.empty()) {
            date_input->value((month + "/" + day).c_str());
        }

        btn->window()->hide();
    }, new Fl_Input *[3]{date_input, day_input, month_input});

    calendar_window->end();
    calendar_window->show();
}


AddGroup::AddGroup(int x, int y, int w, int h, GuiManager *manager)
    : Fl_Group(x, y, w, h), guiManager(manager)
{
    Fl_Tabs *tabs = new Fl_Tabs(165, 10, 800 - 170, 580);
    tabs->selection_color(fl_rgb_color(0x96, 0x7e, 0xd7)); // #967ed7
    tabs->labelcolor(FL_WHITE);
    {
        // Expense Tab
        Fl_Group *expense = new Fl_Group(10, 35, 800 - 170, 580, "Expense");
        expense->labelsize(20);
        expense->labelcolor(FL_WHITE);
        expense->color(fl_rgb_color(0x96, 0x7e, 0xd7));
        expense->color2(fl_rgb_color(0x96, 0x7e, 0xd7));
        {
            // Category Choice for Expense
            expenseChoice = new Fl_Choice(250, 100, 150, 40, "Category:");
            expenseChoice->labelcolor(fl_rgb_color(0x0c, 0x00, 0x5a));
            expenseChoice->color2(FL_WHITE);
            expenseChoice->add("Grocery");
            expenseChoice->add("Health");
            expenseChoice->add("Entertainment");
            expenseChoice->add("Education");
            expenseChoice->add("Transportation");
            expenseChoice->add("Personal Care");
            expenseChoice->add("Clothes");
            expenseChoice->add("Tax");
            expenseChoice->add("Bill");
            expenseChoice->add("Rent");

            // Description Input for Expense
            expenseDescription = new Fl_Input(250, 150, 250, 40, "Description:");
            // Amount Input for Expense
            expenseAmount = new Fl_Input(250, 200, 100, 40, "Amount:");
            // Add Expense Button
            Fl_Button *addExpenseButton = new Fl_Button(430, 300, 100, 40, "Add");
            addExpenseButton->color(fl_rgb_color(0x4f, 0x3b, 0x78));
            addExpenseButton->labelcolor(FL_WHITE);
            addExpenseButton->color2(fl_rgb_color(0xff, 0xd3, 0xb6));
            addExpenseButton->align(FL_ALIGN_CENTER | FL_ALIGN_INSIDE);
            addExpenseButton->labelsize(15);
            addExpenseButton->callback(addExpenseCallback, this);
        }
        expense->end();

        // Regular Expense Tab
        Fl_Group *regularExpense = new Fl_Group(10, 35, 800 - 170, 580, "Regular Expense");
        regularExpense->color(fl_rgb_color(0x96, 0x7e, 0xd7));
        regularExpense->color2(fl_rgb_color(0x96, 0x7e, 0xd7));
        regularExpense->labelcolor(FL_WHITE);
        regularExpense->labelsize(20);
        {
            // Category Choice for Regular Expense
            regularExpenseChoice = new Fl_Choice(250, 100, 150, 40, "Category:");
            regularExpenseChoice->labelcolor(fl_rgb_color(0x0c, 0x00, 0x5a));
            regularExpenseChoice->color2(FL_WHITE);
            regularExpenseChoice->add("Grocery");
            regularExpenseChoice->add("Health");
            regularExpenseChoice->add("Entertainment");
            regularExpenseChoice->add("Education");
            regularExpenseChoice->add("Transportation");
            regularExpenseChoice->add("Personal Care");
            regularExpenseChoice->add("Clothes");
            regularExpenseChoice->add("Tax");
            regularExpenseChoice->add("Bill");
            regularExpenseChoice->add("Rent");

            // Description Input for Regular Expense
            regularExpenseDescription = new Fl_Input(250, 150, 250, 40, "Description:");
            // Amount Input for Regular Expense
            regularExpenseAmount = new Fl_Input(250, 200, 100, 40, "Amount:");
            // Date Input for Regular Expense
            regularExpenseDate = new Fl_Input(250, 250, 100, 40, "Date:");
            // Calendar Button for Regular Expense
            Fl_Button *calendar_button = new Fl_Button(360, 250, 30, 30, "@>>");
            calendar_button->callback(open_calendar, regularExpenseDate);

            // Add Regular Expense Button
            Fl_Button *addExpenseButton = new Fl_Button(430, 300, 100, 40, "Add");
            addExpenseButton->color(fl_rgb_color(0x4f, 0x3b, 0x78));
            addExpenseButton->labelcolor(FL_WHITE);
            addExpenseButton->color2(fl_rgb_color(0xff, 0xd3, 0xb6));
            addExpenseButton->align(FL_ALIGN_CENTER | FL_ALIGN_INSIDE);
            addExpenseButton->labelsize(15);
            addExpenseButton->callback(addRegularExpenseCallback, this);
        }
        regularExpense->end();

        // Income Tab
        Fl_Group *income = new Fl_Group(10, 35, 800 - 170, 580, "Income");
        income->color(fl_rgb_color(0x96, 0x7e, 0xd7));
        income->color2(fl_rgb_color(0x96, 0x7e, 0xd7));
        income->labelcolor(FL_WHITE);
        income->labelsize(20);
        {
            // Description Input for Income
            incomeDescription = new Fl_Input(250, 150, 250, 40, "Description:");
            // Amount Input for Income
            incomeAmount = new Fl_Input(250, 200, 100, 40, "Amount:");
            // Add Income Button
            Fl_Button *addIncomeButton = new Fl_Button(430, 300, 100, 40, "Add");
            addIncomeButton->color(fl_rgb_color(0x4f, 0x3b, 0x78));
            addIncomeButton->labelcolor(FL_WHITE);
            addIncomeButton->color2(fl_rgb_color(0xff, 0xd3, 0xb6));
            addIncomeButton->align(FL_ALIGN_CENTER | FL_ALIGN_INSIDE);
            addIncomeButton->labelsize(15);
            addIncomeButton->callback(addIncomeCallback, this);
        }
        income->end();

        // Regular Income Tab
        Fl_Group *regularIncome = new Fl_Group(10, 35, 800 - 170, 580, "Regular Income");
        regularIncome->color(fl_rgb_color(0x96, 0x7e, 0xd7));
        regularIncome->color2(fl_rgb_color(0x96, 0x7e, 0xd7));
        regularIncome->labelcolor(FL_WHITE);
        regularIncome->labelsize(20);
        {
            // Description Input for Regular Income
            regularIncomeDescription = new Fl_Input(250, 150, 250, 40, "Description:");
            // Amount Input for Regular Income
            regularIncomeAmount = new Fl_Input(250, 200, 100, 40, "Amount:");
            // Date Input for Regular Income
            regularIncomeDate = new Fl_Input(250, 250, 100, 40, "Date:");
            // Calendar Button for Regular Income
            Fl_Button *calendar_button = new Fl_Button(360, 250, 30, 30, "@>>");
            calendar_button->callback(open_calendar, regularIncomeDate);

            // Add Regular Income Button
            Fl_Button *addIncomeButton = new Fl_Button(430, 300, 100, 40, "Add");
            addIncomeButton->color(fl_rgb_color(0x4f, 0x3b, 0x78));
            addIncomeButton->labelcolor(FL_WHITE);
            addIncomeButton->color2(fl_rgb_color(0xff, 0xd3, 0xb6));
            addIncomeButton->align(FL_ALIGN_CENTER | FL_ALIGN_INSIDE);
            addIncomeButton->labelsize(15);
            addIncomeButton->callback(addRegularIncomeCallback, this);
        }
        regularIncome->end();
    }
    tabs->end();
    end();
}


void AddGroup::addRegularExpenseCallback(Fl_Widget *widget, void *data) {
    AddGroup *ag = static_cast<AddGroup *>(data);
    GuiManager *gm = ag->guiManager;
    ExpenseTracker *et = gm->getExpenseTracker();

    int categoryIndex = ag->regularExpenseChoice->value();
    std::string description = ag->regularExpenseDescription->value();
    std::string amount = ag->regularExpenseAmount->value();
    std::string dateString = ag->regularExpenseDate->value();
    double value;

    // Validate empty fields
    if (categoryIndex < 0 || description.empty() || amount.empty() || dateString.empty()) {
        fl_alert("Category, description, amount, and date cannot be empty");
        return;
    }

    // Convert amount to double
    try {
        value = std::stod(amount);
    } catch (const std::invalid_argument &e) {
        fl_alert("Amount must be a number");
        return;
    }

    // Convert date string to Date object
    try {
        // Convert date to `std::tm` structure
        std::tm tm = {};
        std::istringstream ss(dateString);
        ss >> std::get_time(&tm, "%d/%m/%Y"); // Expected format: DD/MM/YYYY
        if (ss.fail()) {
            fl_alert("Invalid date format. Expected format: DD/MM/YYYY");
            return;
        }

        // Create `std::chrono::system_clock::time_point`
        std::time_t timeAsInt = std::mktime(&tm);
        if (timeAsInt == -1) {
            fl_alert("Invalid date");
            return;
        }
        auto timePoint = std::chrono::system_clock::from_time_t(timeAsInt);
        Date date(timePoint);

        // Add Expense
        Category category = ExpenseTracker::getCategory(categoryIndex);
        Expense expense(date, category, description, value);
        et->addExpense(expense);

        // Success Message
        fl_message("Regular Expense successfully added!");
        ag->regularExpenseChoice->value(-1);
        ag->regularExpenseDescription->value("");
        ag->regularExpenseAmount->value("");
        ag->regularExpenseDate->value("");
        gm->update();
    } catch (...) {
        fl_alert("An unexpected error occurred while processing the date.");
    }
}


void AddGroup::addRegularIncomeCallback(Fl_Widget *widget, void *data) {
    AddGroup *ag = static_cast<AddGroup *>(data);
    GuiManager *gm = ag->guiManager;
    ExpenseTracker *et = gm->getExpenseTracker();

    std::string description = ag->regularIncomeDescription->value();
    std::string amount = ag->regularIncomeAmount->value();
    std::string dateString = ag->regularIncomeDate->value();
    double value;

    // Validate empty fields
    if (description.empty() || amount.empty() || dateString.empty()) {
        fl_alert("Description, amount, and date cannot be empty");
        return;
    }

    // Convert amount to double
    try {
        value = std::stod(amount);
    } catch (const std::invalid_argument &e) {
        fl_alert("Amount must be a number");
        return;
    }

    // Convert date string to Date object
    try {
        // Convert date to `std::tm` structure
        std::tm tm = {};
        std::istringstream ss(dateString);
        ss >> std::get_time(&tm, "%d/%m/%Y"); // Expected format: DD/MM/YYYY
        if (ss.fail()) {
            fl_alert("Invalid date format. Expected format: DD/MM/YYYY");
            return;
        }

        // Create `std::chrono::system_clock::time_point`
        std::time_t timeAsInt = std::mktime(&tm);
        if (timeAsInt == -1) {
            fl_alert("Invalid date");
            return;
        }
        auto timePoint = std::chrono::system_clock::from_time_t(timeAsInt);
        Date date(timePoint);

        // Add Income
        Income income(date, description, value);
        et->addIncome(income);

        // Success Message
        fl_message("Regular Income successfully added!");
        ag->regularIncomeDescription->value("");
        ag->regularIncomeAmount->value("");
        ag->regularIncomeDate->value("");
        gm->update();
    } catch (...) {
        fl_alert("An unexpected error occurred while processing the date.");
    }
}

void AddGroup::addExpenseCallback(Fl_Widget *widget, void *data)
{
    AddGroup *ag = static_cast<AddGroup *>(data);
    GuiManager *gm = ag->guiManager;
    ExpenseTracker *et = gm->getExpenseTracker();

    int categoryIndex = ag->expenseChoice->value();
    std::string description = ag->expenseDescription->value();
    std::string amount = ag->expenseAmount->value();
    double value;

    // Validate empty fields
    if (categoryIndex < 0 || description.empty() || amount.empty())
    {
        fl_alert("Category, description and amount cannot be empty");
        return;
    }
    try
    {
        value = std::stod(amount);
    }
    catch (const std::invalid_argument &e)
    {
        fl_alert("Amount must be number");
        return;
    }

    // Add Expense
    Category category = ExpenseTracker::getCategory(categoryIndex);
    Expense expense(*(et->getDate()), category, description, value);
    et->addExpense(expense);
    fl_message("Expense successfully added!");
    ag->expenseChoice->value(-1);
    ag->expenseDescription->value("");
    ag->expenseAmount->value("");
    gm->update();
}


void AddGroup::addIncomeCallback(Fl_Widget *widget, void *data)
{
    AddGroup *ag = static_cast<AddGroup *>(data);
    GuiManager *gm = ag->guiManager;
    ExpenseTracker *et = gm->getExpenseTracker();

    std::string description = ag->incomeDescription->value();
    std::string amount = ag->incomeAmount->value();
    double value;

    // Validate empty fields
    if (description.empty() || amount.empty())
    {
        fl_alert("Description and amount cannot be empty");
        return;
    }
    try
    {
        value = std::stod(amount);
    }
    catch (const std::invalid_argument &e)
    {
        fl_alert("Amount must be number");
        return;
    }

    // Add Income
    Income income(*(et->getDate()), description, value);
    et->addIncome(income);
    fl_message("Income successfully added!");
    ag->incomeDescription->value("");
    ag->incomeAmount->value("");
    gm->update();
}
