#include "MutantStack.hpp"

template <typename T>
MutantStack<T>::MutantStack() : std::stack<T, std::deque<T> >() {}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack& other) : std::stack<T, std::deque<T> >(other) {}

template <typename T>
MutantStack<T>& MutantStack<T>::operator=(const MutantStack& other) {
    if (this != &other)
        std::stack<T, std::deque<T> >::operator=(other);
    return *this;
}

template <typename T>
MutantStack<T>::~MutantStack() {}

template <typename T>
void MutantStack<T>::pop() {
    if (this->c.empty())
        throw std::runtime_error("Cannot pop from an empty stack");
    std::stack<T, std::deque<T> >::pop();
}

template <typename T>
T MutantStack<T>::top() const {
    if (this->c.empty())
        throw std::runtime_error("Cannot top from an empty stack");
    return this->c.back();
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin() {
    return this->c.begin();
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end() {
    return this->c.end();
}

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::begin() const {
    return this->c.begin();
}

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::end() const {
    return this->c.end();
}

template <typename T>
typename MutantStack<T>::reverse_iterator MutantStack<T>::rbegin() {
    return this->c.rbegin();
}

template <typename T>
typename MutantStack<T>::reverse_iterator MutantStack<T>::rend() {
    return this->c.rend();
}

template <typename T>
typename MutantStack<T>::const_reverse_iterator MutantStack<T>::rbegin() const {
    return this->c.rbegin();
}

template <typename T>
typename MutantStack<T>::const_reverse_iterator MutantStack<T>::rend() const {
    return this->c.rend();
}

// Explicit template instantiations for the types used in main.cpp
template class MutantStack<int>;
template class MutantStack<std::string>;