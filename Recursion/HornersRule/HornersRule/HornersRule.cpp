#include <iostream>

// Recursive version
double e(int x, int n) {
    static double s;
    if (n == 0) {
        return s;
    }
    s = 1 + x*s / n;
    return e(x, n - 1);
}

// Iterative version
double eI(int x, int n) {
    double s{ 1 };
    double num{ 1 }; // numerator
    double den{ 1 }; // denominator
    for (int i = 1; i <=n ; i++)
    {
        num *= x;
        den *= i;
        s += num / den;
    }
    return s;
}

int main()
{
    std::cout << e(2, 10) << std::endl;
    std::cout << eI(2, 10) << std::endl;
}
