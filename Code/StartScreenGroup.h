/**
 * @file StartScreenGroup.h
 * @brief Declares the StartScreenGroup class for displaying the start screen within the GUI.
 */

#pragma once
#include <FL/Fl_Group.H>
#include <FL/Fl_Input.H>  // Added to recognize Fl_Input
#include "GuiManager.h"

/**
 * @class StartScreenGroup
 * @brief Manages the start screen interface, including welcome messages and navigation buttons.
 *
 * The StartScreenGroup class inherits from Fl_Group and provides UI components for users to navigate
 * to the Login or Register screens. It includes a welcome label and buttons for initiating login
 * or registration processes within the Expense Tracker application.
 */
class StartScreenGroup : public Fl_Group {
public:
    /**
     * @brief Constructs a StartScreenGroup object.
     *
     * Initializes the start screen with a welcome label and buttons for Login and Register.
     *
     * @param x The x-coordinate of the group.
     * @param y The y-coordinate of the group.
     * @param w The width of the group.
     * @param h The height of the group.
     * @param manager Pointer to the GuiManager instance managing the GUI.
     */
    StartScreenGroup(int x, int y, int w, int h, GuiManager* manager);

private:
    GuiManager* guiManager;           ///< Pointer to the GuiManager instance.
    Fl_Input* usernameInput;          ///< Input field for the username (if needed in future extensions).
    Fl_Input* passwordInput;          ///< Input field for the password (if needed in future extensions).
    Fl_Input* budgetInput;            ///< Input field for the budget (if needed in future extensions).

    // Additional UI components can be declared here if necessary.
};
