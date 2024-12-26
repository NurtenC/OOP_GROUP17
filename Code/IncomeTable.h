/**
 * @file IncomeTable.h
 * @brief Declares the IncomeTable class for displaying incomes in a table format.
 */

#pragma once
#include <Fl/Fl.H>
#include <Fl/fl_draw.H>
#include <Fl/Fl_Table_Row.H>
#include <vector>
#include "Income.h"

/**
 * @class IncomeTable
 * @brief Displays incomes in a table format using FLTK.
 *
 * The IncomeTable class inherits from Fl_Table_Row and is used to display a list of incomes
 * in a tabular form with columns for Date, Amount, and Description.
 */
class IncomeTable : public Fl_Table_Row {
public:
    /**
     * @brief Constructs an IncomeTable with the specified position, size, and incomes.
     *
     * Initializes the table with default settings such as number of rows, columns, headers, and column widths.
     *
     * @param x The x-coordinate of the table.
     * @param y The y-coordinate of the table.
     * @param w The width of the table.
     * @param h The height of the table.
     * @param incomes Pointer to a vector of Income objects to be displayed in the table.
     */
    IncomeTable(int x, int y, int w, int h, std::vector<Income>* incomes);

    /**
     * @brief Draws a cell in the IncomeTable based on the table context, row, and column.
     *
     * Handles the rendering of different parts of the table, including headers and data cells.
     * Displays "No data" if the incomes pointer is null.
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
     * @brief Updates the IncomeTable with a new set of incomes.
     *
     * Sets the incomes pointer to the new vector of Income objects, updates the number of rows,
     * and redraws the table to reflect the changes.
     *
     * @param incomes Pointer to a new vector of Income objects to be displayed in the table.
     */
    void updateTable(std::vector<Income>* incomes);

private:
    std::vector<Income>* incomes; ///< Pointer to a vector of Income objects to display.
};
