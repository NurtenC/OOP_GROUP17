
#include "HomepageGroup.h"
#include "Date.h"
#include <Fl/fl_ask.H>
#include <FL/Fl_Tabs.H>    
#include <FL/Fl_Group.H>   
#include <FL/Fl_Input.H>   

HomepageGroup::HomepageGroup(int x, int y, int w, int h, GuiManager* manager)
    : Fl_Group(x, y, w, h), guiManager(manager)
{
    // Place the "Welcome" text 100 pixels to the right of the Add menu's end and 100 pixels below the top of the window
    welcomeLabel = new Fl_Box(
        165 + 150,  
        y + 85,     
        300, 50,
        "Expense Tracker"
    );
    welcomeLabel->labelcolor(fl_rgb_color(0x77, 0x52, 0x9e));
    welcomeLabel->labelsize(32);
    welcomeLabel->labelfont(FL_COURIER_BOLD);
    welcomeLabel->align(FL_ALIGN_CENTER | FL_ALIGN_INSIDE);

    // Date box (top right)
    dateBox = new Fl_Box(x + w - 210, y + 10, 85, 40);
    dateBox->box(FL_FLAT_BOX);
    dateBox->color(fl_rgb_color(0xa5, 0xbd, 0xfd));
    dateBox->labelsize(18);
    dateBox->labelfont(FL_HELVETICA);
    dateBox->labelcolor(fl_rgb_color(0x27, 0x29, 0x6d));
    dateBox->copy_label(guiManager->getExpenseTracker()->getDate()->getDateString().c_str());

    // Time box (top right, next to date)
    timeBox = new Fl_Box(x + w - 120, y + 10, 85, 40);
    timeBox->box(FL_FLAT_BOX);
    timeBox->color(fl_rgb_color(0xa5, 0xbd, 0xfd));
    timeBox->labelsize(18);
    timeBox->labelfont(FL_HELVETICA);
    timeBox->labelcolor(fl_rgb_color(0x27, 0x29, 0x6d));
    timeBox->copy_label(Date::getTimeStr(guiManager->getExpenseTracker()->getTime()).c_str());

    // Logout button (bottom right)
    Fl_Button* logoutButton = new Fl_Button(x + w - 395, y + h - 50, 140, 35, "Log Out");
    logoutButton->labelsize(16);
    logoutButton->color(fl_rgb_color(0xdc, 0xb5, 0xff));
    logoutButton->color2(fl_rgb_color(0xff, 0xd3, 0xb6));
    logoutButton->callback(logoutCallback, this);

    // Continuous time update
    Fl::add_timeout(0.001, updateTimeCallback, this);

    // Initialize User Info & Settings tabs starting slightly above the bottom of the window and after the Add menu (x=165)
    
    Fl_Tabs* userTabs = new Fl_Tabs(173, y + 160, 620, 290);
    userTabs->selection_color(fl_rgb_color(0x96, 0x7e, 0xd7));
    userTabs->labelcolor(FL_WHITE);
    userTabs->labelfont(FL_COURIER_BOLD);
    userTabs->labelsize(18);
    {
    // --- USER INFO TAB ---
    Fl_Group* userInfoGroup = new Fl_Group(171, y + 190, 620, 290, "User Info");
    userInfoGroup->labelcolor(FL_WHITE);    
    userInfoGroup->labelfont(FL_COURIER_BOLD);
    userInfoGroup->color(fl_rgb_color(0x96, 0x7e, 0xd7));
    userInfoGroup->color2(fl_rgb_color(0x96, 0x7e, 0xd7));
    userInfoGroup->labelsize(16);
    {
        // Username label
        userInfoUsernameLabel = new Fl_Box(
            150+20,       // Left side
            (y + 220),      
            200, 30,
            "Username:"
        );
        userInfoUsernameLabel->labelsize(20);
        userInfoUsernameLabel->labelcolor(FL_WHITE);
       

        // Budget label
        userInfoBudgetLabel = new Fl_Box(
            150+20,
            (y + 260),
            200, 30,
            "Budget:"
        );
        userInfoBudgetLabel->labelsize(20);
        userInfoBudgetLabel->labelcolor(FL_WHITE);
        
    }
    userInfoGroup->end();

    // --- SETTINGS TAB ---
    Fl_Group* userSettingsGroup = new Fl_Group(170, y + 190, 620, 290, "Settings");
    userSettingsGroup->labelcolor(FL_WHITE);
    userSettingsGroup->color(fl_rgb_color(0x96, 0x7e, 0xd7));
    userSettingsGroup->color2(fl_rgb_color(0x96, 0x7e, 0xd7));
    userSettingsGroup->labelfont(FL_COURIER_BOLD);
    userSettingsGroup->labelsize(16);
    {
        // New Username input
        settingsUsernameInput = new Fl_Input(
            350 + 20,  
            (y + 220),
            200, 30,
            "New Username:"
        );
        settingsUsernameInput->labelsize(14);

        // New Password input
        settingsPasswordInput = new Fl_Input(
            350 + 20,
            (y + 260),
            200, 30,
            "New Password:"
        );
        settingsPasswordInput->type(FL_SECRET_INPUT);
        settingsPasswordInput->labelsize(14);

        // Confirm Password input
        settingsPasswordConfirmInput = new Fl_Input(
            350 + 20,
            (y + 300),
            200, 30,
            "Confirm Password:"
        );
        settingsPasswordConfirmInput->type(FL_SECRET_INPUT);
        settingsPasswordConfirmInput->labelsize(14);

        // New Budget input
        settingsBudgetInput = new Fl_Input(
            350 + 20, 
            (y + 340),
            80, 30,
            "New Budget:"
        );
        settingsBudgetInput->labelsize(14);

        // Save button (bottom right)
        settingsSaveButton = new Fl_Button(
            165 + 470,  
            (y + 360),  
            100, 35,
            "Save"
        );
        settingsSaveButton->labelsize(14);
        settingsSaveButton->color(fl_rgb_color(0xdc, 0xb5, 0xff));
        settingsSaveButton->callback(saveSettingsCallback, this);
    }
    userSettingsGroup->end();
}
    userTabs->end();
    end(); // End of Fl_Group
}

void HomepageGroup::updateTimeCallback(void *data)
{
    HomepageGroup* hp = static_cast<HomepageGroup*>(data);
    GuiManager* gm = hp->guiManager;
    ExpenseTracker* et = gm->getExpenseTracker();
    et->updateTime(100);

    auto timeAsInt = std::chrono::system_clock::to_time_t(et->getTime());
    auto timeStruct = *std::localtime(&timeAsInt);
    if (timeStruct.tm_mday != et->getDate()->getDay()) {
        et->updateDate(et->getTime());
    }

    hp->dateBox->copy_label(et->getDate()->getDateString().c_str());
    hp->timeBox->copy_label(Date::getTimeStr(et->getTime()).c_str());
    Fl::repeat_timeout(0.001, updateTimeCallback, data);
}


void HomepageGroup::logoutCallback(Fl_Widget *widget, void *data)
{
    HomepageGroup* homepageGroup = static_cast<HomepageGroup*>(data);
    GuiManager* guiManager = homepageGroup->guiManager;
    ExpenseTracker* expenseTracker = guiManager->getExpenseTracker();

    expenseTracker->logout();
    fl_message("Logout successful! Goodbye!");
    guiManager->showStartScreen();
    guiManager->update();
}


void HomepageGroup::update()
{
    if (userInfoUsernameLabel) {
        userInfoUsernameLabel->copy_label(
            ("Username: " + guiManager->getExpenseTracker()->getCurrentUsername()).c_str()
        );
    }
    if (userInfoBudgetLabel) {
        userInfoBudgetLabel->copy_label(
            ("Budget: " + guiManager->getExpenseTracker()->getBudgetAsString()).c_str()
        );
    }
}

void HomepageGroup::saveSettingsCallback(Fl_Widget* widget, void* data)
{
    HomepageGroup* hg = static_cast<HomepageGroup*>(data);
    GuiManager* gm = hg->guiManager;
    ExpenseTracker* et = gm->getExpenseTracker();

    // Verify user is logged in
    if (!et || et->getCurrentUsername().empty()) {
        fl_alert("You must be logged in to update settings.");
        return;
    }

    std::string newUsername = hg->settingsUsernameInput->value();
    std::string newPassword = hg->settingsPasswordInput->value();
    std::string newPasswordConfirm = hg->settingsPasswordConfirmInput->value();
    std::string newBudgetStr = hg->settingsBudgetInput->value();

    // Check if no input was provided
    bool noInputProvided = (newUsername.empty() && newPassword.empty() && newBudgetStr.empty());
    if (noInputProvided) {
        fl_alert("No changes detected.");
        return;
    }

    // Validate password confirmation
    if (!newPassword.empty() && newPassword != newPasswordConfirm) {
        fl_alert("Passwords do not match. Please try again.");
        return;
    }

    // Parse the new budget or retain the old budget
    double newBudget = et->getBudgetAsString().empty() ? 0.0 : std::stod(et->getBudgetAsString().substr(et->getBudgetAsString().find('$') + 1));
    if (!newBudgetStr.empty()) {
        try {
            newBudget = std::stod(newBudgetStr);
        } catch (...) {
            fl_alert("Budget must be a numeric value.");
            return;
        }
    }

    // Retain the current username if not changed
    if (newUsername.empty()) {
        newUsername = et->getCurrentUsername();
    }

    // Retain the current password if not changed
    if (newPassword.empty()) {
        newPassword = " "; // Placeholder if password is not updated
    }

    // Attempt to update user information
    bool success = et->updateCurrentUserInfo(newUsername, newPassword, newBudget);
    if (success) {
        fl_message("User info updated successfully! Please log in again with your new credentials.");
        et->logout(); // Log out the current user
        gm->showStartScreen(); // Redirect to the login screen
        gm->update();
    } else {
        fl_alert("Update failed! Possibly username already exists or invalid input.");
    }

    // Clear input fields
    hg->settingsUsernameInput->value("");
    hg->settingsPasswordInput->value("");
    hg->settingsPasswordConfirmInput->value("");
    hg->settingsBudgetInput->value("");
}
