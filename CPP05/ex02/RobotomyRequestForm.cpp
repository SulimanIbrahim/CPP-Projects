#include "RobotomyRequestForm.hpp"
#include <unistd.h> // For usleep

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

// Execute method override with enhanced drilling simulation
void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
    // Check if the form is signed and the bureaucrat has enough grade
    if (!this->isSigned())
        throw AForm::FormNotSignedException();
    if (executor.getGrade() > this->getGradeToExecute())
        throw AForm::GradeTooLowException();
    
    // Make drilling noises with visual and audio effects
    std::cout << "\033[1;33m"; // Bright yellow for drilling
    
    // First drilling sequence
    std::cout << "* STARTING ROBOTOMY PROCEDURE *" << std::endl;
    usleep(500000); // 0.5 second pause
    
    std::cout << "* DRILLING NOISES * ";
    for (int i = 0; i < 3; i++) {
        std::cout << "BRR";
        std::cout << '\a'; // Terminal bell
        usleep(300000); // 0.3 second pause
        std::cout << "... ";
        usleep(200000); // 0.2 second pause
    }
    std::cout << "*" << std::endl;
    
    // Second drilling sequence
    std::cout << "* INTENSIFYING DRILL * ";
    for (int i = 0; i < 5; i++) {
        std::cout << "DR-R-R";
        std::cout << '\a'; // Terminal bell
        usleep(200000); // 0.2 second pause
        if (i < 4) std::cout << " ";
    }
    std::cout << " *" << std::endl;
    
    // Final drilling and results
    std::cout << "* FINAL CALIBRATION * ";
    std::cout << "WHIRRRRRR";
    std::cout << '\a' << '\a'; // Multiple bells
    std::cout << " *\n" << std::endl;
    
    std::cout << "\033[0m"; // Reset color
    
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
        std::cout << "\033[1;32m" << this->_target << " has been robotomized successfully! 🤖" << "\033[0m" << std::endl;
    }
    else
    {
        std::cout << "\033[1;31mRobotomy of " << this->_target << " has failed! 💥" << "\033[0m" << std::endl;
    }
} 