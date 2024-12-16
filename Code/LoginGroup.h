#pragma once
#include <FL/Fl_Group.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Input.H>
#include "GuiManager.h"

class LoginGroup : public Fl_Group {
public:
    LoginGroup(int x, int y, int w, int h, GuiManager* manager);
private:
    GuiManager* guiManager;
    Fl_Input* usernameInput;
    Fl_Input* passwordInput;

    static void loginCallback(Fl_Widget* widget, void* data);
};
