/**
 * @file Date.h
 * @brief Declares the Date class for handling date and time functionalities.
 */

#pragma once 

#include <chrono>
#include <string>
#include <sstream> 
#include <iomanip>
#include <ctime>

/**
 * @class Date
 * @brief Represents a calendar date with day, month, and year components.
 *
 * The Date class provides functionalities to parse, format, and retrieve date information.
 * It can be initialized using a string or a time_point, and offers methods to obtain
 * individual date components as well as formatted date and time strings.
 */
class Date{
    /**
     * @brief Constructs a Date object from a formatted date string.
     *
     * Parses the provided date string in "DD/MM/YYYY" format and initializes the day, month, and year.
     * Throws an exception if the format is invalid.
     *
     * @param dateStr A string representing the date in "DD/MM/YYYY" format.
     *
     * @throws std::invalid_argument If the date string is not in the expected format or contains invalid values.
     */
    Date(const std::string& dateStr) {
        std::istringstream ss(dateStr);
        char delimiter;
        ss >> day >> delimiter >> month >> delimiter >> year;
        if (ss.fail() || delimiter != '/' || day <= 0 || month <= 0 || year <= 0) {
            throw std::invalid_argument("Invalid date format. Expected format: DD/MM/YYYY");
        }
    }

private:

    int day;    ///< The day component of the date.
    int month;  ///< The month component of the date.
    int year;   ///< The year component of the date.

public: 
    /**
     * @brief Constructs a Date object from a time_point.
     *
     * Converts the given time_point to a date by extracting the day, month, and year.
     *
     * @param time A std::chrono::system_clock::time_point representing the date and time.
     */
    Date(std::chrono::system_clock::time_point time);
        
    /**
     * @brief Retrieves the date as a formatted string.
     *
     * Formats the date in "DD/MM/YYYY" format with leading zeros for day and month.
     *
     * @return A string representing the formatted date (e.g., "05/09/2023").
     */
    std::string getDateString() const;

    /**
     * @brief Retrieves the day component of the date.
     *
     * @return An integer representing the day of the month.
     */
    int getDay() const;

    /**
     * @brief Retrieves the month component of the date.
     *
     * @return An integer representing the month.
     */
    int getMonth() const;

    /**
     * @brief Retrieves the year component of the date.
     *
     * @return An integer representing the year.
     */
    int getYear() const;

    /**
     * @brief Retrieves the time from a time_point as a formatted string.
     *
     * Formats the time in "HH:MM:SS" format with leading zeros for hours, minutes, and seconds.
     *
     * @param time A std::chrono::system_clock::time_point representing the time.
     * @return A string representing the formatted time (e.g., "14:30:15").
     */
    static std::string getTimeStr(std::chrono::system_clock::time_point time);
};
