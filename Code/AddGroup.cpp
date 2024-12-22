#include "AddGroup.h"
AddGroup::AddGroup(int x, int y, int w, int h, GuiManager* manager)
    : Fl_Group(x, y, w, h), guiManager(manager) {
       
    Fl_Tabs* tabs = new Fl_Tabs(165,10,800-170,580);
        {
            Fl_Group* expense = new Fl_Group(10,35,800-170,580,"Expense");
            expense->labelsize(20);
            {
                
            }
            expense->end();

            Fl_Group* regularExpense = new Fl_Group(10,35,800-170,580,"Regular Expense");
            regularExpense->labelsize(20);
            {
            }
            regularExpense->end();

            Fl_Group* income = new Fl_Group(10,35,800-170,580,"Income");
            income->labelsize(20);
            {
                
            }
            income->end();

            Fl_Group* regularIncome = new Fl_Group(10,35,800-170,580,"Regular Income");
            regularIncome->labelsize(20);
            {
                
            }
            regularIncome->end();
        }
        tabs->end();
    end();
}