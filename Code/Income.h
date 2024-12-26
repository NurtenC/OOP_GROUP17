/**
 * @file Income.h
 * @brief Declares the Income class for managing income entries.
 */

#pragma once
#include "Date.h"
#include <string>
#include <sstream>

/**
 * @class Income
 * @brief Represents an income entry with date, description, and amount.
 *
 * The Income class provides functionalities to store and retrieve income details,
 * including the date of the income, a description, and the amount received.
 */
class Income {

public:

    /**
     * @brief Constructs an Income object with the specified details.
     *
     * Initializes the Income with the provided date, description, and amount.
     *
     * @param date The date of the income.
     * @param description A description of the income source.
     * @param amount The amount of the income.
     */
    Income(Date date, const std::string& description, double amount);

    /**
     * @brief Retrieves the date of the income.
     *
     * @return A constant reference to the Date object representing the income date.
     */
    const Date& getDate() const;

    /**
     * @brief Retrieves the amount of the income.
     *
     * @return The amount of the income as a double.
     */
    double getAmount() const;

    /**
     * @brief Retrieves the amount of the income as a formatted string.
     *
     * Formats the amount by prefixing it with a dollar sign.
     *
     * @return A string representing the formatted amount (e.g., "$100.50").
     */
    std::string getAmountAsString() const;

    /**
     * @brief Retrieves the description of the income.
     *
     * @return A constant reference to the string containing the income description.
     */
    const std::string& getDescription() const;

private:

    Date date; ///< The date of the income.
    std::string description; ///< A description of the income source.
    double amount; ///< The amount of the income.
};
