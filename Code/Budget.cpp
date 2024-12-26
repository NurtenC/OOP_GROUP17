/**
 * @file Budget.cpp
 * @brief Implements the Budget class for managing and tracking budget amounts.
 */

#include "Budget.h"
#include <Fl/fl_ask.H>
#include <sstream>

/**
 * @brief Constructs a Budget with the specified initial amount.
 * 
 * Initializes the budget with the provided amount.
 * 
 * @param amount The initial budget amount.
 */
Budget::Budget(double amount)
{
    this->amount = amount;
}

/**
 * @brief Adds an expense to the budget.
 * 
 * Subtracts the expense amount from the current budget. If the budget becomes negative
 * after adding the expense, an alert is displayed to notify the user that they have exceeded their budget.
 * 
 * @param expense Pointer to the Expense object to be added.
 */
void Budget::addExpense(const Expense *expense)
{
    amount -= expense->getAmount();
    
    if(amount < 0){
        fl_alert("You are exceeding your budget!");
    }
}

/**
 * @brief Adds income to the budget.
 * 
 * Increases the current budget by the amount of the provided income.
 * 
 * @param income Pointer to the Income object to be added.
 */
void Budget::addIncome(const Income *income)
{
    amount += income->getAmount();
}

/**
 * @brief Retrieves the current budget amount.
 * 
 * @return The current budget as a double.
 */
double Budget::getBudget() const
{
    return amount;
}

/**
 * @brief Retrieves the current budget amount as a formatted string.
 * 
 * Formats the budget amount by prefixing it with a dollar sign.
 * 
 * @return The formatted budget string (e.g., "$1000").
 */
std::string Budget::getBudgetAsString() const
{
    std::stringstream ss;
    // Changed: Removed "Budget: $" and only display "$" to prevent duplication in HomepageGroup.cpp
    ss << "$" << amount;  // Display only the dollar sign followed by the amount
    return ss.str();
}

/**
 * @brief Sets a new budget amount.
 * 
 * Updates the budget to the specified new amount.
 * 
 * @param newAmount The new budget amount to be set.
 */
void Budget::setBudget(double newAmount)
{
    this->amount = newAmount;
}
