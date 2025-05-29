#pragma once

#include <iostream>
#include <vector>
#include <deque>
#include <string>
#include <sstream>
#include <utility>
#include <algorithm>

// Forward declarations for utility functions
std::vector<size_t> generateJacobsthalNumbers(size_t n);
void binaryInsert(std::vector<int>& arr, size_t right, int value);
void binaryInsertDeque(std::deque<int>& arr, size_t right, int value);

class PmergeMe
{
    private:
        std::vector<int> _vector;
        std::deque<int> _deque;
        std::string _input;
        
        // Input handling
        void parseInput(const std::string &input);
        void isNumber(const std::string &token);
        void isDuplicate();
        
        // Vector-based Ford-Johnson algorithm components
        void fordJohnsonForVector();
        int extractStrayElement(std::vector<int>& vec);
        std::vector<std::pair<int, int> > createSortedPairs(const std::vector<int>& vec);
        void extractLargerAndSmaller(
            const std::vector<std::pair<int, int> >& pairs, 
            std::vector<int>& larger, 
            std::vector<int>& smaller);
        std::vector<size_t> calculateInsertionOrder(size_t smallerSize);
        void insertSmallerElements(
            std::vector<int>& sortedSequence, 
            const std::vector<int>& smaller,
            const std::vector<size_t>& insertionOrder);
        
        // Deque-based Ford-Johnson algorithm components
        void fordJohnsonForDeque();
        int extractStrayElementDeque(std::deque<int>& deq);
        std::deque<std::pair<int, int  > > createSortedPairsDeque(const std::deque<int>& deq);
        void extractLargerAndSmallerDeque(
            const std::deque<std::pair<int, int> >& pairs, 
            std::deque<int>& larger, 
            std::deque<int>& smaller);
        void insertSmallerElementsDeque(
            std::deque<int>& sortedSequence, 
            const std::deque<int>& smaller,
            const std::vector<size_t>& insertionOrder);
        
        // Result handling
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
