#pragma once
#include <string>
#include <vector>
#include "Expense.h"
#include "Income.h"
#include "Budget.h"

class User {
public:

    User(const std::string& username, const std::string& password, double budget);
    ~User();

    std::string getUsername() const;
    std::string getBudgetAsString() const;
    std::vector<Income>* getIncomes();
    std::vector<Expense>* getExpenses();
    bool checkPassword(const std::string& password) const;
    void addExpense(Expense expense);
    void addIncome(Income income);


private:
    std::string username;
    std::string password;
    Budget* budget;
    std::vector<Expense> expenses;
    std::vector<Income> incomes;
    
};