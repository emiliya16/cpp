#ifndef MY_VECTOR_IMPL_H_
#define MY_VECTOR_IMPL_H_

#pragma once

#include "my_vector.h"

namespace containers {
    template <typename T>
    my_vector<T>::my_vector(std::size_t n) : size_(0) {
        this->capacity_ = 1 << (64 - __builtin_clz(n - 1));
        this->array_ = this->allocator_.allocate(this->capacity_);
    }

    template <typename T>
    my_vector<T>::my_vector(std::initializer_list<T> l) : size_{l.size()} {
        this->capacity_ = 1 << (64 - __builtin_clz(l.size() - 1));
        this->array_ = this->allocator_.allocate(this->capacity_);
        int i = 0;

        for (auto el : l) {
            this->array_[i++] = el;
        }
    }

    template <typename T>
    my_vector<T>::my_vector(containers::my_vector<T> const & other) {
        *this = other;
    }

    template <typename T>
    void containers::my_vector<T>::operator=(containers::my_vector<T> const &other) {
        if (this->capacity_ > 0) {
            this->allocator_.deallocate(this->array_, this->capacity_);
        }

        this->size_ = other.size_;
        this->capacity_ = other.capacity_;

        this->array_ = this->allocator_.allocate(this->capacity_);

        for (std::size_t i = 0; i < this->size_; i++) {
            this->array_[i] = other.array_[i];
        }
    }

    template <typename T>
    my_vector<T>::~my_vector() {
        this->allocator_.deallocate(this->array_, this->capacity_);
    }

    template <typename T>
    volatile std::size_t my_vector<T>::capacity() {
        return this->capacity_;
    }

    template <typename T>
    volatile std::size_t my_vector<T>::size() {
        return this->size_;
    }

    template <typename T>
    bool my_vector<T>::empty() {
        return this->size_ == 0;
    }

    template <typename T>
    void my_vector<T>::resize(std::size_t n) {
        this->reserve(n);
    }

    template <typename T>
    void my_vector<T>::reserve(std::size_t n) {
        int new_capacity = 1 << (64 - __builtin_clz(n - 1));
        T * new_array = this->allocator_.allocate(new_capacity);

        for (std::size_t i = 0; i < this->size_; i++) {
            new_array[i] = this->array_[i];
        }

        this->allocator_.deallocate(this->array_, this->capacity_);
        this->capacity_ = new_capacity;
        this->array_ = new_array;
    }

    template <typename T>
    T & my_vector<T>::operator[](std::size_t index) {
        if (index > this->size_) {
            throw std::invalid_argument("invalid index");
        }

        return this->array_[index];
    }

    template <typename T>
    void my_vector<T>::push_back(T t) {
        if (this->size_ >= this->capacity_) {
            this->capacity_ <<= 1;
            this->reserve(this->capacity_);
        }

        this->array_[this->size_++] = T(t);
    }

    template <typename T>
    T my_vector<T>::pop_back() {
        if (this->size_ <= 0) {
            throw std::invalid_argument("can't pop from empty vector");
        }

        return this->array_[--this->size_];
    }

    template <typename T>
    void my_vector<T>::clear() {
        this->size_ = 0;
    }

    template <typename T>
    std::ostream &operator<<(std::ostream & stream, const my_vector<T> & v) {
        for (std::size_t i = 0; i < v.size_; i++) {
            stream << v.array_[i];
            if (i != v.size_ - 1) {
                stream << " ";
            }
        }

        return stream;
    }

}

#endif // MY_VECTOR_IMPL_H_
