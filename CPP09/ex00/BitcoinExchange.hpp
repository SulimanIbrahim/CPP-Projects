#pragma once
#include <iostream>
#include <exception>
#include <algorithm>
#include <vector>
#include <map>
#include <fstream>
#include <sstream>
#include <string>
#include <limits>
#include <cstdlib>
#include <ctime>
#include <iomanip>

class BitcoinExchange {
    private:
        std::map<std::string, float> _exchangeRates;
        bool isValidDate(const std::string& date) const;
        bool isValidValue(float value) const;
        bool isLeapYear(int year) const;
        int getDaysInMonth(int year, int month) const;
    public:
        BitcoinExchange();
        ~BitcoinExchange();
        BitcoinExchange(const BitcoinExchange& other);
        BitcoinExchange& operator=(const BitcoinExchange& other);
        void loadExchangeRates(const std::string& filename);
        void processInputFile(const std::string& filename);
        float getExchangeRate(const std::string& date) const;
};