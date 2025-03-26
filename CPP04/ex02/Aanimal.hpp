#ifndef ANIMAL_HPP
#define ANIMAL_HPP
#include <iostream>

class Aanimal {
    protected:
        std::string _type;
    public:
        Aanimal();
        Aanimal(const Aanimal &copy);
        Aanimal &operator=(const Aanimal &copy);
        virtual ~Aanimal() = 0;
        virtual void makeSound(void) const = 0;
        std::string getType() const;
};

#endif