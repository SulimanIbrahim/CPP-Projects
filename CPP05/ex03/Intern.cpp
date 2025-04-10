#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

// Constructors and Destructor
Intern::Intern()
{
    std::cout << "Intern default constructor called" << std::endl;
}

Intern::Intern(const Intern &copy)
{
    std::cout << "Intern copy constructor called" << std::endl;
    *this = copy;
}

Intern &Intern::operator=(const Intern &copy)
{
    std::cout << "Intern assignment operator called" << std::endl;
    // No attributes to copy
    (void)copy;
    return *this;
}

Intern::~Intern()
{
    std::cout << "Intern destructor called" << std::endl;
}

// Form creation methods - these are the "factory" methods for specific form types
AForm *Intern::createShrubberyCreationForm(const std::string &target) const
{
    return new ShrubberyCreationForm(target);
}

AForm *Intern::createRobotomyRequestForm(const std::string &target) const
{
    return new RobotomyRequestForm(target);
}

AForm *Intern::createPresidentialPardonForm(const std::string &target) const
{
    return new PresidentialPardonForm(target);
}

// This is the main factory method that implements the Factory Pattern
AForm *Intern::makeForm(const std::string &formName, const std::string &target) const
{
    // Step 1: Define the mapping between form names and creator methods
    // This is a lookup table that connects string names to member function pointers
    FormType formTypes[3] = {
        {"shrubbery creation", &Intern::createShrubberyCreationForm},
        {"robotomy request", &Intern::createRobotomyRequestForm},
        {"presidential pardon", &Intern::createPresidentialPardonForm}
    };
    
    // Step 2: Find the requested form type in our lookup table
    for (int i = 0; i < 3; i++)
    {
        if (formName == formTypes[i].name)
        {
            // Step 3: Call the appropriate creation method using the function pointer
            // (this->*formTypes[i].creator) is using the member function pointer
            // We're calling the method pointed to by the 'creator' field
            AForm *form = (this->*formTypes[i].creator)(target);
            std::cout << "Intern creates " << form->getName() << std::endl;
            return form;
        }
    }
    
    // Step 4: Handle the case where the requested form type is not found
    // This is where we throw an exception that will be caught in main()
    throw FormNotFoundException();
}

// Exception method
const char *Intern::FormNotFoundException::what() const throw()
{
    return "Form type not found! The intern doesn't know how to create this form.";
} 