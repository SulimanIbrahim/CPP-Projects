
#include <iostream>
#include <string>
#include <sstream> // Include this header for std::istringstream
#include <cctype>  // Include this header for std::isdigit
#include <iomanip>  // aaahh for setw, right, etc.
#include "PhoneBook.hpp"

PhoneBook::PhoneBook() {
    contactCount = 0;
    oldestIndex = 0;
}

PhoneBook::~PhoneBook() {
}

void PhoneBook::runPhoneBook(PhoneBook phonebook) {
    std::cout << "\033[1;32m                 PHONEBOOK              \033[0m" << std::endl;
    std::cout << "\033[1;33m Available commands: ADD, SEARCH, EXIT \033[0m" << std::endl;
    std::cout << YELLOW "  ADD : Add a new contact" << std::endl;
    std::cout << YELLOW "  SEARCH : Search for a contact" << std::endl;
    std::cout << YELLOW "  EXIT : Exit the phonebook" << std::endl;
    std::cout << GREEN"--------------------------------------" RESET << std::endl;
    while (1) {
        std::string line;
        std::cout << "\033[1;34m Enter command: \033[0m";
        std::getline(std::cin, line);
        if (std::cin.eof()) {
                return ;
            }
        for (int i = 0; i < (int)line.length(); i++) {
            line[i] = toupper(line[i]);
        }
        std::string command = line;
        if (command == "ADD") {
            phonebook.addContact();
        } else if (command == "SEARCH") {
            phonebook.searchContact();
        } else if (command == "EXIT") {
            std::cout << "Exiting..." << std::endl;
            break;
        } else {
            std::cout << "\033[1;31m Invalid command. Please try again. \033[0m" << std::endl;
            std::cout << YELLOW " Only (ADD, SEARCH, EXIT) are valid" RESET << std::endl;
        }
    }
}