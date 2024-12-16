#pragma once
#include <map>
#include <string>
#include "User.h"

class ExpenseTracker {
public:
    ExpenseTracker() = default;

    bool registerUser(const std::string& username, const std::string& password);
    bool login(const std::string& username, const std::string& password);
    void logout();

    std::string getCurrentUsername() const;

private:
    std::map<std::string, User> users;
    User* currentUser = nullptr;

private:
    bool userExists(const std::string& username) const;
};
