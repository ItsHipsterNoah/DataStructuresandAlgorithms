#include <iostream>

void fun(int n) {
    if (n > 0) {
        // std::cout << n << " "; Ascending
        fun(n - 1);
        fun(n - 1);
        std::cout << n << " "; // Descending
    }
    
}

int main()
{
    fun(3);
    return 0;
}
