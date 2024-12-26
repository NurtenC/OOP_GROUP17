/**
 * @file IncomeTable.cpp
 * @brief Implements the IncomeTable class for displaying incomes in a table format.
 */

#include "IncomeTable.h"
#include <FL/fl_draw.H>

/**
 * @brief Constructs an IncomeTable object.
 *
 * Initializes the income table with specified position, size, and a pointer to the incomes vector.
 * Sets up default table properties such as number of rows, columns, headers, and column widths.
 *
 * @param x The x-coordinate of the table.
 * @param y The y-coordinate of the table.
 * @param w The width of the table.
 * @param h The height of the table.
 * @param incomes Pointer to a vector of Income objects to be displayed in the table.
 */
IncomeTable::IncomeTable(int x, int y, int w, int h, std::vector<Income>* incomes)
    : Fl_Table_Row(x, y, w, h, "Income Table"), incomes(incomes)
{
    rows(10);               // Initial number of rows
    cols(3);                // Number of columns: Date, Amount, Description
    col_header(1);          // Enable column headers
    col_resize(1);          // Allow column resizing
    row_height_all(25);     // Set uniform row height
    col_width(0, 100);      // Date column width
    col_width(1, 100);      // Amount column width
    col_width(2, 250);      // Description column width
    end();
}

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
void IncomeTable::draw_cell(TableContext tableContext, int row, int col, int x, int y, int w, int h)
{
    if (incomes == nullptr)
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
    {
        static const char* headers[] = { "Date", "Amount", "Description" };
        fl_draw_box(FL_THIN_UP_BOX, x, y, w, h, FL_WHITE);
        fl_color(FL_BLACK);
        fl_draw(headers[col], x + 5, y, w, h, FL_ALIGN_LEFT);
        break;
    }
    case CONTEXT_CELL:
        fl_color(row_selected(row) ? FL_YELLOW : FL_WHITE);
        fl_rectf(x, y, w, h);

        fl_color(FL_BLACK);
        switch (col)
        {
        case 0:
            text = (*incomes)[row].getDate().getDateString();
            break;
        case 1:
            text = (*incomes)[row].getAmountAsString();
            break;
        case 2:
            text = (*incomes)[row].getDescription();
            break;
        }
        fl_draw(text.c_str(), x + 5, y, w, h, FL_ALIGN_LEFT);
        break;
    default:
        break;
    }
}

/**
 * @brief Updates the IncomeTable with a new set of incomes.
 *
 * Sets the incomes pointer to the new vector of Income objects, updates the number of rows,
 * and redraws the table to reflect the changes.
 *
 * @param incomes Pointer to a new vector of Income objects to be displayed in the table.
 */
void IncomeTable::updateTable(std::vector<Income>* incomes)
{
    this->incomes = incomes;
    int a = incomes ? static_cast<int>(incomes->size()) : 0;
    rows(a);
    redraw();
}
