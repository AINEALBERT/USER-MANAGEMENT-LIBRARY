// user_manager.h
#ifndef USER_MANAGER_H
#define USER_MANAGER_H

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

class User {
public:
    std::string name;
    std::string email;
    std::string password; // This could be a plain password
    std::string role;
    bool isActive;

    User(const std::string& name, const std::string& email, const std::string& password, const std::string& role);
};

class UserManager {
private:
    std::vector<User> users;
    std::string userFilePath;

    std::vector<User>::iterator findUserByEmail(const std::string& email);

public:
    UserManager(const std::string& userFilePath);
    ~UserManager();

    User getUserProfile(const std::string& email);
    void displayActiveUsers();
    void changePassword(const std::string& email, const std::string& newPassword);
    void logUserActivity(const std::string& email, const std::string& activity);
    void sendNotificationToActiveUsers(const std::string& subject, const std::string& message);
    void removeInactiveUsers();
    void displayUserRoles();
    void loadUserData();
    void saveUserData();
    void scanDocumentWithCamera(const std::string& userId, const std::string& documentType);
};

#endif // USER_MANAGER_H
