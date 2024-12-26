/**
 * @file Income.cpp
 * @brief Implements the Income class for managing income entries.
 */

#include "Income.h"
#include <sstream>

/**
 * @brief Constructs an Income object with the specified details.
 *
 * Initializes the Income with the provided date, description, and amount.
 *
 * @param date The date of the income.
 * @param description A description of the income source.
 * @param amount The amount of the income.
 */
Income::Income(Date date, const std::string& description, double amount) 
    : date{date}, description{description}, amount{amount}
{
}

/**
 * @brief Retrieves the date of the income.
 *
 * @return A constant reference to the Date object representing the income date.
 */
const Date &Income::getDate() const
{
    return date;
}

/**
 * @brief Retrieves the amount of the income.
 *
 * @return The amount of the income as a double.
 */
double Income::getAmount() const
{
    return amount;
}

/**
 * @brief Retrieves the amount of the income as a formatted string.
 *
 * Formats the amount by prefixing it with a dollar sign.
 *
 * @return A string representing the formatted amount (e.g., "$100.50").
 */
std::string Income::getAmountAsString() const
{
    std::stringstream ss;
    ss << "$" << amount;
    return ss.str();
}

/**
 * @brief Retrieves the description of the income.
 *
 * @return A constant reference to the string containing the income description.
 */
const std::string &Income::getDescription() const
{
    return description;
}
