#include "StartScreenGroup.h"
#include "GuiManager.h"
#include <FL/Fl_Box.H>
#include <FL/Fl_Button.H>

StartScreenGroup::StartScreenGroup(int x, int y, int w, int h, GuiManager* manager)
    : Fl_Group(x, y, w, h) {
       // #4c9173 #698474
    Fl_Box *startScreenLabel = new Fl_Box(x + w / 3, y + h / 5, 300, 50, "Welcome to Expense Tracker");
    startScreenLabel->labelcolor(fl_rgb_color(0x77,0x52,0x9e)); // #77529e
    startScreenLabel->labelsize(30);
    startScreenLabel->labelfont(FL_COURIER_BOLD);
    startScreenLabel->align(FL_ALIGN_CENTER | FL_ALIGN_INSIDE);
    // #b6cdbd #ffd3b6 #fcf8f3
    Fl_Button* loginButton = new Fl_Button(x + (w / 5) * 2, y + (h / 7) * 3, 150, 50, "Login");
    loginButton->labelfont(FL_COURIER_BOLD);
    loginButton->labelcolor(fl_rgb_color(0xd9,0xf2,0xff));// #d9f2ff
    loginButton->color(fl_rgb_color(0xdc,0xb5,0xff));//#dcb5ff
    loginButton->color2(fl_rgb_color(0xff,0xd3,0xb6));
    loginButton->align(FL_ALIGN_CENTER | FL_ALIGN_INSIDE);
    loginButton->labelsize(15);
    loginButton->callback(GuiManager::showLoginCallback, manager);

    Fl_Button* registerButton = new Fl_Button(x + (w / 5) * 2, y + (h / 7) * 4, 150, 50, "Register");
    registerButton->labelfont(FL_COURIER_BOLD);
    registerButton->labelcolor(fl_rgb_color(0xfc,0xf8,0xf3));
    registerButton->color(fl_rgb_color(0xff,0xd3,0xb6));
    registerButton->color2(fl_rgb_color(0xdc,0xb5,0xff));//#dcb5ff
    registerButton->align(FL_ALIGN_CENTER | FL_ALIGN_INSIDE);
    registerButton->labelsize(15);
    registerButton->callback(GuiManager::showRegisterCallback, manager);

    end();
}   
