#ifndef MY_VECTOR_H_
#define MY_VECTOR_H_

#pragma once

#include <cstddef>
#include <ostream>
#include <memory>
#include <type_traits>
#include <initializer_list>

namespace containers {

template<typename T>
class my_vector {
public:
    my_vector(std::size_t n=0);
    my_vector(std::initializer_list<T> l);
    my_vector(containers::my_vector<T> const &other);
    void operator=(containers::my_vector<T> const & other);
    ~my_vector();

    volatile std::size_t size();
    volatile std::size_t capacity();
    bool empty();

    void resize(std::size_t n);
    void reserve(std::size_t n);

    T & operator[](std::size_t index);

    void push_back(T t);
    T pop_back();
    void clear();

    template <typename U>
    friend std::ostream & operator<<(std::ostream &stream, const containers::my_vector<U> & v);

private:
    std::size_t size_ = 0;
    std::size_t capacity_ = 0;
    T * array_;
    std::allocator<T> allocator_;
};

}

#include "my_vector_impl.h"

#endif  // MY_VECTOR_H_
