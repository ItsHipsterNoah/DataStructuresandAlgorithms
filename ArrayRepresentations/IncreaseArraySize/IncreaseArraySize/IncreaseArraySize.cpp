#include <iostream>

int main()
{
    int* p, * q;
    p = new int[5];
    q = new int[10];

    for (int i = 0, j = 1; i < 5; i++, j += 2) {
        p[i] = j;
        std::cout << p[i] << std::endl;
    }
    std::cout << std::endl;

    for (int i = 0; i < 5; i++) {
        q[i] = p[i];
        std::cout << q[i] << std::endl;
    }
    p = q;
    q = nullptr;

    std::cout << std::endl;
    for (int i = 0; i < 5; i++) {
        std::cout << p[i] << std::endl;
    }

    delete[] p;
    
}
