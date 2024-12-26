/**
 * @file ExpenseTable.cpp
 * @brief Implements the ExpenseTable class for displaying expenses in a table format.
 */

#include "ExpenseTable.h"
#include <FL/fl_draw.H>

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
ExpenseTable::ExpenseTable(int x, int y, int w, int h, std::vector<Expense> *expenses) 
    : Fl_Table_Row(x, y, w, h, "Expense Table")
{
    this->expenses = expenses;
    rows(10);
    cols(4);
    col_header(1);
    col_resize(1);
    row_height_all(25);
    col_width(0, 100);
    col_width(1, 100);
    col_width(2, 100);
    col_width(3, 250);
    end();
}

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
void ExpenseTable::draw_cell(TableContext tableContext, int row, int col, int x, int y, int w, int h)
{
    if (expenses == nullptr)
    {
        if (tableContext == CONTEXT_CELL)
        {
            fl_color(FL_WHITE);
            fl_rectf(x, y, w, h);
            fl_color(FL_BLACK);
            fl_draw("No data", x + 5, y, w, h, FL_ALIGN_CENTER);
        }
        return;
    }

    std::string text;

    switch (tableContext)
    {
    case CONTEXT_STARTPAGE:
        fl_font(FL_HELVETICA, 14);
        break;
    case CONTEXT_COL_HEADER:
        static const char *headers[] = {"Date", "Category", "Amount", "Description"};
        fl_draw_box(FL_THIN_UP_BOX, x, y, w, h, FL_WHITE);
        fl_color(FL_BLACK);
        fl_draw(headers[col], x + 5, y, w, h, FL_ALIGN_LEFT);
        break;
    case CONTEXT_CELL:
        fl_color(row_selected(row) ? FL_YELLOW : FL_WHITE);
        fl_rectf(x, y, w, h);

        fl_color(FL_BLACK);
        switch (col)
        {
        case 0:
            text = (*expenses)[row].getDate().getDateString();
            break;
        case 1:
            text = (*expenses)[row].getCategoryAsString();
            break;
        case 2:
            text = (*expenses)[row].getAmountAsString();
            break;
        case 3:
            text = (*expenses)[row].getDescription();
            break;
        }
        fl_draw(text.c_str(), x + 5, y, w, h, FL_ALIGN_LEFT);
        break;
    default:
        break;
    }
}

/**
 * @brief Updates the ExpenseTable with a new set of expenses.
 *
 * Sets the expenses pointer to the new vector of Expense objects, updates the number of rows,
 * and redraws the table to reflect the changes.
 *
 * @param expenses A pointer to a new vector of Expense objects to be displayed in the table.
 */
void ExpenseTable::updateTable(std::vector<Expense> *expenses)
{
    this->expenses = expenses;
    int a = expenses ? expenses->size() : 0;
    rows(a);
    redraw();
}
