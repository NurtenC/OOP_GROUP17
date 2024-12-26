/**
 * @file Expense.h
 * @brief Declares the Expense class for managing expense entries.
 */

#pragma once
#include "Category.h"
#include "Date.h"
#include <string> 
#include <sstream>

/**
 * @class Expense
 * @brief Represents an expense entry with date, category, description, and amount.
 *
 * The Expense class provides functionalities to store and retrieve expense details,
 * including the date of the expense, its category, a description, and the amount spent.
 */
class Expense{

public:

    /**
     * @brief Constructs an Expense object with the specified details.
     *
     * Initializes the Expense with the provided date, category, description, and amount.
     *
     * @param date The date of the expense.
     * @param category The category of the expense.
     * @param description A description of the expense.
     * @param amount The amount of the expense.
     */
    Expense(Date date, Category category, const std::string& description, double amount);
    
    /**
     * @brief Retrieves the date of the expense.
     *
     * @return A constant reference to the Date object representing the expense date.
     */
    const Date& getDate() const;
    
    /**
     * @brief Retrieves the category of the expense.
     *
     * @return The Category enumeration value representing the expense category.
     */
    Category getCategory() const;
    
    /**
     * @brief Converts the expense category to its corresponding string representation.
     *
     * @return A string representing the expense category (e.g., "Grocery", "Health").
     */
    std::string getCategoryAsString() const;
    
    /**
     * @brief Retrieves the amount of the expense.
     *
     * @return The amount of the expense as a double.
     */
    double getAmount() const;
    
    /**
     * @brief Retrieves the amount of the expense as a formatted string.
     *
     * Formats the amount by prefixing it with a dollar sign.
     *
     * @return A string representing the formatted amount (e.g., "$100.50").
     */
    std::string getAmountAsString() const;
    
    /**
     * @brief Retrieves the description of the expense.
     *
     * @return A constant reference to the string containing the expense description.
     */
    const std::string& getDescription() const;


private:

    Date date; ///< The date of the expense.
    Category category; ///< The category of the expense.
    std::string description; ///< A description of the expense.
    double amount; ///< The amount of the expense.
};
