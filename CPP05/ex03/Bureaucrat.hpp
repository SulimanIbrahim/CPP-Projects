#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>

// Forward declaration to avoid circular dependency
class AForm;

class Bureaucrat
{
private:
    const std::string _name;
    int _grade;

public:
    // Orthodox Canonical Form
    Bureaucrat();
    Bureaucrat(const std::string &name, int grade);
    Bureaucrat(const Bureaucrat &copy);
    Bureaucrat &operator=(const Bureaucrat &copy);
    ~Bureaucrat();

    // Getters
    std::string getName() const;
    int getGrade() const;

    // Grade modification
    void incrementGrade();
    void decrementGrade();
    
    // Form interaction
    void signForm(AForm &form);
    void executeForm(AForm const &form) const;

    // Exception classes
    class GradeTooHighException : public std::exception
    {
    public:
        virtual const char *what() const throw();
    };

    class GradeTooLowException : public std::exception
    {
    public:
        virtual const char *what() const throw();
    };
};

// Operator overload
std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat);

// Include AForm after Bureaucrat is fully declared to resolve circular dependency
#include "AForm.hpp"

#endif 