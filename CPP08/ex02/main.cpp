#include "MutantStack.hpp"
#include <iostream>
#include <list>
#include <vector>

int main()
{
    // Test with the example from the subject
    std::cout << "==== MutantStack test from subject ====" << std::endl;
    MutantStack<int> mstack;
    
    mstack.push(5);
    mstack.push(17);
    
    std::cout << "Top element: " << mstack.top() << std::endl;
    
    mstack.pop();
    std::cout << "Size after pop: " << mstack.size() << std::endl;
    
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);
    
    // Using iterators
    std::cout << "\nIterating through MutantStack:" << std::endl;
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    
    while (it != ite)
    {
        std::cout << *it << " ";
        ++it;
    }
    std::cout << std::endl;
    
    // Copy constructor test
    std::stack<int> s(mstack);
    
    // Compare with std::list to verify similar behavior
    std::cout << "\n==== Comparison with std::list ====" << std::endl;
    std::list<int> lst;
    
    lst.push_back(5);
    lst.push_back(17);
    
    std::cout << "Top (back) element: " << lst.back() << std::endl;
    
    lst.pop_back();
    std::cout << "Size after pop: " << lst.size() << std::endl;
    
    lst.push_back(3);
    lst.push_back(5);
    lst.push_back(737);
    lst.push_back(0);
    
    // Using iterators with list
    std::cout << "\nIterating through std::list:" << std::endl;
    std::list<int>::iterator lst_it = lst.begin();
    std::list<int>::iterator lst_ite = lst.end();
    
    while (lst_it != lst_ite)
    {
        std::cout << *lst_it << " ";
        ++lst_it;
    }
    std::cout << std::endl;
    
    // Additional tests with different operations
    std::cout << "\n==== Additional MutantStack tests ====" << std::endl;
    
    // Test with strings
    MutantStack<std::string> strStack;
    strStack.push("Hello");
    strStack.push("World");
    strStack.push("42");
    
    std::cout << "String stack contents:" << std::endl;
    for (MutantStack<std::string>::iterator it = strStack.begin(); it != strStack.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    
    // Test reverse iterators
    std::cout << "\nReverse iteration:" << std::endl;
    MutantStack<int> numStack;
    for (int i = 1; i <= 5; i++) {
        numStack.push(i * 10);
    }
    
    std::cout << "Forward: ";
    for (MutantStack<int>::iterator it = numStack.begin(); it != numStack.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    
    std::cout << "Reverse: ";
    for (MutantStack<int>::reverse_iterator rit = numStack.rbegin(); rit != numStack.rend(); ++rit) {
        std::cout << *rit << " ";
    }
    std::cout << std::endl;
    
    // Test copy constructor
    std::cout << "\nTesting copy constructor:" << std::endl;
    MutantStack<int> copyStack(numStack);
    copyStack.push(60);
    
    std::cout << "Original stack: ";
    for (MutantStack<int>::iterator it = numStack.begin(); it != numStack.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    
    std::cout << "Copied stack: ";
    for (MutantStack<int>::iterator it = copyStack.begin(); it != copyStack.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    
    return 0;
}
