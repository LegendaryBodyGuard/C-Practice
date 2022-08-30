#include <iostream>
#include <vector>

int a[] = { 6,10,-4,11,-2 };
char str[7] = { "Hello." };
std::vector<int> vec1;
std::vector<char> vec2;

template <class T>
void reverseArray(T arr[], int SIZE);
template <class T>
void printArray(T arr[], int SIZE);
template <class T>
void initVector(std::vector<T>& vec, T arr[], int SIZE);
template <class T>
void replaceLastThree(std::vector<T>& vec, T values1, T values2, T values3);
template <class T>
void printVector(std::vector<T>& vec);

template <class T>
class Comparable {
private:
    T item1;
    T item2;
public:
    Comparable(T inp1, T inp2);

    bool lt();
    bool gt();
    bool eq();
};

int main() {
    std::cout << "Reverse a[]:";
    reverseArray(a, 5);

    printArray(a, 5);

    std::cout << "\nReverse str[]:";
    reverseArray(str, 6);

    printArray(str, 6);

    std::cout << "\nInitialize vec1 according to a[]:";
    initVector(vec1, a, 5);

    printVector(vec1);

    std::cout << "\nInitialize vec2 according to str[]:";
    initVector(vec2, str, 6);

    printVector(vec2);

    std::cout << "\nReplace last three elements of vec1 with 9, 0 , and 2:";
    replaceLastThree(vec1, 9, 0, 2);

    printVector(vec1);

    std::cout << "\nReplace last three elements of vec2 with ’f’, ’y’ , and ’o’:";
    replaceLastThree(vec2, 'f', 'y', 'o');

    printVector(vec2);

    std::cout << "\nIs 1st component of comp1 less than 2nd component of it?";
    Comparable<int> comp1(3, 5);
    std::cout << comp1.lt();

    std::cout << "\nIs 1st component of comp2 equal to 2nd component of it?";
    Comparable<char> comp2('r', 'b');
    std::cout << comp2.eq();
}

template <class T>
void reverseArray(T arr[], int SIZE) {
    int newSIZE = SIZE / 2;
    for (int i = 0; i < newSIZE; i++) {
        T temp = arr[i];
        arr[i] = arr[SIZE - (i + 1)];
        arr[SIZE - (i + 1)] = temp;
    }
}

template <class T>
void printArray(T arr[], int SIZE) {
    std::cout << std::endl;
    for (int i = 0; i < SIZE; i++) {
        std::cout << arr[i];
        if (i < SIZE - 1) {
            std::cout << ", ";
        }
    }
    std::cout << "\n";
}

template <class T>
void initVector(std::vector<T>& vec, T arr[], int SIZE) {
    for (int i = 0; i < SIZE; i++) {
        vec.push_back(arr[i]);
    }
}

template <class T>
void replaceLastThree(std::vector<T>& vec, T values1, T values2, T values3) {
    for (int i = 0; i < 3; i++) {
    vec.pop_back();
    }
    vec.push_back(values1);
    vec.push_back(values2);
    vec.push_back(values3);
}

template <class T>
void printVector(std::vector<T>& vec) {
    std::cout << "\n";
    int SIZE = vec.size();
    for (int i = 0; i < vec.size(); i++) {
        std::cout << vec[i];
        if (i < SIZE - 1) {
            std::cout << ", ";
        }
    }
    std::cout << "\n";
}

template <class T>
Comparable<T>::Comparable(T input1, T input2)
{
    item1 = input1;
    item2 = input2;
}

template <class T>
bool Comparable<T>::lt() {
    return item1 < item2;
}

template <class T>
bool Comparable<T>::gt() {
    return item1 > item2;
}

template <class T>
bool Comparable<T>::eq() {
    return item1 == item2;
}