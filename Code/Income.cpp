

#include "Income.h"
#include <sstream>


Income::Income(Date date, const std::string& description, double amount) 
    : date{date}, description{description}, amount{amount}
{
}

const Date &Income::getDate() const
{
    return date;
}


double Income::getAmount() const
{
    return amount;
}


std::string Income::getAmountAsString() const
{
    std::stringstream ss;
    ss << "$" << amount;
    return ss.str();
}


const std::string &Income::getDescription() const
{
    return description;
}
