#pragma once
#include <string>
#include <vector>

class User {
public:

    User(const std::string& username, const std::string& password);

    std::string getUsername() const;
    bool checkPassword(const std::string& password) const;

private:
    std::string username;
    std::string password;
    
};
