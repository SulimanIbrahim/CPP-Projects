#include <iostream>
#include "Harl.hpp"

int main(int ac, char **av){

    Harl harl;

    if (!av[1])
        return 1;
    std::string level = av[1];
    harl.complain(level);

    return 0;
}