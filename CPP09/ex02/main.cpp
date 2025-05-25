#include "PmergeMe.hpp"

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cout << "Error: invalid number of arguments." << std::endl;
        return 1;
    }
    PmergeMe pmergeMe;
    try {
        pmergeMe.start(argv[1]);
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }
    return 0;
}
