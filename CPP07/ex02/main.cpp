#include "Array.hpp"
#include <iostream>

int main( void ) {
    try {
        const Array<int> a(5);
        Array<int> b(5);
        const Array <int> c;

        c = a;

        // for (size_t i = 0; i < 5 ; i++)
        // {
        //     c[i] = i;
        // };

        std::cout << c[0] << std::endl;
    } catch (std::exception &e){
        std::cout << "error" << std::endl;
    }
    return 0;
}