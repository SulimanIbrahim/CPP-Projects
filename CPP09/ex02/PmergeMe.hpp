#pragma once

#include <iostream>
#include <vector>
#include <deque>
#include <string>
#include <sstream>
#include <utility>
    

class PmergeMe
{
    private:
        std::vector<int> _vector;
        std::deque<int> _deque;
        std::string _input;        
        void parseInput(const std::string &input);
        void isNumber(const std::string &token);
        void isDuplicate();
        void fordJohnsonForVector();
        void fordJohnsonForDeque();
        void calculateTime();
        void printResult();
        
        // Time measurement variables
        double _vectorTime;
        double _dequeTime;

    public:
        PmergeMe();
        ~PmergeMe();
        PmergeMe(const PmergeMe &other);
        PmergeMe &operator=(const PmergeMe &other);

        void start(const std::string &input);
};
