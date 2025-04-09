#include "RobotomyRequestForm.hpp"

// Constructors and Destructor
RobotomyRequestForm::RobotomyRequestForm() 
    : AForm("Robotomy Request Form", 72, 45), _target("default")
{
    std::cout << "RobotomyRequestForm default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) 
    : AForm("Robotomy Request Form", 72, 45), _target(target)
{
    std::cout << "RobotomyRequestForm parameterized constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy)
    : AForm(copy), _target(copy._target)
{
    std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &copy)
{
    std::cout << "RobotomyRequestForm assignment operator called" << std::endl;
    if (this != &copy)
    {
        AForm::operator=(copy);
        this->_target = copy._target;
    }
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout << "RobotomyRequestForm destructor called" << std::endl;
}

// Getters
std::string RobotomyRequestForm::getTarget() const
{
    return this->_target;
}

// Execute method override
void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
    // Check if the form is signed and the bureaucrat has enough grade
    if (!this->isSigned())
        throw AForm::FormNotSignedException();
    if (executor.getGrade() > this->getGradeToExecute())
        throw AForm::GradeTooLowException();
    
    // Make drilling noises
    std::cout << "* DRILLING NOISES * BRR... BRR... BRR... *" << std::endl;
    
    // Seed the random number generator
    static bool seeded = false;
    if (!seeded)
    {
        std::srand(std::time(NULL));
        seeded = true;
    }
    
    // 50% chance of success
    if (std::rand() % 2)
    {
        std::cout << this->_target << " has been robotomized successfully!" << std::endl;
    }
    else
    {
        std::cout << "Robotomy of " << this->_target << " has failed!" << std::endl;
    }
} 