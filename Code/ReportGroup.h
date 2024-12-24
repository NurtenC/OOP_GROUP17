#pragma once
#include <FL/Fl_Group.H>
#include <FL/Fl_Input.H>
#include "GuiManager.h"
#include "ExpenseTable.h"

class ReportGroup : public Fl_Group{
public:
    ReportGroup(int x, int y, int w, int h, GuiManager* manager);
    void update();

private:
    GuiManager* guiManager;
    ExpenseTable* expenseTable;
};