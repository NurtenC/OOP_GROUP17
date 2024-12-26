/**
 * @file Date.cpp
 * @brief Implements the Date class for handling date and time functionalities.
 */

#include "Date.h"
#include <sstream>
#include <iomanip>
#include <chrono>
#include <ctime>

/**
 * @brief Constructs a Date object from a time_point.
 *
 * Converts the given time_point to a date by extracting the day, month, and year.
 *
 * @param time A std::chrono::system_clock::time_point representing the date and time.
 */
Date::Date(std::chrono::system_clock::time_point time){
    auto timeAsInt = std::chrono::system_clock::to_time_t(time);
    auto timeStruct = *std::localtime(&timeAsInt); // converting time to struct
    day = timeStruct.tm_mday;
    month = timeStruct.tm_mon + 1;
    year = timeStruct.tm_year + 1900;
}

/**
 * @brief Retrieves the date as a formatted string.
 *
 * Formats the date in "DD/MM/YYYY" format with leading zeros for day and month.
 *
 * @return A string representing the formatted date (e.g., "05/09/2023").
 */
std::string Date::getDateString() const{
    std::stringstream ss;
    ss << std::setw(2) << std::setfill('0') << day << '/'
       << std::setw(2) << std::setfill('0') << month << '/'
       << year;
    return ss.str();
}

/**
 * @brief Retrieves the time from a time_point as a formatted string.
 *
 * Formats the time in "HH:MM:SS" format with leading zeros for hours, minutes, and seconds.
 *
 * @param time A std::chrono::system_clock::time_point representing the time.
 * @return A string representing the formatted time (e.g., "14:30:15").
 */
std::string Date::getTimeStr(std::chrono::system_clock::time_point time){
    auto timeAsInt = std::chrono::system_clock::to_time_t(time);
    auto timeStruct = *std::localtime(&timeAsInt); // converting time to struct

    std::stringstream ss;
    ss << std::setw(2) << std::setfill('0') << timeStruct.tm_hour << ":"
       << std::setw(2) << std::setfill('0') << timeStruct.tm_min << ":"
       << std::setw(2) << std::setfill('0') << timeStruct.tm_sec;

    return ss.str();
}

/**
 * @brief Retrieves the day component of the date.
 *
 * @return An integer representing the day of the month.
 */
int Date::getDay() const{
    return day;
}

/**
 * @brief Retrieves the month component of the date.
 *
 * @return An integer representing the month.
 */
int Date::getMonth() const{
    return month;
}

/**
 * @brief Retrieves the year component of the date.
 *
 * @return An integer representing the year.
 */
int Date::getYear() const{
    return year;
}
