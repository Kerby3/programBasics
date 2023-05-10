// Введите последовательность целых чисел длиной не более 1000. Замените все простые числа в диапазоне от -100 до 100 на 0.

#include <iostream>
#include "functions.hpp"


int main()
{
    int n;
    int mas[N];

    el::Read(n, mas);

    el::Replacement(n, mas);

    el::Write(n, mas);
}

