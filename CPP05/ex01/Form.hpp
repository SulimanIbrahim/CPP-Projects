#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>
#include <exception>

// Forward declaration of Bureaucrat class to avoid circular dependency
class Bureaucrat;
#include "Bureaucrat.hpp"

class Form
{
private:
    const std::string _name;
    bool _signed;
    const int _gradeToSign;
    const int _gradeToExecute;

public:
    // Orthodox Canonical Form
    Form();
    Form(const std::string &name, int gradeToSign, int gradeToExecute);
    Form(const Form &copy);
    Form &operator=(const Form &copy);
    ~Form();

    // Getters
    std::string getName() const;
    bool isSigned() const;
    int getGradeToSign() const;
    int getGradeToExecute() const;

    // Member functions
    void beSigned(const Bureaucrat &bureaucrat);

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
std::ostream &operator<<(std::ostream &out, const Form &form);

#endif 