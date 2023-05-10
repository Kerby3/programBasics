#include "functions.hpp"
#include <iostream>

namespace el
{
    bool IsPrime(int x) //������� ��
    {
        if (x < 2)
            return false;
        for (int d = 2; d <= sqrt(x); d++)
            if (x % d == 0)
                return false;
        return true;
    }

    bool Range(int a) //������ �� � ��������
    {
        if ((a >= -100) && (a <= 100))
            return true;
        else
            return false;
    }

    void Replacement(int n, int mas[N])//������
    {
        for (int i = 0; i < n; i++)
            if (IsPrime(mas[i]) && Range(mas[i]))
                mas[i] = 0;
            else
                mas[i] = mas[i];
    }

    void Read(int& n, int mas[N]) //������
    {
        std::cin >> n;
        for (int i = 0; i < n; i++)
            std::cin >> mas[i];
    }

    void Write(int n, int mas[1000]) //������
    {
        std::cout << n << std::endl;
        for (int i = 0; i < n; i++)
            std::cout << mas[i] << " ";
    }


}
