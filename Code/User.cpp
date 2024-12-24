#include "User.h"

User::User(const std::string& username, const std::string& password)
    : username(username), password(password) {}


std::string User::getUsername() const {
    return username;
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
}

void User::addIncome(Income income)
{
    incomes.push_back(income);
}
