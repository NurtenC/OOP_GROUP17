/**
 * @file AddGroup.h
 * @brief Defines the AddGroup class for managing expense and income entries in the GUI.
 */

#pragma once
#include <FL/Fl_Group.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Tabs.H>
#include <FL/Fl_Choice.H>
#include "GuiManager.h"

/**
 * @class AddGroup
 * @brief Handles user input for adding expenses, incomes, and their regular counterparts in the GUI.
 *
 * The AddGroup class provides input fields and buttons for users to add both one-time and regular
 * expenses and incomes. It interacts with the GuiManager to process and store the user inputs.
 */
class AddGroup : public Fl_Group {
public:
    /**
     * @brief Constructs the AddGroup.
     * @param x X-coordinate of the group.
     * @param y Y-coordinate of the group.
     * @param w Width of the group.
     * @param h Height of the group.
     * @param manager Pointer to the GuiManager instance.
     */
    AddGroup(int x, int y, int w, int h, GuiManager* manager);

private:
    GuiManager* guiManager; ///< Pointer to the GUI manager for interaction.

    // Expense fields
    Fl_Choice* expenseChoice; ///< Dropdown to select expense category.
    Fl_Input* expenseDescription; ///< Input field for expense description.
    Fl_Input* expenseAmount; ///< Input field for expense amount.

    // Regular Expense fields
    Fl_Input* regularExpenseAmount; ///< Input field for regular expense amount.
    Fl_Choice* regularExpenseChoice; ///< Dropdown for regular expense category.
    Fl_Input* regularExpenseDescription; ///< Input field for regular expense description.
    Fl_Input* regularExpenseDate; ///< Input field for regular expense date.

    // Income fields
    Fl_Input* incomeDescription; ///< Input field for income description.
    Fl_Input* incomeAmount; ///< Input field for income amount.

    // Regular Income fields
    Fl_Input* regularIncomeDescription; ///< Input field for regular income description.
    Fl_Input* regularIncomeAmount; ///< Input field for regular income amount.
    Fl_Input* regularIncomeDate; ///< Input field for regular income date.

    // Callback functions
    /**
     * @brief Callback for adding a regular expense.
     * @param widget The widget triggering the callback.
     * @param data Additional data passed to the callback.
     */
    static void addRegularExpenseCallback(Fl_Widget *widget, void *data);

    /**
     * @brief Callback for adding a one-time expense.
     * @param widget The widget triggering the callback.
     * @param data Additional data passed to the callback.
     */
    static void addExpenseCallback(Fl_Widget* widget, void* data);

    /**
     * @brief Callback for adding a one-time income.
     * @param widget The widget triggering the callback.
     * @param data Additional data passed to the callback.
     */
    static void addIncomeCallback(Fl_Widget* widget, void* data);

    /**
     * @brief Callback for adding a regular income.
     * @param widget The widget triggering the callback.
     * @param data Additional data passed to the callback.
     */
    static void addRegularIncomeCallback(Fl_Widget *widget, void *data);
};
