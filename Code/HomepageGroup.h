#pragma once
#include <FL/Fl_Group.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Box.H>
#include "GuiManager.h"
#include <FL/Fl_Button.H>

class HomepageGroup : public Fl_Group{
public:
    HomepageGroup(int x, int y, int w, int h, GuiManager* manager);

    void update();
private:
    GuiManager* guiManager;
    Fl_Box* dateBox;
    Fl_Box* timeBox;
    Fl_Box *userNameLabel;
    Fl_Box *budgetLabel;
    

private:
    static void updateTimeCallback(void *data);
    static void logoutCallback(Fl_Widget* widget, void* data);
};