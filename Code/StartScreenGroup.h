#pragma once
#include <FL/Fl_Group.H>
class GuiManager;

class StartScreenGroup : public Fl_Group {
public:
    StartScreenGroup(int x, int y, int w, int h, GuiManager* manager);
};