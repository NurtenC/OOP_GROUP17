
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

    bool registerUser(const std::string& username, const std::string& password, double budget);
    bool login(const std::string& username, const std::string& password);
    void logout();

    std::string getCurrentUsername()const;
    std::string getBudgetAsString() const;
    Date* getDate();
    std::chrono::system_clock::time_point getTime()const;
    std::vector<Expense>* getExpenses();
    std::vector<Income>* getIncomes();
    void updateTime(int time);
    void updateDate(std::chrono::system_clock::time_point time);
    void addExpense(Expense expense);
    void addIncome(Income income);
    bool updateCurrentUserInfo(std::string& username, const std::string& password, double budget);
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
