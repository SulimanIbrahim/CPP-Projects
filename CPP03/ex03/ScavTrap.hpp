#ifndef ScavTrap_HPP
#define ScavTrap_HPP
#include "ClapTrap.hpp"
#include <iostream>

class ScavTrap : virtual public ClapTrap {
    public:
        ScavTrap();
        ScavTrap(std::string name);
        ~ScavTrap();
        ScavTrap(const ScavTrap &copy);
        ScavTrap &operator=(const ScavTrap &copy);

        void attack(const std::string& target);
        void guardGate();
};

#endif