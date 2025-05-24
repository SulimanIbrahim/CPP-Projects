#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) {
    _exchangeRates = other._exchangeRates;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
    if (this != &other) {
        _exchangeRates = other._exchangeRates;
    }
    return *this;
}

bool BitcoinExchange::isLeapYear(int year) const {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int BitcoinExchange::getDaysInMonth(int year, int month) const {
    static const int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    if (month == 2 && isLeapYear(year))
        return 29;
    
    return daysInMonth[month];
}

bool BitcoinExchange::isValidDate(const std::string& date) const {
    // Check format YYYY-MM-DD
    if (date.length() != 10 || date[4] != '-' || date[7] != '-')
        return false;
    
    // Check if all characters are valid
    for (size_t i = 0; i < date.length(); i++) {
        if (i == 4 || i == 7) continue; // Skip hyphens
        if (!isdigit(date[i]))
            return false;
    }
    
    // Extract year, month, day
    int year, month, day;
    try {
        year = std::stoi(date.substr(0, 4));
        month = std::stoi(date.substr(5, 2));
        day = std::stoi(date.substr(8, 2));
    } catch (const std::exception&) {
        return false;
    }
    
    // Validate ranges
    if (year < 2009 || year > 2022) // Assuming valid range
        return false;
    if (month < 1 || month > 12)
        return false;
    if (day < 1 || day > getDaysInMonth(year, month))
        return false;
    
    return true;
}

bool BitcoinExchange::isValidValue(float value) const {
    return value >= 0 && value <= 1000;
}

void BitcoinExchange::loadExchangeRates(const std::string& filename) {
    std::ifstream file(filename.c_str());
    if (!file.is_open()) {
        throw std::runtime_error("Error: could not open file " + filename);
    }
    
    std::string line;
    // Skip header line
    std::getline(file, line);
    if (line != "date,exchange_rate") {
        throw std::runtime_error("Error: invalid header in database file");
    }
    
    while (std::getline(file, line)) {
        if (line.empty())
            continue;
        
        size_t pos = line.find(',');
        if (pos != std::string::npos) {
            std::string date = line.substr(0, pos);
            std::string rateStr = line.substr(pos + 1);
            
            if (!isValidDate(date)) {
                std::cerr << "Warning: Invalid date format in line: " << line << std::endl;
                continue;
            }
            
            try {
                float rate = std::stof(rateStr);
                _exchangeRates[date] = rate;
            } catch (const std::exception& e) {
                std::cerr << "Warning: Invalid rate format in line: " << line << std::endl;
            }
        }
    }
    
    if (_exchangeRates.empty()) {
        throw std::runtime_error("Error: no valid data in database file");
    }
    
    file.close();
}

float BitcoinExchange::getExchangeRate(const std::string& date) const {
    // Try to find exact date
    std::map<std::string, float>::const_iterator it = _exchangeRates.find(date);
    if (it != _exchangeRates.end()) {
        return it->second;
    }
    
    // Find closest earlier date
    it = _exchangeRates.lower_bound(date);
    
    // If no exact match and no lower date, or we got the first element
    if (it == _exchangeRates.begin() && it->first != date) {
        throw std::runtime_error("Error: no exchange rate available for date " + date);
    }
    
    // If we're at the end or the date is greater than requested, go back one
    if (it == _exchangeRates.end() || it->first > date) {
        --it;
    }
    
    return it->second;
}

void BitcoinExchange::processInputFile(const std::string& filename) {
    std::ifstream file(filename.c_str());
    if (!file.is_open()) {
        throw std::runtime_error("Error: could not open file " + filename);
    }
    
    std::string line;
    // Skip header line
    std::getline(file, line);
    if (line != "date | value") {
        throw std::runtime_error("Error: invalid header in input file");
    }
    while (std::getline(file, line)) {
        if (line.empty())
            throw std::runtime_error("Error: empty line in input file");
        
        size_t pos = line.find(" | ");
        if (pos == std::string::npos) {
            std::cout << "Error: bad input => " << line << std::endl;
            continue;
        }
        
        std::string dateStr = line.substr(0, pos);
        std::string valueStr = line.substr(pos + 3); // Skip " | "
        
        // Validate date
        if (!isValidDate(dateStr)) {
            std::cout << "Error: bad input => " << dateStr << std::endl;
            continue;
        }
        
        // Parse and validate value
        float value;
        try {
            value = std::stof(valueStr);
        } catch (const std::exception&) {
            std::cout << "Error: invalid value format" << std::endl;
            continue;
        }
        
        if (value < 0) {
            std::cout << "Error: not a positive number." << std::endl;
            continue;
        }
        
        if (value > 1000) {
            std::cout << "Error: too large a number." << std::endl;
            continue;
        }
        
        // Get exchange rate and calculate result
        try {
            float rate = getExchangeRate(dateStr);
            float result = value * rate;
            std::cout << dateStr << " => " << value << " = " << result << std::endl;
        } catch (const std::exception& e) {
            std::cout << e.what() << std::endl;
        }
    }
    if (file.bad()) {
        throw std::runtime_error("Error: could not read input file");
    }
    
    file.close();
}
