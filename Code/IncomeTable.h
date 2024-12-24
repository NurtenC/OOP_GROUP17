#pragma once
#include <Fl/Fl.H>
#include <fl/fl_draw.H>
#include <Fl/Fl_Table_Row.H>
#include <vector>
#include "Income.h"


class IncomeTable : public Fl_Table_Row{

private: 
    std::vector<Income>* incomes;

public:
    IncomeTable(int x, int y, int w, int h,std::vector<Income>* incomes );

    void draw_cell(TableContext tableContext, int row, int col, int x, int y, int w, int h)override;
    void updateTable(std::vector<Income>* incomes);

    
    
};