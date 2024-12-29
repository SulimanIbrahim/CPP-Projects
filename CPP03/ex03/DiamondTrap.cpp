#include "DiamondTrap.hpp"


DiamondTrap::DiamondTrap() : ScavTrap("Default ScavTrap"), FragTrap("Default FragTrap") {
    this->_name = "DiamondTrap";
    this->_hitsPoints = this->FragTrap::_hitsPoints;
    this->_energyPoints = this->ScavTrap::_energyPoints;
    this->_attackdamage = this->FragTrap::_attackdamage;
    std::cout << "DiamondTrap default constructor called" << std::endl;
}
DiamondTrap::DiamondTrap(std::string name) : ScavTrap(name + "_clap_name"), FragTrap(name + "_clap_name") {
    this->_name = name;
    this->_hitsPoints = this->FragTrap::_hitsPoints;
    this->_energyPoints = this->ScavTrap::_energyPoints;
    this->_attackdamage = this->FragTrap::_attackdamage;
    std::cout << "DiamondTrap " << this->_name << " parameterized constructor called" << std::endl;
}

DiamondTrap::~DiamondTrap() {
    std::cout << "DiamondTrap destructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &copy) : ScavTrap(copy), FragTrap(copy) {
    std::cout << "DiamondTrap copy constructor called" << std::endl;
    *this = copy;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &copy) {
    std::cout << "DiamondTrap assignation operator called" << std::endl;
    if (this != &copy) {
        this->_name = copy._name;
        this->_hitsPoints = copy._hitsPoints;
        this->_energyPoints = copy._energyPoints;
        this->_attackdamage = copy._attackdamage;
    }
    return *this;
}

void DiamondTrap::attack(const std::string& target) {
    ScavTrap::attack(target);
}

void DiamondTrap::whoAmI() {
    std::cout << "DiamondTrap name is " << this->_name << std::endl;
    std::cout << "ClapTrap name is " << ClapTrap::getName() << std::endl;
}