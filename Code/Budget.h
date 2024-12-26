/**
 * @file Budget.h
 * @brief Declares the Budget class for managing and tracking budget amounts.
 */

#pragma once

#include "Expense.h"
#include "Income.h"
#include <string>

/**
 * @class Budget
 * @brief Manages and tracks budget amounts, handling expenses and incomes.
 *
 * The Budget class provides functionalities to add expenses and incomes,
 * set and retrieve the current budget, and represent the budget as a formatted string.
 * It ensures that the budget is not exceeded by alerting the user when necessary.
 */
class Budget {
public:
    /**
     * @brief Constructs a Budget with the specified initial amount.
     *
     * Initializes the budget with the provided amount.
     *
     * @param amount The initial budget amount.
     */
    Budget(double amount);

    /**
     * @brief Adds an expense to the budget.
     *
     * Subtracts the expense amount from the current budget. If the budget becomes negative
     * after adding the expense, an alert is displayed to notify the user that they have exceeded their budget.
     *
     * @param expense Pointer to the Expense object to be added.
     */
    void addExpense(const Expense* expense);

    /**
     * @brief Sets a new budget amount.
     *
     * Updates the budget to the specified new amount.
     *
     * @param newAmount The new budget amount to be set.
     */
    void setBudget(double newAmount);    // Added by mky

    /**
     * @brief Adds income to the budget.
     *
     * Increases the current budget by the amount of the provided income.
     *
     * @param income Pointer to the Income object to be added.
     */
    void addIncome(const Income* income);

    /**
     * @brief Retrieves the current budget amount.
     *
     * @return The current budget as a double.
     */
    double getBudget() const;

    /**
     * @brief Retrieves the current budget amount as a formatted string.
     *
     * Formats the budget amount by prefixing it with a dollar sign.
     *
     * @return The formatted budget string (e.g., "$1000").
     */
    std::string getBudgetAsString() const;

private:
    double amount; ///< The current budget amount.
};
