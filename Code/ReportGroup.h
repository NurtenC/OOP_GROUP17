/**
 * @file ReportGroup.h
 * @brief Declares the ReportGroup class for displaying and filtering expense and income reports in the GUI.
 */

#pragma once
#include <FL/Fl_Group.H>
#include <FL/Fl_Choice.H>
#include "GuiManager.h"
#include "ExpenseTable.h"
#include "IncomeTable.h"
#include <vector>

/**
 * @class ReportGroup
 * @brief Represents a GUI component for managing expense and income reports.
 *
 * The ReportGroup class handles the display, filtering, and management of 
 * expense and income data within the application's GUI.
 */
class ReportGroup : public Fl_Group {
public:
    /**
     * @brief Constructs a ReportGroup object.
     *
     * Initializes the group with tables for expenses and incomes, filtering options for category
     * and duration, and buttons for generating filtered lists. Sets up callbacks for interaction.
     *
     * @param x The x-coordinate of the group.
     * @param y The y-coordinate of the group.
     * @param w The width of the group.
     * @param h The height of the group.
     * @param manager Pointer to the GuiManager instance.
     */
    ReportGroup(int x, int y, int w, int h, GuiManager* manager);

    /**
     * @brief Updates the data displayed in the tables.
     *
     * This function refreshes the expense and income tables based on the current data in the
     * expense tracker.
     */
    void update();

    /**
     * @brief Filters expenses based on selected category and duration.
     *
     * This function applies the selected filters from the category and duration dropdowns
     * and returns a list of matching expenses.
     *
     * @return A vector of filtered Expense objects.
     */
    std::vector<Expense> filterExpenses();

    /**
     * @brief Filters incomes based on selected duration.
     *
     * This function applies the selected filter from the duration dropdown
     * and returns a list of matching incomes.
     *
     * @return A vector of filtered Income objects.
     */
    std::vector<Income> filterIncomes();

    /**
     * @brief Callback function to handle expense list generation.
     *
     * This function is triggered when the "List" button for expenses is clicked.
     * It updates the expense table with the filtered list of expenses.
     *
     * @param widget The widget triggering the callback.
     * @param data Pointer to the ReportGroup instance.
     */
    static void expenseReportListCallback(Fl_Widget* widget, void* data);

    /**
     * @brief Callback function to handle income list generation.
     *
     * This function is triggered when the "List" button for incomes is clicked.
     * It updates the income table with the filtered list of incomes.
     *
     * @param widget The widget triggering the callback.
     * @param data Pointer to the ReportGroup instance.
     */
    static void incomeReportListCallback(Fl_Widget* widget, void* data);

private:
    GuiManager* guiManager; ///< Pointer to the GuiManager instance managing the application.

    ExpenseTable* expenseTable; ///< Table widget displaying expense data.
    IncomeTable* incomeTable; ///< Table widget displaying income data.

    Fl_Choice* expenseReportCategory; ///< Dropdown for selecting expense category filter.
    Fl_Choice* expenseReportTime; ///< Dropdown for selecting expense duration filter.
    Fl_Choice* incomeReportTime; ///< Dropdown for selecting income duration filter.

    std::vector<Expense> filteredExpenses; ///< List of expenses after filtering.
    std::vector<Income> filteredIncomes; ///< List of incomes after filtering.
};
