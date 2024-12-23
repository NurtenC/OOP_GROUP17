#include "AddGroup.h"
AddGroup::AddGroup(int x, int y, int w, int h, GuiManager* manager)
    : Fl_Group(x, y, w, h), guiManager(manager) {
       
    Fl_Tabs* tabs = new Fl_Tabs(165,10,800-170,580);
        tabs->selection_color(fl_rgb_color(0x96,0x7e,0xd7));//#9179ef
        tabs->labelcolor(FL_WHITE);
        {
            Fl_Group* expense = new Fl_Group(10,35,800-170,580,"Expense");
            expense->labelsize(20);
            expense->labelcolor(FL_WHITE);
            expense->color(fl_rgb_color(0x96,0x7e,0xd7));
            expense->color2(fl_rgb_color(0x96,0x7e,0xd7));
            {
                
            }
            expense->end();

            Fl_Group* regularExpense = new Fl_Group(10,35,800-170,580,"Regular Expense");
            regularExpense->color(fl_rgb_color(0x96,0x7e,0xd7));
            regularExpense->color2(fl_rgb_color(0x96,0x7e,0xd7));
            regularExpense->labelcolor(FL_WHITE);
            regularExpense->labelsize(20);
            {
            }
            regularExpense->end();

            Fl_Group* income = new Fl_Group(10,35,800-170,580,"Income");
            income->color(fl_rgb_color(0x96,0x7e,0xd7));
            income->color2(fl_rgb_color(0x96,0x7e,0xd7));
            income->labelcolor(FL_WHITE);
            income->labelsize(20);
            {
                
            }
            income->end();

            Fl_Group* regularIncome = new Fl_Group(10,35,800-170,580,"Regular Income");
            regularIncome->color(fl_rgb_color(0x96,0x7e,0xd7));
            regularIncome->color2(fl_rgb_color(0x96,0x7e,0xd7));
            regularIncome->labelcolor(FL_WHITE);
            regularIncome->labelsize(20);
            {
                
            }
            regularIncome->end();
        }
        tabs->end();
    end();
}