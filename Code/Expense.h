#pragma once
#include "Category.h"
#include "Date.h"
#include <string> 
#include <sstream>

class Expense{

public:

    Expense(Date date, Category category, const std::string& description, double amount);
    
    const Date& getDate()const;
    Category getCategory()const;
    std::string getCategoryAsString()const;
    double getAmount()const;
    std::string getAmountAsString()const;
    const std::string& getDescription()const;


private:

    Date date;
    Category category;
    std::string description;
    double amount;
};