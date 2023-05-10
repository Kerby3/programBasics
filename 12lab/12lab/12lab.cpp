//#include "pointer.hpp"

#include <iostream>
#include <memory> // для std::shared_ptr и std::weak_ptr
#include <string>
#include <vector>
#define MY_DEBUG

class Don;

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

    void addDon(std::shared_ptr<Don>& don)
    {
        e_don = don;
    }

private:
    std::string e_student;
    std::weak_ptr<Don> e_don;
};

class Don
{
public:
    Don(const std::string& name)
    {
        e_name = name;
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

    friend void StudentOfThisDon(std::shared_ptr<Don>& D, std::shared_ptr<Student>& S)
    {
        D->addStudent(S);
        S->addDon(D);
    }

    void addStudent(std::shared_ptr<Student>& student)
    {
        e_students.push_back(student);
    }

    void AllStudents()
    {
        if (!e_students.empty())//если не "пустой"
        {
            std::cout << e_name << "'s students: " << std::endl;

            for (const auto& student : e_students)
                std::cout << student.lock()->nameStudent() << std::endl;
        }
    }

private:
    std::string e_name;
    std::vector<std::weak_ptr<Student>> e_students;

};

int main()
{
    auto Ivan{ std::make_shared<Don>("Ivan") };
    auto Petr{ std::make_shared<Student>("Petr") };

    std::cout << Ivan.use_count() << " " << Petr.use_count() << std::endl;

    StudentOfThisDon(Ivan, Petr);

    std::cout << Ivan.use_count() << " " << Petr.use_count() << std::endl; // use count показвают сколько указателей осталось

    Ivan->AllStudents();
    return 0;
}
