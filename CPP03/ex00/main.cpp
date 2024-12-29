#include "ClapTrap.hpp"
#include <iostream>

// ANSI color codes
#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"

int main() {
    std::cout << BLUE << "Test 1: Constructor and Copy Operations" << RESET << std::endl;
    ClapTrap claptrap("Claptrap");
    ClapTrap claptrap2(claptrap);
    ClapTrap claptrap3 = claptrap;

    std::cout << GREEN << "\nTest 2: Testing attack functionality" << RESET << std::endl;
    for (int i = 0; i < 10; ++i) {
        claptrap.attack("Target A");
    }
    std::cout << "Energy Points After 10 Attacks: " << claptrap.getEnergyPoints() << std::endl;

    std::cout << YELLOW << "\nTest 3: Testing attack when energy is finished" << RESET << std::endl;
    claptrap.attack("Target B"); 

    std::cout << RED << "\nTest 4: Testing takeDamage functionality" << RESET << std::endl;
    claptrap.takeDamage(5);
    std::cout << "Hit Points After Taking 5 Damage: " << claptrap.getHitPoints() << std::endl;
    claptrap.takeDamage(10);
    std::cout << "Hit Points After Taking 10 More Damage: " << claptrap.getHitPoints() << std::endl;

    std::cout << CYAN << "\nTest 5: Testing repair functionality" << RESET << std::endl;
    claptrap.beRepaired(8);
    std::cout << "Hit Points After Repairing 8: " << claptrap.getHitPoints() << std::endl;

    std::cout << MAGENTA << "\nTest 6: Testing over-damage beyond hit points" << RESET << std::endl;
    claptrap.takeDamage(100); // Should bring hit points to 0 or below
    claptrap.attack("Target C"); // Should not attack
    claptrap.beRepaired(5); // Should not repair

    std::cout << GREEN << "\nTest 7: Testing multiple ClapTrap objects independently" << RESET << std::endl;
    ClapTrap anotherClapTrap("Another Claptrap");
    anotherClapTrap.attack("Target D");
    anotherClapTrap.takeDamage(3);
    anotherClapTrap.beRepaired(2);

    std::cout << YELLOW << "\nTest 8: Testing destructor chaining with temporary objects" << RESET << std::endl;
    {
        ClapTrap tempClapTrap("Temporary Claptrap");
        tempClapTrap.attack("Temp Target");
    }

    std::cout << RED << "\nClapTrap destructing:" << RESET << std::endl;
    return 0;
}
