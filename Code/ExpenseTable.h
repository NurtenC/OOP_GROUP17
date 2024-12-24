#pragma once
#include <Fl/Fl.H>
#include <fl/fl_draw.H>
#include <Fl/Fl_Table_Row.H>
#include <vector>
#include "Expense.h"


class ExpenseTable : public Fl_Table_Row{

private: 
    std::vector<Expense>* expenses;

public:
    ExpenseTable(int x, int y, int w, int h,std::vector<Expense>* expenses );

    void draw_cell(TableContext tableContext, int row, int col, int x, int y, int w, int h)override;
    void updateTable(std::vector<Expense>* expenses);

    
    
};