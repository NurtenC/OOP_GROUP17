#pragma once
#include <FL/Fl_Group.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Tabs.H>
#include <FL/Fl_Choice.H>
#include "GuiManager.h"
class AddGroup : public Fl_Group{
public:
    AddGroup(int x, int y, int w, int h, GuiManager* manager);
    

private:
    GuiManager* guiManager;
    Fl_Choice* choice;
    Fl_Input* description;
    Fl_Input* amount;

    static void addExpenseCallback(Fl_Widget* widget, void* data);
};