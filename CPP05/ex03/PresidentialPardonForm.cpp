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

// Execute method override
void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
    // Check if the form is signed and the bureaucrat has enough grade
    if (!this->isSigned())
        throw AForm::FormNotSignedException();
    if (executor.getGrade() > this->getGradeToExecute())
        throw AForm::GradeTooLowException();
    
    // Inform that the target has been pardoned
    std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
} 