#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main()
{
    std::cout << "===== Form Creation Tests =====" << std::endl;
    try
    {
        ShrubberyCreationForm shrubForm("Garden");
        RobotomyRequestForm robotForm("R2D2");
        PresidentialPardonForm pardonForm("Criminal");
        
        std::cout << shrubForm << std::endl;
        std::cout << robotForm << std::endl;
        std::cout << pardonForm << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    
    std::cout << "\n===== ShrubberyCreationForm Test =====" << std::endl;
    try
    {
        Bureaucrat highGrade("Director", 1);
        Bureaucrat mediumGrade("Manager", 70);
        Bureaucrat lowGrade("Intern", 140);
        
        ShrubberyCreationForm shrubForm("Home");
        std::cout << shrubForm << std::endl;
        
        // Test signing with various grades
        std::cout << "\n-- Signing attempts:" << std::endl;
        lowGrade.signForm(shrubForm); // Should work (grade 145 required)
        
        // Test execution with various grades
        std::cout << "\n-- Execution attempts:" << std::endl;
        lowGrade.executeForm(shrubForm);  // Should fail (grade 137 required)
        mediumGrade.executeForm(shrubForm); // Should work
        highGrade.executeForm(shrubForm);  // Should work
    }
    catch(const std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    
    std::cout << "\n===== RobotomyRequestForm Test =====" << std::endl;
    try
    {
        Bureaucrat highGrade("CEO", 1);
        Bureaucrat mediumGrade("Team Lead", 50);
        Bureaucrat lowGrade("Assistant", 80);
        
        RobotomyRequestForm robotForm("C3PO");
        std::cout << robotForm << std::endl;
        
        // Test signing with various grades
        std::cout << "\n-- Signing attempts:" << std::endl;
        lowGrade.signForm(robotForm); // Should fail (grade 72 required)
        mediumGrade.signForm(robotForm); // Should work
        
        // Test execution with various grades
        std::cout << "\n-- Execution attempts:" << std::endl;
        mediumGrade.executeForm(robotForm); // Should work (grade 45 required)
        
        // Test another robotomy for 50% chance
        RobotomyRequestForm anotherRobotForm("BB8");
        highGrade.signForm(anotherRobotForm);
        highGrade.executeForm(anotherRobotForm);
    }
    catch(const std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    
    std::cout << "\n===== PresidentialPardonForm Test =====" << std::endl;
    try
    {
        Bureaucrat highGrade("President", 1);
        Bureaucrat mediumGrade("Senator", 20);
        Bureaucrat lowGrade("Citizen", 50);
        
        PresidentialPardonForm pardonForm("Rebel");
        std::cout << pardonForm << std::endl;
        
        // Test signing with various grades
        std::cout << "\n-- Signing attempts:" << std::endl;
        lowGrade.signForm(pardonForm); // Should fail (grade 25 required)
        mediumGrade.signForm(pardonForm); // Should work
        
        // Test execution with various grades
        std::cout << "\n-- Execution attempts:" << std::endl;
        mediumGrade.executeForm(pardonForm); // Should fail (grade 5 required)
        highGrade.executeForm(pardonForm); // Should work
    }
    catch(const std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    
    std::cout << "\n===== Test Unsigned Form =====" << std::endl;
    try
    {
        Bureaucrat highGrade("Chief", 1);
        PresidentialPardonForm unsignedForm("Unsuspecting Citizen");
        
        // Try to execute without signing
        highGrade.executeForm(unsignedForm); // Should fail (not signed)
    }
    catch(const std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    
    return 0;
} 