#ifndef DOG_HPP
#define DOG_HPP
#include "Aanimal.hpp"
    #include "Brain.hpp"

#include <iostream>

class Dog : public Aanimal {
    private:
        Brain *brain;
    public:
        Dog();
        Dog(const Dog &copy);
        Dog &operator=(const Dog &copy);
        ~Dog();
        void makeSound(void) const;
        void setIdea(int index, std::string idea);
        std::string getIdea(int index) const;
};

#endif