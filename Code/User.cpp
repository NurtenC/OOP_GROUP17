#include "User.h"

// Constructor
// mky changed: Budget artık doğrudan by-value saklanıyor
User::User(const std::string& username, const std::string& password, double budget)
    : username(username), password(password), budget(budget)
{
}

// Getter
std::string User::getUsername() const {
    return username;
}

// Budget değerini string olarak döndürür
std::string User::getBudgetAsString() const {
    // Artık "budget" bir nesne olduğu için doğrudan .getBudgetAsString() çağırıyoruz
    return budget.getBudgetAsString();
}

// Income/Expense vektörlerini döndürür (pointer olarak)
std::vector<Income>* User::getIncomes() {
    return &incomes;
}

std::vector<Expense>* User::getExpenses() {
    return &expenses;
}

// Şifre kontrolü
bool User::checkPassword(const std::string& password) const {
    return this->password == password;
}

// Yeni Expense eklenirken Budget'ı da güncelle
void User::addExpense(Expense expense) {
    expenses.push_back(expense);
    budget.addExpense(&expense);
}

// Yeni Income eklenirken Budget'ı da güncelle
void User::addIncome(Income income) {
    incomes.push_back(income);
    budget.addIncome(&income);
}

// Setters
void User::setUsername(const std::string &newUsername) {
    username = newUsername;
}

void User::setPassword(const std::string &newPassword) {
    password = newPassword;
}

void User::setBudget(double newBudget) {
    budget.setBudget(newBudget);
}
