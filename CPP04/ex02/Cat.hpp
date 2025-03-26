#ifndef CAT_HPP
#define CAT_HPP
#include <iostream>
#include "Aanimal.hpp"
#include "Brain.hpp"


class Cat : public Aanimal {
    private:
        Brain *brain;
    public:
        Cat();
        Cat(const Cat &copy);
        Cat &operator=(const Cat &copy);
        ~Cat();
        void makeSound() const;
        void setIdea(int index, std::string idea);
        std::string getIdea(int index) const;
};

#endif