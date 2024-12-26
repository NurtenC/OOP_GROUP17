/**
 * @file ExpenseTable.h
 * @brief Declares the ExpenseTable class for displaying expenses in a table format.
 */

#pragma once
#include <Fl/Fl.H>
#include <Fl/fl_draw.H>
#include <Fl/Fl_Table_Row.H>
#include <vector>
#include "Expense.h"

/**
 * @class ExpenseTable
 * @brief Displays expenses in a table format using FLTK.
 *
 * The ExpenseTable class inherits from Fl_Table_Row and is used to display a list of expenses
 * in a tabular form with columns for Date, Category, Amount, and Description.
 */
class ExpenseTable : public Fl_Table_Row{

private: 
    std::vector<Expense>* expenses; ///< Pointer to a vector of Expense objects to display.

public:
    /**
     * @brief Constructs an ExpenseTable with the specified position, size, and expenses.
     *
     * Initializes the table with default settings such as number of rows, columns, headers, and column widths.
     *
     * @param x The x-coordinate of the table.
     * @param y The y-coordinate of the table.
     * @param w The width of the table.
     * @param h The height of the table.
     * @param expenses A pointer to a vector of Expense objects to be displayed in the table.
     */
    ExpenseTable(int x, int y, int w, int h, std::vector<Expense>* expenses );

    /**
     * @brief Draws a cell in the ExpenseTable based on the table context, row, and column.
     *
     * Handles the rendering of different parts of the table, including headers and data cells.
     * Displays "No data" if the expenses pointer is null.
     *
     * @param tableContext The context in which the cell is being drawn (e.g., header, cell).
     * @param row The row index of the cell.
     * @param col The column index of the cell.
     * @param x The x-coordinate of the cell.
     * @param y The y-coordinate of the cell.
     * @param w The width of the cell.
     * @param h The height of the cell.
     */
    void draw_cell(TableContext tableContext, int row, int col, int x, int y, int w, int h) override;

    /**
     * @brief Updates the ExpenseTable with a new set of expenses.
     *
     * Sets the expenses pointer to the new vector of Expense objects, updates the number of rows,
     * and redraws the table to reflect the changes.
     *
     * @param expenses A pointer to a new vector of Expense objects to be displayed in the table.
     */
    void updateTable(std::vector<Expense>* expenses);
    
};
