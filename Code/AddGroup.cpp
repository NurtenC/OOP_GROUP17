#include "AddGroup.h"
#include <FL/fl_ask.H>

AddGroup::AddGroup(int x, int y, int w, int h, GuiManager *manager)
    : Fl_Group(x, y, w, h), guiManager(manager)
{

    Fl_Tabs *tabs = new Fl_Tabs(165, 10, 800 - 170, 580);
    tabs->selection_color(fl_rgb_color(0x96, 0x7e, 0xd7)); // #9179ef
    tabs->labelcolor(FL_WHITE);
    {
        Fl_Group *expense = new Fl_Group(10, 35, 800 - 170, 580, "Expense");
        expense->labelsize(20);
        expense->labelcolor(FL_WHITE);
        expense->color(fl_rgb_color(0x96, 0x7e, 0xd7));
        expense->color2(fl_rgb_color(0x96, 0x7e, 0xd7));
        {
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

            expenseDescription = new Fl_Input(250, 150, 250, 40, "Description:");
            expenseAmount = new Fl_Input(250, 200, 100, 40, "Amount:");
            Fl_Button *addExpenseButton = new Fl_Button(430, 300, 100, 40, "Add");
            addExpenseButton->color(fl_rgb_color(0x4f, 0x3b, 0x78));
            addExpenseButton->labelcolor(FL_WHITE);
            addExpenseButton->color2(fl_rgb_color(0xff, 0xd3, 0xb6));
            addExpenseButton->align(FL_ALIGN_CENTER | FL_ALIGN_INSIDE);
            addExpenseButton->labelsize(15);
            addExpenseButton->callback(addExpenseCallback, this);
        }
        expense->end();

        Fl_Group *regularExpense = new Fl_Group(10, 35, 800 - 170, 580, "Regular Expense");
        regularExpense->color(fl_rgb_color(0x96, 0x7e, 0xd7));
        regularExpense->color2(fl_rgb_color(0x96, 0x7e, 0xd7));
        regularExpense->labelcolor(FL_WHITE);
        regularExpense->labelsize(20);
        {
        }
        regularExpense->end();

        Fl_Group *income = new Fl_Group(10, 35, 800 - 170, 580, "Income");
        income->color(fl_rgb_color(0x96, 0x7e, 0xd7));
        income->color2(fl_rgb_color(0x96, 0x7e, 0xd7));
        income->labelcolor(FL_WHITE);
        income->labelsize(20);
        {
            incomeDescription = new Fl_Input(250, 150, 250, 40, "Description:");
            incomeAmount = new Fl_Input(250, 200, 100, 40, "Amount:");
            Fl_Button *addIncomeButton = new Fl_Button(430, 300, 100, 40, "Add");
            addIncomeButton->color(fl_rgb_color(0x4f, 0x3b, 0x78));
            addIncomeButton->labelcolor(FL_WHITE);
            addIncomeButton->color2(fl_rgb_color(0xff, 0xd3, 0xb6));
            addIncomeButton->align(FL_ALIGN_CENTER | FL_ALIGN_INSIDE);
            addIncomeButton->labelsize(15);
            addIncomeButton->callback(addIncomeCallback, this);
        }
        income->end();

        Fl_Group *regularIncome = new Fl_Group(10, 35, 800 - 170, 580, "Regular Income");
        regularIncome->color(fl_rgb_color(0x96, 0x7e, 0xd7));
        regularIncome->color2(fl_rgb_color(0x96, 0x7e, 0xd7));
        regularIncome->labelcolor(FL_WHITE);
        regularIncome->labelsize(20);
        {
        }
        regularIncome->end();
    }
    tabs->end();
    end();
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

    Income income(*(et->getDate()),description, value);
    et->addIncome(income);
    fl_message("Income successfully added!");
    ag->incomeDescription->value("");
    ag->incomeAmount->value("");
    gm->update();
}