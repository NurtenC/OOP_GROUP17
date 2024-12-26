/**
 * @file User.cpp
 * @brief Implements the User class for managing user information and financial records.
 */

#include "User.h"
#include <sstream>

/**
 * @brief Constructs a User object with the specified credentials and budget.
 *
 * Initializes the User with a username, password, and initial budget.
 *
 * @param username The username of the user.
 * @param password The password of the user.
 * @param budget The initial budget allocated to the user.
 */
User::User(const std::string& username, const std::string& password, double budget)
    : username(username), password(password), budget(budget)
{
}

/**
 * @brief Retrieves the username of the user.
 *
 * @return The username as a std::string.
 */
std::string User::getUsername() const {
    return username;
}

/**
 * @brief Retrieves the budget of the user as a formatted string.
 *
 * Formats the budget by delegating to the Budget class's getBudgetAsString method.
 *
 * @return The budget as a formatted std::string (e.g., "$1000.00").
 */
std::string User::getBudgetAsString() const {
    return budget.getBudgetAsString();
}

/**
 * @brief Retrieves a pointer to the user's incomes.
 *
 * @return A pointer to a std::vector of Income objects.
 */
std::vector<Income>* User::getIncomes() {
    return &incomes;
}

/**
 * @brief Retrieves a pointer to the user's expenses.
 *
 * @return A pointer to a std::vector of Expense objects.
 */
std::vector<Expense>* User::getExpenses() {
    return &expenses;
}

/**
 * @brief Checks if the provided password matches the user's password.
 *
 * @param password The password to verify.
 * @return True if the password matches, false otherwise.
 */
bool User::checkPassword(const std::string& password) const {
    return this->password == password;
}

/**
 * @brief Adds a new expense to the user's records and updates the budget.
 *
 * @param expense The Expense object to add.
 */
void User::addExpense(Expense expense) {
    expenses.push_back(expense);
    budget.addExpense(&expense);
}

/**
 * @brief Adds a new income to the user's records and updates the budget.
 *
 * @param income The Income object to add.
 */
void User::addIncome(Income income) {
    incomes.push_back(income);
    budget.addIncome(&income);
}

/**
 * @brief Sets a new username for the user.
 *
 * @param newUsername The new username to assign.
 */
void User::setUsername(const std::string &newUsername) {
    username = newUsername;
}

/**
 * @brief Sets a new password for the user.
 *
 * @param newPassword The new password to assign.
 */
void User::setPassword(const std::string &newPassword) {
    password = newPassword;
}

/**
 * @brief Sets a new budget for the user.
 *
 * @param newBudget The new budget amount to assign.
 */
void User::setBudget(double newBudget) {
    budget.setBudget(newBudget);
}
