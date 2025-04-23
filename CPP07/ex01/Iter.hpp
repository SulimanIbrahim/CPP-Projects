#ifndef ITER_HPP
#define ITER_HPP
#include <iostream>

template<class T>
void iter(T* arr, size_t len, void (*func)(T&)){
    if (!arr || !func)
        return;
    for (size_t i = 0; i < len ; i++){
        func(arr[i]);
    }
}

#endif