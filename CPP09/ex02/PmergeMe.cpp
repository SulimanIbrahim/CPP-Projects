#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &other) {
    _vector = other._vector;
    _deque = other._deque;
    _input = other._input;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other) {
    if (this != &other) {
        _vector = other._vector;
        _deque = other._deque;
        _input = other._input;
    }
    return *this;
}

void PmergeMe::isDuplicate(){
    for (size_t i = 0; i < _vector.size(); i++){
        for (size_t j = i + 1; j < _vector.size(); j++) 
        {
            if (_vector[i] == _vector[j])
                throw std::runtime_error("Duplicated numbers not allowed");
        }
    }
    for (size_t i = 0; i < _deque.size(); i++){
        for (size_t j = i + 1; j < _deque.size(); j++) 
        {
            if (_deque[i] == _deque[j])
                throw std::runtime_error("Duplicated numbers not allowed");
        }
    }
}

void PmergeMe::parseInput(const std::string &input) {
    std::stringstream ss(input);
    std::string token;
    while (std::getline(ss, token, ' ')) {
        try {
            isNumber(token);
            int number = std::stoi(token);
            if (number < 0) {
                throw std::runtime_error("Invalid input: expected a positive number");
            }
            _vector.push_back(number);
            _deque.push_back(number);
        } catch (const std::exception &e) {
            throw std::runtime_error("Invalid input: expected a number");
        }
    }
}

void PmergeMe::fordJohnsonForVector() {
        
}

void PmergeMe::isNumber(const std::string &token) {
    for(size_t i = 0; i < token.length(); i++) {
        if (!std::isdigit(token[i]))
            throw std::runtime_error("Invalid input: " + token + " is not a number");
    }
}

void PmergeMe::start(const std::string &input) {
    _input = input;
    parseInput(input);
    isDuplicate();
    fordJohnsonForVector();
    // fordJohnsonForDeque();
    // calculateTime();
    // printResult();
}