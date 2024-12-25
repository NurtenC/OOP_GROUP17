#include "User.h"

User::User(const std::string& username, const std::string& password, double budget)
    : username(username), password(password) {
    
    this->budget = new Budget(budget);
}

User::~User()
{
    delete budget;
}

std::string User::getUsername() const {
    return username;
}

std::string User::getBudgetAsString() const
{
    return budget->getBudgetAsString();
}

std::vector<Income> *User::getIncomes()
{
    return &incomes;
}

std::vector<Expense>* User::getExpenses()
{
    return &expenses;
}

bool User::checkPassword(const std::string& password) const {
    return this->password == password;
}

void User::addExpense(Expense expense)
{
    expenses.push_back(expense);
    budget->addExpense(&expense);
}

void User::addIncome(Income income)
{
    incomes.push_back(income);
    budget->addIncome(&income);
}
