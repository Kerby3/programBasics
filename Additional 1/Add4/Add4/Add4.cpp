#include<iostream>

int main()
{
	int a, b, c, d, e, f, sum1, sum2, numberoftickets;
	int n = 10;
	numberoftickets = 0;
	sum1 = 0;
	sum2 = 0;
	for (a = 0; a < n; a++)
		for (b = 0; b < n; b++)
			for (c = 0; c < n; c++)
				for (d = 0; d < n; d++)
					for (e = 0; e < n; e++)
						for (f = 0; f < n; f++)
						{
							sum1 = a + b + c;
							sum2 = d + e + f;
							if (sum1 == sum2)
								numberoftickets += 1;
						}
	std::cout << numberoftickets << std::endl;

	return 0;
}
