#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
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
    TEST_HEADER("Form Creation Tests");
    try
    {
        std::cout << MAGENTA << "Creating different form types..." << RESET << std::endl;
        ShrubberyCreationForm shrubForm("Garden");
        RobotomyRequestForm robotForm("R2D2");
        PresidentialPardonForm pardonForm("Criminal");
        
        std::cout << GREEN << shrubForm << RESET << std::endl;
        std::cout << GREEN << robotForm << RESET << std::endl;
        std::cout << GREEN << pardonForm << RESET << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << RED << "Exception: " << e.what() << RESET << std::endl;
    }
    
    TEST_HEADER("ShrubberyCreationForm Test");
    try
    {
        SUBHEADER("Creating Bureaucrats");
        Bureaucrat highGrade("Director", 1);
        Bureaucrat mediumGrade("Manager", 70);
        Bureaucrat lowGrade("Intern", 140);
        
        std::cout << CYAN << highGrade << RESET << std::endl;
        std::cout << CYAN << mediumGrade << RESET << std::endl;
        std::cout << CYAN << lowGrade << RESET << std::endl;
        
        SUBHEADER("Creating Shrubbery Form");
        ShrubberyCreationForm shrubForm("Home");
        std::cout << GREEN << shrubForm << RESET << std::endl;
        
        SUBHEADER("Signing Attempts");
        std::cout << WHITE << "Low grade bureaucrat attempting to sign (should succeed)..." << RESET << std::endl;
        lowGrade.signForm(shrubForm); // Should work (grade 145 required)
        
        SUBHEADER("Execution Attempts");
        std::cout << WHITE << "Low grade bureaucrat attempting to execute..." << RESET << std::endl;
        lowGrade.executeForm(shrubForm);  // Should fail (grade 137 required)
        
        std::cout << WHITE << "Medium grade bureaucrat attempting to execute..." << RESET << std::endl;
        mediumGrade.executeForm(shrubForm); // Should work
        
        std::cout << WHITE << "High grade bureaucrat attempting to execute..." << RESET << std::endl;
        highGrade.executeForm(shrubForm);  // Should work
    }
    catch(const std::exception& e)
    {
        std::cerr << RED << "Exception: " << e.what() << RESET << std::endl;
    }
    
    TEST_HEADER("RobotomyRequestForm Test");
    try
    {
        SUBHEADER("Creating Bureaucrats");
        Bureaucrat highGrade("CEO", 1);
        Bureaucrat mediumGrade("Team Lead", 50);
        Bureaucrat lowGrade("Assistant", 80);
        
        SUBHEADER("Creating Robotomy Form");
        RobotomyRequestForm robotForm("C3PO");
        std::cout << GREEN << robotForm << RESET << std::endl;
        
        SUBHEADER("Signing Attempts");
        std::cout << WHITE << "Low grade bureaucrat attempting to sign (should fail)..." << RESET << std::endl;
        lowGrade.signForm(robotForm); // Should fail (grade 72 required)
        
        std::cout << WHITE << "Medium grade bureaucrat attempting to sign (should succeed)..." << RESET << std::endl;
        mediumGrade.signForm(robotForm); // Should work
        
        SUBHEADER("Execution Attempts");
        std::cout << WHITE << "Medium grade bureaucrat attempting to execute..." << RESET << std::endl;
        mediumGrade.executeForm(robotForm); // Should work (grade 45 required)
        
        SUBHEADER("Testing 50% Success Rate");
        RobotomyRequestForm anotherRobotForm("BB8");
        std::cout << WHITE << "High grade bureaucrat signing and executing another form..." << RESET << std::endl;
        highGrade.signForm(anotherRobotForm);
        highGrade.executeForm(anotherRobotForm);
    }
    catch(const std::exception& e)
    {
        std::cerr << RED << "Exception: " << e.what() << RESET << std::endl;
    }
    
    TEST_HEADER("PresidentialPardonForm Test");
    try
    {
        SUBHEADER("Creating Bureaucrats");
        Bureaucrat highGrade("President", 1);
        Bureaucrat mediumGrade("Senator", 20);
        Bureaucrat lowGrade("Citizen", 50);
        
        SUBHEADER("Creating Presidential Pardon Form");
        PresidentialPardonForm pardonForm("Rebel");
        std::cout << GREEN << pardonForm << RESET << std::endl;
        
        SUBHEADER("Signing Attempts");
        std::cout << WHITE << "Low grade bureaucrat attempting to sign (should fail)..." << RESET << std::endl;
        lowGrade.signForm(pardonForm); // Should fail (grade 25 required)
        
        std::cout << WHITE << "Medium grade bureaucrat attempting to sign (should succeed)..." << RESET << std::endl;
        mediumGrade.signForm(pardonForm); // Should work
        
        SUBHEADER("Execution Attempts");
        std::cout << WHITE << "Medium grade bureaucrat attempting to execute (should fail)..." << RESET << std::endl;
        mediumGrade.executeForm(pardonForm); // Should fail (grade 5 required)
        
        std::cout << WHITE << "High grade bureaucrat attempting to execute (should succeed)..." << RESET << std::endl;
        highGrade.executeForm(pardonForm); // Should work
    }
    catch(const std::exception& e)
    {
        std::cerr << RED << "Exception: " << e.what() << RESET << std::endl;
    }
    
    TEST_HEADER("Unsigned Form Test");
    try
    {
        SUBHEADER("Attempting to Execute Unsigned Form");
        Bureaucrat highGrade("Chief", 1);
        PresidentialPardonForm unsignedForm("Unsuspecting Citizen");
        
        std::cout << WHITE << "High grade bureaucrat attempting to execute unsigned form..." << RESET << std::endl;
        highGrade.executeForm(unsignedForm); // Should fail (not signed)
    }
    catch(const std::exception& e)
    {
        std::cerr << RED << "Exception: " << e.what() << RESET << std::endl;
    }
    
    return 0;
}