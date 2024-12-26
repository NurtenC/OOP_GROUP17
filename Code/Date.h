#pragma once 
#include <chrono>
#include <string>
#include <sstream> 
#include <iomanip>
#include <ctime>

class Date{
    Date(const std::string& dateStr) {
        std::istringstream ss(dateStr);
        char delimiter;
        ss >> day >> delimiter >> month >> delimiter >> year;
        if (ss.fail() || delimiter != '/' || day <= 0 || month <= 0 || year <= 0) {
            throw std::invalid_argument("Invalid date format. Expected format: DD/MM/YYYY");
        }
    }

private:

    int day;
    int month;
    int year;

public: 
//cpp time library
    Date(std::chrono::system_clock::time_point time);
    
    std::string getDateString()const;
    int getDay()const;
    int getMonth()const;
    int getYear()const;
    static std::string getTimeStr(std::chrono::system_clock::time_point time);


};
