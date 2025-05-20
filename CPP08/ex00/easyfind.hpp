#ifndef EASYFIND_HPP
#define EASYFIND_HPP
#include <iostream>
#include <exception>
#include <algorithm>
#include <vector>
template<typename T>
typename T::iterator easyfind(T array, int element){

    typename T::iterator element_found;

    element_found = std::find(array.begin(), array.end(), element);
    if (element_found != array.end())
        return (element_found);
    throw std::exception();
}

#endif