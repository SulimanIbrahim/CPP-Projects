#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <string>
#include <exception>

// Forward declaration of Bureaucrat class to avoid circular dependency
class Bureaucrat;
#include "Bureaucrat.hpp"

class AForm
{
private:
    const std::string _name;
    bool _signed;
    const int _gradeToSign;
    const int _gradeToExecute;

public:
    // Orthodox Canonical Form
    AForm();
    AForm(const std::string &name, int gradeToSign, int gradeToExecute);
    AForm(const AForm &copy);
    AForm &operator=(const AForm &copy);
    virtual ~AForm();

    // Getters
    std::string getName() const;
    bool isSigned() const;
    int getGradeToSign() const;
    int getGradeToExecute() const;

    // Member functions
    void beSigned(const Bureaucrat &bureaucrat);
    
    // Pure virtual function to make AForm abstract
    virtual void execute(Bureaucrat const &executor) const = 0;
    
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
    
    class FormNotSignedException : public std::exception
    {
    public:
        virtual const char *what() const throw();
    };
};

// Operator overload
std::ostream &operator<<(std::ostream &out, const AForm &form);

#endif 