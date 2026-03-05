#ifndef MYSTRING_IMPROVED_H
#define MYSTRING_IMPROVED_H

#include <cstring>
#include <iostream>

class MyString {
private:
    char* str;
    size_t length;

public:
    MyString(const char* s = "") {
        if (s == nullptr) {
            str = new char[1];
            str[0] = '\0';
        } else {
            length = strlen(s);
            str = new char[length + 1];
            strcpy(str, s);
        }
    }

    ~MyString() {
        delete[] str;
    }

    // copy from constructor xd
    MyString(const MyString& other) {
        length = other.length;
        str = new char[length + 1];
        strcpy(str, other.str);
    }

    // overload the assignment operator
    MyString& operator=(const MyString& other) {
        if (this != &other) {
            delete[] str;
            length = other.length;
            str = new char[length + 1];
            strcpy(str, other.str);
        }
        return *this;
    }

    // overload the comparison operators
    bool operator==(const MyString& other) const {
        return strcmp(str, other.str) == 0;
    }

    bool operator!=(const MyString& other) const {
        return !(*this == other);
    }

    // overload the concatenation operator
    MyString operator+(const MyString& other) const {
        MyString result;
        result.length = length + other.length;
        result.str = new char[result.length + 1];
        strcpy(result.str, str);
        strcat(result.str, other.str);
        return result;
    }

    // append method 0_0
    void append(const MyString& other) {
        size_t new_length = length + other.length;
        char* new_str = new char[new_length + 1];
        strcpy(new_str, str);
        strcat(new_str, other.str);
        delete[] str;
        str = new_str;
        length = new_length;
    }

    // substr method
    MyString substr(size_t start, size_t len) const {
        if (start >= length) return MyString();
        if (len > length - start) len = length - start;
        char* sub_str = new char[len + 1];
        strncpy(sub_str, str + start, len);
        sub_str[len] = '\0';
        return MyString(sub_str);
    }

    // output method for easy printing
    friend std::ostream& operator<<(std::ostream& os, const MyString& obj) {
        return os << obj.str;
    }
};
