/**
 * @file LoginGroup.cpp
 * @brief Implements the LoginGroup class for handling user login within the GUI.
 */

#include "LoginGroup.h"
#include "GuiManager.h"
#include <FL/fl_ask.H>

/**
 * @brief Constructs a LoginGroup object.
 *
 * Initializes the login interface with input fields for username and password,
 * a login button to submit credentials, and a back button to return to the start screen.
 *
 * @param x The x-coordinate of the group.
 * @param y The y-coordinate of the group.
 * @param w The width of the group.
 * @param h The height of the group.
 * @param manager Pointer to the GuiManager instance managing the GUI.
 */
LoginGroup::LoginGroup(int x, int y, int w, int h, GuiManager* manager)
    : Fl_Group(x, y, w, h), guiManager(manager) {

    // Username input field
    usernameInput = new Fl_Input(x + (w / 6) * 2, y + (h / 10) * 3, 260, 35, "Username:");
    usernameInput->labelcolor(fl_rgb_color(0x77, 0x52, 0x9e));
    usernameInput->labelsize(16);

    // Password input field
    passwordInput = new Fl_Input(x + (w / 6) * 2, y + (h / 10) * 4, 260, 35, "Password:");
    passwordInput->labelcolor(fl_rgb_color(0x77, 0x52, 0x9e));
    passwordInput->type(FL_SECRET_INPUT);
    passwordInput->labelsize(16);

    // Login button
    Fl_Button* loginSubmit = new Fl_Button(x + (w / 20) * 7, y + (h / 20) * 11, 230, 35, "Login");
    loginSubmit->labelsize(16);
    loginSubmit->color(fl_rgb_color(0xdc, 0xb5, 0xff)); // #dcb5ff
    loginSubmit->color2(fl_rgb_color(0xff, 0xd3, 0xb6));
    loginSubmit->callback(loginCallback, this);

    // Back button
    Fl_Button* backButton = new Fl_Button(x + 10, y + 10, 70, 30, "@<- Back");
    backButton->color(fl_rgb_color(0xff, 0xd3, 0xb6));
    backButton->color2(fl_rgb_color(0xdc, 0xb5, 0xff)); // #dcb5ff
    backButton->callback(GuiManager::showStartScreenCallback, guiManager);

    end(); // End of Fl_Group
}

/**
 * @brief Callback function for handling the login process.
 *
 * This static function is triggered when the login button is clicked. It retrieves
 * the entered username and password, validates them, and attempts to log the user in
 * using the ExpenseTracker instance. Provides feedback based on the success or failure
 * of the login attempt.
 *
 * @param widget Pointer to the widget triggering the callback.
 * @param data Pointer to the LoginGroup instance.
 */
void LoginGroup::loginCallback(Fl_Widget* widget, void* data) {
    LoginGroup* loginGroup = static_cast<LoginGroup*>(data);
    GuiManager* guiManager = loginGroup->guiManager;
    ExpenseTracker* expenseTracker = guiManager->getExpenseTracker();

    std::string username = loginGroup->usernameInput->value();
    std::string password = loginGroup->passwordInput->value();

    // Validate input fields
    if (username.empty() || password.empty()) {
        fl_alert("Username and Password cannot be empty.");
        return;
    }

    // Attempt to log in
    if (expenseTracker->login(username, password)) {
        fl_message("Login successful! Welcome, %s.", expenseTracker->getCurrentUsername().c_str());
        guiManager->showMainApplication();
        guiManager->update();
    }
    else {
        fl_alert("Invalid username or password. Please try again.");
    }
}
