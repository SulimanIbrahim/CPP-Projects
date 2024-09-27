#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>


class Contact {
private:
    std::string FirstName;
    std::string LastName;
    std::string NickName;
    std::string PhoneNumber;
    std::string DarkestSecret;
public:
    // constructors and destructors
    Contact();
    ~Contact();
    // setters
    int setFirstName(std::string FirstName);
    int setLastName(std::string LastName);
    int setNickName(std::string NickName);
    int setPhoneNumber(std::string PhoneNumber);
    int setDarkestSecret(std::string DarkestSecret);
    // getters
    std::string getFirstName();
    std::string getLastName();
    std::string getNickName();
    std::string getPhoneNumber();
    std::string getDarkestSecret();
};

#endif