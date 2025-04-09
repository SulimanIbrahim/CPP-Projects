#include "Form.hpp"

// Constructors and Destructor
Form::Form() : _name("Default Form"), _signed(false), _gradeToSign(150), _gradeToExecute(150)
{
    std::cout << "Form default constructor called" << std::endl;
}

Form::Form(const std::string &name, int gradeToSign, int gradeToExecute)
    : _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
    std::cout << "Form parameterized constructor called" << std::endl;
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw Form::GradeTooHighException();
    else if (gradeToSign > 150 || gradeToExecute > 150)
        throw Form::GradeTooLowException();
}

Form::Form(const Form &copy)
    : _name(copy._name), _signed(copy._signed), 
      _gradeToSign(copy._gradeToSign), _gradeToExecute(copy._gradeToExecute)
{
    std::cout << "Form copy constructor called" << std::endl;
}

Form &Form::operator=(const Form &copy)
{
    std::cout << "Form assignment operator called" << std::endl;
    if (this != &copy)
    {
        // Cannot reassign const attributes, only _signed can be modified
        this->_signed = copy._signed;
    }
    return *this;
}

Form::~Form()
{
    std::cout << "Form destructor called" << std::endl;
}

// Getters
std::string Form::getName() const
{
    return this->_name;
}

bool Form::isSigned() const
{
    return this->_signed;
}

int Form::getGradeToSign() const
{
    return this->_gradeToSign;
}

int Form::getGradeToExecute() const
{
    return this->_gradeToExecute;
}

// Member functions
void Form::beSigned(const Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() <= this->_gradeToSign)
    {
        this->_signed = true;
    }
    else
    {
        throw Form::GradeTooLowException();
    }
}

// Exception class methods
const char *Form::GradeTooHighException::what() const throw()
{
    return "Grade is too high! The grade cannot be higher than 1.";
}

const char *Form::GradeTooLowException::what() const throw()
{
    return "Grade is too low! The bureaucrat's grade is insufficient or the form's required grade is too low.";
}

// Operator overload
std::ostream &operator<<(std::ostream &out, const Form &form)
{
    out << "Form: " << form.getName()
        << ", Sign Status: " << (form.isSigned() ? "Signed" : "Not Signed")
        << ", Grade Required to Sign: " << form.getGradeToSign()
        << ", Grade Required to Execute: " << form.getGradeToExecute();
    return out;
} 