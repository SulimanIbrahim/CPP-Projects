#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include <iostream>

int main()
{
    std::cout << "===== Intern Tests =====" << std::endl;
    try
    {
        Intern someRandomIntern;
        
        // Create different forms using the intern
        AForm *shrubForm = someRandomIntern.makeForm("shrubbery creation", "Park");
        AForm *robotForm = someRandomIntern.makeForm("robotomy request", "Bender");
        AForm *pardonForm = someRandomIntern.makeForm("presidential pardon", "Prisoner");
        
        // Create a bureaucrat to sign and execute the forms
        Bureaucrat boss("Big Boss", 1);
        
        std::cout << "\n-- Testing Shrubbery Creation Form --" << std::endl;
        std::cout << *shrubForm << std::endl;
        boss.signForm(*shrubForm);
        boss.executeForm(*shrubForm);
        
        std::cout << "\n-- Testing Robotomy Request Form --" << std::endl;
        std::cout << *robotForm << std::endl;
        boss.signForm(*robotForm);
        boss.executeForm(*robotForm);
        
        std::cout << "\n-- Testing Presidential Pardon Form --" << std::endl;
        std::cout << *pardonForm << std::endl;
        boss.signForm(*pardonForm);
        boss.executeForm(*pardonForm);
        
        // Clean up dynamically allocated forms
        delete shrubForm;
        delete robotForm;
        delete pardonForm;
        
        // Try to create a non-existent form
        std::cout << "\n-- Testing Invalid Form --" << std::endl;
        AForm *invalidForm = someRandomIntern.makeForm("invalid form", "Target");
        // The next line should not be executed
        delete invalidForm;
    }
    catch(const std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    
    return 0;
} 