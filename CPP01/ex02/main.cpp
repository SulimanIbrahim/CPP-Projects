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
    std::string *stringPTR = &str;
    std::string &stringREF = str;

    std::cout << "Address in memory of the string: " << &str << std::endl;
    std::cout << "Address in memory of the stringPTR: " << stringPTR << std::endl;
    std::cout << "Address in memory of the stringREF: " << &stringREF << std::endl;
    std::cout << "String: " << str << std::endl;
    std::cout << "StringPTR: " << *stringPTR << std::endl;
    std::cout << "StringREF: " << stringREF << std::endl;
    return 0;
}