#ifndef SPAN_HPP
#define SPAN_HPP
#include <iostream>
#include <exception>
#include <vector>
#include <algorithm>
#include <limits>
class Span {
    
    private:
        unsigned int _N;
        std::vector<int> _numbers;

    public:
    Span();
    ~Span();
    Span(unsigned int N);
    Span(const Span& other);
    Span& operator=(const Span& other);

    void addNumber(int number);
    int shortestSpan() const;
    int longestSpan() const;
    
    template <typename Iterator>
    void addNumbers(Iterator begin, Iterator end) {
        unsigned int availableSpace = _N - _numbers.size();
        unsigned int distance = std::distance(begin, end);
        
        if (distance > availableSpace)
            throw OutOfBoundsException();
            
        _numbers.insert(_numbers.end(), begin, end);
    }

    public:
    class OutOfBoundsException : public std::exception {
    public:
        virtual const char* what() const throw() {
            return "Span is full, can't add anymore numbers";
        }
    };

class NoSpanException : public std::exception {
public:
    virtual const char* what() const throw() {
        return "No span can be found (need at least 2 numbers)";
    }
};

};


#endif