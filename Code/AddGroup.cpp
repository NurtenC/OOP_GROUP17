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
            choice = new Fl_Choice(250, 100, 150, 40, "Category:");
            choice->labelcolor(fl_rgb_color(0x0c, 0x00, 0x5a));
            choice->color2(FL_WHITE);
            choice->add("Grocery");
            choice->add("Health");
            choice->add("Entertainment");
            choice->add("Education");
            choice->add("Transportation");
            choice->add("Personal Care");
            choice->add("Clothes");
            choice->add("Tax");
            choice->add("Bill");
            choice->add("Rent");

            description = new Fl_Input(250, 150, 250, 40, "Description:");
            amount = new Fl_Input(250, 200, 100, 40, "Amount:");
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

    int categoryIndex = ag->choice->value();
    std::string description = ag->description->value();
    std::string amount = ag->amount->value();
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
    ag->choice->value(-1);
    ag->description->value("");
    ag->amount->value("");
    gm->update();
}
