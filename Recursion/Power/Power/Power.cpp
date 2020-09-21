#include <iostream>

int power(int base, int pow) {
    return (pow > 0) ? base * power(base, pow - 1) : 1;
}

int fastPower(int base, int pow) {
	if (pow == 0)
	{
		return 1;
	}
	if (pow % 2 == 0) {
		return fastPower(base * base, pow / 2);
	}
	return base * fastPower(base * base, (pow - 1) / 2);
}

int main()
{
	std::cout << pow(5, 2) << std::endl;
	std::cout << fastPower(5, 2);
}