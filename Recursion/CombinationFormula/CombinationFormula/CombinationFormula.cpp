#include <iostream>

int factorial(int n) {
    int f{ 1 };
    if (n == 0) {
        return 1;
    }
    for (int i = 1; i <= n; i++) {
        f *= i;
    }
    return f;
}

int nCr(int n, int r) {
    return factorial(n) / (factorial(r) * factorial(n - r));
}

int nCrRecursive(int n, int r) {
    if (r == 0 || n == r) {
        return 1;
    }
    return nCrRecursive(n - 1, r - 1) + nCrRecursive(n - 1, r);
}

int main()
{
    std::cout << nCr(10, 5) << std::endl;
    std::cout << nCrRecursive(10, 5) << std::endl;
}
