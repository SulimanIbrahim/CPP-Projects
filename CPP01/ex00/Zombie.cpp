#include "Zombie.hpp"

Zombie::Zombie()
{
    this->name = "Foo";
}

Zombie::~Zombie()
{
    std::cout << "Zombie " << this->name << " is dead" << std::endl;
}

void Zombie::announce(void)
{
    if (this->name == "Foo")
        std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
    else
        std::cout <<"<"<< this->name << ">: BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(std::string name)
{
    this->name = name;
}

Zombie* Zombie::newZombie( std::string name )
{
    Zombie *zombie = new Zombie();
    zombie->setName(name);
    return zombie;
}

void Zombie::randomChump( std::string name )
{
    Zombie zombie;
    zombie.setName(name);
    zombie.announce();
}