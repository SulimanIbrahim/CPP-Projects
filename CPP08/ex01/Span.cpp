#include "Span.hpp"

Span::Span() : _N(0) {}

Span::Span(unsigned int N) : _N(N) {}

Span::~Span() {}

Span::Span(const Span& other) : _N(other._N), _numbers(other._numbers) {}

Span& Span::operator=(const Span& other) {
    if (this != &other) {
        _N = other._N;
        _numbers = other._numbers;
    }
    return *this;
}

void Span::addNumber(int number) {
    if (_numbers.size() == _N)
        throw OutOfBoundsException();
    _numbers.push_back(number);
}


int Span::shortestSpan() const {
    if (_numbers.size() < 2)
        throw NoSpanException();
        
    std::vector<int> sorted = _numbers;
    std::sort(sorted.begin(), sorted.end());
    
    int minSpan = std::numeric_limits<int>::max();
    
    for (size_t i = 1; i < sorted.size(); ++i) {
        int span = sorted[i] - sorted[i - 1];
        if (span < minSpan)
            minSpan = span;
    }

    return minSpan;
}

int Span::longestSpan() const {
    if (_numbers.size() < 2)
        throw NoSpanException();
        
    std::pair<std::vector<int>::const_iterator, std::vector<int>::const_iterator> minmax = 
        std::minmax_element(_numbers.begin(), _numbers.end());
        
    return *minmax.second - *minmax.first;
}