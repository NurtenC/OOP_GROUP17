#pragma once
#include <map>
#include <string>
#include <chrono>
#include "User.h"
#include "Date.h"
#include "Category.h"
#include <cctype>
#include <algorithm>
#include <array>


class ExpenseTracker {
public:
    ExpenseTracker();
    ~ExpenseTracker();

    bool registerUser(const std::string& username, const std::string& password);
    bool login(const std::string& username, const std::string& password);
    void logout();

    std::string getCurrentUsername() const;
    Date* getDate();
    std::chrono::system_clock::time_point getTime()const;
    std::vector<Expense>* getExpenses();
    void updateTime(int time);
    void updateDate(std::chrono::system_clock::time_point time);
    void addExpense(Expense expense);

    static Category getCategory(int index);


private:
    std::map<std::string, User> users;
    User* currentUser;
    Date* date;
    std::vector<Expense>* expenses;
    std::chrono::system_clock::time_point time;
    static std::array<Category,10> categories; 

private:
    bool userExists(const std::string& username) const;
};
