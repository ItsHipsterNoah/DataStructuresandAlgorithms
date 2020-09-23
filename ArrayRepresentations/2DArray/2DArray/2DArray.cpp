#include <iostream>

int main()
{
    // Using an initializer list
    int A[3][4] = { {1,2,3,4}, {2,4,6,8}, {1,3,5,7} };

    for (int r = 0; r < 3; r++)
    {
        for (int c = 0; c < 4; c++)
        {
            std::cout << A[r][c] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

    // Using dynamic memory allocation
    int* B[3];
    B[0] = new int[4];
    B[1] = new int[4];
    B[2] = new int[4];

    for (int r = 0; r < 3; r++)
    {
        for (int c = 0; c < 4; c++)
        {
            B[r][c] = c;
            std::cout << B[r][c] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
    int** C = new int*[3]; // pointer to an array of pointers
    C[0] = new int[4];
    C[1] = new int[4];
    C[2] = new int[4];

    for (int r = 0; r < 3; r++)
    {
        for (int c = 0; c < 4; c++)
        {
            C[r][c] = c;
            std::cout << B[r][c] << " ";
        }
        std::cout << std::endl;
    }
}

