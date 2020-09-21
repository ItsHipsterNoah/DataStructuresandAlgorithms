#include <iostream>

void ToH(int n, int A, int B, int C) {
    if (n > 0) {
        ToH(n - 1, A, C, B);
        std::cout << "Move from " << A << " to " << C << std::endl;
        ToH(n - 1, B, A, C);
    }
}

int f(int& x, int c)

{
    c = c - 1;

    if (c == 0) return 1;

    x = x + 1;

    return f(x, c) * x;

}

int main()
{
    //ToH(16, 1, 2, 3);
    int p = 5;
    std::cout << f(p,p);
}
