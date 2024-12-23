#include "LoginGroup.h"
#include "GuiManager.h"
#include <FL/Fl_Box.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Input.H>
#include <FL/fl_ask.H>

LoginGroup::LoginGroup(int x, int y, int w, int h, GuiManager* manager)
    : Fl_Group(x, y, w, h), guiManager(manager) {

    usernameInput = new Fl_Input(x + (w / 6) * 2, y + (h / 10) * 3, 260, 35, "Username:");
    usernameInput->labelcolor(fl_rgb_color(0x77,0x52,0x9e));
    usernameInput->labelsize(16);

    passwordInput = new Fl_Input(x + (w / 6) * 2, y + (h / 10) * 4, 260, 35, "Password:");
    passwordInput->labelcolor(fl_rgb_color(0x77,0x52,0x9e));
    passwordInput->type(FL_SECRET_INPUT);
    passwordInput->labelsize(16);

    Fl_Button* loginSubmit = new Fl_Button(x + (w / 20) * 7, y + (h / 20) * 11, 230, 35, "Login");
    loginSubmit->labelsize(16);
    loginSubmit->color(fl_rgb_color(0xdc,0xb5,0xff));//#dcb5ff
    loginSubmit->color2(fl_rgb_color(0xff,0xd3,0xb6));
    loginSubmit->callback(loginCallback, this);

    Fl_Button* backButton = new Fl_Button(x + 10, y + 10, 70, 30, "@<- Back");
    backButton->color(fl_rgb_color(0xff,0xd3,0xb6));
    backButton->color2(fl_rgb_color(0xdc,0xb5,0xff));//#dcb5ff
    backButton->callback(GuiManager::showStartScreenCallback, guiManager);

    end();
}

void LoginGroup::loginCallback(Fl_Widget* widget, void* data) {
    LoginGroup* loginGroup = static_cast<LoginGroup*>(data);
    GuiManager* guiManager = loginGroup->guiManager;
    ExpenseTracker* expenseTracker = guiManager->getExpenseTracker();

    std::string username = loginGroup->usernameInput->value();
    std::string password = loginGroup->passwordInput->value();

    if (username.empty() || password.empty()) {
        fl_alert("Username and Password cannot be empty.");
        return;
    }

    if (expenseTracker->login(username, password)) {
        fl_message("Login successful! Welcome, %s.", expenseTracker->getCurrentUsername().c_str());
        guiManager->showMainApplication();
    }
    else {
        fl_alert("Invalid username or password. Please try again.");
    }
}
