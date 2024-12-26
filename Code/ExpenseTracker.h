/**
 * @file ExpenseTracker.h
 * @brief Declares the ExpenseTracker class for managing users, expenses, incomes, and budgets.
 */

#pragma once
#include <map>
#include <string>
#include <chrono>
#include "User.h"
#include "Date.h"
#include "Category.h"
#include <cctype>
#include <algorithm>
#include <array>
#include <vector>

/**
 * @class ExpenseTracker
 * @brief Manages users, their expenses, incomes, and budgets.
 *
 * The ExpenseTracker class provides functionalities to register and authenticate users,
 * manage their expenses and incomes, track budgets, and handle date and time-related operations.
 * It maintains a collection of users and ensures that each user's financial data is properly managed.
 */
class ExpenseTracker {
public:
    /**
     * @brief Constructs an ExpenseTracker object.
     *
     * Initializes the ExpenseTracker with no current user, no expenses,
     * sets the current time, and initializes the date based on the current time.
     */
    ExpenseTracker();

    /**
     * @brief Destructs the ExpenseTracker object.
     *
     * Cleans up dynamically allocated memory for the date.
     */
    ~ExpenseTracker();

    /**
     * @brief Registers a new user.
     *
     * Adds a new user with the provided username, password, and budget if the username is not already taken.
     *
     * @param username The desired username for the new user.
     * @param password The password for the new user.
     * @param budget The initial budget amount for the new user.
     * @return true if registration is successful, false if the username already exists.
     */
    bool registerUser(const std::string& username, const std::string& password, double budget);

    /**
     * @brief Logs in a user.
     *
     * Authenticates the user with the provided username and password.
     *
     * @param username The username of the user attempting to log in.
     * @param password The password of the user attempting to log in.
     * @return true if login is successful, false otherwise.
     */
    bool login(const std::string& username, const std::string& password);

    /**
     * @brief Logs out the current user.
     *
     * Clears the current user, effectively logging them out.
     */
    void logout();

    /**
     * @brief Retrieves the username of the currently logged-in user.
     *
     * @return The username of the current user as a string. Returns an empty string if no user is logged in.
     */
    std::string getCurrentUsername() const;

    /**
     * @brief Retrieves the budget of the currently logged-in user as a formatted string.
     *
     * @return The budget of the current user as a string. Returns an empty string if no user is logged in.
     */
    std::string getBudgetAsString() const;

    /**
     * @brief Retrieves the current date.
     *
     * @return A pointer to the Date object representing the current date.
     */
    Date* getDate();

    /**
     * @brief Retrieves the current time point.
     *
     * @return A std::chrono::system_clock::time_point representing the current time.
     */
    std::chrono::system_clock::time_point getTime() const;

    /**
     * @brief Retrieves the expenses of the currently logged-in user.
     *
     * @return A pointer to a vector of Expense objects. Returns nullptr if no user is logged in.
     */
    std::vector<Expense>* getExpenses();

    /**
     * @brief Retrieves the incomes of the currently logged-in user.
     *
     * @return A pointer to a vector of Income objects. Returns nullptr if no user is logged in.
     */
    std::vector<Income>* getIncomes();

    /**
     * @brief Updates the current time by adding a specified number of seconds.
     *
     * @param time The number of seconds to add to the current time.
     */
    void updateTime(int time);

    /**
     * @brief Updates the current date based on a new time point.
     *
     * Deletes the existing Date object and creates a new one with the provided time.
     *
     * @param time A std::chrono::system_clock::time_point representing the new time.
     */
    void updateDate(std::chrono::system_clock::time_point time);

    /**
     * @brief Adds an expense to the current user's expense list.
     *
     * @param expense The Expense object to add.
     */
    void addExpense(Expense expense);

    /**
     * @brief Adds income to the current user's income list.
     *
     * @param income The Income object to add.
     */
    void addIncome(Income income);

    /**
     * @brief Updates the information of the currently logged-in user.
     *
     * Sets a new username, password, and budget for the current user.
     *
     * @param username The new username to set.
     * @param password The new password to set.
     * @param budget The new budget amount to set.
     * @return true if the update is successful, false otherwise.
     */
    bool updateCurrentUserInfo(std::string& username, const std::string& password, double budget);

    /**
     * @brief Retrieves a Category enumeration based on an index.
     *
     * @param index The index corresponding to a Category.
     * @return The Category enumeration value.
     */
    static Category getCategory(int index);

private:
    std::map<std::string, User> users; ///< Map of usernames to User objects.
    User* currentUser; ///< Pointer to the currently logged-in user.
    Date* date; ///< Pointer to the current Date object.
    std::vector<Expense>* expenses; ///< Pointer to the current user's expenses.
    std::chrono::system_clock::time_point time; ///< Current time point.
    static std::array<Category,10> categories; ///< Array of available categories.

    /**
     * @brief Checks if a user with the given username exists.
     *
     * Searches the user map to determine if the specified username is already registered.
     *
     * @param username The username to check for existence.
     * @return true if the user exists, false otherwise.
     */
    bool userExists(const std::string& username) const;
};
