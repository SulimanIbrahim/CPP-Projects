#include "PmergeMe.hpp"
#include <sys/time.h>

int recursion_calls = 0;

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

void PmergeMe::isDuplicate() {
    for (size_t i = 0; i < _vector.size(); i++) {
        for (size_t j = i + 1; j < _vector.size(); j++) {
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

// Utility function to check if token is a number
void PmergeMe::isNumber(const std::string &token) {
    for(size_t i = 0; i < token.length(); i++) {
        if (!std::isdigit(token[i]))
            throw std::runtime_error("Invalid input: " + token + " is not a number");
    }
}

// Generate Jacobsthal sequence up to n
std::vector<size_t> generateJacobsthalNumbers(size_t n) {
    std::vector<size_t> jacobsthal;
    if (n <= 0) return jacobsthal;
    
    jacobsthal.push_back(0);
    if (n == 1) return jacobsthal;
    
    jacobsthal.push_back(1);
    size_t i = 2;
    while (jacobsthal.back() < n) {
        // J(n) = J(n-1) + 2*J(n-2)
        //0, 1, 1, 3, 5, 11, 21, 43..
        size_t next = jacobsthal[i-1] + 2 * jacobsthal[i-2];
        if (next > n) break;
        jacobsthal.push_back(next);
        i++;
    }
    return jacobsthal;
}

void binaryInsert(std::vector<int>& arr, size_t right, int value) {
    std::vector<int>::iterator it = std::lower_bound(arr.begin(), arr.begin() + right, value);
    arr.insert(it, value);
}

void binaryInsertDeque(std::deque<int>& arr, size_t right, int value) {
    std::deque<int>::iterator it = std::lower_bound(arr.begin(), arr.begin() + right, value);
    arr.insert(it, value);
}

int PmergeMe::extractStrayElement(std::vector<int>& vec) {
    int strayElement = -1;
    if (vec.size() % 2 != 0) {
        strayElement = vec.back();
        vec.pop_back();
    }
    return strayElement;
}

std::vector<std::pair<int, int> > PmergeMe::createSortedPairs(const std::vector<int>& vec) {
    std::vector<std::pair<int, int> > pairs;
    for (size_t i = 0; i < vec.size(); i += 2) {
        int a = vec[i];
        int b = vec[i + 1];
        if (a > b) {
            pairs.push_back(std::make_pair(a, b));
        } else {
            pairs.push_back(std::make_pair(b, a));
        }
    }
    return pairs;
}

void PmergeMe::extractLargerAndSmaller(
    const std::vector<std::pair<int, int> >& pairs, 
    std::vector<int>& larger, 
    std::vector<int>& smaller) {
    
    for (size_t i = 0; i < pairs.size(); i++) {
        larger.push_back(pairs[i].first);
        smaller.push_back(pairs[i].second);
    }
}

void printVector(const std::string& label, const std::vector<int>& vec) {
    std::cout << label << ": ";
    for (size_t i = 0; i < vec.size(); i++) {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;
}

std::vector<size_t> PmergeMe::calculateInsertionOrder(size_t smallerSize) {
    std::vector<size_t> jacobsthal = generateJacobsthalNumbers(smallerSize);
    
    std::vector<size_t> insertionOrder;
    if (smallerSize > 0) {
        insertionOrder.push_back(0); // Always start with the first element
    }
    
    for (size_t i = 1; i < jacobsthal.size(); i++) {
        size_t prev = jacobsthal[i - 1];
        size_t curr = jacobsthal[i];
        
        // Add positions in reverse order between Jacobsthal gaps
        for (size_t j = curr; j > prev; j--) {
            if (j - 1 < smallerSize) {
                insertionOrder.push_back(j - 1);
            }
        }
    }
    // Add any remaining positions
    size_t last = jacobsthal.empty() ? 0 : jacobsthal.back();
    for (size_t i = last + 1; i <= smallerSize; i++) {
        if (i - 1 < smallerSize && i - 1 > 0) { // Skip first element already inserted
            insertionOrder.push_back(i - 1);
        }
    }
    return insertionOrder;
}

void PmergeMe::insertSmallerElements(
    std::vector<int>& sortedSequence, 
    const std::vector<int>& smaller,
    const std::vector<size_t>& insertionOrder) {
    
    for (size_t i = 0; i < insertionOrder.size(); i++) {
        size_t index = insertionOrder[i];
        if (index < smaller.size() && index > 0) { // Skip first element (already inserted)
            int element = smaller[index];
            binaryInsert(sortedSequence, sortedSequence.size(), element);
        }
    }
}

// Debug function to print insertion order
void printInsertionOrder(const std::vector<size_t>& order) {
    std::cout << "Insertion order: ";
    for (size_t i = 0; i < order.size(); i++) {
        std::cout << order[i] << " ";
    }
    std::cout << std::endl;
}

void PmergeMe::fordJohnsonForVector() {
    if (_vector.size() <= 1) {
        return; 
    }
    std::vector<int> originalVector = _vector;
    // Step 1: Extract stray element if array size is odd
    int strayElement = extractStrayElement(originalVector);
    // Step 2: Create sorted pairs
    std::vector<std::pair<int, int> > pairs = createSortedPairs(originalVector);
    // Step 3: Extract larger and smaller elements
    std::vector<int> larger, smaller;
    extractLargerAndSmaller(pairs, larger, smaller);
    // Step 4: Recursively sort larger elements
    if (larger.size() > 1) {
        _vector = larger;
        fordJohnsonForVector();
        larger = _vector;
    }
    printVector("Larger", larger);
    printVector("Smaller", smaller);
    std::vector<int> sortedSequence = larger;
    // Step 6: Insert first element from smaller array
    if (!smaller.empty()) {
        binaryInsert(sortedSequence, 1, smaller[0]);
    }
    // Step 7: Calculate insertion order using Jacobsthal numbers
    std::vector<size_t> insertionOrder = calculateInsertionOrder(smaller.size());
    
    // Debug output
    printInsertionOrder(insertionOrder);
    
    // Step 8: Insert remaining smaller elements according to insertion order
    insertSmallerElements(sortedSequence, smaller, insertionOrder);
    
    // Step 9: Insert stray element if present
    if (strayElement != -1) {
        binaryInsert(sortedSequence, sortedSequence.size(), strayElement);
    }
    
    // Debug output for final sequence
    printVector("Sorted sequence", sortedSequence);
    
    // Update recursion counter and output
    recursion_calls++;
    std::cout << "--------------------------------  end of recursion number : " 
              << recursion_calls << "--------------------------------" << std::endl;
    
    // Update original vector with sorted sequence
    _vector = sortedSequence;
}

// Similar refactoring for deque implementation
// Extract stray element for deque
int PmergeMe::extractStrayElementDeque(std::deque<int>& deq) {
    int strayElement = -1;
    if (deq.size() % 2 != 0) {
        strayElement = deq.back();
        deq.pop_back();
    }
    return strayElement;
}

// Create sorted pairs from the input deque
std::deque<std::pair<int, int> > PmergeMe::createSortedPairsDeque(const std::deque<int>& deq) {
    std::deque<std::pair<int, int> > pairs;
    for (size_t i = 0; i < deq.size(); i += 2) {
        int a = deq[i];
        int b = deq[i + 1];
        if (a > b) {
            pairs.push_back(std::make_pair(a, b));
        } else {
            pairs.push_back(std::make_pair(b, a));
        }
    }
    return pairs;
}

// Extract larger and smaller elements from pairs (deque version)
void PmergeMe::extractLargerAndSmallerDeque(
    const std::deque<std::pair<int, int> >& pairs, 
    std::deque<int>& larger, 
    std::deque<int>& smaller) {
    
    for (size_t i = 0; i < pairs.size(); i++) {
        larger.push_back(pairs[i].first);
        smaller.push_back(pairs[i].second);
    }
}

// Insert smaller elements according to the insertion order (deque version)
void PmergeMe::insertSmallerElementsDeque(
    std::deque<int>& sortedSequence, 
    const std::deque<int>& smaller,
    const std::vector<size_t>& insertionOrder) {
    
    for (size_t i = 0; i < insertionOrder.size(); i++) {
        size_t index = insertionOrder[i];
        if (index < smaller.size() && index > 0) { // Skip first element (already inserted)
            int element = smaller[index];
            binaryInsertDeque(sortedSequence, sortedSequence.size(), element);
        }
    }
}

// Main Ford-Johnson algorithm for deque
void PmergeMe::fordJohnsonForDeque() {
    if (_deque.size() <= 1) {
        return; 
    }
    
    std::deque<int> originalDeque = _deque;
    
    // Step 1: Extract stray element if array size is odd
    int strayElement = extractStrayElementDeque(originalDeque);
    
    // Step 2: Create sorted pairs
    std::deque<std::pair<int, int> > pairs = createSortedPairsDeque(originalDeque);

    // Step 3: Extract larger and smaller elements
    std::deque<int> larger, smaller;
    extractLargerAndSmallerDeque(pairs, larger, smaller);
    
    // Step 4: Recursively sort larger elements
    if (larger.size() > 1) {
        _deque = larger;
        fordJohnsonForDeque();
        larger = _deque;
    }
    
    // Step 5: Initialize sorted sequence with larger elements
    std::deque<int> sortedSequence = larger;
    
    // Step 6: Insert first element from smaller array
    if (!smaller.empty()) {
        binaryInsertDeque(sortedSequence, 1, smaller[0]);
    }
    
    // Step 7: Calculate insertion order using Jacobsthal numbers
    std::vector<size_t> insertionOrder = calculateInsertionOrder(smaller.size());
    
    // Step 8: Insert remaining smaller elements according to insertion order
    insertSmallerElementsDeque(sortedSequence, smaller, insertionOrder);
    
    // Step 9: Insert stray element if present
    if (strayElement != -1) {
        binaryInsertDeque(sortedSequence, sortedSequence.size(), strayElement);
    }
    
    // Update original deque with sorted sequence
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
    
    // Reset recursion counter
    recursion_calls = 0;
    
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
