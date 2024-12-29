#include "DiamondTrap.hpp"
#include <iostream>

#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"

int main() {
    std::cout << BLUE << "Test 1: Creating DiamondTrap" << RESET << std::endl;
    DiamondTrap diamond("monster");
   
    std::cout << BLUE << "\nTest 2: Attack" << RESET << std::endl;
    diamond.attack("target");
 
    std::cout << BLUE << "\nTest 3: Guard Gate" << RESET << std::endl;
    diamond.guardGate();

    std::cout << BLUE << "\nTest 4: Who Am I" << RESET << std::endl;
    diamond.whoAmI();

    std::cout << RED << "\nDiamondTrap destructing:" << RESET << std::endl;
    return 0;
}
