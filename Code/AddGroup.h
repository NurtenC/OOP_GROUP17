#pragma once
#include <FL/Fl_Group.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Tabs.H>
#include "GuiManager.h"
class AddGroup : public Fl_Group{
public:
    AddGroup(int x, int y, int w, int h, GuiManager* manager);

private:
    GuiManager* guiManager;
};