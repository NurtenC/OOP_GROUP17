#include "HomepageGroup.h"
#include "Date.h"

HomepageGroup::HomepageGroup(int x, int y, int w, int h, GuiManager* manager)
    : Fl_Group(x, y, w, h), guiManager(manager) {


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
