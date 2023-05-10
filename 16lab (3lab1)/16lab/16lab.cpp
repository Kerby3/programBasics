//   ,      .    M (0<M<10000)      N (0<N<100000) ,     
//Вариант 7 1.	Реализуйте алгоритм бинарного поиска, о котором шла речь на лекции.
//Решите задачу выполнения M(0 < M < 10000) поисковых запросов над массивом из N(0 < N < 100000) элементов, используя проход по массиву циклом и бинарный поиск.
//Сравните время работы этих двух подходов.

#include <iostream>
#include <chrono> //    std::chrono

#define N 100000
#define M 1000

class Timer
{
private:
	//         
	using clock_t = std::chrono::high_resolution_clock;
	using second_t = std::chrono::duration<double, std::ratio<1> >;

	std::chrono::time_point<clock_t> m_beg;

public:
	Timer() : m_beg(clock_t::now())
	{
	}

	double elapsed() const
	{
		return std::chrono::duration_cast<second_t>(clock_t::now() - m_beg).count();
	}
};



int BinarySearch(int* mas, int l, int n, int k)
{
	if (k < mas[l]) //
		return -1; //
	if (k == mas[l]) // 
		return 0; //
	if (k > mas[n]) //
		return -1; //

	int a = l; // 
	int b = n; // ищем новые границы

	while (a + 1 < b) //
	{
		int c = (a + b) / 2; //
		if (k > mas[c]) //
			a = c; //
		else //
			b = c; //
 	}
	if (mas[b] == k) //
		return b; //
	else // 
		return -1; // сужаем границы
}

int main()
{
	setlocale(LC_ALL, "rus");
	srand(time(0));

	int* mass = new int[N];
	int kk = rand() % N + 1;

	for (int i = 0; i < N; i++)
		mass[i] = i + 1;

	Timer B;
	std::cout << " " << '\n';
	for (int i = 0; i < M; i++)
	{
		//std::cout << "" << kk << " " << BinarySearch(mass, 0, N - 1, kk) << '\n'; //используем бинарный поиск
	}
	std::cout << "  = " << B.elapsed() << '\n';

	Timer C;
	std::cout << "" << '\n';
	for (int i = 0; i < M; i++)
		for (int j = 0; j < N; j++)
			if (mass[j] == kk)
			{
				//std::cout << "" << kk << " " << j << '\n'; // используем циклы
				break;
			}
	std::cout << "  = " << C.elapsed() << '\n';
}
