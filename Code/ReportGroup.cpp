#include "ReportGroup.h"
ReportGroup::ReportGroup(int x, int y, int w, int h, GuiManager* manager)
    : Fl_Group(x, y, w, h), guiManager(manager) {
        new Fl_Input(170+140,160+00,200,20,"ReportInfo:");
    }