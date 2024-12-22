#pragma once 
#include <chrono>
#include <string>
#include <sstream> 
#include <iomanip>
#include <ctime>

class Date{

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