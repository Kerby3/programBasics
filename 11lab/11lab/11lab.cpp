#include "generator.hpp"
#include <iostream>

int main()
{
	JAVAcodeGenerator java;
	std::cout << java.generateCode().data();//.data() достаёт массив char из std::string
	CPPcodeGenerator cpp;
	std::cout << cpp.generateCode().data();
	PHPcodeGenerator php;
	std::cout << php.generateCode().data();

	return 0;
}
