#pragma once
#include <FL/Fl_Group.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Multiline_Output.H>
#include <Fl/Fl_Hold_Browser.H>
#include "GuiManager.h"

class MainApplicationGroup : public Fl_Group {
public:
    MainApplicationGroup(int x, int y, int w, int h, GuiManager* manager);
    
    void update();

private:
    GuiManager* guiManager;
    Fl_Hold_Browser *browser;
    Fl_Group *grp[3];
    Fl_Button* logoutButton;

    static void SelectGroup_CB(Fl_Widget*, void*);
};
