#ifndef ITER_HPP
#define ITER_HPP
#include <iostream>

template<class T, int n>
void iter(T (&arr)[n], size_t len, void (*func)(T const &)){
    if (!arr || !func)
        return;
    if (len > n)
        std::cout<< "len is not acceptable\n"; return ;
    for (size_t i = 0; i < len ; i++){
        func(arr[i]);
    }
}
template<class T, int n>
void iter(T (&arr)[n], size_t len, void (*func)(T &)){
    if (!arr || !func)
        return;
    if (len > n)
        std::cout<< "len is not acceptable\n"; return ;
    for (size_t i = 0; i < len ; i++){
        func(arr[i]);
    }
}

#endif