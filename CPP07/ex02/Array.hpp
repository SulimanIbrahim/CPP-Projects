#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <exception>

template <class T>
class Array{
    private:
        T *arr;
        size_t len;
    public:
        Array(){
            this->arr = NULL;
            len = 0;
        }
        Array(unsigned int n){
            arr = new T[n];
            len = n;
        }
        Array(Array const &copy){
            this->arr = new T[copy.len];
            for (size_t i = 0; i < this->len; i++){
                this->arr[i] = copy.arr[i];
            }
            len = copy.len;
        }
        Array &operator=(Array const &copy) {
            if (this == &copy)
                return (*this);
            if (!copy.arr)
            {
                this->arr = NULL;
                this->len = 0;
                return (*this);
            }
            if (this->arr)
                delete[] arr;
            this->len = copy.size();
            this->arr = new T[copy.size()];
            for (size_t i = 0; i < this->len; i++){
                this->arr[i] = copy.arr[i];
            }
            return (*this);
        }

        T &operator[](const size_t index){
            if (!arr)
                throw std::exception();
            if (index < 0 || index >= this->len)
                throw std::exception();
            return (this->arr[index]);
        }

        const T &operator[](const size_t index) const{
            if (!arr)
                throw std::exception();
            if (index < 0 || index >= this->len)
                throw std::exception();
            return (this->arr[index]);
        }
        ~Array(){
            if (arr)
                delete[] arr;
        }

        size_t size() const{
            if (!arr)
                return 0;
            return this->len;
        }
};

#endif