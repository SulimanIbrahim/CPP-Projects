#pragma once

#include <iostream>
#include <vector>
#include <deque>
#include <string>
#include <sstream>

class PmergeMe
{
    private:
        std::vector<int> _vector;
        std::deque<int> _deque;
        std::string _input;        
        void parseInput(const std::string &input);
        void isNumber(const std::string &token);
        void isDuplicate();
        // void fordJohnsonForVector();
        // void fordJohnsonForDeque();
        // void calculateTime();
        // void printResult();

    public:
        PmergeMe();
        ~PmergeMe();
        PmergeMe(const PmergeMe &other);
        PmergeMe &operator=(const PmergeMe &other);

        void start(const std::string &input);
};
