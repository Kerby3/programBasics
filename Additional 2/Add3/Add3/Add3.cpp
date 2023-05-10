#include <iostream>

struct El_list
{
	int num;
	struct El_list* next;
	struct El_list* prev;
};

struct El_list* init(int a)
{
	struct El_list* lst;
	lst = (struct El_list*)malloc(sizeof(struct El_list));
	lst->num = a;
	lst->next = lst;
	lst->prev = lst;
	return(lst);
}

struct El_list* Add(El_list* lst, int number)
{
	struct El_list* temp, * p;
	temp = (struct El_list*)malloc(sizeof(El_list));
	p = lst->next;
	lst->next = temp;
	temp->num = number;
	temp->next = p;
	temp->prev = lst;
	p->prev = temp;
	return(temp);
}

struct El_list* Del(El_list* lst)
{
	struct El_list* prev, * next;
	prev = lst->prev;
	next = lst->next;
	prev->next = lst->next;
	next->prev = lst->prev;
	free(lst);
	return(prev);
}

void Print(El_list* lst)
{
	struct El_list* p;
	p = lst;
	do {
		printf("%d ", p->num);
		p = p->next;
	} while (p != lst);
}

void PrintRev(El_list* lst)
{
	struct El_list* p;
	p = lst;
	do {
		p = p->prev;
			printf("%d ", p->num);
	} while (p != lst);
}

int main()
{
	El_list* q = init(15);

	Add(q, 5);
	Add(q, 1);
	Add(q, 7);
	Add(q, 9);
	Add(q, 3);

	Print(q);
	std::cout << "===" << std::endl;

	Del(q->next);
	Print(q);

	std::cout << "===" << std::endl;

	PrintRev(q);

	return 0;
}
