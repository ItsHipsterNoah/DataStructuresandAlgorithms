#pragma once
#include <iostream>
#include <cmath>

template <class T>
class Array
{
private:
    T* A = nullptr; // stored array
    int size = 0; // total size of the array
    int length = 0; // current length of numbers within the array
    bool isSorted = false;
    void InsertSorted(T);
    void swap(T&, T&);
    int LinearSearch(T);
    int BinarySearch(T);
    int RecursiveBinarySearch(int, int, T);
    // void RearrangeUdemy(void);
    Array* UnionSorted(const Array);
public:
    Array();
    Array(int);
    void Display(void);
    void Append(T);
    void Insert(int index, T value);
    T Search(T value);
    T Get(int index);
    T Max(void);
    T Min(void);
    void ShiftLeft(void);
    void ShiftRight(void);
    void RotateLeft(void);
    void RotateRight(void);
    double Sum(void);
    double Avg(void);
    void Reverse(void);
    void Rearrange(void);
    bool IsSorted(void);
    Array* Merge(const Array<T>);
    Array* Union(const Array<T>);
    Array* Intersection(const Array<T>);
    Array* Difference(const Array<T>);
    T Delete(int);
    virtual ~Array();
};

