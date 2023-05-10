//Создайте класс, описывающий параллелограмм. Найдите его периметр и площадь.
#include <iostream>
#include "param.hpp"



int main()
{
	el::Parallelogram p(PI / 4, 5, 9);

	std::cout << "Perimetr:" << p.Perimetr() << " Square:" << p.Square() << std::endl;

	return 0;
}
