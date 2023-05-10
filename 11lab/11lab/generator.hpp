#pragma once
#include <iostream>

enum Lang      //перечисление enum, в данном случае языки 
{
	JAVA = 0, C_PLUS_PLUS = 1, PHP = 2
};

class CodeGenerator
{
public:
	CodeGenerator(/*Lang language*/)
	{

	}
	virtual ~CodeGenerator()
	{

	}

	std::string generateCode()
	{
		return someCodeRelatedThing();
	}

protected:
	virtual std::string someCodeRelatedThing() = 0;

protected:
	Lang e_language;
};

class JAVAcodeGenerator : public CodeGenerator
{
public:

	JAVAcodeGenerator() : CodeGenerator()
	{

	}
	virtual~JAVAcodeGenerator()
	{

	}

private:
	std::string someCodeRelatedThing() override
	{
		return "JAVA code thing\n";
	}

private:
	Lang e_language;
};

class CPPcodeGenerator : public CodeGenerator
{
public:

	CPPcodeGenerator() : CodeGenerator()
	{

	}
	virtual~CPPcodeGenerator()
	{

	}

	std::string someCodeRelatedThing() override
	{
		return "CPP code thing\n";
	}

private:
	Lang e_language;
};

class PHPcodeGenerator : public CodeGenerator
{
public:

	PHPcodeGenerator() : CodeGenerator()
	{

	}
	virtual~PHPcodeGenerator()
	{

	}

	std::string someCodeRelatedThing() override
	{
		return "PHP code thing\n";
	}

private:
	Lang e_language;
};
