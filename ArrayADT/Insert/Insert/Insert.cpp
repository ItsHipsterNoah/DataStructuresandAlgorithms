#include <iostream>

struct Array
{
    int A[20];
    int size; // total size of the array
    int length; // current length of numbers within the array
};

void Display(const Array a) {
    std::cout << "Elements are:\n";
    for (int i = 0; i < a.length; i++)
    {
        std::cout << a.A[i] << " ";
    }
}

void Append(Array* arr, int x) {
    if (arr->length < arr->size) {
        arr->A[arr->length++] = x;
    }
    
}

void Insert(Array* arr, int index, int x) {
    if (index >= 0 && index <= arr->length) {
        for (int i = arr->length; i > index; i--) {
            arr->A[i] = arr->A[i-1];
        }
        arr->A[index] = x;
        arr->length++;
    }
}

int Delete(Array* arr, int index) {
    int x=0;
    if (index >= 0 && index < arr->length) {
        for (int i = index; i < arr->length; i++) {
            x = arr->A[i];
            arr->A[i] = arr->A[i + 1];
        }
        arr->length--;
    }
    return x;
}

int LinearSearch(const Array* arr, int x) {
    for (int i = 0; i < arr->length; i++)
    {
        if (arr->A[i] == x) {
            return i;
        }
    }
    return -1;
}

int main()
{
   Array array = { {2,3,4,5,6}, 20, 5 };
   Append(&array, 10);
   Insert(&array, 3, 20);
   Display(array);
   Delete(&array, -100);
   Display(array);
}
