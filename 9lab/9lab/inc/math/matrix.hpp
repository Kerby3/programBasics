#pragma once
#include <iostream>

namespace el
{
#define MY_DEBUG 

	template<typename T, int N, int M>
	struct TotMas
	{
		T mas[N][M];
	};

	template<typename T, int N, int M>
	class Matrix
	{

	public:
		// Конструктор
		Matrix()
		{
#ifdef MY_DEBUG
			std::cout << "Constructor" << std::endl;
#endif // MY_DEBUG
			m_n = N;
			m_m = M;
			for (int i = 0; i < m_n; i++)
				for (int j = 0; j < m_m; j++)
					m_mat[i][j] = 0;
		}

		Matrix(const T mas[N][M])
		{
#ifdef MY_DEBUG
			std::cout << "Constructor" << std::endl;
#endif
			m_n = N;
			m_m = M;
			for (int i = 0; i < m_n; i++)
				for (int j = 0; j < m_m; j++)
					m_mat[i][j] = mas[i][j];
		}

		Matrix(const TotMas<T, N, M>& mas)
		{
#ifdef MY_DEBUG
			std::cout << "Constructor" << std::endl;
#endif
			m_n = N;
			m_m = M;
			for (int i = 0; i < m_n; i++)
				for (int j = 0; j < m_m; j++)
					m_mat[i][j] = mas.mas[i][j];
		}


		// Конструктор копирования
		Matrix(const Matrix<T, N, M>& mat)
		{
#ifdef MY_DEBUG

			std::cout << "Copy constructor" << std::endl;
#endif // MY_DEBUG

			m_n = mat.m_n;
			m_m = mat.m_m;

			for (int i = 0; i < m_n; i++)
				for (int j = 0; j < m_m; j++)
					m_mat[i][j] = mat.m_mat[i][j];
		}

		int getN() const { return m_n; }
		int getM() const { return m_m; }
		T get(int i, int j) const { return m_mat[i][j]; }
		void set(int i, int j, T data) { m_mat[i][j] = data; }

		// Присваивание
		template<typename T, int N, int M>
		Matrix <T, N, M>& operator=(const Matrix<T, N, M>& mat)
		{
			std::cout << "Operator =" << std::endl;

			m_n = mat.getN();
			m_m = mat.getM();

			for (int i = 0; i < m_n; i++)
				for (int j = 0; j < m_m; j++)
					m_mat[i][j] = mat.get(i, j);

			return *this;
		}

		// Оператор сложения
		template<typename T, int N, int M>
		Matrix <T, N, M> operator+(const Matrix<T, N, M>& mat)
		{
			std::cout << "operator+" << std::endl;
			Matrix<T, N, M> tmp;
			for (int i = 0; i < m_n; i++)
				for (int j = 0; j < m_m; j++)
					tmp.m_mat[i][j] = m_mat[i][j] + mat.m_mat[i][j];
			return tmp;
		}

		// Оператор += 
		template<typename T, int N, int M>
		Matrix <T, N, M> operator+=(const Matrix<T, N, M>& mat)
		{
#ifdef MY_DEBUG
			std::cout << "operator+=" << std::endl;
#endif
			Matrix<T, N, M> tmp;
			for (int i = 0; i < m_n; i++)
				for (int j = 0; j < m_m; j++)
					tmp.m_mat[i][j] = m_mat[i][j] + mat.get(i, j);
			return tmp;
		}

		// Оператор умножения
		template<typename T, int N, int M>
		Matrix <T, N, M> operator*(const Matrix<T, N, M>& mat)
		{
#ifdef MY_DEBUG
			std::cout << "operator*" << std::endl;
#endif
			Matrix<T, N, M> tmp;

			for (int i = 0; i < m_n; i++)
				for (int j = 0; j < mat.getM(); j++)
				{
					T sum = 0;
					for (int k = 0; k < m_m; k++)
						sum += m_mat[i][k] * mat.get(k, j);
					tmp.set(i, j, sum);
				}
			return tmp;
		}

		template<typename T, int N, int M>
		Matrix <T, N, M> operator-(const Matrix<T, N, M>& mat)
		{
#ifdef MY_DEBUG
			std::cout << "operator+" << std::endl;
#endif
			Matrix<T, N, M> tmp;
			for (int i = 0; i < m_n; i++)
				for (int j = 0; j < m_m; j++)
					tmp.m_mat[i][j] = m_mat[i][j] - mat.m_mat[i][j];
			return tmp;
		}

		T Det()
		{
#ifdef MY_DEBUG
			std::cout << "determ" << std::endl;
#endif
			if ((m_m == 2 && m_n == 2) || (m_m == 3 && m_n == 3))
				if (m_m == 2 && m_n == 2)
				{
					T d;
					d = m_mat[0][0] * m_mat[1][1] - m_mat[0][1] * m_mat[1][0];
					return d;
				}
				else
				{
					T d;
					d = m_mat[0][0] * m_mat[1][1] * m_mat[2][2] + m_mat[1][0] * m_mat[0][1] * m_mat[2][2] + m_mat[0][2] * m_mat[1][0] * m_mat[2][1]
						- m_mat[0][0] * m_mat[1][2] * m_mat[2][1] - m_mat[0][1] * m_mat[1][0] * m_mat[2][2] - m_mat[0][2] * m_mat[1][1] * m_mat[2][0];
					return d;
				}
			else
				std::cout << "error" << std::endl;
		}

		Matrix <T, N, M> Rev()
		{
#ifdef MY_DEBUG
			std::cout << "reverse" << std::endl;
#endif
			if ((m_n == 2 && m_m == 2) || (m_n == 3 && m_m == 3))
			{
				if (m_n == 2 && m_m == 2)
				{
					Matrix<T, N, M> tmp;
					T f;
					f = m_mat[0][0] * m_mat[1][1] - m_mat[0][1] * m_mat[1][0];

					tmp.m_mat[0][0] = m_mat[1][1] / f;
					tmp.m_mat[1][0] = (-m_mat[1][0]) / f;
					tmp.m_mat[0][1] = (-m_mat[0][1]) / f;
					tmp.m_mat[1][1] = m_mat[0][0] / f;

					return tmp;
				}
				else
				{
					Matrix<T, N, M> tmp;
					T k;
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

		Matrix <T, N, M> Trans()
		{
#ifdef MY_DEBUG
			std::cout << "trans...ponirovane :)" << std::endl;
#endif
			Matrix<T, N, M> tmp;
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
#ifdef MY_DEBUG
			std::cout << "Destructor" << std::endl;
#endif
		}

		// friend - позволяет функции иметь доступ к private полям/методам класса
		template<typename T, int N, int M>
		friend std::istream& operator>>(std::istream& os, Matrix<T, N, M>& mat);

		template<typename T, int N, int M>
		friend std::ostream& operator<<(std::ostream& os, const Matrix<T, N, M>& mat);



		// Использование внутри класса
	private:
		int m_n, m_m;		// Поле
		//int n;
		T m_mat[N][M];
	};

	// Перегрузка оператора ввода
	template<typename T, int N, int M>
	std::istream& operator>>(std::istream& in, Matrix<T, N, M>& mat)
	{
		for (int i = 0; i < mat.m_n; i++)
			for (int j = 0; j < mat.m_m; j++)
				in >> mat.m_mat[i][j];
		return in;
	}

	// Перегрузка оператора вывода
	template<typename T, int N, int M>
	std::ostream& operator<<(std::ostream& out, const Matrix<T, N, M>& mat)
	{
		out << "Matrix " << mat.m_n << "x" << mat.m_m << std::endl;
		for (int i = 0; i < mat.m_n; i++) {
			for (int j = 0; j < mat.m_m; j++)
				out << mat.m_mat[i][j] << " ";
			out << std::endl;
		}
		return out;
	}

	using Vec2i = Matrix<int, 2, 1>;
	using Vec2d = Matrix<double, 2, 1>;
	using Mat22i = Matrix<int, 2, 2>;
	using Mat22d = Matrix<double, 2, 2>;

}
