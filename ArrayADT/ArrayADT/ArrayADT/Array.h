#include <iostream>
#include <cmath>
#pragma once

class Array
{
private:
    int* A = nullptr; // stored array
    int size = 0; // total size of the array
    int length = 0; // current length of numbers within the array
    bool isSorted = false;
    void InsertSorted(int);
    void swap(int&, int&);
    int LinearSearch(int);
    int BinarySearch(int);
    int RecursiveBinarySearch(int, int, int);
    void RearrangeUdemy(void);
    Array* UnionSorted(const Array);
public:
    Array();
    Array(int);
    void Display(void);
    void Append(int);
    void Insert(int, int);
    int Search(int);
    int Get(int);
    int Max(void);
    int Min(void);
    void ShiftLeft(void);
    void ShiftRight(void);
    void RotateLeft(void);
    void RotateRight(void);
    int Sum(void);
    double Avg(void);
    void Reverse(void);
    void Rearrange(void);
    bool IsSorted(void);
    Array* Merge(const Array);
    Array* Union(const Array);
    Array* Intersection(const Array);
    Array* Difference(const Array);
    int Delete(int);
    virtual ~Array();
};

