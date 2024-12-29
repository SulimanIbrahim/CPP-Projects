#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap("Default ClapTrap") {
    std::cout << "FragTrap default constructor called" << std::endl;
    this->_hitsPoints = 100;
    this->_energyPoints = 100;
    this->_attackdamage = 30;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
    std::cout << "FragTrap parameterized constructor called" << std::endl;
    this->_hitsPoints = 100;
    this->_energyPoints = 100;
    this->_attackdamage = 30;
}

FragTrap::~FragTrap() {
    std::cout << "FragTrap destructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap &copy) {
    std::cout << "FragTrap copy constructor called" << std::endl;
    *this = copy;
}

FragTrap &FragTrap::operator=(const FragTrap &copy) {
    std::cout << "FragTrap assignation operator called" << std::endl;
    if (this != &copy) {
        this->_name = copy._name;
        this->_hitsPoints = copy._hitsPoints;
        this->_energyPoints = copy._energyPoints;
        this->_attackdamage = copy._attackdamage;
    }
    return *this;
}

void FragTrap::highFivesGuys() {
    std::cout << "FragTrap " << this->_name << " requests a high five" << std::endl;
}

