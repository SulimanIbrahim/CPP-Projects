#include "Zombie.hpp"

int main(){
    Zombie zombie;
    // zombie.setName("Foo");
    // zombie.setName("Suliman");
    // zombie.setName("Foo");
    // zombie.announce();
    Zombie *haben_zombie = zombie.newZombie("haben");
    haben_zombie->announce();
    delete haben_zombie;
    zombie.randomChump("Foo");
}