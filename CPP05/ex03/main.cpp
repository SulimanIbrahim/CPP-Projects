#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include <iostream>

// Color macros for better visual output
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"

// Test header macro
#define TEST_HEADER(x) std::cout << YELLOW << "\n===== " << x << " =====" << RESET << std::endl
#define SUBHEADER(x) std::cout << BLUE << "\n-- " << x << " --" << RESET << std::endl

int main()
{
    TEST_HEADER("Intern Tests");
    try
    {
        std::cout << MAGENTA << "Creating an intern..." << RESET << std::endl;
        Intern someRandomIntern;
        
        // Create different forms using the intern
        std::cout << MAGENTA << "Asking intern to create various forms..." << RESET << std::endl;
        
        std::cout << WHITE << "Creating shrubbery creation form..." << RESET << std::endl;
        AForm *shrubForm = someRandomIntern.makeForm("shrubbery creation", "Park");
        
        std::cout << WHITE << "Creating robotomy request form..." << RESET << std::endl;
        AForm *robotForm = someRandomIntern.makeForm("robotomy request", "Bender");
        
        std::cout << WHITE << "Creating presidential pardon form..." << RESET << std::endl;
        AForm *pardonForm = someRandomIntern.makeForm("presidential pardon", "Prisoner");
        
        // Create a bureaucrat to sign and execute the forms
        std::cout << MAGENTA << "\nCreating high-level bureaucrat..." << RESET << std::endl;
        Bureaucrat boss("Big Boss", 1);
        std::cout << CYAN << boss << RESET << std::endl;
        
        SUBHEADER("Testing Shrubbery Creation Form");
        std::cout << GREEN << *shrubForm << RESET << std::endl;
        
        std::cout << WHITE << "Signing form..." << RESET << std::endl;
        boss.signForm(*shrubForm);
        
        std::cout << WHITE << "Executing form..." << RESET << std::endl;
        boss.executeForm(*shrubForm);
        
        SUBHEADER("Testing Robotomy Request Form");
        std::cout << GREEN << *robotForm << RESET << std::endl;
        
        std::cout << WHITE << "Signing form..." << RESET << std::endl;
        boss.signForm(*robotForm);
        
        std::cout << WHITE << "Executing form..." << RESET << std::endl;
        boss.executeForm(*robotForm);
        
        SUBHEADER("Testing Presidential Pardon Form");
        std::cout << GREEN << *pardonForm << RESET << std::endl;
        
        std::cout << WHITE << "Signing form..." << RESET << std::endl;
        boss.signForm(*pardonForm);
        
        std::cout << WHITE << "Executing form..." << RESET << std::endl;
        boss.executeForm(*pardonForm);
        
        // Clean up dynamically allocated forms
        std::cout << MAGENTA << "\nCleaning up forms..." << RESET << std::endl;
        delete shrubForm;
        delete robotForm;
        delete pardonForm;
        
        SUBHEADER("Testing Invalid Form");
        std::cout << WHITE << "Asking intern to create an invalid form type..." << RESET << std::endl;
        std::cout << RED << "This should throw FormNotFoundException:" << RESET << std::endl;
        AForm *invalidForm = someRandomIntern.makeForm("invalid form", "Target");
        // The next line should not be executed
        delete invalidForm;
    }
    catch(const std::exception& e)
    {
        std::cerr << RED << "Exception: " << e.what() << RESET << std::endl;
    }
    
    return 0;
} 