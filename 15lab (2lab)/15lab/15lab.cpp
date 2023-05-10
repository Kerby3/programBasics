#include <iostream>
#include <chrono>

#define N 10

class Timer
{
private:
	// Псевдонимы типов используются для удобного доступа к вложенным типам
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

Timer t1;

void QuickSort(int a, int b, int* mas)
{
	if (a >= b) //
		std::cout << "Прошло времени t1 " << t1.elapsed() << std::endl;
		return; // терминирующее условие
	int m = ((rand() * rand()) % (b - a + 1)) + a; //
	int k = mas[m]; // выбор разделяющего элемента с помощью случайного числа
	int l = a - 1;                           //левая граница
	int r = b + 1;                          //правая граница 
	while (1)
	{
		do
		{
			l += 1; // если выполняется, то смещаем левый вправо
		} while (mas[l] < k); // проверка условия сортировки
		do
		{
			r -= 1; //если выполняется, то смещаем правый край влево
		} while (mas[r] > k); // проверка условия сортировки

		if (l >= r) // проверка условия "указателей" массива
			break; //выходим из бесконечного цикла
		std::swap(mas[r], mas[l]); // меняем элементы местами
	}
	r = l; //
	l = l - 1; // ставим "указатели" на место
	QuickSort(a, l, mas); //
	QuickSort(r, b, mas); // рекурсивно сортируем
}

Timer t2;

void BubleSort(int* mas, int n) { // пузырчатая сортировка
	for (int i = 1; i < n; i++)
	{
		if (mas[i] >= mas[i - 1])
		{
			continue;
		}
		int j = i - 1;
		while (j >= 0 && mas[j] > mas[j + 1])
		{
			std::swap(mas[j], mas[j + 1]);
			j = j - 1;
		}
		std::cout << "Прошло времени t2 " << t1.elapsed() << std::endl;
	}
	
}

int main()
{
	setlocale(LC_ALL, "Russian");
	int* mass = new int [N] {}; //первый массив
	int* masi = new int [N] {}; //второй массив
	srand(time(0)); // генератор случайных чисел

	for (int i = 0; i < N; i++)
	{
		mass[i] = rand(); // задаем элементы массива случайными числами
	}
	for (int i = 0; i < N; i++)
	{
		masi[i] = mass[i]; // задаем элементы второго  массива элементами первого
	}

	QuickSort(0, N - 1, mass); // быстрая сортировка 
	std::cout << '\n';

	for (int i = 0; i < N; i++)
	{
		std::cout << mass[i] << " ";
	}


	BubleSort(masi, N); // пузырьчатая сортировка
	std::cout << '\n';

	for (int i = 0; i < N; i++)
	{
		std::cout << masi[i] << " ";
	}

	delete[] mass; //
	delete[] masi; // очистка памяти
}
