
#include "ExpenseTable.h"
#include <FL/fl_draw.H>


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

void ExpenseTable::updateTable(std::vector<Expense> *expenses)
{
    this->expenses = expenses;
    int a = expenses ? expenses->size() : 0;
    rows(a);
    redraw();
}
