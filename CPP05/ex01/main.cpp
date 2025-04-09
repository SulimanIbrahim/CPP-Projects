#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

// Color macros for better visual output
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"

// Test header macro
#define TEST_HEADER(x) std::cout << YELLOW << "\n===== " << x << " =====" << RESET << std::endl

int main()
{
    TEST_HEADER("Form Creation Tests");
    try
    {
        Form validForm("Tax Form", 50, 25);
        std::cout << GREEN << validForm << RESET << std::endl;
        
        Form copyForm(validForm);
        std::cout << GREEN << copyForm << RESET << std::endl;
        
        Form defaultForm;
        std::cout << GREEN << defaultForm << RESET << std::endl;
        
        defaultForm = validForm;
        std::cout << GREEN << defaultForm << RESET << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << RED << "Exception: " << e.what() << RESET << std::endl;
    }
    
    TEST_HEADER("Form Grade Too High Exception Test");
    try
    {
        std::cout << BLUE << "Attempting to create form with sign grade 0..." << RESET << std::endl;
        Form tooHighSign("Too High Sign", 0, 25);
        std::cout << GREEN << tooHighSign << RESET << std::endl; // This should not be executed
    }
    catch(const std::exception& e)
    {
        std::cerr << RED << "Exception: " << e.what() << RESET << std::endl;
    }
    
    try
    {
        std::cout << BLUE << "Attempting to create form with execute grade 0..." << RESET << std::endl;
        Form tooHighExec("Too High Exec", 50, 0);
        std::cout << GREEN << tooHighExec << RESET << std::endl; // This should not be executed
    }
    catch(const std::exception& e)
    {
        std::cerr << RED << "Exception: " << e.what() << RESET << std::endl;
    }
    
    TEST_HEADER("Form Grade Too Low Exception Test");
    try
    {
        std::cout << BLUE << "Attempting to create form with sign grade 151..." << RESET << std::endl;
        Form tooLowSign("Too Low Sign", 151, 25);
        std::cout << GREEN << tooLowSign << RESET << std::endl; // This should not be executed
    }
    catch(const std::exception& e)
    {
        std::cerr << RED << "Exception: " << e.what() << RESET << std::endl;
    }
    
    try
    {
        std::cout << BLUE << "Attempting to create form with execute grade 151..." << RESET << std::endl;
        Form tooLowExec("Too Low Exec", 50, 151);
        std::cout << GREEN << tooLowExec << RESET << std::endl; // This should not be executed
    }
    catch(const std::exception& e)
    {
        std::cerr << RED << "Exception: " << e.what() << RESET << std::endl;
    }
    
    TEST_HEADER("Form Signing Tests");
    try
    {
        std::cout << MAGENTA << "Creating bureaucrats with different grades..." << RESET << std::endl;
        Bureaucrat highGrade("Bob", 5);
        Bureaucrat lowGrade("Alice", 100);
        
        std::cout << MAGENTA << "Creating forms with different requirements..." << RESET << std::endl;
        Form highRequirement("High Security Form", 10, 5);
        Form lowRequirement("Regular Form", 90, 80);
        
        std::cout << CYAN << highRequirement << RESET << std::endl;
        std::cout << CYAN << lowRequirement << RESET << std::endl;
        
        // High grade bureaucrat can sign both forms
        std::cout << BLUE << "\nHigh grade bureaucrat signing attempts:" << RESET << std::endl;
        highGrade.signForm(highRequirement);
        highGrade.signForm(lowRequirement);
        
        // Low grade bureaucrat can only sign the low requirement form
        std::cout << BLUE << "\nLow grade bureaucrat signing attempts:" << RESET << std::endl;
        lowGrade.signForm(lowRequirement); // Should work
        lowGrade.signForm(highRequirement); // Should fail
        
        // Check the status after signing
        std::cout << BLUE << "\nAfter signing attempts:" << RESET << std::endl;
        std::cout << CYAN << highRequirement << RESET << std::endl;
        std::cout << CYAN << lowRequirement << RESET << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << RED << "Exception: " << e.what() << RESET << std::endl;
    }
    
    return 0;
} 