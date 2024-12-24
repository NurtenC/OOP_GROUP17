#pragma once
#include "Date.h"
#include <string> 
#include <sstream>

class Income{

public:

    Income(Date date,const std::string& description, double amount);
    
    const Date& getDate()const;
    std::string getCategoryAsString()const;
    double getAmount()const;
    std::string getAmountAsString()const;
    const std::string& getDescription()const;


private:

    Date date;
    std::string description;
    double amount;
};