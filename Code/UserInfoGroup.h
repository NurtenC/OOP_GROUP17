#pragma once
#include <FL/Fl_Group.H>
#include <FL/Fl_Input.H>
#include "GuiManager.h"

class UserInfoGroup : public Fl_Group{
public:
    UserInfoGroup(int x, int y, int w, int h, GuiManager* manager);

private:
    GuiManager* guiManager;
};