#include "Zombie.hpp"

int main(){
    Zombie zombie;
    zombie.setName("Foo");
    zombie.setName("Suliman");
    zombie.setName("Foo");
    zombie.announce();
    zombie.newZombie("Baz")->announce();
    zombie.newZombie("Foo")->announce();
    zombie.randomChump("Foo");
}