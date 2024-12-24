#include "ExpenseTracker.h"

ExpenseTracker::ExpenseTracker(){

    currentUser = nullptr;
    expenses = nullptr;
    time = std::chrono::system_clock::now();
    date = new Date(time);
}

ExpenseTracker::~ExpenseTracker(){

    delete date;
}

bool ExpenseTracker::userExists(const std::string& username) const {

    return users.find(username) != users.end();
}

bool ExpenseTracker::registerUser(const std::string& username, const std::string& password) {

    if (userExists(username)) {

        return false;
    }
    users.emplace(username, User(username, password));
    return true;
}

bool ExpenseTracker::login(const std::string& username, const std::string& password) {

    auto iterator = users.find(username);
    if (iterator != users.end() && iterator->second.checkPassword(password)) {

        currentUser = &(iterator->second);
        return true;
    }
    return false;
}

void ExpenseTracker::logout() {

    currentUser = nullptr;
}

std::string ExpenseTracker::getCurrentUsername() const {

    if (currentUser) {
        
        return currentUser->getUsername();
    }
    return "";
}

Date* ExpenseTracker::getDate(){

    return date;
}

std::chrono::system_clock::time_point ExpenseTracker::getTime()const{

    return time;
}

std::vector<Expense> *ExpenseTracker::getExpenses()
{
    if(currentUser){
        return currentUser->getExpenses();
    }
    return nullptr;
}

void ExpenseTracker::updateTime(int time){
    this->time += std::chrono::seconds(time);
    
}

void ExpenseTracker::updateDate(std::chrono::system_clock::time_point time){

    delete date;
    date = new Date(time);
}

void ExpenseTracker::addExpense(Expense expense)
{
    currentUser->addExpense(expense);
}

Category ExpenseTracker::getCategory(int index)
{
    return categories[index];
}

std::array<Category, 10> ExpenseTracker::categories = {
    Category::GROCERY,
    Category::HEALTH,
    Category::ENTERTAINMENT,
    Category::EDUCATION,
    Category::TRANSPORTATION,
    Category::PERSONAL_CARE,
    Category::CLOTHES,
    Category::TAX,
    Category::BILL,
    Category::RENT,
};