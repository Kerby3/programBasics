//Дана последовательность натуральных чисел {Aj}j=1...n (n<=10000). Удалить из последовательности числа, содержащие цифру 9, а среди оставшихся продублировать числа, содержащие хотя бы   пару одинаковых цифр.
#include <iostream>
#include <fstream>
#include <vector>

int Check(int a)
{

	for (int i = 0; i < 10; i++)
	{
		int count = 0, sub = a;
		while (sub > 0)
		{
			if (sub % 10 == i)
				count++;
			if (count > 1)
			{
				return 1;
			}
			sub = (sub - (sub % 10)) / 10;
		}
	}
	return 0;
}

int main()
{
	std::vector <int> mas;

	int n, p, a, b;

	std::cin >> n;
	for (int i = 0; i < n; i++)
	{
		std::cin >> a;
		mas.push_back(a);
	}

	int erased = 0;

	int del = 0;
	while (del < mas.size())
	{
		a = mas[del];
		erased = 0;
		while (a > 0)
		{
			b = a % 10;
			a = a / 10;
			if (b == 9)
			{
				mas.erase(mas.begin() + del);
				erased = 1;
				break;
			}
		}
		if (!erased)
			del++;
	}

	// Дублирование
	for (int i = 0; i < mas.size(); i++) {
		if (Check(mas[i])) {
			mas.insert(mas.cbegin() + i, mas[i]); //
			i++;
		}
	}

	// Вывод
	for (int i = 0; i < mas.size(); i++)
	{
		std::cout << mas[i] << " ";
	}


	return 0;
}
