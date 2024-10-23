
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

static bool containsNonAlpha(std::string str) {
    for (int i = 0; i < (int)str.length(); i++) {
        if (!isalpha(str[i])) {
            return true;
        }
    }
    return false;
}

static bool containsNonNumeric(std::string str) {
    for (int i = 0; i < (int)str.length(); i++) {
        if (!isdigit(str[i])) {
            return true;
        }
    }
    return false;
}

static void enterFirstName(std::string input, Contact *contact) {
    do {
        std::cout << "1 - Enter first name: ";
        std::getline(std::cin, input);
        if (std::cin.eof()) {
            std::cout << "\033[1;31mEOF detected.\033[0m" << std::endl;
            return ;
        }
        if (input.empty()) {
            std::cout << "\033[1;31mFirst name cannot be empty.\033[0m" << std::endl;
        } else if (containsNonAlpha(input)) {
            std::cout << "\033[1;31mFirst name must contain only alphabetic characters.\033[0m" << std::endl;
        } else if (input.length() > 30) {
            std::cout << "\033[1;31mFirst name must be less than 30 characters.\033[0m" << std::endl;
        }
    } while (input.empty() || containsNonAlpha(input) || input.length() > 30);
    contact->setFirstName(input);
}

static void enterLastName(std::string input, Contact *contact) {
    do {
        std::cout << "2 - Enter last name: ";
        std::getline(std::cin, input);
        if (std::cin.eof()) {
            std::cout << "\033[1;31mEOF detected.\033[0m" << std::endl;
            return ;
        }
        if (input.empty()) {
            std::cout << "\033[1;31mLast name cannot be empty.\033[0m" << std::endl;
        } else if (containsNonAlpha(input)) {
            std::cout << "\033[1;31mLast name must contain only alphabetic characters.\033[0m" << std::endl;
        } else if (input.length() > 30) {
            std::cout << "\033[1;31mLast name must be less than 30 characters.\033[0m" << std::endl;
        }
    } while (input.empty() || containsNonAlpha(input) || input.length() > 30);
    contact->setLastName(input);
}

static void enterNickName(std::string input, Contact *contact) {
     do {
        std::cout << "3 - Enter nickname: ";
        std::getline(std::cin, input);
        if (std::cin.eof()) {
            std::cout << "\033[1;31mEOF detected.\033[0m" << std::endl;
            return ;
        }
        if (input.empty()) {
            std::cout << "\033[1;31mNickname cannot be empty.\033[0m" << std::endl;
        } else if (input.length() > 30) {
            std::cout << "\033[1;31mNickname must be less than 30 characters.\033[0m" << std::endl;
        }
    } while (input.empty() || input.length() > 30);
    contact->setNickName(input);
}

static void enterPhoneNumber(std::string input, Contact *contact) {
     do {
        std::cout << "4 - Enter phone number: ";
        std::getline(std::cin, input);
        if (std::cin.eof()) {
            std::cout << "\033[1;31mEOF detected.\033[0m" << std::endl;
            return ;
        }
        if (input.empty()) {
            std::cout << "\033[1;31mPhone number cannot be empty.\033[0m" << std::endl;
        } else if (input.length() > 17 || input.length() < 4) {
            std::cout << "\033[1;31mPhone number must be between 4 and 17 numbers.\033[0m" << std::endl;
        } else if (containsNonNumeric(input)) {
            std::cout << "\033[1;31mPhone number must contain only numeric characters.\033[0m" << std::endl;
        }
    } while (input.empty() || input.length() > 17 
    || input.length() < 4 || containsNonNumeric(input));
        contact->setPhoneNumber(input);

}

static void enterDarkestSecret(std::string input, Contact *contact) {
    do {
        std::cout << "5 - Enter darkest secret: ";
        std::getline(std::cin, input);
        if (std::cin.eof()) {
            std::cout << "\033[1;31mEOF detected.\033[0m" << std::endl;
            return ;
        }
        if (input.empty()) {
            std::cout << "\033[1;31mDarkest secret cannot be empty.\033[0m" << std::endl;
        } else if (input.length() > 200) {
            std::cout << "\033[1;31mDarkest secret must be less than 200 characters.\033[0m" << std::endl;
        }
    } while (input.empty() || input.length() > 200);
        contact->setDarkestSecret(input);

}

void PhoneBook::addContact() {

    Contact contact;
    std::string input;
    enterFirstName(input, &contact);
    enterLastName(input, &contact);
    enterNickName(input, &contact);
    enterPhoneNumber(input, &contact);
    enterDarkestSecret(input, &contact);
    if (this->contactCount == 7){
        std::cout << YELLOW "Warning:" RESET<< std::endl;
        std::cout << "Phonebook is full, if you added a contact the oldest contact will be replaced" << std::endl;
        std::cout << std::endl;
    }
    if (this->contactCount > 7)
        std::cout << GREEN "Contact number (" << this->contactCount << ") added successfully ✅" RESET << std::endl;
    else
        std::cout << GREEN "Contact number (" << this->contactCount + 1 << ") added successfully ✅" RESET << std::endl;
    if (this->contactCount > 7){
        std::cout << "\033[1;33m The oldest contact has been replaced \033[0m" << std::endl;
        std::cout << std::endl;
        this->contacts[oldestIndex] = contact;
                oldestIndex++;
            if (oldestIndex > 7) {
                oldestIndex = 0;
            }
    } else {
        this->contacts[this->contactCount] = contact;
        this->contactCount++;
    }
}

void PhoneBook::searchContact() {
    if (this->contactCount == 0) {
        std::cout << "Phonebook is empty." << std::endl;
        return;
    }
    std::cout << std::endl;
    std::cout << GREEN << "------------------------------------------------------" << RESET << std::endl;
    std::cout << BLUE << "     Index|First Name| Last Name|  Nickname|" << RESET << std::endl;
    for (int i = 0; i < this->contactCount; i++) {
        Contact contact = this->contacts[i];
        std::cout << "         " << i << "|";
        std::string firstName = contact.getFirstName();
        if (firstName.length() > 10) {
            firstName = firstName.substr(0, 9) + ".";
        }
        std::cout << std::setw(10) << std::right << firstName << "|";
        std::string lastName = contact.getLastName();
        if (lastName.length() > 10) {
            lastName = lastName.substr(0, 9) + ".";
        }
        std::cout << std::setw(10) << std::right << lastName << "|";
        std::string nickName = contact.getNickName();
        if (nickName.length() > 10) {
            nickName = nickName.substr(0, 9) + ".";
        }
        std::cout << std::setw(10) << std::right << nickName << "|" << std::endl;
    }
    std::cout << GREEN << "------------------------------------------------------" << RESET << std::endl;

int index;
std::string input;
do {
    std::cout << "Enter the index of the contact to view details: ";
    std::getline(std::cin, input);
    if (std::cin.eof()) {
            std::cout << "\033[1;31mEOF detected.\033[0m" << std::endl;
            return ;
    }
    std::istringstream iss(input);

    if (input.empty() || !isdigit(input[0])) {
        std::cout << "\033[1;31mInvalid index.\033[0m" << std::endl;
        continue;
    }

    if (iss >> index) {
        if (index >= 0 && index < this->contactCount) {
            break;
        } else {
            std::cout << "\033[1;31mInvalid index.\033[0m" << std::endl;
        }
    } else {
        std::cout << "\033[1;31mInvalid index.\033[0m" << std::endl;
    }
} while (true);

Contact contact = this->contacts[index];
std::cout << BLUE"Contact details: " RESET <<" ------------------------------------>" << std::endl;
std::cout << "First Name     :" << GREEN << contact.getFirstName() << RESET << std::endl;
std::cout << "Last Name      :" << GREEN << contact.getLastName() << RESET << std::endl;
std::cout << "Nickname       :"<< GREEN << contact.getNickName() << RESET<<std::endl;
std::cout << "Phone Number   :"<< GREEN << contact.getPhoneNumber() << RESET<<std::endl;
std::cout << "Darkest Secret :"<< GREEN << contact.getDarkestSecret() << RESET<<std::endl;
std::cout << "------------------------------------------------------" << std::endl;
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