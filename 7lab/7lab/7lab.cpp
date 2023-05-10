#include <iostream>

class Matrix
{
	// Абстракция
	// Инкапсуляция
	// Использование вне класса
public:
	// Конструктор
	Matrix(int n, int m)
	{
		std::cout << "Конструктор" << std::endl;
		m_n = n;
		m_m = m;
		m_mat = new int* [m_n];
		for (int i = 0; i < m_n; i++)
			m_mat[i] = new int[m_m];
	}

	// Конструктор копирования
	Matrix(const Matrix& mat)
	{
		std::cout << "Конструктор копирования" << std::endl;

		m_n = mat.m_n;
		m_m = mat.m_m;

		m_mat = new int* [m_n];
		for (int i = 0; i < m_n; i++)
			m_mat[i] = new int[m_m];

		for (int i = 0; i < m_n; i++)
			for (int j = 0; j < m_m; j++)
				m_mat[i][j] = mat.m_mat[i][j];
	}

	// Присваивание
	Matrix& operator=(const Matrix& mat)
	{
		std::cout << "Оператор присваивания" << std::endl;

		m_n = mat.m_n;
		m_m = mat.m_m;

		for (int i = 0; i < m_n; i++)
			for (int j = 0; j < m_m; j++)
				m_mat[i][j] = mat.m_mat[i][j];

		return *this;
	}

	// Оператор сложения
	Matrix operator+(const Matrix& mat) {
		std::cout << "Оператор сложения" << std::endl;
		Matrix tmp(m_n, m_m);
		for (int i = 0; i < m_n; i++)
			for (int j = 0; j < m_m; j++)
				tmp.m_mat[i][j] = m_mat[i][j] + mat.m_mat[i][j];
		return tmp;
	}

	// Оператор умножения
	Matrix operator*(const Matrix& mat) {
		std::cout << "Оператор умножения" << std::endl;
		Matrix tmp(m_n, mat.m_m);
		for (int i = 0; i < m_n; i++)
			for (int j = 0; j < m_m; j++)
				tmp.m_mat[i][j] = 0;
		for (int i = 0; i < m_n; i++)
			for (int j = 0; j < m_m; j++)
				for (int k = 0; k < m_m; k++)
					tmp.m_mat[i][j] += m_mat[i][k] + mat.m_mat[k][j];
		return tmp;
	}

	Matrix operator-(const Matrix& mat)
	{
		std::cout << "Оператор вычитания" << std::endl;
		Matrix tmp(m_n, m_m);
		for (int i = 0; i < m_n; i++)
			for (int j = 0; j < m_m; j++)
				tmp.m_mat[i][j] = m_mat[i][j] - mat.m_mat[i][j];
		return tmp;
	}

	int Det()
	{
		std::cout << "Вычисляем определитель" << std::endl;
		if ((m_m == 2 && m_n == 2) || (m_m == 3 && m_n == 3))
			if (m_m == 2 && m_n == 2)
			{
				int d;
				d = m_mat[0][0] * m_mat[1][1] - m_mat[0][1] * m_mat[1][0];
				return d;
			}
			else
			{
				int d;
				d = m_mat[0][0] * m_mat[1][1] * m_mat[2][2] + m_mat[1][0] * m_mat[0][1] * m_mat[2][2] + m_mat[0][2] * m_mat[1][0] * m_mat[2][1]
					- m_mat[0][0] * m_mat[1][2] * m_mat[2][1] - m_mat[0][1] * m_mat[1][0] * m_mat[2][2] - m_mat[0][2] * m_mat[1][1] * m_mat[2][0];
				return d;
			}
		else
			std::cout << "error" << std::endl;
	}

	Matrix Rev()
	{
		std::cout << "Обратная матрица" << std::endl;
		if ((m_n == 2 && m_m == 2) || (m_n == 3 && m_m == 3))
		{
			if (m_n == 2 && m_m == 2)
			{
				Matrix tmp(m_n, m_m);
				int k;
				k = Det();

				tmp.m_mat[0][0] = m_mat[1][1] / k;
				tmp.m_mat[1][0] = -m_mat[0][1] / k;
				tmp.m_mat[0][1] = -m_mat[1][0] / k;
				tmp.m_mat[1][1] = m_mat[0][0] / k;

				return tmp;
			}
			else
			{
				Matrix tmp(m_n, m_m);
				int k;
				k = tmp.Det();

				tmp.m_mat[0][0] = (m_mat[1][1] * m_mat[2][2] - m_mat[2][1] * m_mat[1][2]) / k;
				tmp.m_mat[0][1] = -(m_mat[0][1] * m_mat[2][2] - m_mat[2][1] * m_mat[0][2]) / k;
				tmp.m_mat[0][2] = (m_mat[0][1] * m_mat[1][2] - m_mat[1][1] * m_mat[0][2]) / k;

				tmp.m_mat[1][0] = -(m_mat[1][0] * m_mat[2][2] - m_mat[2][0] * m_mat[1][2]) / k;
				tmp.m_mat[1][1] = (m_mat[0][0] * m_mat[2][2] - m_mat[2][0] * m_mat[0][2]) / k;
				tmp.m_mat[1][2] = -(m_mat[0][0] * m_mat[1][2] - m_mat[1][0] * m_mat[0][2]) / k;

				tmp.m_mat[2][0] = (m_mat[1][0] * m_mat[2][1] - m_mat[2][0] * m_mat[1][1]) / k;
				tmp.m_mat[2][1] = -(m_mat[0][0] * m_mat[2][1] - m_mat[2][0] * m_mat[0][1]) / k;
				tmp.m_mat[2][2] = (m_mat[0][0] * m_mat[1][1] - m_mat[1][0] * m_mat[0][1]) / k;

				return tmp;
			}
		}
		else
			std::cout << "error" << std::endl;
	}

	Matrix Trans()
	{
		std::cout << "Транспонирование" << std::endl;
		Matrix tmp(m_n, m_m);
		for (int i = 0; i < m_n; i++)
			for (int j = 0; j < m_m; j++)
			{
				tmp.m_mat[i][j] = m_mat[j][i];
			}
		return tmp;
	}

	// Деструктор
	~Matrix()
	{
		std::cout << "Деструктор" << std::endl;
		for (int i = 0; i < m_n; i++)
			delete[] m_mat[i];
		delete m_mat;
	}

	// friend - позволяет функции иметь доступ к private полям/методам класса
	friend std::istream& operator>>(std::istream& os, Matrix& mat);
	friend std::ostream& operator<<(std::ostream& os, const Matrix& mat);



	// Использование внутри класса
private:
	int m_n, m_m;		// Поле
	int n;
	int** m_mat;
};

// Перегрузка оператора ввода
// 
std::istream& operator>>(std::istream& in, Matrix& mat)
{
	for (int i = 0; i < mat.m_n; i++)
		for (int j = 0; j < mat.m_m; j++)
			in >> mat.m_mat[i][j];
	return in;
}

// Перегрузка оператора вывода
std::ostream& operator<<(std::ostream& out, const Matrix& mat)
{
	out << "Матрица " << mat.m_n << "x" << mat.m_m << std::endl;
	for (int i = 0; i < mat.m_n; i++) {
		for (int j = 0; j < mat.m_m; j++)
			out << mat.m_mat[i][j] << " ";
		out << std::endl;
	}
	return out;
}

void print(Matrix& mat)
{
	std::cout << "111" << std::endl;
}

int main()
{
	setlocale(LC_ALL, "Russian");

	Matrix A(2, 2);

	std::cin >> A;
	std::cout << A << std::endl;

	std::cout << A.Rev() << std::endl;

	Matrix B(2, 2);
	std::cin >> B;
	std::cout << B << std::endl;

	Matrix C(2, 2);
	C = A + B;

	std::cout << C << std::endl;

	C = A * B;
	std::cout << C << std::endl;

	std::cout << A.Det() << std::endl;

	A = C - B;
	std::cout << A << std::endl;

	std::cout << A.Trans() << std::endl;

	std::cout << A << std::endl;

	std::cout << A.Trans() << std::endl;

	std::cout << A << std::endl;

	return 0;
}
