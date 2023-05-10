//Дана последовательность натуральных чисел. Удалить из последовательности числа, содержащие цифру 9, а среди оставшихся продублировать числа, содержащие хотя бы   пару одинаковых цифр.
#include <iostream>
#define N 1000
#define M 2000

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

bool Consist9(int x)
{
	while (x > 0)
	{
		if (x % 10 == 9)
			return true;
		x = x / 10;
	}
	return false;
}

void Delete(int mas[N], int& q)
{


	int j = 0;
	for (int i = 0; i < N; i++)
	{
		if (!Consist9(mas[i]))
		{
			mas[j] = mas[i];
			j++;
		}
	}

	//for (int i = j; i < N; i++)
	//	mas[i] = 0;
}



void Double(int k, int mas[N])
{
	for (int i = N - 2; i >= k; i--)
	{
		mas[i + 1] = mas[i];
	}
}


int main()
{
	int mas[N] = { 2, 19, 91, 232, 5 };
	int a, b;
	a = 0;
	int max[M];

	int q = 0;


	Delete(mas, q);
	for (int i = 0; i < N; i++)
	{
		if (Check(mas[i]))
		{
			Double(i, mas);
			i++;
		}
	}


	for (int i = 0; i < N; i++)
	{
		std::cout << mas[i] << " ";
	}
}
