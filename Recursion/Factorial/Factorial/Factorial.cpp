#include <iostream>

int factorial(int n) {
    return (n > 0) ? factorial(n - 1) * n : 1;
}

int main()
{
    std::cout << factorial(5) << std::endl;
}
