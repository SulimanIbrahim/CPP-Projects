#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <cstdlib>  // For rand() and srand()
#include <ctime>    // For time()

class RobotomyRequestForm : public AForm
{
private:
    std::string _target;

public:
    // Orthodox Canonical Form
    RobotomyRequestForm();
    RobotomyRequestForm(const std::string &target);
    RobotomyRequestForm(const RobotomyRequestForm &copy);
    RobotomyRequestForm &operator=(const RobotomyRequestForm &copy);
    ~RobotomyRequestForm();

    // Getters
    std::string getTarget() const;

    // Execute method override
    void execute(Bureaucrat const &executor) const;
};

#endif 