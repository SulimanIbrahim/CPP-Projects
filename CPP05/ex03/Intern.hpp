#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include <string>

class Intern
{
private:
    // Function pointer type for form creators
    typedef AForm *(Intern::*FormCreator)(const std::string &target) const;
    
    // Form creation methods
    AForm *createShrubberyCreationForm(const std::string &target) const;
    AForm *createRobotomyRequestForm(const std::string &target) const;
    AForm *createPresidentialPardonForm(const std::string &target) const;
    
    // Structure to map form names to creator functions
    struct FormType
    {
        std::string name;
        FormCreator creator;
    };

public:
    // Orthodox Canonical Form
    Intern();
    Intern(const Intern &copy);
    Intern &operator=(const Intern &copy);
    ~Intern();

    // Form creation method
    AForm *makeForm(const std::string &formName, const std::string &target) const;
    
    // Custom exception
    class FormNotFoundException : public std::exception
    {
    public:
        virtual const char *what() const throw();
    };
};

#endif 