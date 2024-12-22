#pragma once
#include <map>
#include <string>
#include <chrono>
#include "User.h"
#include "Date.h"


class ExpenseTracker {
public:
    ExpenseTracker();
    ~ExpenseTracker();

    bool registerUser(const std::string& username, const std::string& password);
    bool login(const std::string& username, const std::string& password);
    void logout();

    std::string getCurrentUsername() const;
    Date* getDate()const;
    std::chrono::system_clock::time_point getTime()const;
    void updateTime(int time);
    void updateDate(std::chrono::system_clock::time_point time);



private:
    std::map<std::string, User> users;
    User* currentUser;
    Date* date;
    std::chrono::system_clock::time_point time;

private:
    bool userExists(const std::string& username) const;
};
