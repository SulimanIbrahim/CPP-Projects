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
    std::string str = "HI THIS IS BRAIN";
    std::string *stringPTR;
    std::string &stringREF = str;
    stringPTR = &str; 
    std::string anotherString = "Hello World!";
    stringPTR = &anotherString;

    std::cout << "Dereferencing Pointer: " << *stringPTR << std::endl; 
    std::cout << "Dereferencing Reference: " << stringREF << std::endl; 

    std::cout << "Pointer holds its own memory address: " << &stringPTR << std::endl;
    std::cout << "Reference shares memory address with referred variable: " << &stringREF << std::endl;

    stringPTR = NULL;
    if (stringPTR == NULL)
    {
        std::cout << "Pointer is null." << stringPTR << std::endl;
    }

    std::string arr[] = {"One", "Two", "Three"};
    std::string *arrPTR = arr;
    std::cout << "Pointer Arithmetic (arrPTR + 1): " << *(arrPTR + 1) << std::endl; 
  
    std::cout << "Size of pointer: " << sizeof(stringPTR) << " bytes" << std::endl;
    std::cout << "Size of reference: " << sizeof(stringREF) << " bytes (same as referred variable)" << std::endl;
   
    std::cout << "Pointer Usage: Dynamic memory allocation (not shown here)." << std::endl;
    std::cout << "Reference Usage: Aliasing another variable (shown with stringREF)." << std::endl;

    return 0;
}
