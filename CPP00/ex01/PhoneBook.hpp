#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#define RESET   "\033[0m"
#define RED     "\033[1;31m"
#define GREEN   "\033[1;32m"
#define YELLOW  "\033[1;33m"
#define BLUE    "\033[1;34m"
#include "Contact.hpp"

class PhoneBook {
private:
    int         contactCount;
    int  oldestIndex;
    Contact contacts[8];
public:
    PhoneBook();
    ~PhoneBook();
    void runPhoneBook(PhoneBook phonebook);
    void addContact();
    void searchContact();
    
};

#endif