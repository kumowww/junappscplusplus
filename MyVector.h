#pragma once
#include <cstddef>
#include <stdexcept>
#include <algorithm>

template <typename T>
class MyVector {
private:
    T* data_;
    size_t size_;
    size_t capacity_;

    void reallocate(size_t newCapacity) {
        T* newData = new T[newCapacity];
        for (size_t i = 0; i < size_; ++i)
            newData[i] = std::move(data_[i]);

        delete[] data_;
        data_ = newData;
        capacity_ = newCapacity;
    }

public:
    MyVector() : data_(nullptr), size_(0), capacity_(0) {}

    MyVector(const MyVector& other)
        : size_(other.size_), capacity_(other.capacity_) {
        data_ = new T[capacity_];
        for (size_t i = 0; i < size_; ++i)
            data_[i] = other.data_[i];
    }

    MyVector(MyVector&& other) noexcept
        : data_(other.data_), size_(other.size_), capacity_(other.capacity_) {
        other.data_ = nullptr;
        other.size_ = other.capacity_ = 0;
    }

    MyVector& operator=(const MyVector& other) {
        if (this == &other) return *this;

        delete[] data_;
        size_ = other.size_;
        capacity_ = other.capacity_;
        data_ = new T[capacity_];

        for (size_t i = 0; i < size_; ++i)
            data_[i] = other.data_[i];

        return *this;
    }

    MyVector& operator=(MyVector&& other) noexcept {
        delete[] data_;
        data_ = other.data_;
        size_ = other.size_;
        capacity_ = other.capacity_;

        other.data_ = nullptr;
        other.size_ = other.capacity_ = 0;
        return *this;
    }

    ~MyVector() {
        delete[] data_;
    }

    void push_back(const T& value) {
        if (size_ == capacity_)
            reallocate(capacity_ == 0 ? 1 : capacity_ * 2);

        data_[size_++] = value;
    }

    void pop_back() {
        if (size_ == 0)
            throw std::out_of_range("Vector is empty");
        --size_;
    }

    T& operator[](size_t index) {
        return data_[index];
    }

    const T& operator[](size_t index) const {
        return data_[index];
    }

    size_t size() const { return size_; }
    size_t capacity() const { return capacity_; }
};
