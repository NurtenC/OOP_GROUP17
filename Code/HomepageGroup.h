#pragma once
#include <FL/Fl_Group.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Box.H>
#include "GuiManager.h"

class HomepageGroup : public Fl_Group{
public:
    HomepageGroup(int x, int y, int w, int h, GuiManager* manager);

private:
    GuiManager* guiManager;
    Fl_Box* dateBox;
    Fl_Box* timeBox;

private:
    static void updateTimeCallback(void *data);
};