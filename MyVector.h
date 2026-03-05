#ifndef MYVECTOR_IMPROVED_H
#define MYVECTOR_IMPROVED_H

#include <stdexcept>
#include <memory>

template <typename T>
class MyVector {
private:
    T* data;
    size_t capacity;
    size_t size;

public:
    MyVector() : data(nullptr), capacity(0), size(0) {}

    // destructor
    ~MyVector() { delete[] data; }

    // method to reserve memory
    void reserve(size_t new_capacity) {
        if (new_capacity > capacity) {
            T* new_data = new T[new_capacity];
            for (size_t i = 0; i < size; ++i) {
                new_data[i] = std::move(data[i]);
            }
            delete[] data;
            data = new_data;
            capacity = new_capacity;
        }
    }

    // method to add elements
    void push_back(const T& value) {
        if (size == capacity) {
            reserve(capacity == 0 ? 1 : capacity * 2);
        }
        data[size++] = value;
    }

    void clear() {
        size = 0;
    }

    // at method with exception throwing
    T& at(size_t index) {
        if (index >= size) {
            throw std::out_of_range("Index out of bounds");
        }
        return data[index];
    }

    // get the current size
    size_t get_size() const { return size; }

    // get the capacity
    size_t get_capacity() const { return capacity; }
};