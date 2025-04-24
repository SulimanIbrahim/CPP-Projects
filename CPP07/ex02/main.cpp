#include "Array.hpp"
#include <iostream>
#include <string>

void printLine() {
    std::cout << "----------------------------------------" << std::endl;
}

int main() {
    // Test default constructor (empty array)
    std::cout << "=== Testing default constructor ===" << std::endl;
    Array<int> emptyArray;
    std::cout << "Size of empty array: " << emptyArray.size() << std::endl;
    
    try {
        std::cout << "Trying to access element 0: ";
        std::cout << emptyArray[0] << std::endl;
    } catch (std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    printLine();
    
    // Test with int array
    std::cout << "=== Testing with int array ===" << std::endl;
    Array<int> intArray(5);
    
    // Initialize array
    for (size_t i = 0; i < intArray.size(); i++) {
        intArray[i] = i * 10;
    }
    
    // Print array
    std::cout << "Int array contents:" << std::endl;
    for (size_t i = 0; i < intArray.size(); i++) {
        std::cout << "intArray[" << i << "] = " << intArray[i] << std::endl;
    }
    
    // Test copy constructor
    std::cout << "\n=== Testing copy constructor ===" << std::endl;
    Array<int> intArrayCopy(intArray);
    
    std::cout << "Original array:" << std::endl;
    for (size_t i = 0; i < intArray.size(); i++) {
        std::cout << "intArray[" << i << "] = " << intArray[i] << std::endl;
    }
    
    std::cout << "\nCopied array:" << std::endl;
    for (size_t i = 0; i < intArrayCopy.size(); i++) {
        std::cout << "intArrayCopy[" << i << "] = " << intArrayCopy[i] << std::endl;
    }
    
    // Verify deep copy
    std::cout << "\nModifying original array element 2 to 999" << std::endl;
    intArray[2] = 999;
    
    std::cout << "Original array after modification:" << std::endl;
    for (size_t i = 0; i < intArray.size(); i++) {
        std::cout << "intArray[" << i << "] = " << intArray[i] << std::endl;
    }
    
    std::cout << "\nCopied array (should remain unchanged):" << std::endl;
    for (size_t i = 0; i < intArrayCopy.size(); i++) {
        std::cout << "intArrayCopy[" << i << "] = " << intArrayCopy[i] << std::endl;
    }
    printLine();
    
    // Test assignment operator
    std::cout << "=== Testing assignment operator ===" << std::endl;
    Array<int> intArrayAssigned;
    intArrayAssigned = intArray;
    
    std::cout << "Assigned array:" << std::endl;
    for (size_t i = 0; i < intArrayAssigned.size(); i++) {
        std::cout << "intArrayAssigned[" << i << "] = " << intArrayAssigned[i] << std::endl;
    }
    
    // Verify deep copy via assignment
    std::cout << "\nModifying original array element 0 to 555" << std::endl;
    intArray[0] = 555;
    
    std::cout << "Original array after modification:" << std::endl;
    for (size_t i = 0; i < intArray.size(); i++) {
        std::cout << "intArray[" << i << "] = " << intArray[i] << std::endl;
    }
    
    std::cout << "\nAssigned array (should remain unchanged):" << std::endl;
    for (size_t i = 0; i < intArrayAssigned.size(); i++) {
        std::cout << "intArrayAssigned[" << i << "] = " << intArrayAssigned[i] << std::endl;
    }
    printLine();
    
    // Test out of bounds access
    std::cout << "=== Testing out of bounds exception ===" << std::endl;
    try {
        std::cout << "Trying to access element at index 10: ";
        std::cout << intArray[10] << std::endl;
    } catch (std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    printLine();
    
    // Test with string array
    std::cout << "=== Testing with string array ===" << std::endl;
    Array<std::string> stringArray(3);
    stringArray[0] = "Hello";
    stringArray[1] = "C++";
    stringArray[2] = "Templates";
    
    std::cout << "String array contents:" << std::endl;
    for (size_t i = 0; i < stringArray.size(); i++) {
        std::cout << "stringArray[" << i << "] = " << stringArray[i] << std::endl;
    }
    
    return 0;
}