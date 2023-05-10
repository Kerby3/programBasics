// Вариант 7. Дана матрица NхN.Найдите наибольшую сумму элементов столбца.
//Оцените сложность алгоритма в лучшем, среднем и худшем случае.Рассчитайте примерное время работы алгоритма.Запрограммируйте его.Определите реальное время работы.

#include <iostream>
#define N 10000

#include <chrono> // для функций из std::chrono

class Timer
{
private:
	// Псевдонимы типов используются для удобного доступа к вложенным типам
	using clock_t = std::chrono::high_resolution_clock; // таймер
	using second_t = std::chrono::duration<double, std::ratio<1>>; // необходимо для приведения чисел к удобному виду

	std::chrono::time_point<clock_t> m_beg; //момент времени

public:
	Timer() : m_beg(clock_t::now())
	{
	}

	double elapsed() const
	{
		return std::chrono::duration_cast<second_t>(clock_t::now() - m_beg).count(); // прошедшее время
	}
};


int matrix[N][N]; //матрица
int main()
{
	srand(time(0)); //генератор случайных чисел

	int max, sum;
	max = INT_MIN;

	for (int i = 0; i < N; i++) //
		for (int j = 0; j < N; j++) // проходимся по массивам
			matrix[i][j] = rand(); //задаем случайное число элементу матрицы

	Timer t; //создаем таймер

	for (int j = 0; j < N; j++) // проходимся по столбцам матрицы
	{
		sum = 0; // текущая сумма столбца
		for (int i = 0; i < N; i++) // проходимся по элементам столбца
			sum = sum + matrix[i][j]; // прибавляем значения элемента к сумме 
		if (sum > max) //если сумма больше максимальной
			max = sum; //сделать ее максимальной
	}

	std::cout << "Time elapsed: " << t.elapsed() << '\n'; //вывод времени

	std::cout << max; //вывод максимальной суммы
}
