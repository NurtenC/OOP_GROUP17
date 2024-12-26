#include "Budget.h"
#include <Fl/fl_ask.H>
#include <sstream>

Budget::Budget(double amount)
{
    this->amount = amount;
}

void Budget::addExpense(const Expense *expense)
{
    amount -= expense->getAmount();
    
    if(amount < 0){
        fl_alert("You are exceeding your budget!");
    }
}

void Budget::addIncome(const Income *income)
{
    amount += income->getAmount();
}

double Budget::getBudget() const
{
    return amount;
}

// mky changed: bu fonksiyonda "Budget: $" yazısını kaldırdık, sadece "$" koyduk
std::string Budget::getBudgetAsString() const
{
    std::stringstream ss;
    // Eski hali: ss << "Budget: $" << amount;  // Bu, HomepageGroup.cpp içinde "Budget: " ile birleşip iki kez yazdırıyordu
    ss << "$" << amount;  // Sadece dolar işareti + miktar gösteriyoruz
    return ss.str();
}

    // mky Ekledi

void Budget::setBudget(double newAmount)
{
    this->amount = newAmount;
}
    // mky Ekledi
