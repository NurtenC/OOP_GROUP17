#pragma once
#include <FL/Fl_Group.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Tabs.H>
#include <FL/Fl_Choice.H>
#include "GuiManager.h"

class AddGroup : public Fl_Group {
public:
    AddGroup(int x, int y, int w, int h, GuiManager* manager);

private:
    GuiManager* guiManager;
    
    // Expense fields
    Fl_Choice* expenseChoice;
    Fl_Input* expenseDescription;
    Fl_Input* expenseAmount;

    // Regular Expense fields
    Fl_Input* regularExpenseAmount;
    Fl_Choice* regularExpenseChoice;
    Fl_Input* regularExpenseDescription;
    Fl_Input* regularExpenseDate;

    // Income fields
    Fl_Input* incomeDescription;
    Fl_Input* incomeAmount;

    // Regular Income fields
    Fl_Input* regularIncomeDescription;
    Fl_Input* regularIncomeAmount;
    Fl_Input* regularIncomeDate;

    // Callback functions
    static void addRegularExpenseCallBack(Fl_Widget *widget, void *data);
    static void addExpenseCallback(Fl_Widget* widget, void* data);
    static void addIncomeCallback(Fl_Widget* widget, void* data);
    static void addRegularIncomeCallBack(Fl_Widget *widget, void *data);
};
