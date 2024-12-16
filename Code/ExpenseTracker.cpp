#include "ExpenseTracker.h"

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
    auto it = users.find(username);
    if (it != users.end() && it->second.checkPassword(password)) {
        currentUser = &(it->second);
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

