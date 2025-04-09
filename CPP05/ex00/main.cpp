#include "Bureaucrat.hpp"
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
    TEST_HEADER("Basic Tests");
    try
    {
        Bureaucrat b1("Bob", 1);
        std::cout << GREEN << b1 << RESET << std::endl;
        
        Bureaucrat b2("Alice", 150);
        std::cout << GREEN << b2 << RESET << std::endl;
        
        Bureaucrat b3(b1); // Copy constructor
        std::cout << GREEN << b3 << RESET << std::endl;
        
        Bureaucrat b4;
        b4 = b2; // Assignment operator
        std::cout << GREEN << b4 << RESET << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << RED << "Exception: " << e.what() << RESET << std::endl;
    }
    
    TEST_HEADER("Grade Too High Exception Test");
    try
    {
        std::cout << BLUE << "Attempting to create bureaucrat with grade 0..." << RESET << std::endl;
        Bureaucrat tooHigh("TooHigh", 0); // Should throw GradeTooHighException
        std::cout << GREEN << tooHigh << RESET << std::endl; // This should not be executed
    }
    catch(const std::exception& e)
    {
        std::cerr << RED << "Exception: " << e.what() << RESET << std::endl;
    }
    
    TEST_HEADER("Grade Too Low Exception Test");
    try
    {
        std::cout << BLUE << "Attempting to create bureaucrat with grade 151..." << RESET << std::endl;
        Bureaucrat tooLow("TooLow", 151); // Should throw GradeTooLowException
        std::cout << GREEN << tooLow << RESET << std::endl; // This should not be executed
    }
    catch(const std::exception& e)
    {
        std::cerr << RED << "Exception: " << e.what() << RESET << std::endl;
    }
    
    TEST_HEADER("Increment/Decrement Tests");
    try
    {
        Bureaucrat b("John", 5);
        std::cout << CYAN << b << RESET << std::endl;
        
        std::cout << BLUE << "Testing increment..." << RESET << std::endl;
        for (int i = 0; i < 4; i++)
        {
            b.incrementGrade();
            std::cout << CYAN << b << RESET << std::endl;
        }
        
        std::cout << MAGENTA << "Testing increment beyond limit (should throw exception)..." << RESET << std::endl;
        // This should throw GradeTooHighException
        b.incrementGrade();
    }
    catch(const std::exception& e)
    {
        std::cerr << RED << "Exception: " << e.what() << RESET << std::endl;
    }
    
    try
    {
        Bureaucrat b("Jane", 145);
        std::cout << "\n" << CYAN << b << RESET << std::endl;
        
        std::cout << BLUE << "Testing decrement..." << RESET << std::endl;
        for (int i = 0; i < 5; i++)
        {
            b.decrementGrade();
            std::cout << CYAN << b << RESET << std::endl;
        }
        
        std::cout << MAGENTA << "Testing decrement beyond limit (should throw exception)..." << RESET << std::endl;
        // This should throw GradeTooLowException
        b.decrementGrade();
    }
    catch(const std::exception& e)
    {
        std::cerr << RED << "Exception: " << e.what() << RESET << std::endl;
    }
    
    return 0;
} 