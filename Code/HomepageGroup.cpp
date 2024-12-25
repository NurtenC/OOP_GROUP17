#include "HomepageGroup.h"
#include "Date.h"
#include <fl/fl_ask.H>

HomepageGroup::HomepageGroup(int x, int y, int w, int h, GuiManager* manager)
    : Fl_Group(x, y, w, h), guiManager(manager) {

    userNameLabel = new Fl_Box((x + w / 3) + 30, (y + h / 5) + 20, 300, 50);
    userNameLabel->copy_label("");
    userNameLabel->labelcolor(fl_rgb_color(0x77,0x52,0x9e)); // #77529e
    userNameLabel->labelsize(50);
    userNameLabel->labelfont(FL_COURIER_BOLD);
    userNameLabel->align(FL_ALIGN_CENTER | FL_ALIGN_INSIDE);

    budgetLabel = new Fl_Box((x + (w / 20) * 7) + 20,((y + h / 20) * 6) + 60, 300, 50);
    budgetLabel->copy_label("");
    budgetLabel->labelcolor(fl_rgb_color(0x77,0x52,0x9e)); // #77529e
    budgetLabel->labelsize(30);
    budgetLabel->labelfont(FL_COURIER_BOLD);
    budgetLabel->align(FL_ALIGN_CENTER | FL_ALIGN_INSIDE);
    

    Fl_Button* logoutButton = new Fl_Button(x + (w / 20) * 9, y + ((h / 20) * 17) + 30, 230, 35, "Log Out");
    logoutButton->labelsize(16);
    logoutButton->color(fl_rgb_color(0xdc,0xb5,0xff));//#dcb5ff
    logoutButton->color2(fl_rgb_color(0xff,0xd3,0xb6));
    logoutButton->callback(logoutCallback, this);

    dateBox = new Fl_Box(500,10,150,60);
    dateBox->box(FL_FLAT_BOX);
    dateBox->color(fl_rgb_color(0xa5,0xbd,0xfd));
    dateBox->labelsize(24);
    dateBox->labelfont(FL_HELVETICA);
    dateBox->labelcolor(fl_rgb_color(0x27, 0x29, 0x6d));

    timeBox = new Fl_Box(650,10,150,60);
    timeBox->box(FL_FLAT_BOX);
    timeBox->color(fl_rgb_color(0xa5,0xbd,0xfd));
    timeBox->labelsize(24);
    timeBox->labelfont(FL_HELVETICA);
    timeBox->labelcolor(fl_rgb_color(0x27, 0x29, 0x6d));

    dateBox->copy_label(guiManager->getExpenseTracker()->getDate()->getDateString().c_str());
    timeBox->copy_label(Date::getTimeStr(guiManager->getExpenseTracker()->getTime()).c_str());

    //callback method that calls itself per second 
    Fl::add_timeout(0.001, updateTimeCallback, this);

    end();
}

void HomepageGroup::updateTimeCallback(void *data){

    HomepageGroup* hp = static_cast<HomepageGroup*>(data);
    GuiManager* gm = hp->guiManager;
    ExpenseTracker* et = gm->getExpenseTracker();
    et->updateTime(100);

    auto timeAsInt = std::chrono::system_clock::to_time_t(et->getTime());
    auto timeStruct = *std::localtime(&timeAsInt); 
    
    if(timeStruct.tm_mday != et->getDate()->getDay()){
        et->updateDate(et->getTime());
    }

    hp->dateBox->copy_label(gm->getExpenseTracker()->getDate()->getDateString().c_str());
    hp->timeBox->copy_label(Date::getTimeStr(gm->getExpenseTracker()->getTime()).c_str());


    Fl::repeat_timeout(0.001, updateTimeCallback, data);
}

void HomepageGroup::logoutCallback(Fl_Widget *widget, void *data)
{
    HomepageGroup* homepageGroup = static_cast<HomepageGroup*>(data);
    GuiManager* guiManager = homepageGroup->guiManager;
    ExpenseTracker* expenseTracker = guiManager->getExpenseTracker();

    expenseTracker->logout();
    fl_message("Logout successful! Goodbye!");
    guiManager->showStartScreen();
    guiManager->update();
}

void HomepageGroup::update()
{
    if (userNameLabel != nullptr)
    {
        userNameLabel->copy_label(guiManager->getExpenseTracker()->getCurrentUsername().c_str());
    }
    if (budgetLabel != nullptr)
    {
        budgetLabel->copy_label(guiManager->getExpenseTracker()->getBudgetAsString().c_str());
    }
}