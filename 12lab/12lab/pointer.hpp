#pragma once
#include <iostream>
#include <memory> // для std::shared_ptr и std::weak_ptr
#include <string>
#include <vector>
#define MY_DEBUG

class Student;

class Don
{
public:
	Don(std::string name)
	{
		e_don = name;
#ifdef MY_DEBUG
		std::cout << "don constructor works" << std::endl;
#endif // MY_DEBUG
	}
	~Don()
	{
#ifdef MY_DEBUG
		std::cout << "don destructor works" << std::endl;
#endif // MY_DEBUG
	}

	std::string getDon() { return e_don; }

	friend void StudentOfThisDon(std::shared_ptr<Don> D, std::shared_ptr<Student> S);

	void addStudent(std::shared_ptr<Student> student)
	{
		e_students.push_back(student);
	}

	void AllStudents()
	{
		if (!e_students.empty())//åñëè íå "ïóñòîé"
		{
			std::cout << e_don << "'s students: " << std::endl;
			for (auto const& student : e_students)
				std::cout << student->getDon() << std::endl;
		}
	}

private:
	//std::string e_name;
	std::string e_don;
	std::vector<std::shared_ptr<Student>> e_students;

};

class Student
{
public:
	Student(std::string name)
	{
		e_student = name;
#ifdef MY_DEBUG
		std::cout << "student constructor works" << std::endl;
#endif // MY_DEBUG

	}
	~Student()
	{
#ifdef MY_DEBUG
		std::cout << "student destructor works" << std::endl;
#endif
	}

	std::string nameStudent() { return e_student; }
	std::shared_ptr<Don> getDon() { e_don; }
	friend void StudentOfThisDon(std::shared_ptr<Don> D, std::shared_ptr<Student> S);

private:
	std::string e_student;
	std::shared_ptr<Don> e_don;
};
