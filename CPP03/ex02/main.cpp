#include "FragTrap.hpp"
#include <iostream>

#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"

int main() {
    std::cout << BLUE << "Test 1: Creating FragTrap" << RESET << std::endl;
    FragTrap ft("Fraggy");

    std::cout << GREEN << "\nTest 2: Testing FragTrap's special ability" << RESET << std::endl;
    ft.highFivesGuys();

    std::cout << YELLOW << "\nTest 3: Testing attack functionality" << RESET << std::endl;
    ft.attack("Target A");
    std::cout << "Energy Points After Attack: " << ft.getEnergyPoints() << std::endl;

    std::cout << RED << "\nTest 4: Testing takeDamage functionality" << RESET << std::endl;
    ft.takeDamage(20);
    std::cout << "Hit Points After Damage: " << ft.getHitPoints() << std::endl;

    std::cout << CYAN << "\nTest 5: Testing repair functionality" << RESET << std::endl;
    ft.beRepaired(15);
    std::cout << "Hit Points After Repair: " << ft.getHitPoints() << std::endl;
    std::cout << "Energy Points After Repair: " << ft.getEnergyPoints() << std::endl;

    std::cout << MAGENTA << "\nTest 6: Exhausting energy points through multiple attacks" << RESET << std::endl;
    while (ft.getEnergyPoints() > 0) {
        ft.attack("Target B");
    }
    ft.attack("Target B (No Energy Left)");

    std::cout << BLUE << "\nTest 7: Testing FragTrap with full damage" << RESET << std::endl;
    ft.takeDamage(200);
    ft.attack("Target C");
    ft.beRepaired(10);

    std::cout << GREEN << "\nTest 8: Copy Constructor and Assignment" << RESET << std::endl;
    FragTrap copyFrag(ft);
    FragTrap assignedFrag = ft;
    copyFrag.highFivesGuys();
    assignedFrag.highFivesGuys();

    std::cout << YELLOW << "\nTest 9: Destructor Chaining Check" << RESET << std::endl;
    {
        FragTrap tempFrag("Temporary Fraggy");
        tempFrag.highFivesGuys();
    }

    std::cout << RED << "\nFragTrap destructing:" << RESET << std::endl;
    return 0;
}
