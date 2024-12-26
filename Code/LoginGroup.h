/**
 * @file LoginGroup.h
 * @brief Declares the LoginGroup class for handling user login within the GUI.
 */

#pragma once
#include <FL/Fl_Group.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Input.H>
#include "GuiManager.h"

/**
 * @class LoginGroup
 * @brief Manages the login interface, including input fields and buttons for user authentication.
 *
 * The LoginGroup class inherits from Fl_Group and provides UI components for users to enter
 * their username and password, submit their credentials, and navigate back to the start screen.
 * It handles user interactions related to logging into the Expense Tracker application.
 */
class LoginGroup : public Fl_Group {
public:
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
    LoginGroup(int x, int y, int w, int h, GuiManager* manager);

private:
    GuiManager* guiManager;           ///< Pointer to the GuiManager instance.
    Fl_Input* usernameInput;           ///< Input field for the username.
    Fl_Input* passwordInput;           ///< Input field for the password.

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
    static void loginCallback(Fl_Widget* widget, void* data);
};
