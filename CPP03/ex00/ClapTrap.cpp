#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("ClapTrap"), _hitsPoints(100), _energyPoints(50), _attackdamage(20){
    std::cout << "ClapTrap parameter constructor has been called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitsPoints(10), _energyPoints(10), _attackdamage(0) {
    std::cout << "ClapTrap constructor has been called" << std::endl;
}


ClapTrap::~ClapTrap() {
    std::cout << "ClapTrap destructor has been called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &copy) {
    std::cout << "ClapTrap copy constructor has been called" << std::endl;
    *this = copy;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &copy) {
    std::cout << "ClapTrap assignation operator has been called" << std::endl;
    if (this != &copy) {
        this->_name = copy._name;
        this->_hitsPoints = copy._hitsPoints;
        this->_energyPoints = copy._energyPoints;
        this->_attackdamage = copy._attackdamage;
    }
    return *this;
}


void ClapTrap::attack(const std::string& target) {
    if (this->_energyPoints > 0) {
        this->_energyPoints -= 1;
    } else {
        if (this->_hitsPoints <= 0)
            std::cout << this->_name << " has no hit points left" << std::endl;
        else if (this->_energyPoints <= 0)
            std::cout << this->_name << " has no energy points left" << std::endl;
        return;
    }
    std::cout << this->_name << " attacks " << target << ", causing " << this->_attackdamage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
    if (this->_hitsPoints <= 0) {
        std::cout << this->_name << " has no hit points left" << std::endl;
    if (this->_energyPoints <= 0)
        std::cout << this->_name << " has no energy points left" << std::endl;
    } else {
        std::cout << this->_name << " takes " << amount << " points of damage!" << std::endl;
        this->_hitsPoints -= amount;
    }
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (this->_energyPoints > 0) {
        this->_energyPoints -= 1;
    } else {
        std::cout << this->_name << " has no energy points left" << std::endl;
        return;
    }
    if (this->_hitsPoints <= 0) {
        std::cout << this->_name << " has no hit points left" << std::endl;
    } else if (this->_energyPoints <= 0){
        std::cout << this->_name << " has no energy points left" << std::endl;
    } else {
        std::cout << this->_name << " has been repaired by " << amount << " points!" << std::endl;
        this->_hitsPoints += amount;
    }
}

int ClapTrap::getEnergyPoints() {
    return this->_energyPoints;
}

int ClapTrap::getHitPoints() {
    return this->_hitsPoints;
}

std::string ClapTrap::getName() {
    return this->_name;
}

