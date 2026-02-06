#include <iostream>
#include "MyVector.h"
#include "MyString.h"

int main() {
    MyVector<int> vec;
    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);

    for (size_t i = 0; i < vec.size(); ++i)
        std::cout << vec[i] << " ";
    std::cout << "\n";

    MyString s1("Hello");
    MyString s2 = s1;
    MyString s3 = std::move(s1);

    std::cout << s2 << "\n";
    std::cout << s3 << "\n";
}