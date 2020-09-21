#include <iostream>
#include <cmath>
#include <time.h>

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

double TaylorSeries(double x, double upperLimit = 10) {
    if(upperLimit > 0) {
        return pow(x, upperLimit)/factorial(upperLimit) + TaylorSeries(x, --upperLimit);
    }
    return 0;
   // Single line return
   // return upperLimit > 0 ? pow(x, upperLimit) / factorial(upperLimit) + TaylorSeries(x, --upperLimit) : 0;
}

// Udemy Solution
double e(int x, int n) {
    static double p = 1, f = 1;
    double r;
    if (n == 0) {
        return 1;
    }
    r = e(x, n - 1);
    p *= x;
    f *= n;
    return r + p / f;
}

int main()
{
    int start = clock();
    std::cout << TaylorSeries(1, 10) << std::endl;
    int end = clock();
     
    std::cout << "Noah's solution took " << end - start << " ticks, or " << ((float)end - start) / CLOCKS_PER_SEC << "seconds." << std::endl;

    int start1 = clock();
    std::cout << e(1, 10) << std::endl;
    int end1 = clock();

    std::cout << "Abdul's solution took " << end1 - start1 << " ticks, or " << ((float)end1 - start1) / CLOCKS_PER_SEC << "seconds." << std::endl;
   
    int start2 = clock();
    std::cout << std::exp(2) << std::endl;
    int end2 = clock();

    std::cout << "exp() took " << end2 - start2 << " ticks, or " << ((float)end2 - start2) / CLOCKS_PER_SEC << "seconds." << std::endl;
}