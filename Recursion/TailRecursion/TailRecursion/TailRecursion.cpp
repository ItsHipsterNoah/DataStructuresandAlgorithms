#include <iostream>

void fun(int n) {
    if (n > 0) {
        fun(n - 1); // Ascending
        std::cout << n << " ";
        //  fun(n - 1); // Descending
    }
}

int main()
{
    int x{ 3 };
    fun(x);
    return 0;
}
