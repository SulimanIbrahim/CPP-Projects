#include "HumanA.hpp"
#include "HumanB.hpp"

int main(){
    {
        Weapon club = Weapon("glock");
        HumanA bob("Bob", club);
        bob.attack();
        club.setType("some other type of glock");
        bob.attack();
    }
    {
        Weapon club = Weapon("club");
        HumanB jim("Jim");
        jim.setWeapon(club);
        jim.attack();
        club.setType("some other type of club");
        jim.attack();
    }
    return 0;
}