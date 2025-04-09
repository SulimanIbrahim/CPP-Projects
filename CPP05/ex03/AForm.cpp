#include "AForm.hpp"

// Constructors and Destructor
AForm::AForm() : _name("Default Form"), _signed(false), _gradeToSign(150), _gradeToExecute(150)
{
    std::cout << "AForm default constructor called" << std::endl;
}

AForm::AForm(const std::string &name, int gradeToSign, int gradeToExecute)
    : _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
    std::cout << "AForm parameterized constructor called" << std::endl;
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw AForm::GradeTooHighException();
    else if (gradeToSign > 150 || gradeToExecute > 150)
        throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm &copy)
    : _name(copy._name), _signed(copy._signed), 
      _gradeToSign(copy._gradeToSign), _gradeToExecute(copy._gradeToExecute)
{
    std::cout << "AForm copy constructor called" << std::endl;
}

AForm &AForm::operator=(const AForm &copy)
{
    std::cout << "AForm assignment operator called" << std::endl;
    if (this != &copy)
    {
        // Cannot reassign const attributes, only _signed can be modified
        this->_signed = copy._signed;
    }
    return *this;
}

AForm::~AForm()
{
    std::cout << "AForm destructor called" << std::endl;
}

// Getters
std::string AForm::getName() const
{
    return this->_name;
}

bool AForm::isSigned() const
{
    return this->_signed;
}

int AForm::getGradeToSign() const
{
    return this->_gradeToSign;
}

int AForm::getGradeToExecute() const
{
    return this->_gradeToExecute;
}

// Member functions
void AForm::beSigned(const Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() <= this->_gradeToSign)
    {
        this->_signed = true;
    }
    else
    {
        throw AForm::GradeTooLowException();
    }
}

// Exception class methods
const char *AForm::GradeTooHighException::what() const throw()
{
    return "Grade is too high! The grade cannot be higher than 1.";
}

const char *AForm::GradeTooLowException::what() const throw()
{
    return "Grade is too low! The bureaucrat's grade is insufficient or the form's required grade is too low.";
}

const char *AForm::FormNotSignedException::what() const throw()
{
    return "Form is not signed! The form must be signed before execution.";
}

// Operator overload
std::ostream &operator<<(std::ostream &out, const AForm &form)
{
    out << "Form: " << form.getName()
        << ", Sign Status: " << (form.isSigned() ? "Signed" : "Not Signed")
        << ", Grade Required to Sign: " << form.getGradeToSign()
        << ", Grade Required to Execute: " << form.getGradeToExecute();
    return out;
}

 