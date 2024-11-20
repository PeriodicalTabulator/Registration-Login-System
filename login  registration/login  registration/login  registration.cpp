

#include <iostream>
#include <string>
#include <functional>
#include <unordered_map>

void registration(std::unordered_map<std::string, std::string>& users) {
	std::string username, password;

	std::cout << "Enter username: ";
	std::cin >> username;

	// Check if the username already exists
	if (users.find(username) != users.end()) {
		std::cout << "Username already exists. Please try another one.\n";
		return;
	}

	std::cout << "Enter password: ";
	std::cin >> password;

	// Store the username and password
	users[username] = password;
	std::cout << "User registered successfully!\n";
}

void login(const std::unordered_map<std::string, std::string>& users) {
	std::string username, password;

	std::cout << "Enter username: ";
	std::cin >> username;
	std::cout << "Enter password: ";
	std::cin >> password;

	// Verify the username and password
	auto it = users.find(username);
	if (it != users.end() && it->second == password) {
		std::cout << "Login successful!\n";
	}
	else {
		std::cout << "Invalid username or password. Please try again.\n";
	}
}


int main() {
	int answer;
	std::unordered_map<std::string, std::string> users;
	do {
		std::cout << "1. Login\n2. Register\n3. Exit\nEnter your choice: ";
		std::cin >> answer;
		switch (answer)
		{
		case(1):
			login(users);
			break;
		case(2):
			registration(users);
			break;
		case(3):
			std::cout << ("GOODBYE \n");
			break;
		default:
			std::cout << ("Invalid choice choose another \n");
			break;
		}
	} while (answer != 3);
	return 0;
	
}

