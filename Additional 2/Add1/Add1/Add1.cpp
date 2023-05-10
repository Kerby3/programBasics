#include <iostream>

int NOD(int a, int b)
{
	if (a % b == 0)
		return b;
	if (b % a == 0)
		return a;
	if (a > b)
		return NOD(a % b, b);
	return NOD(a, b % a);
}

int main()
{
	int a, b;
	std::cin >> a >> b;
	std::cout << NOD(a, b);
}
