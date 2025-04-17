#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>
#include <iostream>
#include <cstdlib>
#include <limits>
#include <cmath>
#include <exception>

class ScalarConverter
{
private:
    ScalarConverter();
    ScalarConverter(const ScalarConverter &copy);
    ScalarConverter &operator=(const ScalarConverter &copy);
    ~ScalarConverter();
    
    static void printChar(double value);
    static void printInt(double value);
    static void printFloat(double value);
    static void printDouble(double value);

public:
    class ConversionException : public std::exception {
    private:
        std::string _message;
    public:
        ConversionException(const std::string &message) : _message(message) {}
        virtual ~ConversionException() throw() {}
        virtual const char* what() const throw() { return _message.c_str(); }
    };

    static void convert(const std::string &literal);
};

#endif 