
#include "Date.h"
#include <sstream>
#include <iomanip>
#include <chrono>
#include <ctime>


Date::Date(std::chrono::system_clock::time_point time){
    auto timeAsInt = std::chrono::system_clock::to_time_t(time);
    auto timeStruct = *std::localtime(&timeAsInt); // converting time to struct
    day = timeStruct.tm_mday;
    month = timeStruct.tm_mon + 1;
    year = timeStruct.tm_year + 1900;
}

std::string Date::getDateString() const{
    std::stringstream ss;
    ss << std::setw(2) << std::setfill('0') << day << '/'
       << std::setw(2) << std::setfill('0') << month << '/'
       << year;
    return ss.str();
}


std::string Date::getTimeStr(std::chrono::system_clock::time_point time){
    auto timeAsInt = std::chrono::system_clock::to_time_t(time);
    auto timeStruct = *std::localtime(&timeAsInt); // converting time to struct

    std::stringstream ss;
    ss << std::setw(2) << std::setfill('0') << timeStruct.tm_hour << ":"
       << std::setw(2) << std::setfill('0') << timeStruct.tm_min << ":"
       << std::setw(2) << std::setfill('0') << timeStruct.tm_sec;

    return ss.str();
}


int Date::getDay() const{
    return day;
}


int Date::getMonth() const{
    return month;
}


int Date::getYear() const{
    return year;
}
