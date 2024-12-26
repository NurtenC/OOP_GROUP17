/**
 * @file ReportGroup.h
 * @brief Declares the ReportGroup class for generating and displaying reports within the GUI.
 */

#pragma once
#include <FL/Fl_Group.H>
#include <FL/Fl_Input.H>
#include "GuiManager.h"
#include "ExpenseTable.h"
#include "IncomeTable.h"
#include <FL/Fl_Choice.H>

/**
 * @class ReportGroup
 * @brief Manages the reporting interface, including tables and filters for expenses and incomes.
 *
 * The ReportGroup class inherits from Fl_Group and provides UI components for displaying
 * expense and income tables. It includes choice widgets for filtering reports based on
 * categories and durations. The class handles updating the tables based on user-selected filters.
 */
class ReportGroup : public Fl_Group {
public:
    /**
     * @brief Constructs a ReportGroup object.
     *
     * Initializes the reporting interface with tables for expenses and incomes, along with
     * choice widgets for filtering reports by category and duration. Sets up buttons for
     * listing the reports and handles callbacks for user interactions.
     *
     * @param x The x-coordinate of the group.
     * @param y The y-coordinate of the group.
     * @param w The width of the group.
     * @param h The height of the group.
     * @param manager Pointer to the GuiManager instance managing the GUI.
     */
    ReportGroup(int x, int y, int w, int h, GuiManager* manager);

    /**
     * @brief Updates the expense and income tables with the latest data.
     *
     * Retrieves the latest expenses and incomes from the ExpenseTracker instance and updates
     * the corresponding tables to reflect any changes.
     */
    void update();

private:
    GuiManager* guiManager;                   ///< Pointer to the GuiManager instance.
    ExpenseTable* expenseTable;               ///< Table displaying expenses.
    IncomeTable* incomeTable;                 ///< Table displaying incomes.
    Fl_Choice* expenseReportCategory;         ///< Dropdown for selecting expense categories.
    Fl_Choice* expenseReportTime;             ///< Dropdown for selecting expense report duration.
    Fl_Choice* incomeReportTime;              ///< Dropdown for selecting income report duration.

    // Callback functions can be added here for handling button clicks and other interactions.
};
