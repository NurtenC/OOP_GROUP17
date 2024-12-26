#pragma once
#include "Expense.h"
#include "Income.h"
#include <string>


class Budget{

public:

    Budget(double amount);
    void addExpense(const Expense* expense);
    void setBudget(double newAmount);    // mky Ekledi
    void addIncome(const Income* income);
    double getBudget()const;
    std::string getBudgetAsString()const;

private:
    double amount;
};
