// user_manager.cpp
#include "user_manager.h"
#include <algorithm>
#include <opencv2/opencv.hpp>

User::User(const std::string& name, const std::string& email, const std::string& password, const std::string& role)
    : name(name), email(email), password(password), role(role), isActive(true) {}

std::vector<User>::iterator UserManager::findUserByEmail(const std::string& email) {
    return std::find_if(users.begin(), users.end(), [&](const User& user) {
        return user.email == email;
    });
}

UserManager::UserManager(const std::string& userFilePath)
    : userFilePath(userFilePath) {
    loadUserData();
}

UserManager::~UserManager() {
    saveUserData();
}

User UserManager::getUserProfile(const std::string& email) {
    auto it = findUserByEmail(email);
    if (it == users.end()) {
        throw std::runtime_error("User not found.");
    }
    return *it;
}

void UserManager::displayActiveUsers() {
    for (const auto& user : users) {
        if (user.isActive) {
            std::cout << "Name: " << user.name << ", Email: " << user.email << ", Role: " << user.role << std::endl;
        }
    }
}

void UserManager::changePassword(const std::string& email, const std::string& newPassword) {
    auto it = findUserByEmail(email);
    if (it == users.end()) {
        throw std::runtime_error("User not found.");
    }
    it->password = newPassword; // Update password directly
    saveUserData();
}

void UserManager::logUserActivity(const std::string& email, const std::string& activity) {
    std::cout << "User '" << email << "' performed activity: " << activity << std::endl;
}

void UserManager::sendNotificationToActiveUsers(const std::string& subject, const std::string& message) {
    // sending of notifications (e.g., email)
}

void UserManager::removeInactiveUsers() {
    auto it = std::remove_if(users.begin(), users.end(), [](const User& user) {
        return !user.isActive;
    });
    users.erase(it, users.end());
    saveUserData();
}

void UserManager::displayUserRoles() {
    std::unordered_map<std::string, int> roleCount;
    for (const auto& user : users) {
        roleCount[user.role]++;
    }
    for (const auto& entry : roleCount) {
        std::cout << "Role: " << entry.first << ", Count: " << entry.second << std::endl;
    }
}

void UserManager::loadUserData() {
    // Read user data from file.
}

void UserManager::saveUserData() {
    // Write user data to file (if used)
}

void UserManager::scanDocumentWithCamera(const std::string& userId, const std::string& documentType) {
    cv::VideoCapture capture(0);

    if (!capture.isOpened()) {
        std::cerr << "Error: Unable to open the camera." << std::endl;
        return;
    }

    cv::Mat frame;
    capture >> frame;

    // Processing the captured frame (e.g., saving, analyzing)
    cv::imshow("Document Scan", frame);
    cv::waitKey(0);

    capture.release();
}
