#pragma once
#include <string>
#include <vector>
#include "Expense.h"

class User {
public:

    User(const std::string& username, const std::string& password);

    std::string getUsername() const;
    std::vector<Expense>* getExpenses();
    bool checkPassword(const std::string& password) const;
    void addExpense(Expense expense);

private:
    std::string username;
    std::string password;
    std::vector<Expense> expenses;
    
};