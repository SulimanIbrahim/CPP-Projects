#include "Harl.hpp"
#include <iostream>


void Harl::debug( void ){
    std::cout << "[ DEBUG ]" << std::endl;
    std::cout << "I think I deserve to have some extra bacon for free." << std::endl;
}

void Harl::info( void ){
    std::cout << "[ INFO ]" << std::endl;
    std::cout << "I've been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::warning( void ){
    std::cout << "[ WARNING ]" << std::endl;
    std::cout << "I think I deserve to have some extra bacon for free." << std::endl;
}

void Harl::error( void ){
    std::cout << "[ ERROR ]" << std::endl;
    std::cout << "This is unacceptable, I want to speak to the manager now." << std::endl;
}

void Harl::complain( std::string level ){
    std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    switch 
}