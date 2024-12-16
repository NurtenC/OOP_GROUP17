#include "MainApplicationGroup.h"
#include <FL/fl_ask.H>
#include <sstream>
#include <iomanip>
#include "UserInfoGroup.h"
#include "AddGroup.h"
#include "ReportGroup.h"


MainApplicationGroup::MainApplicationGroup(int x, int y, int w, int h, GuiManager* manager)
    : Fl_Group(x, y, w, h), guiManager(manager) {


    bro = new Fl_Hold_Browser(10,10,150,580);
    bro->add("User Info");
    bro->add("Add");
    bro->add("Generate Report");

    grp[0] = new UserInfoGroup(170,10,450,400, manager);
    grp[0]->end();
    grp[1] = new AddGroup(0,0,800,600, manager);
    grp[1]->end();
    grp[2] = new ReportGroup(170,10,450,400,manager);
    grp[2]->end();

/*
    Fl_Box* mainAppLabel = new Fl_Box(x + 50, y + 20, 300, 30, "Expense");
    mainAppLabel->labelsize(16);
    mainAppLabel->align(FL_ALIGN_CENTER | FL_ALIGN_INSIDE);

    descInput = new Fl_Input(x + 100, y + 60, 200, 30, "Description:");
    descInput->labelsize(14);

    amountInput = new Fl_Input(x + 100, y + 100, 200, 30, "Amount:");
    amountInput->labelsize(14);

    addExpenseButton = new Fl_Button(x + 150, y + 180, 100, 30, "Add Expense");

    logoutButton = new Fl_Button(x + 10, y + 10, 60, 30, "Logout");
    logoutButton->callback(GuiManager::showStartScreenCallback, guiManager);
*/
    bro->callback(SelectGroup_CB, this);
    bro->select(1);
    SelectGroup_CB(0,this);
    end();
}

void MainApplicationGroup::SelectGroup_CB(Fl_Widget*, void* data) {
    MainApplicationGroup* self = static_cast<MainApplicationGroup*>(data);
    int selected = self->bro->value();

    if (selected == 0) return;

    for (int t = 0; t < 3; t++) {
        if (t == (selected - 1)) {
            self->grp[t]->show();
        } else {
            self->grp[t]->hide();
        }
    }
}

