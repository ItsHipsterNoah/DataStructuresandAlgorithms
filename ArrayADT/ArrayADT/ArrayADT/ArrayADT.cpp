#include <iostream>
#include <cmath>

struct Array
{
    int A[20]; // stored array
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
    else {
        std::cerr << "Array is full, cannot insert" << std::endl;
    }

}

void Insert(Array* arr, int index, int x) {
    if (arr->length == arr->size) {
        std::cerr << "Array is full, cannot insert" << std::endl;
        return;
    }
    if (index >= 0 && index <= arr->length) {
        for (int i = arr->length; i > index; i--) {
            arr->A[i] = arr->A[i - 1];
        }
        arr->A[index] = x;
        arr->length++;
    }
}

void InsertSorted(Array& arr, int x) {
    if (arr.length == arr.size) {
        std::cerr << "Array is full, cannot insert" << std::endl;
        return;
    }
    int i = arr.length -1;
    while (i >= 0 && arr.A[i] > x) {
        arr.A[i + 1] = arr.A[i];
        i--;
    }
    arr.A[i + 1] = x;
    arr.length++;
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
            //swap(arr.A[i], arr.A[i-1]); // Transposition
            //swap(arr.A[i], arr.A[0]); // Move to head
            return i;
        }
    }
    return -1;
}


int BinarySearch(Array arr, int key) {
    int mid{ 0 }, l{ 0 }, h{ arr.length - 1 };
    while (l <= h) {
        mid = (int)floor((l + h) / 2);
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
        int mid = (int)floor((l + h) / 2);
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

int Get(const Array& arr, int index) {
    if (index > 0 && index < arr.length) {
        return arr.A[index];
    }
    else {
        return -1;
    }
}

bool Set(Array& arr, int index, int x) {
    if (index > 0 && index < arr.length) {
        arr.A[index] = x;
        return true;
    }
    else {
        return false;
    }
}

int Max(const Array& arr) {
    if (arr.length > 0) {
        int max{ arr.A[0] };
        for (int i = 1; i < arr.length; i++)
        {
            if (arr.A[i] > max) {
                max = arr.A[i];
            }
        }
        return max;
    }
    return -1;
}

int Min(const Array& arr) {
    if (arr.length > 0) {
        int min{ arr.A[0] };
        for (int i = 1; i < arr.length; i++)
        {
            if (arr.A[i] < min) {
                min = arr.A[i];
            }
        }
        return min;
    }
    return -1;
}

void ShiftLeft(Array& arr) {
    if (arr.length > 0) {
        int truncated = arr.A[0];
        for (int i = 0; i < arr.length; i++)
        {
            arr.A[i] = arr.A[i + 1];
        }
        arr.A[arr.length - 1] = 0;
    }
}

void ShiftRight(Array& arr) {
    if (arr.length > 0) {
        int truncated = arr.A[arr.length - 1];
        for (int i = arr.length-1; i > 0 ; i--)
        {
            arr.A[i] = arr.A[i - 1];
        }
        arr.A[0] = 0;
    }
}

void RotateLeft(Array& arr) {
    if (arr.length > 0) {
        int truncated = arr.A[0];
        for (int i = 0; i < arr.length; i++)
        {
            arr.A[i] = arr.A[i + 1];
        }
        arr.A[arr.length - 1] = truncated;
    }
}

void RotateRight(Array& arr) {
    if (arr.length > 0) {
        int truncated = arr.A[arr.length - 1];
        for (int i = arr.length - 1; i > 0; i--)
        {
            arr.A[i] = arr.A[i - 1];
        }
        arr.A[0] = truncated;
    }
}

int Sum(const Array& arr) {
    int sum{ 0 };
    if (arr.length > 0) {
        for (int i = 0; i < arr.length; i++)
        {
            sum += arr.A[i];
        }
        return sum;
    }
    return sum;
}

// Calculates average valueof an array
double Avg(const Array& arr) {
    double avg{ 0 };
    if (arr.length > 0) {
        return Sum(arr) / arr.length;
    }
    return avg;
}

// Reverses an array
void Reverse(Array& arr) {
    for (int i = 0, j = arr.length - 1; i < j; i++, j--) {
        swap(arr.A[i], arr.A[j]);
    }
}

// Checks if array is sorted
bool IsSorted(Array& arr) {
    for (int i = 0; i < arr.length - 1; i++)
    {
        if (arr.A[i] > arr.A[i + 1]) {
            return false;
        }
    }
    return true;
}

// Places negative numbers on left side of array,
// and positive numbers on the right
void Rearrange(Array& arr) {
    for (int i = 0; i < arr.length; i++) {
        if (arr.A[i] > 0) {
            for (int j = arr.length-1; j != i; j--) {
                if (arr.A[j] < 0) {
                    swap(arr.A[i], arr.A[j]);
                }
            }
        }
    }
}

// Udemy solution
void RearrangeUdemy(Array& arr) {
    int i{ 0 }, j{ arr.length - 1 };
    while (i < j) {
        while (arr.A[i] < 0) {
            i++;
        }
        while (arr.A[i] >= 0) {
            j--;
        }
        if (i < j) {
            swap(arr.A[i], arr.A[j]);
        }
    }
}

// Merges two arrays
Array* Merge(const Array A, const Array B) {
    Array* C = new Array();
    C->size = A.size + B.size;
    C->length = A.length + B.length;
    int k{ 0 }, i{ 0 }, j{ 0 };
    while (i < A.length && j < B.length) {
        if (A.A[i] < B.A[j]) {
            C->A[k++] = A.A[i++];
        }
        else {
            C->A[k++] = B.A[j++];
        }
    }
    for (; i < A.length; i++) {
        C->A[k++] = A.A[i];
    }
    for (; j < B.length; j++) {
        C->A[k++] = B.A[j];
    }
    return C;
}

// Performs UNION on two unsorted array sets
Array* Union(const Array A, const Array B) {
    Array* C = new Array();
    C->length = 0;
    C->size = A.size + B.size;
    for (int i = 0; i < A.length; i++) {
        C->A[i] = A.A[i];
        C->length++;
    }
    for (int i = 0, j = C->length; i < B.length; i++, j++) {
        if (LinearSearch(*C, B.A[i]) == -1) {
            C->A[j] = B.A[i];
            C->length++;
        }
    }
    return C;
}

// Performs UNION set operation on two sorted array sets
Array* UnionSorted(const Array A, const Array B) {
    Array* C = new Array();
    C->size = A.size + B.size;
    C->length = A.length + B.length;
    int k{ 0 }, i{ 0 }, j{ 0 };
    while (i < A.length && j < B.length) {
        if (A.A[i] < B.A[j]) {
            C->A[k++] = A.A[i++];
        }
        else if (A.A[i] == B.A[j]) {
            C->A[k++] = A.A[i++];
            j++;
        }
        else {
            C->A[k++] = B.A[j++];
        }
    }
    for (; i < A.length; i++) {
        C->A[k++] = A.A[i];
    }
    for (; j < B.length; j++) {
        C->A[k++] = B.A[j];
    }
    return C;
}

// Performs INTERSECT set operation on two arrays
Array* Intersection(const Array A, const Array B) {
    Array* C = new Array();
    C->size = A.size + B.size;
    C->length = 0;
    int k{ 0 };
    for (int i = 0; i < A.length; i++) {
        for (int j = 0; j < B.length; j++) {
            if (A.A[i] == B.A[j]) {
                if (LinearSearch(*C, A.A[i]) == -1) {
                    C->A[k++] = A.A[i];
                    C->length++;
                }
            }
        }
    }
    return C;
}

Array* Difference(const Array A, const Array B) {
    Array* C = new Array();
    C->size = A.size + B.size;
    C->length = 0;
    int k{ 0 };
    for (int i = 0; i < A.length; i++) {
        for (int j = 0; j < B.length; j++) {
            if (A.A[i] == B.A[j])  {
                i++;
            }
            // if A[i] is not equal to B[i],
            // and we're at the end of the list,
            // store A[i] in C.
            if (A.A[i] != B.A[j] && j == B.length-1) {
                C->A[k++] = A.A[i];
                C->length++;
            }
            
        }
    }
    return C;
}

int main()
{
    //Array array = { {2,3,4,5,6,7}, 20, 6 };
    //Array array1 = { {-6, 3, -8, 10, 5, -7, -9, 12, -4, 2}, 20, 10 };

    //Array array2 = { {6, 3, 8, 10, 5, 7, -9, 12, -4, 2}, 20, 10 };
    //Array array3 = { {6, -3, 8, -10, -5, -7, 9, -12, -4, -2}, 20, 10 };
    ////Append(&array, 10);
    ////Insert(&array, 3, 20);
    //Display(array);
    //Delete(&array, -100);
    //Display(array);
    //std::cout << std::endl;
    //int num = 2;
    //
    //std::cout << "Found " << num << " at position " << RecursiveBinarySearch(array, 0, array.length, num) << std::endl;
    //std::cout << "Found " << num << " at position " << BinarySearch(array, num) << std::endl;
    //std::cout << "Found " << num << " at position " << LinearSearch(array, num) << std::endl;
    //std::cout << std::boolalpha;
    //std::cout << IsSorted(array);
    //InsertSorted(array, 10);
    //Display(array);
    //InsertSorted(array, 9);
    //Display(array);

    //Rearrange(array1);
    //Display(array1);

    //Array A = { {1,3,5,7,9}, 5, 5 };
    //Array B = { {2,4,6,8,10}, 5, 5 };

    //Array* C = Merge(A, B);
    //Display(*C);

    //Display(*Union(A, B));

    //Array X = { {3,8,16,20,25}, 5,5 };
    //Array Y = { {4,10,12,22}, 5,4 };

    //Array* Z = Merge(X, Y);
    //Display(*Z);

    //A = { {3,5,10,4,4}, 5, 5 };
    //B = { {12,4,7,2,5}, 5, 5 };

    //Display(*UnionSorted(A, B));

    //Display(*Intersection(A, B));
   
    //A = { {3,4,5,6,10}, 5, 5 };
    //B = { {2,4,5,7,12}, 5, 5 };

    //Display(*Intersection(A, B));

    //A = { {3,5,10,4,6}, 5, 5 };
    //B = { {12,4,7,2,5}, 5, 5 };

    //Display(*Difference(A, B));



}
