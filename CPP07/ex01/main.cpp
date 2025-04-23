#include "Iter.hpp"



void echoInt(int &i)
{
    std::cout << i << std::endl;
}


int main( void ) {
    int         int_arr[] = {1, 2, 3, 4, 5};
    iter(int_arr, 5, echoInt);
    return 0;
}