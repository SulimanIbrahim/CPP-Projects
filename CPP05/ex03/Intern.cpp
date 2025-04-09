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

// Form creation methods
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

// Make form method
AForm *Intern::makeForm(const std::string &formName, const std::string &target) const
{
    // Array of form types and their creator functions
    FormType formTypes[3] = {
        {"shrubbery creation", &Intern::createShrubberyCreationForm},
        {"robotomy request", &Intern::createRobotomyRequestForm},
        {"presidential pardon", &Intern::createPresidentialPardonForm}
    };
    
    // Try to find a matching form
    for (int i = 0; i < 3; i++)
    {
        if (formName == formTypes[i].name)
        {
            AForm *form = (this->*formTypes[i].creator)(target);
            std::cout << "Intern creates " << form->getName() << std::endl;
            return form;
        }
    }
    
    // No matching form found
    throw FormNotFoundException();
}

// Exception method
const char *Intern::FormNotFoundException::what() const throw()
{
    return "Form type not found! The intern doesn't know how to create this form.";
} 