#include <iostream>
#include <algorithm>
#include <vector>

// My Fibonacci function
int fibonacci(int n) {
    if (n == 0) {
        return 0;
    }
    if (n > 1) {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
    else {
        return 1;
    }
}

// My memoization solution
int fastFib(int n) {
    static std::vector<int> values(n+1, -1);
    if (n <= 1) {
        return n;
    }
    else if (values[n] == -1) {
        values[n] = fastFib(n-1) + fastFib(n-2);
        return values[n];
    }
    else {
        return values[n];
    }
}

// Abdul's iterative solution
int fib(int n) {
    int t0{ 0 }, t1{ 1 }, s{ 0 };
    if (n <= 1) {
        return n;
    }
    for (int i = 2; i <= n; i++) {
        s = t0 + t1;
        t0 = t1;
        t1 = s;
    }
    return s;
}

// Abdul's recursive solution
int rfib(int n) {
    if (n <= 1) {
        return n;
    }
    return rfib(n - 2) + (n - 1);

}

// Abdul's memoization solution
const int SIZE = 10;
int F[SIZE];

int mfib(int n) {
    if (n <= 1) {
        F[n] = n;
    }
    else {
        if (F[n - 2] == -1) {
            F[n - 2] = mfib(n - 2);
        }
        if (F[n-1] == -1) {
            F[n - 1] = mfib(n - 1);
        }
        return F[n - 2] + F[n - 1];
    }
}

int main()
{
    // Fill array with -1
    for (int i = 0; i < SIZE; i++)
    {
        F[i] = -1;
    }
    std::cout << fastFib(10) << std::endl;
    std::cout << rfib(5) << std::endl;
    std::cout << mfib(10) << std::endl;
}

