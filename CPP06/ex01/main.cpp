#include "Serializer.hpp"
#include "Data.hpp"
#include <iostream>

int main()
{
    Data* original = new Data;
    original->id = 42;
    original->name = "Sample Data";
    original->value = 3.14159;
    
    std::cout << "Original Data:" << std::endl;
    std::cout << "ID: " << original->id << std::endl;
    std::cout << "Name: " << original->name << std::endl;
    std::cout << "Value: " << original->value << std::endl;
    std::cout << "Address: " << original << std::endl;
    
    uintptr_t serialized = Serializer::serialize(original);
    Data* deserialized = Serializer::deserialize(serialized);
    
    std::cout << "\nAfter serialization and deserialization:" << std::endl;
    std::cout << "Serialized value (uintptr_t): " << serialized << std::endl;
    std::cout << "Deserialized address: " << deserialized << std::endl;
    std::cout << "ID: " << deserialized->id << std::endl;
    std::cout << "Name: " << deserialized->name << std::endl;
    std::cout << "Value: " << deserialized->value << std::endl;
    
    std::cout << "\nVerification:" << std::endl;
    std::cout << "Same address? " << (original == deserialized ? "YES" : "NO") << std::endl;
    
    delete original;
    
    return 0;
} 