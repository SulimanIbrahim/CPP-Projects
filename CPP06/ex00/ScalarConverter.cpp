#include "ScalarConverter.hpp"

// Private constructors and destructor to prevent instantiation
ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter &copy) { (void)copy; }
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &copy)
{
    (void)copy;
    return *this;
}
ScalarConverter::~ScalarConverter() {}

// ANSI color codes for terminal output
#define RED_TEXT "\033[1;31m"
#define RESET_COLOR "\033[0m"

// Print methods
void ScalarConverter::printChar(double value)
{
    std::cout << "char: ";
    if (std::isnan(value) || std::isinf(value))
        std::cout << "impossible" << std::endl;
    else if (value < 0 || value > 127)
        std::cout << "impossible" << std::endl;
    else if (value < 32 || value == 127)
        std::cout << "Non displayable" << std::endl;
    else
        std::cout << "'" << static_cast<char>(value) << "'" << std::endl;
}

void ScalarConverter::printInt(double value)
{
    std::cout << "int: ";
    if (std::isnan(value) || std::isinf(value))
        std::cout << "impossible" << std::endl;
    else if (value < std::numeric_limits<int>::min() || value > std::numeric_limits<int>::max())
        std::cout << "impossible" << std::endl;
    else
        std::cout << static_cast<int>(value) << std::endl;
}

void ScalarConverter::printFloat(double value)
{
    std::cout << "float: ";
    if (std::isnan(value))
        std::cout << "nanf" << std::endl;
    else if (value == std::numeric_limits<double>::infinity())
        std::cout << "+inff" << std::endl;
    else if (value == -std::numeric_limits<double>::infinity())
        std::cout << "-inff" << std::endl;
    else
    {
        float f = static_cast<float>(value);
        std::cout << f;
        if (f == static_cast<int>(f))
            std::cout << ".0";
        std::cout << "f" << std::endl;
    }
}

void ScalarConverter::printDouble(double value)
{
    std::cout << "double: ";
    if (std::isnan(value))
        std::cout << "nan" << std::endl;
    else if (value == std::numeric_limits<double>::infinity())
        std::cout << "+inf" << std::endl;
    else if (value == -std::numeric_limits<double>::infinity())
        std::cout << "-inf" << std::endl;
    else
    {
        std::cout << value;
        if (value == static_cast<int>(value))
            std::cout << ".0";
        std::cout << std::endl;
    }
}

// The public convert method
void ScalarConverter::convert(const std::string &literal)
{
    try
    {
        if (literal.empty())
            throw ConversionException("Empty input");
            
        double value;
        std::string detectedType;
        
        if (literal.length() == 1 && !std::isdigit(literal[0]))
        {
            value = static_cast<double>(literal[0]);
            detectedType = "char";
        }
        else if (literal == "nan" || literal == "nanf")
        {
            value = std::numeric_limits<double>::quiet_NaN();
            detectedType = (literal == "nan") ? "double" : "float";
        }
        else if (literal == "+inf" || literal == "+inff")
        {
            value = std::numeric_limits<double>::infinity();
            detectedType = (literal == "+inf") ? "double" : "float";
        }
        else if (literal == "-inf" || literal == "-inff")
        {
            value = -std::numeric_limits<double>::infinity();
            detectedType = (literal == "-inf") ? "double" : "float";
        }
        else
        {
            std::string cleanLiteral = literal;
            bool isFloat = false;
            if (!literal.empty() && literal[literal.length() - 1] == 'f')
            {
                cleanLiteral = literal.substr(0, literal.length() - 1);
                isFloat = true;
            }
            
            for (size_t i = 0; i < cleanLiteral.length(); i++) 
            {
                if (!std::isdigit(cleanLiteral[i]) && 
                    cleanLiteral[i] != '.' && 
                    !(i == 0 && (cleanLiteral[i] == '+' || cleanLiteral[i] == '-')))
                {
                    throw ConversionException("Invalid character in input: " + std::string(1, cleanLiteral[i]));
                }
            }
            
            int pointCount = 0;
            for (size_t i = 0; i < cleanLiteral.length(); i++)
                if (cleanLiteral[i] == '.')
                    pointCount++;
                    
            if (pointCount > 1)
                throw ConversionException("Invalid input: multiple decimal points");
                
            if (cleanLiteral == "." || cleanLiteral == "+." || cleanLiteral == "-.")
                throw ConversionException("Invalid input: lone decimal point");
                
            char *endptr;
            value = std::strtod(cleanLiteral.c_str(), &endptr);
            
            if (*endptr != '\0')
                throw ConversionException("Failed to convert: invalid numeric format");
            
            if (isFloat)
                detectedType = "float";
            else if (cleanLiteral.find('.') != std::string::npos)
                detectedType = "double";
            else
                detectedType = "int";
        }
        
        std::cout << "Input type detected: " << detectedType << std::endl;
        
        printChar(value);
        printInt(value);
        printFloat(value);
        printDouble(value);
    }
    catch(const ConversionException& e)
    {
        std::cerr << RED_TEXT << "Error: " << e.what() << RESET_COLOR << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << RED_TEXT << "Unexpected error: " << e.what() << RESET_COLOR << std::endl;
    }
    catch(...)
    {
        std::cerr << RED_TEXT << "Unknown error occurred" << RESET_COLOR << std::endl;
    }
} 
