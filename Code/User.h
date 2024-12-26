#pragma once
#include <string>
#include <vector>
#include "Expense.h"
#include "Income.h"
#include "Budget.h"

// mky changed: Budget artık by-value saklanacak

class User {
public:
    // Constructor
    User(const std::string& username, const std::string& password, double budget);

    // Getters
    std::string getUsername() const;
    std::string getBudgetAsString() const;
    std::vector<Income>* getIncomes();
    std::vector<Expense>* getExpenses();
    bool checkPassword(const std::string& password) const;

    // Adding expense/income
    void addExpense(Expense expense);
    void addIncome(Income income);

    // Setters
    void setUsername(const std::string& newUsername);
    void setPassword(const std::string& newPassword);
    void setBudget(double newBudget);

private:
    std::string username;
    std::string password;
    Budget budget;  // mky changed: artık pointer değil, doğrudan Budget nesnesi

    std::vector<Expense> expenses;
    std::vector<Income> incomes;

    // mky removed: Artık destructor yok, Budget by-value
};
