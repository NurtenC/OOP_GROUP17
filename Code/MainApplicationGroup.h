#pragma once
#include <FL/Fl_Group.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Multiline_Output.H>
#include <Fl/Fl_Hold_Browser.H>
#include "GuiManager.h"
#include "AddGroup.h"

class MainApplicationGroup : public Fl_Group {
public:
    MainApplicationGroup(int x, int y, int w, int h, GuiManager* manager);
    
private:
    GuiManager* guiManager;
    Fl_Hold_Browser *bro = 0;
    Fl_Group *grp[3] = { 0,0,0 };
    Fl_Input* descInput;
    Fl_Input* amountInput;
    Fl_Button* addExpenseButton;
    Fl_Button* logoutButton;

    static void SelectGroup_CB(Fl_Widget*, void*);
};
