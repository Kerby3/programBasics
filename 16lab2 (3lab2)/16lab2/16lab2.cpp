#include <iostream>

double f(double a) { return a - 10; } //Данное уравнение

double Bisection(double a, double b, double e) //Бисекция
{
	double fa = f(a); // левая граница
	while (1)
	{
		double x = (a + b) / 2; // сужаем границы
		if (abs(a - b) < e) //если отрезок меньше е
			return x; // вернуть корень
		else if (f(x) * fa > 0) //проверка, что х внутри отрезка
			a = x;
		else
			b = x;
	}
}

int main()
{
	double epsilon = 1e-4;
	double L = 0;
	double R = _MAX_INT_DIG;

	double ans = Bisection(L, R, epsilon);
	std::cout << ans;

}
