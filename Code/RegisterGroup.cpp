
#include "RegisterGroup.h"
#include "GuiManager.h"
#include "ExpenseTracker.h"
#include <FL/Fl_Box.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Input.H>
#include <FL/fl_ask.H>


RegisterGroup::RegisterGroup(int x, int y, int w, int h, GuiManager *manager)
    : Fl_Group(x, y, w, h), guiManager(manager)
{
    // Username input field
    usernameInput = new Fl_Input(x + (w / 6) * 2, y + (h / 10) * 3, 260, 35, "Username:");
    usernameInput->labelcolor(fl_rgb_color(0x77, 0x52, 0x9e));
    usernameInput->labelsize(16);

    // Password input field
    passwordInput = new Fl_Input(x + (w / 6) * 2, y + (h / 10) * 4, 260, 35, "Password:");
    passwordInput->labelcolor(fl_rgb_color(0x77, 0x52, 0x9e));
    passwordInput->type(FL_SECRET_INPUT);
    passwordInput->labelsize(16);

    // Budget input field
    budgetInput = new Fl_Input(x + (w / 6) * 2, y + (h / 10) * 5, 120, 35, "Budget:");
    budgetInput->labelcolor(fl_rgb_color(0x77, 0x52, 0x9e));
    budgetInput->labelsize(16);

    // Register button
    Fl_Button *registerSubmit = new Fl_Button(x + (w / 20) * 7, y + (h / 20) * 13, 230, 35, "Sign In");
    registerSubmit->labelsize(16);
    registerSubmit->color(fl_rgb_color(0xdc, 0xb5, 0xff)); // #dcb5ff
    registerSubmit->color2(fl_rgb_color(0xff, 0xd3, 0xb6));
    registerSubmit->callback(registerCallback, this);

    // Back button
    Fl_Button *backButton = new Fl_Button(x + 10, y + 10, 70, 30, "@<- Back");
    backButton->color(fl_rgb_color(0xff, 0xd3, 0xb6));
    backButton->color2(fl_rgb_color(0xdc, 0xb5, 0xff)); // #dcb5ff
    backButton->callback(GuiManager::showStartScreenCallback, guiManager);

    end(); // End of Fl_Group
}


void RegisterGroup::registerCallback(Fl_Widget *widget, void *data)
{
    RegisterGroup *registerGroup = static_cast<RegisterGroup *>(data);
    GuiManager *guiManager = registerGroup->guiManager;
    ExpenseTracker *expenseTracker = guiManager->getExpenseTracker();

    std::string username = registerGroup->usernameInput->value();
    std::string password = registerGroup->passwordInput->value();
    std::string amount = registerGroup->budgetInput->value();
    double value;

    // Validate input fields
    if (username.empty() || password.empty())
    {
        fl_alert("Username and Password cannot be empty.");
        return;
    }
    try
    {
        value = std::stod(amount);
    }
    catch (const std::invalid_argument &e)
    {
        fl_alert("Amount must be a number.");
        return;
    }

    // Attempt to register the user
    if (expenseTracker->registerUser(username, password, value))
    {
        fl_message("Registration successful! Please log in.");
        guiManager->update();
        guiManager->showLogin();
    }
    else
    {
        fl_alert("Username already exists. Please choose a different username.");
    }
}
