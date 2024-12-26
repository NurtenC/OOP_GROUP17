/**
 * @file Expense.cpp
 * @brief Implements the Expense class for managing expense entries.
 */

#include "Expense.h"
#include <sstream>

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
Expense::Expense(Date date, Category category, const std::string& description, double amount) 
    : date{date}, category{category}, description{description}, amount{amount}
{
}

/**
 * @brief Retrieves the date of the expense.
 *
 * @return A constant reference to the Date object representing the expense date.
 */
const Date &Expense::getDate() const
{
    return date;
}

/**
 * @brief Retrieves the category of the expense.
 *
 * @return The Category enumeration value representing the expense category.
 */
Category Expense::getCategory() const
{
    return category;
}

/**
 * @brief Converts the expense category to its corresponding string representation.
 *
 * @return A string representing the expense category (e.g., "Grocery", "Health").
 */
std::string Expense::getCategoryAsString() const
{
    switch(category){
        case Category::GROCERY:
            return "Grocery";
        case Category::HEALTH:
            return "Health";
        case Category::ENTERTAINMENT:
            return "Entertainment";
        case Category::EDUCATION:
            return "Education";
        case Category::TRANSPORTATION:
            return "Transportation";
        case Category::PERSONAL_CARE:
            return "Personal Care";
        case Category::CLOTHES:
            return "Clothes";
        case Category::TAX:
            return "Tax";
        case Category::BILL:
            return "Bill";
        case Category::RENT:
            return "Rent";
        default:
            return "Error!";
    }
}

/**
 * @brief Retrieves the amount of the expense.
 *
 * @return The amount of the expense as a double.
 */
double Expense::getAmount() const
{
    return amount;
}

/**
 * @brief Retrieves the amount of the expense as a formatted string.
 *
 * Formats the amount by prefixing it with a dollar sign.
 *
 * @return A string representing the formatted amount (e.g., "$100.50").
 */
std::string Expense::getAmountAsString() const
{
    std::stringstream ss;
    ss << "$" << amount;
    return ss.str();
}

/**
 * @brief Retrieves the description of the expense.
 *
 * @return A constant reference to the string containing the expense description.
 */
const std::string &Expense::getDescription() const
{
    return description;
}
