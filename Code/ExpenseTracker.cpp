
#include "ExpenseTracker.h"
#include <Fl/fl_ask.H>
#include <sstream>

ExpenseTracker::ExpenseTracker()
{
    currentUser = nullptr;
    expenses = nullptr;
    time = std::chrono::system_clock::now();
    date = new Date(time);
}

ExpenseTracker::~ExpenseTracker()
{
    delete date;
}

bool ExpenseTracker::userExists(const std::string &username) const
{
    return users.find(username) != users.end();
}


bool ExpenseTracker::registerUser(const std::string &username, const std::string &password, double budget)
{
    if (userExists(username))
    {
        return false;
    }
    users.emplace(username, User(username, password, budget));
    return true;
}


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


void ExpenseTracker::logout()
{
    currentUser = nullptr;
}

std::string ExpenseTracker::getCurrentUsername() const
{
    if (currentUser)
    {
        return currentUser->getUsername();
    }
    return "";
}


std::string ExpenseTracker::getBudgetAsString() const
{
    if (currentUser)
    {
        return currentUser->getBudgetAsString();
    }
    return "";
}


Date *ExpenseTracker::getDate()
{
    return date;
}


std::chrono::system_clock::time_point ExpenseTracker::getTime() const
{
    return time;
}


std::vector<Expense> *ExpenseTracker::getExpenses()
{
    if (currentUser)
    {
        return currentUser->getExpenses();
    }
    return nullptr;
}


std::vector<Income> *ExpenseTracker::getIncomes()
{
    if (currentUser)
    {
        return currentUser->getIncomes();
    }
    return nullptr;
}


void ExpenseTracker::updateTime(int time)
{
    this->time += std::chrono::seconds(time);
}


bool ExpenseTracker::updateCurrentUserInfo(std::string& username, const std::string& password, double budget){
    try
    {
        if (!currentUser) {
            return false; // No user is logged in
        }

        std::string oldUsername = currentUser->getUsername();
        bool isUsernameChanged = (username != oldUsername);

        // If the username is being changed, update the user map
        if (isUsernameChanged) {
            // Verify the new username does not already exist
            if (userExists(username)) {
                return false; // New username already in use
            }

            // Locate the current user in the user map
            auto it = users.find(oldUsername);
            if (it != users.end()) {
                User updatedUser = it->second; // Copy the current user
                updatedUser.setUsername(username); // Update the username
                updatedUser.setPassword(password); // Update the password
                updatedUser.setBudget(budget); // Update the budget

                users.erase(it); // Remove the old username entry

                users.emplace(username, updatedUser); // Add the updated user with the new username

                currentUser = &(users.find(username)->second); // Update the current user pointer
            } else {
                return false; // Current user not found in the map
            }
        }
        else {
            // Update password and budget only
            currentUser->setPassword(password);
            currentUser->setBudget(budget);
        }

        return true; // Update successful
    }
    catch(...) {
        return false; // Catch any unexpected errors
    }
}




void ExpenseTracker::updateDate(std::chrono::system_clock::time_point time)
{
    delete date;
    date = new Date(time);
}


void ExpenseTracker::addExpense(Expense expense)
{
    currentUser->addExpense(expense);
}


void ExpenseTracker::addIncome(Income income)
{
    currentUser->addIncome(income);
}


Category ExpenseTracker::getCategory(int index)
{
    return categories[index];
}


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
