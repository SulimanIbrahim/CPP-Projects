#include "Cat.hpp"
#include "Dog.hpp"
#include "Animal.hpp"
#include "WrongCat.hpp"
#include "WrongAnimal.hpp"
#include <iostream>

int main()
{
        const Animal* meta = new Animal();
        const Animal* j = new Dog();
        const Animal* i = new Cat();
        std::cout<<"######################################################################\n";
        std::cout<<"######################################################################\n";
        std::cout << j->getType() << " " << std::endl;
        std::cout << i->getType() << " " << std::endl;
        i->makeSound(); //will output the cat sound!
        j->makeSound();
        meta->makeSound();
        std::cout<<"######################################################################\n";
        delete meta;
        delete j;
        delete i;
        std::cout<<"######################################################################\n";
        const WrongAnimal* wrong = new WrongCat();
        wrong->makeSound();
        delete wrong;
        std::cout<<"######################################################################\n";
        return 0;
}