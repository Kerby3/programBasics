#include <iostream>
#include<cassert>
#include "matrix.hpp"
#include <iomanip>


using el::Mat22i;
using el::Mat22d;
using el::Vec2i;

int main()
{

	std::cout << "...Test 1..." << std::endl;
	{
		Mat22i A({ { {1, 2},
					 {3, 4} } });

		Vec2i X({ { {1},
					{1} } });

		auto B = A * X;

		assert(B.get(0, 0) == 3);
		assert(B.get(1, 0) == 7);
	}
	std::cout << "Done" << std::endl;

	std::cout << "...Test 2..." << std::endl;
	{
		Mat22i A({ { {1, 2},
					 {3, 4} } });

		auto d = A.Det();

		assert(d == -2);

	}
	std::cout << "Done" << std::endl;

	std::cout << "...Test 3..." << std::endl;
	{
		Mat22d A({ { {1, 2},
					 {3, 4} } });

		auto B = A.Rev();

		assert(B.get(0, 0) == -2);
		assert(B.get(0, 1) == 1);
		assert(B.get(1, 0) == 1.5);
		assert(B.get(1, 1) == -0.5);
	}
	std::cout << "Done" << std::endl;

	std::cout << "...Test 4..." << std::endl;
	{
		Mat22i A({ { {1, 2},
					 {3, 4} } });



		auto B = A.Trans();

		assert(B.get(0, 0) == 1);
		assert(B.get(0, 1) == 3);
		assert(B.get(1, 0) == 2);
		assert(B.get(1, 1) == 4);
	}
	std::cout << "Done" << std::endl;



	return 0;
}
