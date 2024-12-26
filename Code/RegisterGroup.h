/**
 * @file RegisterGroup.h
 * @brief Declares the RegisterGroup class for handling user registration within the GUI.
 */

#pragma once
#include <FL/Fl_Group.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Input.H>
#include "GuiManager.h"

/**
 * @class RegisterGroup
 * @brief Manages the registration interface, including input fields and buttons for user sign-up.
 *
 * The RegisterGroup class inherits from Fl_Group and provides UI components for users to enter
 * their desired username, password, and budget. It includes buttons to submit the registration
 * information and navigate back to the start screen. The class handles user interactions related
 * to registering a new account in the Expense Tracker application.
 */
class RegisterGroup : public Fl_Group {
public:
    /**
     * @brief Constructs a RegisterGroup object.
     *
     * Initializes the registration interface with input fields for username, password, and budget,
     * a register button to submit the information, and a back button to return to the start screen.
     *
     * @param x The x-coordinate of the group.
     * @param y The y-coordinate of the group.
     * @param w The width of the group.
     * @param h The height of the group.
     * @param manager Pointer to the GuiManager instance managing the GUI.
     */
    RegisterGroup(int x, int y, int w, int h, GuiManager* manager);

private:
    GuiManager* guiManager;           ///< Pointer to the GuiManager instance.
    Fl_Input* usernameInput;           ///< Input field for the desired username.
    Fl_Input* passwordInput;           ///< Input field for the desired password.
    Fl_Input* budgetInput;             ///< Input field for the user's budget.

    /**
     * @brief Callback function for handling the registration process.
     *
     * This static function is triggered when the register button is clicked. It retrieves
     * the entered username, password, and budget, validates them, and attempts to register
     * the user using the ExpenseTracker instance. Provides feedback based on the success or failure
     * of the registration attempt.
     *
     * @param widget Pointer to the widget triggering the callback.
     * @param data Pointer to the RegisterGroup instance.
     */
    static void registerCallback(Fl_Widget* widget, void* data);
};
