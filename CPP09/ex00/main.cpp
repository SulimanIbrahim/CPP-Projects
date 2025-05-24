#include "BitcoinExchange.hpp"

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cout << "Error: could not open file." << std::endl;
        return 1;
    }
    
    try {
        BitcoinExchange bitcoin;
        // Load the database file with exchange rates
        bitcoin.loadExchangeRates("data.csv");
        
        // Process the input file provided as argument
        bitcoin.processInputFile(argv[1]);
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }

    return 0;
}
