#include <iostream>

int main()
{
	int Q1, P1, Q2, P2, A, a;
	std::cin >> Q1 >> P1 >> Q2 >> P2 >> A;
	a = A;
	int sum1 = 0;
	int sum2 = 0;

	while (a > 0)
	{
		sum1 = sum1 + ((a / Q1) * P1);
		a = a % Q1;
		sum1 = sum1 + (((a / Q2) + 1) * P2);
	}

	a = A;

	while (a > 0)
	{
		sum2 = sum2 + ((a / Q2) * P2);
		a = a % Q1;
		sum2 = sum2 + (((a / Q1) + 1) * P1);
	}

	if (sum2 < sum1)
	{
		std::cout << sum2 << std::endl;
	}
	else
	{
		std::cout << sum1 << std::endl;
	}

	return 0;
}
