
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


std::string Budget::getBudgetAsString() const
{
    std::stringstream ss;
    // Changed: Removed "Budget: $" and only display "$" to prevent duplication in HomepageGroup.cpp
    ss << "$" << amount;  // Display only the dollar sign followed by the amount
    return ss.str();
}


void Budget::setBudget(double newAmount)
{
    this->amount = newAmount;
}
