#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include "PhoneBook.hpp"

void PhoneBook::displayContactList() const {
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
}

int PhoneBook::getValidContactIndex() const {
    int index;
    std::string input;
    while (true) {
        std::cout << "Enter the index of the contact to view details: ";
        std::getline(std::cin, input);
        
        if (std::cin.eof()) {
            std::cout << "\033[1;31mEOF detected.\033[0m" << std::endl;
            return -1;
        }

        if (input.empty() || !isdigit(input[0])) {
            std::cout << "\033[1;31mInvalid index.\033[0m" << std::endl;
            continue;
        }

        std::istringstream iss(input);
        if (iss >> index && index >= 0 && index < this->contactCount) {
            break;
        } else {
            std::cout << "\033[1;31mInvalid index.\033[0m" << std::endl;
        }
    }
    return index;
}

void PhoneBook::displayContactDetails(Contact& contact) const {
    std::cout << BLUE"Contact details: " RESET <<" ------------------------------------>" << std::endl;
    std::cout << "First Name     :" << GREEN << contact.getFirstName() << RESET << std::endl;
    std::cout << "Last Name      :" << GREEN << contact.getLastName() << RESET << std::endl;
    std::cout << "Nickname       :" << GREEN << contact.getNickName() << RESET << std::endl;
    std::cout << "Phone Number   :" << GREEN << contact.getPhoneNumber() << RESET << std::endl;
    std::cout << "Darkest Secret :" << GREEN << contact.getDarkestSecret() << RESET << std::endl;
    std::cout << "------------------------------------------------------" << std::endl;
}

void PhoneBook::searchContact() {
    if (this->contactCount == 0) {
        std::cout << "Phonebook is empty." << std::endl;
        return;
    }
    displayContactList();
    int index = getValidContactIndex();
    if (index == -1) 
        return;
    Contact contact = this->contacts[index];
    displayContactDetails(contact);
}

