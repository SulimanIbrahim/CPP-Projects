#include "Zombie.hpp"


int main()
{
    Zombie *zombie;
    Zombie *zombie1;
    zombie = zombieHorde(5, "Zombie");
    zombie1 = zombieHorde(5, "eibmoZ");
    for (int i = 0; i < 5; i++)
    {
        zombie[i].announce();
        zombie1[i].announce();
    }
    delete[] zombie;
    delete[] zombie1;
    return 0;
}
