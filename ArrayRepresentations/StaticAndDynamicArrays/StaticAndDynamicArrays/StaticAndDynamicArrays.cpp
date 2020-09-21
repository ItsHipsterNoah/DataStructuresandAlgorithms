#include <iostream>

int main()
{
    int A[10] = { 2,4,6,8,10 }; //created on the stack
    int* p;
    p = new int[5]; // created on the heap
    for (int i = 0, j=1; i < 6; i++, j+=2)
    {
        p[i] = j;
        std::cout << p[i] << std::endl;
    }
}
