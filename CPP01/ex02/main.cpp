#include <iostream>
#include <string>

// Feature	                Pointer	                                              Reference
// Declaration	            int *ptr;	                                          int &ref = var;
// Initialization	        Can be initialized to nullptr or an address	          Must be initialized at declaration
// Reassignment	            Can point to different variables	                  Cannot be reseated to refer to another variable
// Dereferencing	        Requires * operator to access value	                  Accessed directly without *
// Memory Address	        Holds its own memory address	                      Shares the memory address of the referred variable
// Nullability	            Can be nullptr	                                      Cannot be null
// Pointer Arithmetic	    Supports arithmetic operations	                      Does not support arithmetic
// Size	                    8 bytes	                                              Same as the referred variable
// Memory Management	    Requires manual memory management	                  No memory management required
// Usage	                Used for dynamic memory allocation	                  Used for aliasing
//


int main()
{
    // Feature: Declaration
    std::string str = "HI THIS IS BRAIN";

    // Pointer Declaration
    std::string *stringPTR;

    // Reference Declaration (Must initialize at declaration)
    std::string &stringREF = str;

    // Feature: Initialization
    stringPTR = &str; // Can be initialized to nullptr or an address
    
    // stringREF = "NEW STRING"; // Error: Must be initialized at declaration and cannot change

    // Feature: Reassignment
    std::string anotherString = "Hello World!";
    
    stringPTR = &anotherString;  // Pointer can point to different variables

    // stringREF = anotherString; // Error: Reference cannot be reseated to another variable

    // Feature: Dereferencing
    std::cout << "Dereferencing Pointer: " << *stringPTR << std::endl; // Requires * to access the value
    std::cout << "Dereferencing Reference: " << stringREF << std::endl; // Directly accessed without *

    // Feature: Memory Address
    std::cout << "Pointer holds its own memory address: " << &stringPTR << std::endl;
    std::cout << "Reference shares memory address with referred variable: " << &stringREF << std::endl;

    // Feature: Nullability
    stringPTR = NULL; // Pointers can be nullptr
    if (stringPTR == NULL)
    {
        std::cout << "Pointer is null." << stringPTR << std::endl;
    }

    // stringREF = nullptr; // Error: Reference cannot be null

    // Feature: Pointer Arithmetic
    std::string arr[] = {"One", "Two", "Three"};
    std::string *arrPTR = arr;
    
    std::cout << "Pointer Arithmetic (arrPTR + 1): " << *(arrPTR + 1) << std::endl; // Supports arithmetic

    // References do not support arithmetic
    // std::string &arrREF = arr[0];
    // std::cout << "Reference Arithmetic: " << &arrREF + 1 << std::endl; // Error: No arithmetic allowed

    // Size
    std::cout << "Size of pointer: " << sizeof(stringPTR) << " bytes" << std::endl;
    std::cout << "Size of reference: " << sizeof(stringREF) << " bytes (same as referred variable)" << std::endl;

    // Feature: Memory Management
    // In C++, pointers are used for dynamic memory management, not demonstrated here.
    // References do not require manual memory management.

    // Feature: Usage
    std::cout << "Pointer Usage: Dynamic memory allocation (not shown here)." << std::endl;
    std::cout << "Reference Usage: Aliasing another variable (shown with stringREF)." << std::endl;

    return 0;
}
