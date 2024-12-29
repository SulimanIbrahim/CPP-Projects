#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP
#include <iostream>


class ClapTrap{
    private:
        std::string _name;
        int _hitsPoints;
        int _energyPoints;
        int _attackdamage;
    public:
        // Orthodox Canonical Form
        ClapTrap();
        ClapTrap(std::string name);
        ClapTrap(const ClapTrap &copy);
        ClapTrap &operator=(const ClapTrap &copy);
        ~ClapTrap();
        // member functions
        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
        // getters
        int getEnergyPoints();
        int getHitPoints();
        std::string getName();
};


#endif