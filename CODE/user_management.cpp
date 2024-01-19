#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <bcrypt.h>
#include <fstream>

class User {
public:
  std::string name;
  std::string email;
  std::string passwordHash;
  std::string role;
  bool isActive;

  //Attributes

  User(const std::string& name, const std::string& email, const std::string& password, const std::string& role)
    : name(name), email(email), passwordHash(hashPassword(password)), role(role), isActive(true) {}

private:
  std::string hashPassword(const std::string& password) {
    char hashedPassword[BCRYPT_HASHSIZE];
    if (bcrypt_hashpw(password.c_str(), BCRYPT_COST, nullptr, hashedPassword, BCRYPT_HASHSIZE) != 0) {
      throw std::runtime_error("Error hashing password.");
    }
    return std::string(hashedPassword);
  }
};

class UserManager {
private:
  std::vector<User> users;
  std::string userFilePath;

public:
  // Function to get a user's profile
  User getUserProfile(const std::string& email) {
    auto it = findUserByEmail(email);
    if (it == users.end()) {
      throw std::runtime_error("User not found.");
    }
    return *it;
  }

  // Function to display all active users
  void displayActiveUsers() {
    for (const auto& user : users) {
      if (user.isActive) {
        std::cout << "Name: " << user.name << ", Email: " << user.email << ", Role: " << user.role << std::endl;
      }
    }
  }

  // Function to change a user's password
  void changePassword(const std::string& email, const std::string& newPassword) {
    auto it = findUserByEmail(email);
    if (it == users.end()) {
      throw std::runtime_error("User not found.");
    }
    it->passwordHash = hashPassword(newPassword);
    saveUserData();
  }

  // Function to log user activity
  void logUserActivity(const std::string& email, const std::string& activity) {
    std::cout << "User '" << email << "' performed activity: " << activity << std::endl;
  }

  // Function to send a notification to all active users
  void sendNotificationToActiveUsers(const std::string& subject, const std::string& message) {
    for (const auto& user : users) {
      if (user.isActive) {
        sendEmailNotification(user.email, subject, message);
      }
    }
  }

  // Function to permanently remove inactive users
  void removeInactiveUsers() {
    auto it = std::remove_if(users.begin(), users.end(), [](const User& user) {
      return !user.isActive;
    });
    users.erase(it, users.end());
    saveUserData();
  }

  // Function to display user roles
  void displayUserRoles() {
    std::unordered_map<std::string, int> roleCount;
    for (const auto& user : users) {
      roleCount[user.role]++;
    }
    for (const auto& entry : roleCount) {
      std::cout << "Role: " << entry.first << ", Count: " << entry.second << std::endl;
    }
  }

  // Data persistence
  void loadUserData() {
    // Read user data from file (if used)
  }

  void saveUserData() {
    // Write user data to file (if used)
  }
};
