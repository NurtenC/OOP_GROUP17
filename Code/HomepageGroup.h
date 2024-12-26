/**
 * @file HomepageGroup.h
 * @brief Declares the HomepageGroup class for displaying the homepage in the GUI.
 */

#pragma once
#include <FL/Fl_Group.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Tabs.H>
#include "GuiManager.h"

class HomepageGroup : public Fl_Group {
public:
    /**
     * @brief Constructs a HomepageGroup object.
     *
     * Initializes the homepage with welcome labels, date and time displays, a logout button,
     * and tabs for User Info and Settings. Sets up callbacks for updating time and handling logout.
     *
     * @param x The x-coordinate of the group.
     * @param y The y-coordinate of the group.
     * @param w The width of the group.
     * @param h The height of the group.
     * @param manager Pointer to the GuiManager instance.
     */
    HomepageGroup(int x, int y, int w, int h, GuiManager* manager);

    /**
     * @brief Updates the user information display on the homepage.
     *
     * This function updates the username and budget labels based on the current user's information.
     */
    void update();

private:
    GuiManager* guiManager; ///< Pointer to the GuiManager instance.

    Fl_Box* welcomeLabel;  ///< Label for the welcome message.

    Fl_Box* dateBox; ///< Box displaying the current date.
    Fl_Box* timeBox; ///< Box displaying the current time.

    Fl_Tabs* userTabs; ///< Tabs for User Info and Settings.

    Fl_Group* userInfoGroup; ///< Group for displaying user information.
    Fl_Box* userInfoUsernameLabel; ///< Label displaying the username.
    Fl_Box* userInfoBudgetLabel; ///< Label displaying the budget.

    Fl_Group* userSettingsGroup; ///< Group for user settings.
    Fl_Input* settingsUsernameInput; ///< Input field for new username.
    Fl_Input* settingsPasswordInput; ///< Input field for new password.
    Fl_Input* settingsBudgetInput; ///< Input field for new budget.
    Fl_Button* settingsSaveButton; ///< Button to save settings.
    Fl_Input* settingsPasswordConfirmInput; ///< Input field to confirm new password.

    /**
     * @brief Callback function to update the time display.
     *
     * This function is called periodically to update the date and time displayed on the homepage.
     * It updates the ExpenseTracker's time, refreshes the date and time boxes, and reschedules itself.
     *
     * @param data Pointer to the HomepageGroup instance.
     */
    static void updateTimeCallback(void *data);

    /**
     * @brief Callback function to handle user logout.
     *
     * This function is triggered when the user clicks the "Log Out" button.
     * It logs out the current user, displays a confirmation message, and navigates back to the start screen.
     *
     * @param widget The widget triggering the callback.
     * @param data Pointer to the HomepageGroup instance.
     */
    static void logoutCallback(Fl_Widget* widget, void* data);

    /**
     * @brief Callback function to save user settings.
     *
     * This function is triggered when the user clicks the "Save" button in the Settings tab.
     * It validates the input fields, updates the user's information in the ExpenseTracker,
     * and provides feedback to the user.
     *
     * @param widget The widget triggering the callback.
     * @param data Pointer to the HomepageGroup instance.
     */
    static void saveSettingsCallback(Fl_Widget* widget, void* data);
};
