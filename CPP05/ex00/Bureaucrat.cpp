#include "Bureaucrat.hpp"

// Constructors and Destructor
Bureaucrat::Bureaucrat() : _name("Default"), _grade(150)
{
    std::cout << "Bureaucrat default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string &name, int grade) : _name(name)
{
    std::cout << "Bureaucrat parameterized constructor called" << std::endl;
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    else if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
    _grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy) : _name(copy._name), _grade(copy._grade)
{
    std::cout << "Bureaucrat copy constructor called" << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &copy)
{
    std::cout << "Bureaucrat assignment operator called" << std::endl;
    if (this != &copy)
    {
        this->_grade = copy._grade;
    }
    return *this;
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "Bureaucrat destructor called" << std::endl;
}

// Getters
std::string Bureaucrat::getName() const
{
    return this->_name;
}

int Bureaucrat::getGrade() const
{
    return this->_grade;
}

// Grade modification methods
void Bureaucrat::incrementGrade()
{
    std::cout << "Attempting to increment grade..." << std::endl;
    if (_grade <= 1)
        throw Bureaucrat::GradeTooHighException();
    _grade--;
    std::cout << "Grade incremented to " << _grade << std::endl;
}

void Bureaucrat::decrementGrade()
{
    std::cout << "Attempting to decrement grade..." << std::endl;
    if (_grade >= 150)
        throw Bureaucrat::GradeTooLowException();
    _grade++;
    std::cout << "Grade decremented to " << _grade << std::endl;
}

// Exception class methods
const char *Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Grade is too high! The grade cannot be higher than 1.";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Grade is too low! The grade cannot be lower than 150.";
}

// Operator overload
std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat)
{
    out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
    return out;
} 