
#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : name(name), weapon(weapon) {}


void HumanA::attack()
{
    if (this->weapon.getType().empty())
    {
        std::cout << "\033[1;31m" << "Error: Weapon type cannot be empty." << "\033[0m" << std::endl;
        return;
    }
    else if (this->name.empty())
    {
        std::cout << "\033[1;31m" << "Error: Human name cannot be empty." << "\033[0m" << std::endl;
        return;
    }
    std::cout << this->name << " attacks with his " << this->weapon.getType() << std::endl;
}
