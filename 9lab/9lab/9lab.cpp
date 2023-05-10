#include<iostream>
#include <fstream>
#include "bmp_struct.hpp"


int main()
{
	el::BMP pic;
	pic.Read();
	//pic.Entry();
	pic.Filtr();

	pic.Entry();

}
