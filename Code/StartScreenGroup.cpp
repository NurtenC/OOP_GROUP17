#include "StartScreenGroup.h"
#include "GuiManager.h"
#include <FL/Fl_Box.H>
#include <FL/Fl_Button.H>

StartScreenGroup::StartScreenGroup(int x, int y, int w, int h, GuiManager* manager)
    : Fl_Group(x, y, w, h) {
        
    Fl_Box *startScreenLabel = new Fl_Box(x + w / 3, y + h / 5, 300, 50, "Welcome to Expense Tracker");
    startScreenLabel->labelsize(30);
    startScreenLabel->labelfont(FL_COURIER_BOLD);
    startScreenLabel->align(FL_ALIGN_CENTER | FL_ALIGN_INSIDE);

    Fl_Button* loginButton = new Fl_Button(x + (w / 5) * 2, y + (h / 7) * 3, 150, 50, "Login");
    loginButton->labelfont(FL_COURIER_BOLD);
    loginButton->align(FL_ALIGN_CENTER | FL_ALIGN_INSIDE);
    loginButton->labelsize(15);
    loginButton->callback(GuiManager::showLoginCallback, manager);

    Fl_Button* registerButton = new Fl_Button(x + (w / 5) * 2, y + (h / 7) * 4, 150, 50, "Register");
    registerButton->labelfont(FL_COURIER_BOLD);
    registerButton->align(FL_ALIGN_CENTER | FL_ALIGN_INSIDE);
    registerButton->labelsize(15);
    registerButton->callback(GuiManager::showRegisterCallback, manager);

    end();
}   
