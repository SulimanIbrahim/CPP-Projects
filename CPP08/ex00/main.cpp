#include "easyfind.hpp"
#include <vector>
#include <list>
#include <deque>
#include <iostream>

int main(void) {
    // Test with vector
    std::cout << "=== Testing with std::vector ===" << std::endl;
    std::vector<int> v;
    v.push_back(8);
    v.push_back(7);
    v.push_back(10);
    v.push_back(42);
    v.push_back(-1);

    try {
        std::vector<int>::iterator it = easyfind(v, 10);
        std::cout << "Found: " << *it << std::endl;
    } catch (std::exception &e) {
        std::cout << "Element not found" << std::endl;
    }

    try {
        std::vector<int>::iterator it = easyfind(v, 99);
        std::cout << "Found: " << *it << std::endl;
    } catch (std::exception &e) {
        std::cout << "Element not found" << std::endl;
    }

    // Test with list
    std::cout << "\n=== Testing with std::list ===" << std::endl;
    std::list<int> l;
    l.push_back(21);
    l.push_back(42);
    l.push_back(84);

    try {
        std::list<int>::iterator it = easyfind(l, 42);
        std::cout << "Found: " << *it << std::endl;
    } catch (std::exception &e) {
        std::cout << "Element not found" << std::endl;
    }

    try {
        std::list<int>::iterator it = easyfind(l, 100);
        std::cout << "Found: " << *it << std::endl;
    } catch (std::exception &e) {
        std::cout << "Element not found" << std::endl;
    }

    // Test with deque
    std::cout << "\n=== Testing with std::deque ===" << std::endl;
    std::deque<int> d;
    d.push_back(11);
    d.push_front(22);
    d.push_back(33);

    try {
        std::deque<int>::iterator it = easyfind(d, 22);
        std::cout << "Found: " << *it << std::endl;
    } catch (std::exception &e) {
        std::cout << "Element not found" << std::endl;
    }

    try {
        std::deque<int>::iterator it = easyfind(d, 44);
        std::cout << "Found: " << *it << std::endl;
    } catch (std::exception &e) {
        std::cout << "Element not found" << std::endl;
    }

    return 0;
}