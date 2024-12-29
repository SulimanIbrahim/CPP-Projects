#include "ScavTrap.hpp"


ScavTrap::ScavTrap(){
    std::cout << "ScavTrap default constructor has been called" << std::endl;
    this->_name = "ScavTrap";
    this->_hitsPoints = 100;
    this->_energyPoints = 50;
    this->_attackdamage = 20;
}

ScavTrap::ScavTrap(std::string name){
    this->_name = name;
    std::cout << "ScavTrap " << this->_name << " parameterized constructor has been called" << std::endl;
}

ScavTrap::~ScavTrap() {
    std::cout << "ScavTrap destructor has been called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &copy) : ClapTrap(copy) {
    std::cout << "ScavTrap copy constructor has been called" << std::endl;
    *this = copy;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &copy) {
    std::cout << "ScavTrap assignation operator has been called" << std::endl;
    if (this != &copy) {
        this->_name = copy._name;
        this->_hitsPoints = copy._hitsPoints;
        this->_energyPoints = copy._energyPoints;
        this->_attackdamage = copy._attackdamage;
    }
    return *this;
}

void ScavTrap::attack(const std::string& target) {
    if (this->_energyPoints > 0 && this->_hitsPoints > 0) {
        this->_energyPoints -= 1;
    } else {
        if (this->_hitsPoints <= 0)
            std::cout << "ScavTrap " << this->_name << " has no hit points left" << std::endl;
        else if (this->_energyPoints <= 0)
            std::cout << "ScavTrap " << this->_name << " has no energy points left" << std::endl;
        return;
    }
    std::cout << "ScavTrap " << this->_name << " attacks " << target << ", causing " << this->_attackdamage << " points of damage!" << std::endl;
}
void ScavTrap::guardGate() {
    std::cout << "ScavTrap " << this->_name << " has entered in Gate keeper mode" << std::endl;
}
