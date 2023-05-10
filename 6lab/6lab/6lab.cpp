#include <iostream>

struct El_list // структура списка
{
	El_list* next;
	int num;
};

void Add(El_list* head, int num) // добавление элемента в список
{
	El_list* p = new El_list;
	p->num = num;

	p->next = head->next;
	head->next = p;
}

void Print(El_list* head) // вывод списка
{
	El_list* p = head->next;
	while (p != nullptr)
	{
		std::cout << p->num << std::endl;
		p = p->next;
	}
}


void Del(El_list* head, int a) // удаление элемента
{
	El_list* tmp;
	El_list* p = head;
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




void Duplicate(El_list* head) // дублирование элемента
{
	El_list* p = head->next;
	while (p != nullptr)
	{
		if (p->num % 2 == 1)
		{
			El_list* q = new El_list;
			q->next = p->next;
			p->next = q;
			q->num = p->num;
			p = p->next;
		}
		p = p->next;
	}
}


void Search(El_list* head, int k) //поиска элемента
{
	El_list* p = head->next;
	while (p != nullptr)
	{
		if (p->num == k)
		{
			std::cout << p->num << std::endl;
			p = p->next;
		}
		else
			p = p->next;
	}
}


int main()
{
	El_list* head = new El_list; // создаем список
	head->next = nullptr;

	Add(head, 2); //
	Add(head, 5); //
	Add(head, 7); //
	Add(head, 3); //
	Add(head, 9); // добавляем элементы в список

	Print(head); // распечатываем его
	std::cout << "====" << std::endl;

	Del(head, 2); // удаляем элемент

	Print(head); // печатаем элемент без этого списка
	std::cout << "====" << std::endl;

	Search(head, 7); // находим элемент

	std::cout << "====" << std::endl;

	Duplicate(head); // дублируем все элементы в списке

	Print(head); // распечатываем получившийся список
	std::cout << "====" << std::endl;

	delete head;

	return 0;
}
