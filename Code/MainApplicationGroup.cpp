
#include "MainApplicationGroup.h"
#include <FL/fl_ask.H>
#include <sstream>
#include <iomanip>

MainApplicationGroup::MainApplicationGroup(int x, int y, int w, int h, GuiManager* manager)
    : Fl_Group(x, y, w, h), guiManager(manager) {

    // Initialize the navigation browser
    browser = new Fl_Hold_Browser(10, 10, 150, 580);
    browser->textsize(23);
    browser->add("Homepage");
    browser->add("Add");
    browser->add("Report");

    // Initialize the different application sections
    grp[0] = new HomepageGroup(0, 0, 800, 600, manager);
    grp[1] = new AddGroup(0, 0, 800, 600, manager);
    grp[2] = new ReportGroup(0, 0, 800, 600, manager);

    // Set up the callback for browser selection
    browser->callback(SelectGroup_CB, this);
    browser->select(1); // Select the first item by default
    SelectGroup_CB(0, this); // Display the first group initially

    end(); // End of Fl_Group
}


void MainApplicationGroup::update()
{
    if(grp[2] != nullptr){
        static_cast<ReportGroup*>(grp[2])->update();
    }
    
    if(grp[0] != nullptr){
        static_cast<HomepageGroup*>(grp[0])->update();
    }
}


void MainApplicationGroup::SelectGroup_CB(Fl_Widget*, void* data)
{
    MainApplicationGroup* mainGroup = static_cast<MainApplicationGroup*>(data);
    int selected = mainGroup->browser->value();

    if (selected == 0) return;

    for (int t = 0; t < 3; t++) {
        if (t == (selected - 1)) {
            mainGroup->grp[t]->show();
        } else {
            mainGroup->grp[t]->hide();
        }
    }
}
