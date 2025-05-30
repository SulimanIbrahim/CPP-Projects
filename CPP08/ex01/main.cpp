#include "Span.hpp"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <list>

int main()
{
    // Basic test from subject
    try {
        std::cout << "==== Basic test from subject ====" << std::endl;
        Span sp = Span(5);
        
        sp.addNumber(6);
        sp.addNumber(3);
    

        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
     try {

         // Test with a larger number of elements
         std::cout << "\n==== Test with 10,000,000 numbers ====" << std::endl;
         Span largeSpan = Span(10000000);
         
         // Fill using the range insertion method
         std::vector<int> numbers;
         for (int i = 0; i < 10000000; i++)
         numbers.push_back(rand() % 10000000);
        
        largeSpan.addNumbers(numbers.begin(), numbers.end());
        
        std::cout << "Shortest span: " << largeSpan.shortestSpan() << std::endl;
        std::cout << "Longest span: " << largeSpan.longestSpan() << std::endl;
        
        // Test edge cases
        std::cout << "\n==== Edge cases ====" << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    
    // Test with empty span
    Span emptySpan = Span(5);
    try {
        std::cout << "Trying to find shortest span in empty span: ";
        emptySpan.shortestSpan();
    } catch(const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    
    // Test with one element
    Span oneElem = Span(5);
    oneElem.addNumber(42);
    try {
        std::cout << "Trying to find longest span with one element: ";
        oneElem.longestSpan();
    } catch(const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    
    // Test adding too many numbers
    Span fullSpan = Span(3);
    fullSpan.addNumber(1);
    fullSpan.addNumber(2);
    fullSpan.addNumber(3);
    
    try {
        std::cout << "Trying to add one more element to full span: ";
        fullSpan.addNumber(4);
    } catch(const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    
    // Test adding range that exceeds capacity
    Span smallSpan = Span(3);
    std::vector<int> manyNumbers(5, 10);  // 5 elements with value 10
    
    try {
        std::cout << "Trying to add 5 elements to span with capacity 3: ";
        smallSpan.addNumbers(manyNumbers.begin(), manyNumbers.end());
    } catch(const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    
    // Another range insertion test with std::list
    std::cout << "\n==== Test with std::list range insertion ====" << std::endl;
    Span listSpan = Span(5);
    std::list<int> listNumbers;
    listNumbers.push_back(23);
    listNumbers.push_back(11);
    listNumbers.push_back(37);
    listNumbers.push_back(4);
    listNumbers.push_back(42);
    
    listSpan.addNumbers(listNumbers.begin(), listNumbers.end());
    std::cout << "Shortest span: " << listSpan.shortestSpan() << std::endl;
    std::cout << "Longest span: " << listSpan.longestSpan() << std::endl;
    
    return 0;
}
