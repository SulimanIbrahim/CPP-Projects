#include <iostream>
#include <cctype>
#include "Contact.hpp"


#include "Contact.hpp"

Contact::Contact() {
    // Constructor implementation (can be empty)
}

Contact::~Contact() {
    // Destructor implementation (can be empty)
}

int Contact::setFirstName(std::string FirstName)
{
    this->FirstName = FirstName;
    return 0;  // Return an int, which can represent success (e.g., 0)
}

int Contact::setLastName(std::string LastName)
{
    this->LastName = LastName;
    return 0;
}

int Contact::setNickName(std::string NickName)
{
    this->NickName = NickName;
    return 0;
}

int Contact::setPhoneNumber(std::string PhoneNumber)
{
    this->PhoneNumber = PhoneNumber;
    return 0;
}

int Contact::setDarkestSecret(std::string DarkestSecret)
{
    this->DarkestSecret = DarkestSecret;
    return 0;
}

std::string Contact::getFirstName()
{
    return this->FirstName;
}

std::string Contact::getLastName()
{
    return this->LastName;
}

std::string Contact::getNickName()
{
    return this->NickName;
}

std::string Contact::getPhoneNumber()
{
    return this->PhoneNumber;
}

std::string Contact::getDarkestSecret()
{
    return this->DarkestSecret;
}
