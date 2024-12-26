/**
 * @file ExpenseTracker.cpp
 * @brief Implements the ExpenseTracker class for managing users, expenses, incomes, and budget.
 */

#include "ExpenseTracker.h"
#include <Fl/fl_ask.H>
#include <sstream>

/**
 * @brief Constructs an ExpenseTracker object.
 *
 * Initializes the ExpenseTracker with no current user, no expenses, sets the current time,
 * and initializes the date based on the current time.
 */
ExpenseTracker::ExpenseTracker()
{
    currentUser = nullptr;
    expenses = nullptr;
    time = std::chrono::system_clock::now();
    date = new Date(time);
}

/**
 * @brief Destructs the ExpenseTracker object.
 *
 * Cleans up dynamically allocated memory for the date.
 */
ExpenseTracker::~ExpenseTracker()
{
    delete date;
}

/**
 * @brief Checks if a user with the given username exists.
 *
 * Searches the user map to determine if the specified username is already registered.
 *
 * @param username The username to check for existence.
 * @return true if the user exists, false otherwise.
 */
bool ExpenseTracker::userExists(const std::string &username) const
{
    return users.find(username) != users.end();
}

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
bool ExpenseTracker::registerUser(const std::string &username, const std::string &password, double budget)
{
    if (userExists(username))
    {
        return false;
    }
    users.emplace(username, User(username, password, budget));
    return true;
}

/**
 * @brief Logs in a user.
 *
 * Authenticates the user with the provided username and password.
 *
 * @param username The username of the user attempting to log in.
 * @param password The password of the user attempting to log in.
 * @return true if login is successful, false otherwise.
 */
bool ExpenseTracker::login(const std::string &username, const std::string &password)
{
    auto iterator = users.find(username);
    if (iterator != users.end() && iterator->second.checkPassword(password))
    {
        currentUser = &(iterator->second);
        return true;
    }
    return false;
}

/**
 * @brief Logs out the current user.
 *
 * Clears the current user, effectively logging them out.
 */
void ExpenseTracker::logout()
{
    currentUser = nullptr;
}

/**
 * @brief Retrieves the username of the currently logged-in user.
 *
 * @return The username of the current user as a string. Returns an empty string if no user is logged in.
 */
std::string ExpenseTracker::getCurrentUsername() const
{
    if (currentUser)
    {
        return currentUser->getUsername();
    }
    return "";
}

/**
 * @brief Retrieves the budget of the currently logged-in user as a formatted string.
 *
 * @return The budget of the current user as a string. Returns an empty string if no user is logged in.
 */
std::string ExpenseTracker::getBudgetAsString() const
{
    if (currentUser)
    {
        return currentUser->getBudgetAsString();
    }
    return "";
}

/**
 * @brief Retrieves the current date.
 *
 * @return A pointer to the Date object representing the current date.
 */
Date *ExpenseTracker::getDate()
{
    return date;
}

/**
 * @brief Retrieves the current time point.
 *
 * @return A std::chrono::system_clock::time_point representing the current time.
 */
std::chrono::system_clock::time_point ExpenseTracker::getTime() const
{
    return time;
}

/**
 * @brief Retrieves the expenses of the currently logged-in user.
 *
 * @return A pointer to a vector of Expense objects. Returns nullptr if no user is logged in.
 */
std::vector<Expense> *ExpenseTracker::getExpenses()
{
    if (currentUser)
    {
        return currentUser->getExpenses();
    }
    return nullptr;
}

/**
 * @brief Retrieves the incomes of the currently logged-in user.
 *
 * @return A pointer to a vector of Income objects. Returns nullptr if no user is logged in.
 */
std::vector<Income> *ExpenseTracker::getIncomes()
{
    if (currentUser)
    {
        return currentUser->getIncomes();
    }
    return nullptr;
}

/**
 * @brief Updates the current time by adding a specified number of seconds.
 *
 * @param time The number of seconds to add to the current time.
 */
void ExpenseTracker::updateTime(int time)
{
    this->time += std::chrono::seconds(time);
}

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
bool ExpenseTracker::updateCurrentUserInfo(std::string& username, const std::string& password, double budget){
    try
    {
        currentUser->setUsername(username);
        currentUser->setPassword(password);
        currentUser->setBudget(budget);
        return true;
    }
    catch(...){
        return false;
    }
}

/**
 * @brief Updates the current date based on a new time point.
 *
 * Deletes the existing Date object and creates a new one with the provided time.
 *
 * @param time A std::chrono::system_clock::time_point representing the new time.
 */
void ExpenseTracker::updateDate(std::chrono::system_clock::time_point time)
{
    delete date;
    date = new Date(time);
}

/**
 * @brief Adds an expense to the current user's expense list.
 *
 * @param expense The Expense object to add.
 */
void ExpenseTracker::addExpense(Expense expense)
{
    currentUser->addExpense(expense);
}

/**
 * @brief Adds income to the current user's income list.
 *
 * @param income The Income object to add.
 */
void ExpenseTracker::addIncome(Income income)
{
    currentUser->addIncome(income);
}

/**
 * @brief Retrieves a Category enumeration based on an index.
 *
 * @param index The index corresponding to a Category.
 * @return The Category enumeration value.
 */
Category ExpenseTracker::getCategory(int index)
{
    return categories[index];
}

/**
 * @brief Defines the available categories for expenses and incomes.
 */
std::array<Category, 10> ExpenseTracker::categories = {
    Category::GROCERY,
    Category::HEALTH,
    Category::ENTERTAINMENT,
    Category::EDUCATION,
    Category::TRANSPORTATION,
    Category::PERSONAL_CARE,
    Category::CLOTHES,
    Category::TAX,
    Category::BILL,
    Category::RENT,
};
