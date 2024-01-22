#include <iostream>
#include <unordered_map>
#include <string>
#include <functional>

std::unordered_map<std::string, std::string> userDatabase;

bool createUser(const std::string& username, const std::string& password) {
    if (userDatabase.find(username) == userDatabase.end()) {
        std::hash<std::string> hasher;
        userDatabase[username] = std::to_string(hasher(password));
        return true;
    }
    return false; // Username already exists
}

bool authenticateUser(const std::string& username, const std::string& password) {
    auto it = userDatabase.find(username);
    if (it != userDatabase.end()) {
        std::hash<std::string> hasher;
        return it->second == std::to_string(hasher(password));
    }
    return false; // Username not found
}

size_t hashPassword(const std::string& password) {
    std::hash<std::string> hasher;
    return hasher(password);
}

void listUsers() {  //Passwords are stored as hash! So nothing will be readable
    for (const auto& user : userDatabase) {
        std::cout << "Username: " << user.first << ", Password: " << user.second << std::endl;
    }
}

void changePassword(const std::string& username, const std::string& newPassword) {
    std::hash<std::string> hasher;
    userDatabase[username] = std::to_string(hasher(newPassword));
}

int main() {
    int choice = 0;
    std::string username, password;

    do {
        std::cout << "Choose an option:\n1. Register\n2. Log-In\n3. List Users\n4. Change Password\n5. Exit\n";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Enter username: ";
                std::cin >> username;
                if (userDatabase.find(username) != userDatabase.end()){
                    std::cout<<"Username already exists!\n";
                    break;
                }
                std::cout << "Enter password: ";
                std::cin >> password;
                if (createUser(username, password)) {
                    std::cout << "Registration successful!\n";
                } else {
                    std::cout << "Username already exists!\n";
                }
                break;
            case 2:
                std::cout << "Enter username: ";
                std::cin >> username;
                std::cout << "Enter password: ";
                std::cin >> password;
                if (authenticateUser(username, password)) {
                    std::cout << "Login successful!\n";
                    if (username == "admin") {
                        listUsers();
                    } else {
                        int changePassChoice = 0;
                        std::cout << "Do you want to change your password? (1 for Yes, 0 for No): ";
                        std::cin >> changePassChoice;
                        if (changePassChoice == 1) {
                            std::string newPass;
                            std::cout << "Enter new password: ";
                            std::cin >> newPass;
                            changePassword(username, newPass);
                            std::cout << "Password changed successfully!\n";
                        }
                    }
                } else {
                    std::cout << "Login failed!\n";
                }
                break;
            case 3:
                listUsers();
                break;
            case 4:
                std::cout << "Enter username: ";
                std::cin >> username;
                std::cout << "Enter new password: ";
                std::cin >> password;
                changePassword(username, password);
                std::cout << "Password changed successfully!\n";
                break;
            case 5:
                std::cout << "Exiting...\n";
                break;
            default:
                std::cout << "Invalid choice!\n";
                break;
        }
    } while (choice != 5);

    return 0;
}
