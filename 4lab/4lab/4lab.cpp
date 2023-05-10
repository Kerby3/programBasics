//Создайте односвязный список из 10000 целых чисел и реализуйте в нем операцию удаления элемента k.
//Если элементов, равных k несколько, удалите их все. Выполните M = 1000 запросов на удаление.
//Реализуйте такую же операцию для массива.Сравните производительность.
#include <iostream>
#define N 10000
#define M 1000
struct El_List //  структура списка
{
	El_List* next;
	int num;
};
void Add(El_List* head, int num) // добавление элемента в список
{
	El_List* p = new El_List;
	p->num = num;
	p->next = head->next;
	head->next = p;
}
void Print(El_List* head) // вывод списка
{
	El_List* p = head->next;
	while (p != nullptr)
	{
		std::cout << p->num << " ";
		p = p->next;
	}
}
void Del(El_List* head, int a) // удаление элемента списка
{
	El_List* tmp;
	El_List* p = head;
	while (p->next != nullptr)
	{
		if (p->next->num == a)
		{
			tmp = p->next;
			p->next = p->next->next;
			delete tmp;
		}
		else
			p = p->next;
	}
}
int main() // выполнение задания над списком
{
	srand(time(0));
	El_List* head = new El_List;
	head->next = nullptr;
	int k;
	std::cin >> k;
	for (int i = 0; i < N; i++)
		Add(head, (rand() % 100));
	Print(head);
	std::cout << "====" << std::endl;
	Del(head, k);
	Print(head);
	std::cout << "====" << std::endl;
	for (int i = 0; i < M; i++)
	{
		//int b = (rand() % 100);
		Del(head, (i + 11));
	}
	Print(head);
	std::cout << "====" << std::endl;
	delete head;
	return 0;
}

/*int main() // выполнение задания над массивом
{
	srand(time(0));
	int *mas = new int[N];
	int k;
	std::cin >> k;
	for (int i = 0; i < N; i++)
		mas[i] = (rand() % 100);
	for (int i = 0; i < N; i++)
		std::cout << mas[i] << " ";
	std::cout << "====" << std::endl;
	int n = N;
	int j = 0;
	for (int i = 0; i < n; i++)
	{
		if (mas[i] != k)
		{
			mas[j] = mas[i];
			j++;
		}
	}
	n = j;
	for (int i = 0; i < n; i++)
		std::cout << mas[i] << " ";
	std::cout << "====" << std::endl;
	int m = M;
	int d = 0;
	for (int i = 0; i < m; i++)
	{
		if (mas[i] != (rand() % 100))
		{
			mas[d] = mas[i];
			d++;
		}
	}
	n = d;
	for (int i = 0; i < n; i++)
		std::cout << mas[i] << " ";
	std::cout << "====" << std::endl;
	delete[] mas;
	return 0;
}*/

//для списка: 10.2202 / 6.48055 / 9.59745
//для массива : 12.9448 / 9.98126 / 15.8064
