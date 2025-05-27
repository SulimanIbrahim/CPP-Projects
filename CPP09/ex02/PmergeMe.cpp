#include "PmergeMe.hpp"
#include <sys/time.h>

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



// Helper function to generate Jacobsthal numbers
// These numbers determine the insertion order in Ford-Johnson algorithm
std::vector<size_t> generateJacobsthalNumbers(size_t n) {
    std::vector<size_t> jacobsthal;
    if (n <= 0) return jacobsthal;
    
    jacobsthal.push_back(0); // J(0) = 0
    if (n == 1) return jacobsthal;
    
    jacobsthal.push_back(1); // J(1) = 1
    size_t i = 2;
    while (jacobsthal.back() < n) {
        // J(n) = J(n-1) + 2*J(n-2)
        size_t next = jacobsthal[i-1] + 2 * jacobsthal[i-2];
        if (next > n) break;
        jacobsthal.push_back(next);
        i++;
    }
    return jacobsthal;
}

// Helper function for binary insertion
void binaryInsert(std::vector<int>& arr, size_t right, int value) {
    // Binary search to find insertion point
    size_t left = 0;
    while (left < right) {
        size_t mid = left + (right - left) / 2;
        if (arr[mid] <= value) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    
    // Shift elements to make room for the new value
    arr.insert(arr.begin() + left, value);
}

void PmergeMe::fordJohnsonForVector() {
    // Simple cases
    if (_vector.size() <= 1) {
        return; // Already sorted
    }
    
    // Create a copy of the original vector to work with
    std::vector<int> originalVector = _vector;
    
    // Handle the stray element if the size is odd
    int strayElement = -1;
    if (originalVector.size() % 2 != 0) {
        strayElement = originalVector.back();
        originalVector.pop_back();
    }
    
    // Step 1: Form pairs and sort them internally
    std::vector<std::pair<int, int> > pairs;
    for (size_t i = 0; i < originalVector.size(); i += 2) {
        int a = originalVector[i];
        int b = originalVector[i + 1];
        // Store pairs as (larger, smaller)
        if (a > b) {
            pairs.push_back(std::make_pair(a, b));
        } else {
            pairs.push_back(std::make_pair(b, a));
        }
    }
    
    // Step 2: Extract the larger and smaller elements
    std::vector<int> larger, smaller;
    for (size_t i = 0; i < pairs.size(); i++) {
        larger.push_back(pairs[i].first);  // Larger elements
        smaller.push_back(pairs[i].second); // Smaller elements
    }
    
    // Step 3: Recursively sort the larger elements
    if (larger.size() > 1) {
        // Make a temporary copy and sort it
        _vector = larger;
        fordJohnsonForVector();
        larger = _vector;
    }
    
    // Step 4: Create the main chain with sorted larger elements
    std::vector<int> sortedSequence = larger;
    
    // Step 5: Insert the smaller elements using binary insertion in a specific order
    // Determine insertion sequence using Jacobsthal numbers
    std::vector<size_t> jacobsthalPos;
    
    // Insert the first smaller element
    if (!smaller.empty()) {
        binaryInsert(sortedSequence, 1, smaller[0]);  // Insert after first element
    }
    
    // Generate Jacobsthal numbers
    std::vector<size_t> jacobsthal = generateJacobsthalNumbers(smaller.size());
    
    // Build insertion order from Jacobsthal numbers
    std::vector<size_t> insertionOrder;
    if (smaller.size() > 0) {
        insertionOrder.push_back(0); // Always start with the first element
    }
    
    // Use Jacobsthal numbers to determine insertion order
    for (size_t i = 1; i < jacobsthal.size(); i++) {
        size_t prev = jacobsthal[i - 1];
        size_t curr = jacobsthal[i];
        
        // Add positions in reverse order
        for (size_t j = curr; j > prev; j--) {
            if (j - 1 < smaller.size()) {
                insertionOrder.push_back(j - 1);
            }
        }
    }
    
    // Add any remaining positions
    size_t last = jacobsthal.empty() ? 0 : jacobsthal.back();
    for (size_t i = last + 1; i <= smaller.size(); i++) {
        if (i - 1 < smaller.size() && i - 1 > 0) { // Skip first element already inserted
            insertionOrder.push_back(i - 1);
        }
    }
    
    // Insert the smaller elements using binary search
    for (size_t i = 0; i < insertionOrder.size(); i++) {
        size_t index = insertionOrder[i];
        if (index < smaller.size() && index > 0) { // Skip first element (already inserted)
            int element = smaller[index];
            binaryInsert(sortedSequence, sortedSequence.size(), element);
        }
    }
    
    // Step 6: Insert the stray element (if any) using binary search
    if (strayElement != -1) {
        binaryInsert(sortedSequence, sortedSequence.size(), strayElement);
    }
    
    // Update the original vector with the sorted result
    _vector = sortedSequence;
}

void PmergeMe::isNumber(const std::string &token) {
    for(size_t i = 0; i < token.length(); i++) {
        if (!std::isdigit(token[i]))
            throw std::runtime_error("Invalid input: " + token + " is not a number");
    }
}

// Helper function for binary insertion with deque
void binaryInsertDeque(std::deque<int>& arr, size_t right, int value) {
    // Binary search to find insertion point
    size_t left = 0;
    while (left < right) {
        size_t mid = left + (right - left) / 2;
        if (arr[mid] <= value) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    
    // Insert at the correct position
    arr.insert(arr.begin() + left, value);
}

void PmergeMe::fordJohnsonForDeque() {
    // Simple cases
    if (_deque.size() <= 1) {
        return; // Already sorted
    }
    
    // Create a copy of the original deque to work with
    std::deque<int> originalDeque = _deque;
    
    // Handle the stray element if the size is odd
    int strayElement = -1;
    if (originalDeque.size() % 2 != 0) {
        strayElement = originalDeque.back();
        originalDeque.pop_back();
    }
    
    // Step 1: Form pairs and sort them internally
    std::deque<std::pair<int, int> > pairs;
    for (size_t i = 0; i < originalDeque.size(); i += 2) {
        int a = originalDeque[i];
        int b = originalDeque[i + 1];
        // Store pairs as (larger, smaller)
        if (a > b) {
            pairs.push_back(std::make_pair(a, b));
        } else {
            pairs.push_back(std::make_pair(b, a));
        }
    }
    
    // Step 2: Extract the larger and smaller elements
    std::deque<int> larger, smaller;
    for (size_t i = 0; i < pairs.size(); i++) {
        larger.push_back(pairs[i].first);  // Larger elements
        smaller.push_back(pairs[i].second); // Smaller elements
    }
    
    // Step 3: Recursively sort the larger elements
    if (larger.size() > 1) {
        // Make a temporary copy and sort it
        _deque = larger;
        fordJohnsonForDeque();
        larger = _deque;
    }
    
    // Step 4: Create the main chain with sorted larger elements
    std::deque<int> sortedSequence = larger;
    
    // Step 5: Insert the smaller elements using binary insertion in a specific order
    // Determine insertion sequence using Jacobsthal numbers
    std::vector<size_t> jacobsthalPos;
    
    // Insert the first smaller element
    if (!smaller.empty()) {
        binaryInsertDeque(sortedSequence, 1, smaller[0]);  // Insert after first element
    }
    
    // Generate Jacobsthal numbers
    std::vector<size_t> jacobsthal = generateJacobsthalNumbers(smaller.size());
    
    // Build insertion order from Jacobsthal numbers
    std::vector<size_t> insertionOrder;
    if (smaller.size() > 0) {
        insertionOrder.push_back(0); // Always start with the first element
    }
    
    // Use Jacobsthal numbers to determine insertion order
    for (size_t i = 1; i < jacobsthal.size(); i++) {
        size_t prev = jacobsthal[i - 1];
        size_t curr = jacobsthal[i];
        
        // Add positions in reverse order
        for (size_t j = curr; j > prev; j--) {
            if (j - 1 < smaller.size()) {
                insertionOrder.push_back(j - 1);
            }
        }
    }
    
    // Add any remaining positions
    size_t last = jacobsthal.empty() ? 0 : jacobsthal.back();
    for (size_t i = last + 1; i <= smaller.size(); i++) {
        if (i - 1 < smaller.size() && i - 1 > 0) { // Skip first element already inserted
            insertionOrder.push_back(i - 1);
        }
    }
    
    // Insert the smaller elements using binary search
    for (size_t i = 0; i < insertionOrder.size(); i++) {
        size_t index = insertionOrder[i];
        if (index < smaller.size() && index > 0) { // Skip first element (already inserted)
            int element = smaller[index];
            binaryInsertDeque(sortedSequence, sortedSequence.size(), element);
        }
    }
    
    // Step 6: Insert the stray element (if any) using binary search
    if (strayElement != -1) {
        binaryInsertDeque(sortedSequence, sortedSequence.size(), strayElement);
    }
    
    // Update the original deque with the sorted result
    _deque = sortedSequence;
    
    // Update the original deque with the sorted sequence
    _deque = sortedSequence;
}

void PmergeMe::calculateTime() {
    // This should be called from start() after timing the operations
    // The actual timing is done in the start() method
}

void PmergeMe::printResult() {
    std::cout << "Before: " << _input << std::endl;
    
    std::cout << "After: ";
    for (size_t i = 0; i < _vector.size(); i++) {
        std::cout << _vector[i] << " ";
    }
    std::cout << std::endl;
    
    std::cout << "Time to process a range of " << _vector.size() 
              << " elements with std::vector: " << _vectorTime 
              << " microseconds" << std::endl;
    
    std::cout << "Time to process a range of " << _deque.size() 
              << " elements with std::deque: " << _dequeTime 
              << " microseconds" << std::endl;
}

void PmergeMe::start(const std::string &input) {
    _input = input;
    parseInput(input);
    isDuplicate();
    
    // Store original vectors for printing "before" state
    std::vector<int> originalVector = _vector;
    std::deque<int> originalDeque = _deque;
    
    // Time the vector implementation
    struct timeval start, end;
    gettimeofday(&start, NULL);
    fordJohnsonForVector();
    gettimeofday(&end, NULL);
    _vectorTime = (end.tv_sec - start.tv_sec) * 1000000.0 + (end.tv_usec - start.tv_usec);
    
    // Reset for deque implementation
    _deque = originalDeque;
    
    // Time the deque implementation
    gettimeofday(&start, NULL);
    fordJohnsonForDeque();
    gettimeofday(&end, NULL);
    _dequeTime = (end.tv_sec - start.tv_sec) * 1000000.0 + (end.tv_usec - start.tv_usec);
    
    printResult();
}