#include "ShrubberyCreationForm.hpp"

// Constructors and Destructor
ShrubberyCreationForm::ShrubberyCreationForm() 
    : AForm("Shrubbery Creation Form", 145, 137), _target("default")
{
    std::cout << "ShrubberyCreationForm default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) 
    : AForm("Shrubbery Creation Form", 145, 137), _target(target)
{
    std::cout << "ShrubberyCreationForm parameterized constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy)
    : AForm(copy), _target(copy._target)
{
    std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &copy)
{
    std::cout << "ShrubberyCreationForm assignment operator called" << std::endl;
    if (this != &copy)
    {
        AForm::operator=(copy);
        this->_target = copy._target;
    }
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}

// Getters
std::string ShrubberyCreationForm::getTarget() const
{
    return this->_target;
}

// Execute method override
void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
    // Check if the form is signed and the bureaucrat has enough grade
    if (!this->isSigned())
        throw AForm::FormNotSignedException();
    if (executor.getGrade() > this->getGradeToExecute())
        throw AForm::GradeTooLowException();
    
    // Create the output file
    std::string fileName = this->_target + "_shrubbery";
    std::ofstream outFile(fileName.c_str());
    
    if (!outFile.is_open())
    {
        std::cout << "Failed to create output file" << std::endl;
        return;
    }
    
    // Write ASCII trees to the file
    outFile << "               ,@@@@@@@,               " << std::endl;
    outFile << "       ,,,.   ,@@@@@@/@@,  .oo8888o.   " << std::endl;
    outFile << "    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o  " << std::endl;
    outFile << "   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'" << std::endl;
    outFile << "   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'" << std::endl;
    outFile << "   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88' " << std::endl;
    outFile << "   `&%\\ ` /%&'    |.|        \\ '|8'   " << std::endl;
    outFile << "       |o|        | |         | |      " << std::endl;
    outFile << "       |.|        | |         | |      " << std::endl;
    outFile << "    \\/ ._\\//_/__/  ,\\_//__\\/.  \\_//__/_" << std::endl;
    outFile << std::endl;
    outFile << "              _-_                     " << std::endl;
    outFile << "           /~~   ~~\\                  " << std::endl;
    outFile << "        /~~         ~~\\               " << std::endl;
    outFile << "       {               }              " << std::endl;
    outFile << "        \\  _-     -_  /               " << std::endl;
    outFile << "          ~  \\\\ //  ~                 " << std::endl;
    outFile << "       _- -   | | _- _                " << std::endl;
    outFile << "       _ -    | |   -_                " << std::endl;
    outFile << "            // \\\\                    " << std::endl;
    
    outFile.close();
    std::cout << "Created shrubbery file: " << fileName << std::endl;
} 