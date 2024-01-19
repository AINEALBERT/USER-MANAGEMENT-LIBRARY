#include "user_manager.h"

int main() {
    // Example usage of the UserManager
    try {
        UserManager userManager("path/to/user_data.txt");  // Replace with the actual path to user data file
        userManager.loadUserData();  // Load user data from file (if any)

        // Perform operations on the UserManager
        userManager.displayActiveUsers();
        userManager.displayUserRoles();

        // Example: Change password for a user
        userManager.changePassword("user@example.com", "newPassword");

        // Log user activity
        userManager.logUserActivity("user@example.com", "Logged in");

        // Send notification to active users
        userManager.sendNotificationToActiveUsers("Important Update", "Check your account for important information");

        // Remove inactive users
        userManager.removeInactiveUsers();

        // Save user data to file
        userManager.saveUserData();
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;  // Return an error code
    }

    return 0;  // Return success
}
