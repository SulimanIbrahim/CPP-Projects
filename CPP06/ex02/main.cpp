#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <exception>

Base* generate(void) {
    std::srand(static_cast<unsigned int>(std::time(NULL)));
    
    int randomNum = std::rand() % 3;
    
    switch (randomNum) {
        case 0:
            std::cout << "Generated an instance of class A" << std::endl;
            return new A();
        case 1:
            std::cout << "Generated an instance of class B" << std::endl;
            return new B();
        case 2:
            std::cout << "Generated an instance of class C" << std::endl;
            return new C();
        default:
            return NULL;
    }
}

void identify(Base& p) {
    try {
        A& a = dynamic_cast<A&>(p);
        (void)a;
        std::cout << "A" << std::endl;
        return;
    } catch (std::exception& e) {}
    
    try {
        B& b = dynamic_cast<B&>(p);
        (void)b;
        std::cout << "B" << std::endl;
        return;
    } catch (std::exception& e) {}
    
    try {
        C& c = dynamic_cast<C&>(p);
        (void)c; 
        std::cout << "C" << std::endl;
        return;
    } catch (std::exception& e) {}
    
    std::cout << "Unknown type" << std::endl;
}

void identify(Base* p) {
    if (dynamic_cast<A*>(p) != NULL) {
        std::cout << "A" << std::endl;
    } else if (dynamic_cast<B*>(p) != NULL) {
        std::cout << "B" << std::endl;
    } else if (dynamic_cast<C*>(p) != NULL) {
        std::cout << "C" << std::endl;
    } else {
        std::cout << "Unknown type" << std::endl;
    }
}

int main() {
    Base* instance = generate();
    
    std::cout << "\nIdentification using pointer:" << std::endl;
    identify(instance);
    
    std::cout << "\nIdentification using reference:" << std::endl;
    identify(*instance);
    
    delete instance;
    
    return 0;
} 