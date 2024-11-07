#include <iostream>
#include "PhoneBook.hpp"
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