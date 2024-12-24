#include "Expense.h"

Expense::Expense(Date date, Category category, const std::string& description, double amount) : date{date}
{
    this->description = description;
    this->category = category;
    this->amount = amount;
    
}

const Date &Expense::getDate() const
{
   return date;
}

Category Expense::getCategory() const
{
    return category;
}

std::string Expense::getCategoryAsString() const
{
    switch(category){
        case Category::GROCERY:
            return "Grocery";
        case Category::HEALTH:
            return "Health";
        case Category::ENTERTAINMENT:
            return "Entertainment";
        case Category::EDUCATION:
            return "Education";
        case Category::TRANSPORTATION:
            return "Transportation";
        case Category::PERSONAL_CARE:
            return "Personal Care";
        case Category::CLOTHES:
            return "Clothes";
        case Category::TAX:
            return "Tax";
        case Category::BILL:
            return "Bill";
        case Category::RENT:
            return "Rent";
        default:
            return "Error!";
    }
}

double Expense::getAmount() const
{
    return amount;
}

std::string Expense::getAmountAsString() const
{
    std::stringstream ss;
    ss<< "$" << amount;
    return ss.str();
}

const std::string &Expense::getDescription() const
{
    return description;
}
