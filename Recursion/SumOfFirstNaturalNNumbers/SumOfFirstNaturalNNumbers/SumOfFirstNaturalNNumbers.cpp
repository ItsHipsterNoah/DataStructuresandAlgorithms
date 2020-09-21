#include <iostream>


int SumOfFirstN(int n) {
	while (n > 0)
	{
		return n + SumOfFirstN(n - 1);
	}
	return 0;
}

int UdemySumOfFirstN(int n) {
	if (n == 0) {
		return 0;
	}
	else {
		return UdemySumOfFirstN(n - 1) + n;
	}
}

int main()
{
	std::cout << SumOfFirstN(7) << std::endl;
	std::cout << UdemySumOfFirstN(7) << std::endl;
}



