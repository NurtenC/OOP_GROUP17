#include "IncomeTable.h"

IncomeTable::IncomeTable(int x, int y, int w, int h, std::vector<Income> *incomes) : Fl_Table_Row(x, y, w, h, "Income Table")
{
    this->incomes = incomes;
    rows(10);
    cols(3);
    col_header(1);
    col_resize(1);
    row_height_all(25);
    col_width(0, 100);
    col_width(1, 100);
    col_width(2, 250);
    end();
}

void IncomeTable::draw_cell(TableContext tableContext, int row, int col, int x, int y, int w, int h)
{
    if(incomes == nullptr){
        if(tableContext == CONTEXT_CELL){
            fl_color(FL_WHITE);
            fl_rectf(x,y,w,h);
            fl_color(FL_BLACK);
            fl_draw("No data", x+5, y, w, h, FL_ALIGN_CENTER);
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
        static const char *headers[] = {"Date", "Amount", "Description"};
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

void IncomeTable::updateTable(std::vector<Income> *incomes)
{
    this->incomes = incomes;
    int a = incomes ? incomes->size() : 0;
    rows(a);
    redraw();
}
