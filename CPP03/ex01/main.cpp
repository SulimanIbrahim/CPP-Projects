#include "ScavTrap.hpp"
#include <iostream>

#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"

int main() {
    std::cout << BLUE << "Test 1: Creating ScavTrap" << RESET << std::endl;
    ScavTrap scav("Scavy");

    std::cout << GREEN << "\nTest 2: Testing attack functionality" << RESET << std::endl;
    scav.attack("Target A");
    std::cout << "Energy Points After Attack: " << scav.getEnergyPoints() << std::endl;

    std::cout << YELLOW << "\nTest 3: Testing Guard Gate functionality" << RESET << std::endl;
    scav.guardGate();

    std::cout << RED << "\nTest 4: Testing takeDamage functionality" << RESET << std::endl;
    scav.takeDamage(30);
    std::cout << "Hit Points After Damage: " << scav.getHitPoints() << std::endl;

    std::cout << CYAN << "\nTest 5: Testing repair functionality" << RESET << std::endl;
    scav.beRepaired(20);
    std::cout << "Hit Points After Repair: " << scav.getHitPoints() << std::endl;
    std::cout << "Energy Points After Repair: " << scav.getEnergyPoints() << std::endl;

    std::cout << MAGENTA << "\nTest 6: Exhausting energy points through multiple attacks" << RESET << std::endl;
    while (scav.getEnergyPoints() > 0) {
        scav.attack("Target B");
    }
    scav.attack("Target B (No Energy Left)");

    std::cout << BLUE << "\nTest 7: Testing ScavTrap with full damage" << RESET << std::endl;
    scav.takeDamage(150);
    scav.attack("Target C");
    scav.beRepaired(10);

    std::cout << GREEN << "\nTest 8: Testing copy constructor and assignment operator" << RESET << std::endl;
    ScavTrap copyScav(scav);
    ScavTrap assignedScav = scav;
    copyScav.guardGate();
    assignedScav.guardGate();

    std::cout << YELLOW << "\nTest 9: Testing destructor chaining with a temporary object" << RESET << std::endl;
    {
        ScavTrap tempScav("Temporary Scavy");
        tempScav.guardGate();
    }

    std::cout << RED << "\nScavTrap destructing:" << RESET << std::endl;
    return 0;
}
