#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <exception>
#include <cstddef>

template <typename T>
class Array {
private:
    T* arr;
    size_t len;

public:
    class OutOfBoundsException : public std::exception {
    public:
        virtual const char* what() const throw() {
            return "Index is out of bounds";
        }
    };

    Array() : arr(NULL), len(0) {}

    Array(unsigned int n) : len(n) {
        arr = new T[n]();
    }

    Array(const Array& copy) : arr(NULL), len(0) {
        *this = copy;
    }

    Array& operator=(const Array& copy) {
        if (this == &copy)
            return *this;

        if (this->arr)
            delete[] this->arr;

        this->len = copy.len;
        if (this->len > 0) {
            this->arr = new T[this->len];
            for (size_t i = 0; i < this->len; i++) {
                this->arr[i] = copy.arr[i];
            }
        } else {
            this->arr = NULL;
        }
        
        return *this;
    }

    T& operator[](const size_t index) {
        if (index >= this->len)
            throw OutOfBoundsException();
        return this->arr[index];
    }

    const T& operator[](const size_t index) const {
        if (index >= this->len)
            throw OutOfBoundsException();
        return this->arr[index];
    }

    ~Array() {
        delete[] this->arr;
    }

    size_t size() const {
        return this->len;
    }
};

#endif