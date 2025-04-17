#include "PresidentialPardonForm.hpp"

// Constructors and Destructor
PresidentialPardonForm::PresidentialPardonForm() 
    : AForm("Presidential Pardon Form", 25, 5), _target("default")
{
    std::cout << "PresidentialPardonForm default constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) 
    : AForm("Presidential Pardon Form", 25, 5), _target(target)
{
    std::cout << "PresidentialPardonForm parameterized constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy)
    : AForm(copy), _target(copy._target)
{
    std::cout << "PresidentialPardonForm copy constructor called" << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &copy)
{
    std::cout << "PresidentialPardonForm assignment operator called" << std::endl;
    if (this != &copy)
    {
        AForm::operator=(copy);
        this->_target = copy._target;
    }
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
    std::cout << "PresidentialPardonForm destructor called" << std::endl;
}

// Getters
std::string PresidentialPardonForm::getTarget() const
{
    return this->_target;
}

// Execute method override with enhanced visual presentation
void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
    // Check if the form is signed and the bureaucrat has enough grade
    if (!this->isSigned())
        throw AForm::FormNotSignedException();
    if (executor.getGrade() > this->getGradeToExecute())
        throw AForm::GradeTooLowException();
    
    std::cout << "\033[1;36m";
    std::cout << "\n┌─────────────────────────────────────────────────┐" << std::endl;
    std::cout << "│                                                 │" << std::endl;
    std::cout << "│             PRESIDENTIAL PARDON                 │" << std::endl;
    std::cout << "│                                                 │" << std::endl;
    std::cout << "│  By the authority vested in the President of    │" << std::endl;
    std::cout << "│  the Galaxy, I, Zaphod Beeblebrox, do hereby    │" << std::endl;
    std::cout << "│  grant a full and unconditional pardon to:      │" << std::endl;
    std::cout << "│                                                 │" << std::endl;
    std::cout << "│           \033[1;33m" << _target << "\033[1;36m |" << std::endl;
    std::cout << "│                                                 │" << std::endl;
    std::cout << "│  For all offenses against the Galactic Empire   │" << std::endl;
    std::cout << "│  which have been or may be charged or alleged.  │" << std::endl;
    std::cout << "│                                                 │" << std::endl;
    std::cout << "│                             Sincerely,          │" << std::endl;
    std::cout << "│                        \033[1;35mZaphod Beeblebrox\033[1;36m       │" << std::endl;
    std::cout << "│                    \033[3mPresident of the Galaxy\033[0;1;36m      │" << std::endl;
    std::cout << "│                                                 │" << std::endl;
    std::cout << "└─────────────────────────────────────────────────┘\033[0m" << std::endl;
} 