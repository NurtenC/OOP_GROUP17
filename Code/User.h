/**
 * @file User.h
 * @brief Declares the User class for managing user information and financial records.
 */

#pragma once
#include <string>
#include <vector>
#include "Expense.h"
#include "Income.h"
#include "Budget.h"

/**
 * @class User
 * @brief Represents a user with credentials and financial data.
 *
 * The User class manages user-related information, including username, password,
 * budget, expenses, and incomes. It provides functionalities to authenticate users,
 * manage their financial records, and update their profiles.
 */
class User {
public:
    /**
     * @brief Constructs a User object with the specified credentials and budget.
     *
     * Initializes the User with a username, password, and initial budget.
     *
     * @param username The username of the user.
     * @param password The password of the user.
     * @param budget The initial budget allocated to the user.
     */
    User(const std::string& username, const std::string& password, double budget);

    /**
     * @brief Retrieves the username of the user.
     *
     * @return The username as a std::string.
     */
    std::string getUsername() const;

    /**
     * @brief Retrieves the budget of the user as a formatted string.
     *
     * Formats the budget by delegating to the Budget class's getBudgetAsString method.
     *
     * @return The budget as a formatted std::string (e.g., "$1000.00").
     */
    std::string getBudgetAsString() const;

    /**
     * @brief Retrieves a pointer to the user's incomes.
     *
     * @return A pointer to a std::vector of Income objects.
     */
    std::vector<Income>* getIncomes();

    /**
     * @brief Retrieves a pointer to the user's expenses.
     *
     * @return A pointer to a std::vector of Expense objects.
     */
    std::vector<Expense>* getExpenses();

    /**
     * @brief Checks if the provided password matches the user's password.
     *
     * @param password The password to verify.
     * @return True if the password matches, false otherwise.
     */
    bool checkPassword(const std::string& password) const;

    /**
     * @brief Adds a new expense to the user's records and updates the budget.
     *
     * @param expense The Expense object to add.
     */
    void addExpense(Expense expense);

    /**
     * @brief Adds a new income to the user's records and updates the budget.
     *
     * @param income The Income object to add.
     */
    void addIncome(Income income);

    /**
     * @brief Sets a new username for the user.
     *
     * @param newUsername The new username to assign.
     */
    void setUsername(const std::string& newUsername);

    /**
     * @brief Sets a new password for the user.
     *
     * @param newPassword The new password to assign.
     */
    void setPassword(const std::string& newPassword);

    /**
     * @brief Sets a new budget for the user.
     *
     * @param newBudget The new budget amount to assign.
     */
    void setBudget(double newBudget);

private:
    std::string username;           ///< The username of the user.
    std::string password;           ///< The password of the user.
    Budget budget;                  ///< The budget allocated to the user.

    std::vector<Expense> expenses;  ///< Vector holding the user's expenses.
    std::vector<Income> incomes;    ///< Vector holding the user's incomes.
};
