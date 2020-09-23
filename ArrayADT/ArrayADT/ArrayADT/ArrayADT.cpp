#include <iostream>
#include <cmath>

struct Array
{
    int A[20];
    int size; // total size of the array
    int length; // current length of numbers within the array
};

void Display(const Array a) {
    std::cout << "\nElements are:\n";
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
            arr->A[i] = arr->A[i - 1];
        }
        arr->A[index] = x;
        arr->length++;
    }
}



int Delete(Array* arr, int index) {
    int x = 0;
    if (index >= 0 && index < arr->length) {
        for (int i = index; i < arr->length; i++) {
            x = arr->A[i];
            arr->A[i] = arr->A[i + 1];
        }
        arr->length--;
    }
    return x;
}

void swap(int& x, int& y) {
    int temp = y;
    y = x;
    x = temp;
}

int LinearSearch(Array& arr, int x) {
    for (int i = 0; i < arr.length; i++)
    {
        if (arr.A[i] == x) {
            if (i == 0) {
                return i;
            }
            swap(arr.A[i], arr.A[i-1]); // Transposition
            //swap(arr.A[i], arr.A[0]); // Move to head
            return i;
        }
    }
    return -1;
}


int BinarySearch(Array arr, int key) {
    int mid{ 0 }, l{ 0 }, h{ arr.length };
    while (l <= h) {
        mid = floor((l + h) / 2);
        if (key == arr.A[mid]) {
            return mid;
        }
        else if (key < arr.A[mid]) {
            h = mid - 1;
        }
        else {
            l = mid + 1;
        }
    }
    return -1;
}

int RecursiveBinarySearch(Array arr, int l, int h, int key) {
    if (l <= h) {
        int mid = floor((l + h) / 2);
        if (key == arr.A[mid]) {
            return mid;
        }
        else if (key < arr.A[mid]) {
            return RecursiveBinarySearch(arr, l, mid - 1, key);
        }
        else {
            return RecursiveBinarySearch(arr, mid + 1, h, key);
        }
    }
    return -1;
}


int main()
{
    Array array = { {2,3,4,5,6}, 20, 5 };
    //Append(&array, 10);
    //Insert(&array, 3, 20);
    Display(array);
    Delete(&array, -100);
    Display(array);
    std::cout << std::endl;
    int num = 2;
    std::cout << "Found " << num << " at position " << RecursiveBinarySearch(array, 0, array.length, num) << std::endl;
    std::cout << "Found " << num << " at position " << BinarySearch(array, num) << std::endl;
    std::cout << "Found " << num << " at position " << LinearSearch(array, num) << std::endl;
    Display(array);
}
