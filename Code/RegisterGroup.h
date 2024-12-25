#pragma once
#include <FL/Fl_Group.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Input.H>

class GuiManager;

class RegisterGroup : public Fl_Group {
public:
    RegisterGroup(int x, int y, int w, int h, GuiManager* manager);
private:
    GuiManager* guiManager;
    Fl_Input* usernameInput;
    Fl_Input* passwordInput;
    Fl_Input* budgetInput;

    static void registerCallback(Fl_Widget* widget, void* data);
};
