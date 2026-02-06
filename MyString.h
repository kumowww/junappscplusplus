#pragma once
#include <cstring>
#include <iostream>

class MyString {
private:
    char* data_;
    size_t length_;

public:
    MyString() : data_(new char[1]{'\0'}), length_(0) {}

    MyString(const char* str) {
        length_ = std::strlen(str);
        data_ = new char[length_ + 1];
        std::strcpy(data_, str);
    }

    MyString(const MyString& other) {
        length_ = other.length_;
        data_ = new char[length_ + 1];
        std::strcpy(data_, other.data_);
    }
    MyString(MyString&& other) noexcept
        : data_(other.data_), length_(other.length_) {
        other.data_ = nullptr;
        other.length_ = 0;
    }
    MyString& operator=(const MyString& other) {
        if (this == &other) return *this;

        delete[] data_;
        length_ = other.length_;
        data_ = new char[length_ + 1];
        std::strcpy(data_, other.data_);
        return *this;
    }
    MyString& operator=(MyString&& other) noexcept {
        delete[] data_;
        data_ = other.data_;
        length_ = other.length_;

        other.data_ = nullptr;
        other.length_ = 0;
        return *this;
    }
    ~MyString() {
        delete[] data_;
    }

    size_t length() const { return length_; }
    const char* c_str() const { return data_; }

    char& operator[](size_t index) {
        return data_[index];
    }

    friend std::ostream& operator<<(std::ostream& os, const MyString& str) {
        os << str.data_;
        return os;
    }
};