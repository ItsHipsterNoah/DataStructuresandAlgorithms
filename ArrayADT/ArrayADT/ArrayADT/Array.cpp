#include "Array.h"

template <class T>
Array<T>::Array() 
{
	size = 10;
	length = 0;
	A = new T[size];
}

template <class T>
Array<T>::Array(int size)
{
	this->size = size;
	this->length = 0;
	this->A = new T[size];
}


// Display all elements in the array.
template <class T>
void Array<T>::Display() {
	std::cout << "\nElements are:\n";
	for (int i = 0; i < length; i++)
	{
		std::cout << this->A[i] << " ";
	}
}

// Add an element to the end of the array.
template <class T>
void Array<T>::Append(T x) {
	if (length < size) {
		A[length++] = x;
	}
	else {
		std::cerr << "Array is full, cannot insert" << std::endl;
	}

}

// Insert value x at the given index.
template <class T>
void Array<T>::Insert(int index, T x) {
	if (length == size) {
		std::cerr << "Array is full, cannot insert" << std::endl;
		return;
	}
	else if (index >= 0 && index <= length) {
		for (int i = length; i > index; i--) {
			A[i] = A[i - 1];
		}
		A[index] = x;
		length++;
	}
}

// Search for a specified element. Returns -1 if the element
// cannot be found.
template <class T>
T Array<T>::Search(T value)
{
	if (IsSorted()) {
		return BinarySearch(value);
	}
	else {
		return LinearSearch(value);
	}
}

// Insertion that preserves sorted order.
template <class T>
void Array<T>::InsertSorted(T x) {
	if (this->length == size) {
		std::cerr << "Array is full, cannot insert" << std::endl;
		return;
	}
	int i = length - 1;
	while (i >= 0 && A[i] > x) {
		A[i + 1] = A[i];
		i--;
	}
	A[i + 1] = x;
	length++;
}

// Deletes element at specified index.
template <class T>
T Array<T>::Delete(int index) {
	T x = 0;
	if (index >= 0 && index < length) {
		for (int i = index; i < length; i++) {
			x = A[i];
			A[i] = A[i + 1];
		}
		length--;
	}
	return x;
}


// Performs a linear search in O(n) time.
template <class T>
int Array<T>::LinearSearch(T x) {
	for (int i = 0; i < length; i++)
	{
		if (A[i] == x) {
			if (i == 0) {
				return i;
			}
			swap(A[i], A[i-1]); // Transposition
			//swap(arr.A[i], arr.A[0]); // Move to head
			return i;
		}
	}
	return -1;
}

// Performs a Binary Search in O(logbase2 N).
template <class T>
int Array<T>::BinarySearch(T key) {
	int mid{ 0 }, l{ 0 }, h{ length - 1 };
	while (l <= h) {
		mid = (int)floor((l + h) / 2);
		if (key == A[mid]) {
			return mid;
		}
		else if (key < A[mid]) {
			h = mid - 1;
		}
		else {
			l = mid + 1;
		}
	}
	return -1;
}

// Performs a binary search recursively.
template <class T>
int Array<T>::RecursiveBinarySearch(int l, int h, T key) {
	if (l <= h) {
		int mid = (int)floor((l + h) / 2);
		if (key == A[mid]) {
			return mid;
		}
		else if (key < A[mid]) {
			return RecursiveBinarySearch(l, mid - 1, key);
		}
		else {
			return RecursiveBinarySearch(mid + 1, h, key);
		}
	}
	return -1;
}

// Gets the value at the specified index.
template <class T>
T Array<T>::Get(int index) {
	if (index > 0 && index < length) {
		return A[index];
	}
	else {
		return -1;
	}
}

// Returns the largest value in the array.
template <class T>
T Array<T>::Max() {
	if (length > 0) {
		T max{ A[0] };
		for (int i = 1; i < length; i++)
		{
			if (A[i] > max) {
				max = A[i];
			}
		}
		return max;
	}
	return -1;
}

// Returns the smallest value in the array.
template <class T>
T Array<T>::Min() {
	if (length > 0) {
		int min{ A[0] };
		for (int i = 1; i < length; i++)
		{
			if (A[i] < min) {
				min = A[i];
			}
		}
		return min;
	}
	return -1;
}

// Shifts all the elements in the array leftward.
template <class T>
void Array<T>::ShiftLeft() {
	if (length > 0) {
		T truncated = A[0];
		for (int i = 0; i < length; i++)
		{
			A[i] = A[i + 1];
		}
	    A[length - 1] = 0;
	}
}

// Shifts all the elements in the array rightward.
template <class T>
void Array<T>::ShiftRight() {
	if (length > 0) {
		T truncated = A[length - 1];
		for (int i = length - 1; i > 0; i--)
		{
			A[i] = A[i - 1];
		}
		A[0] = 0;
	}
}

// Rotates the array counterclockwise.
template <class T>
void Array<T>::RotateLeft() {
	if (length > 0) {
		T truncated = A[0];
		for (int i = 0; i < length; i++)
		{
			A[i] = A[i + 1];
		}
		A[length - 1] = truncated;
	}
}

// Rotates the array clockwise.
template <class T>
void Array<T>::RotateRight() {
	if (length > 0) {
		int truncated = A[length - 1];
		for (int i = length - 1; i > 0; i--)
		{
			A[i] = A[i - 1];
		}
		A[0] = truncated;
	}
}

// Calculates and returns the sum of the elements
// in the array.
template <class T>
double Array<T>::Sum() {
	double sum{ 0 };
	if (length > 0) {
		for (int i = 0; i < length; i++)
		{
			sum += A[i];
		}
		return sum;
	}
	return sum;
}

// Calculates average value of the array.
template <class T>
double Array<T>::Avg() {
	double avg{ 0 };
	if (this->length > 0) {
		return Sum() / this->length;
	}
	return avg;
}


// Checks if the array is sorted.
template <class T>
bool Array<T>::IsSorted() {
	for (int i = 0; i < length - 1; i++)
	{
		if (A[i] > A[i + 1]) {
			return false;
		}
	}
	return true;
}


// Reverses the array.
template <class T>
void Array<T>::Reverse() {
	for (int i = 0, j = length - 1; i < j; i++, j--) {
		swap(A[i], A[j]);
	}
}

// Places negative numbers on left side of array,
// and positive numbers on the right.
template <class T>
void Array<T>::Rearrange() {
	for (int i = 0; i < length; i++) {
		if (A[i] > 0) {
			for (int j = length - 1; j != i; j--) {
				if (A[j] < 0) {
					swap(A[i], A[j]);
				}
			}
		}
	}
}

// Merges this array with another array,
// and returns a new array.
template <class T>
Array<T>* Array<T>::Merge(const Array<T> B) {
	Array* C = new Array();
	C->size = this->size + B.size;
	C->length = this->  length + B.length;
	int k{ 0 }, i{ 0 }, j{ 0 };
	while (i < this->length && j < B.length) {
		if (this->A[i] < B.A[j]) {
			C->A[k++] = this->A[i++];
		}
		else {
			C->A[k++] = B.A[j++];
		}
	}
	for (; i < this->length; i++) {
		C->A[k++] = this->A[i];
	}
	for (; j < B.length; j++) {
		C->A[k++] = B.A[j];
	}
	return C;
}


//// Udemy solution (DEPRECATED)
//void Array::RearrangeUdemy() {
//	int i{ 0 }, j{ length - 1 };
//	while (i < j) {
//		while (A[i] < 0) {
//			i++;
//		}
//		while (A[i] >= 0) {
//			j--;
//		}
//		if (i < j) {
//			swap(A[i], A[j]);
//		}
//	}
//}

// Performs UNION on two unsorted array sets.
template <class T>
Array<T>* Array<T>::Union(const Array<T> B) {
	if (IsSorted()) {
		return UnionSorted(B);
	}
	Array* C = new Array();
	C->length = 0;
	C->size = this->size + B.size;
	for (int i = 0; i < this->length; i++) {
		C->A[i] = this->A[i];
		C->length++;
	}
	for (int i = 0, j = C->length; i < B.length; i++, j++) {
		if (C->LinearSearch(B.A[i]) == -1) {
			C->A[j] = B.A[i];
			C->length++;
		}
	}
	return C;
}

// Performs UNION set operation on two sorted array sets.
template <class T>
Array<T>* Array<T>::UnionSorted(const Array<T> B) {
	Array* C = new Array();
	C->size = this->size + B.size;
	C->length = this->length + B.length;
	int k{ 0 }, i{ 0 }, j{ 0 };
	while (i < this->length && j < B.length) {
		if (this->A[i] < B.A[j]) {
			C->A[k++] = this->A[i++];
		}
		else if (this->A[i] == B.A[j]) {
			C->A[k++] = this->A[i++];
			j++;
		}
		else {
			C->A[k++] = B.A[j++];
		}
	}
	for (; i < this->length; i++) {
		C->A[k++] = this->A[i];
	}
	for (; j < B.length; j++) {
		C->A[k++] = B.A[j];
	}
	return C;
}

// Performs INTERSECT set operation on two arrays
template <class T>
Array<T>* Array<T>::Intersection(const Array<T> B) {
	Array* C = new Array();
	C->size = this->size + B.size;
	C->length = 0;
	int k{ 0 };
	for (int i = 0; i < this->length; i++) {
		for (int j = 0; j < B.length; j++) {
			if (this->A[i] == B.A[j]) {
				if (C->LinearSearch(this->A[i]) == -1) {
					C->A[k++] = this->A[i];
					C->length++;
				}
			}
		}
	}
	return C;
}

template <class T>
Array<T>* Array<T>::Difference(const Array<T> B) {
	Array* C = new Array();
	C->size = this->size + B.size;
	C->length = 0;
	int k{ 0 };
	for (int i = 0; i < this->length; i++) {
		for (int j = 0; j < B.length; j++) {
			if (this->A[i] == B.A[j]) {
				i++;
			}
			// if A[i] is not equal to B[i],
			// and we're at the end of the list,
			// store A[i] in C.
			if (this->A[i] != B.A[j] && j == B.length - 1) {
				C->A[k++] = this->A[i];
				C->length++;
			}

		}
	}
	return C;
}

// Internal swap function
template <class T>
void Array<T>::swap(T& x, T& y) {
	int temp = y;
	y = x;
	x = temp;
}

template <class T>
Array<T>::~Array()
{
	if (A) {
		delete[] A;
	}
}
