
#include <iostream>
#include <fstream>

struct Elem
{
    int data;       // Данные
    // Указатели на соседние вершины
    Elem* left;
    Elem* right;
    Elem* parent;
};

// Инициализация вершины
Elem* MAKE(int data, Elem* p)
{
    Elem* q = new Elem;         // Выделяем память под вершину
    q->data = data;
    q->left = nullptr;
    q->right = nullptr;
    q->parent = p;
    return q;
}

// Добавление элемента
void ADD(int data, Elem*& root)
{
    if (root == nullptr) {
        root = MAKE(data, nullptr);
        return;
    }
    Elem* v = root;
    while ((data < v->data && v->left != nullptr) || (data > v->data && v->right != nullptr))
        if (data < v->data)
            v = v->left;
        else
            v = v->right;
    if (data == v->data)
        return;
    Elem* u = MAKE(data, v);
    if (data < v->data)
        v->left = u;
    else
        v->right = u;
}

// Обход дерева
void PASS(Elem* v)
{
    if (v == nullptr)
        return;
    // Префиксный(перед тем с чем работает)

    PASS(v->left);
    // Инфиксный(между)
    std::cout << v->data << std::endl;

    PASS(v->right);

    // Постфиксный(после того с чем работает)
}

Elem* SEARCH(int data, Elem* v) // v - элемент, от которого начинаем поиск
{
    if (v == nullptr)
        return v;
    if (v->data == data)
        return v;
    if (data < v->data)
        return SEARCH(data, v->left);
    else
        return SEARCH(data, v->right);
}

Elem* SearchDepth(int data, Elem* v, int& k)//ищет на какой глубине находится искомое число 
{
    if (v == nullptr)
    {
        k = 0;
        return v;
    }
    if (v->data == data)
        return v;
    k++;
    if (data < v->data)
        return SearchDepth(data, v->left, k);
    else
        return SearchDepth(data, v->right, k);
}


void DELETE(int data, Elem*& root)
{
    // Проверка на сущ. такого элемента
    Elem* u = SEARCH(data, root);
    if (u == nullptr)
        return;

    // Удаление корня (особый случай)
    if (u->left == nullptr && u->right == nullptr && u == root)
    {
        delete root;
        root = nullptr;
        return;
    }

    // Присутствует правый потомок
    if (u->left == nullptr && u->right != nullptr && u == root) // TODO убрать u==root
    {
        Elem* t = u->right;
        while (t->left != nullptr)
            t = t->left;
        u->data = t->data;
        u = t;
    }

    // Присутствует левый потомок
    if (u->left != nullptr && u->right == nullptr && u == root) // TODO убрать u==root
    {
        Elem* t = u->left;
        while (t->right != nullptr)
            t = t->right;
        u->data = t->data;
        u = t;
    }

    // Если оба потомка присутствуют
    if (u->left != nullptr && u->right != nullptr)
    {
        Elem* t = u->right;
        while (t->left != nullptr)
            t = t->left;
        u->data = t->data;
        u = t;
    }
    Elem* t;
    if (u->left == nullptr)
        t = u->right;
    else
        t = u->left;
    if (u->parent->left == u)
        u->parent->left = t;
    else
        u->parent->right = t;
    if (t != nullptr)
        t->parent = u->parent;
    delete u;
}

// Обход дерева
void CLEAR(Elem*& v)
{
    if (v == nullptr)
        return;
    // Префиксный

    CLEAR(v->left);
    // Инфиксный

    CLEAR(v->right);

    // Постфиксный
    delete v;
    v = nullptr;
}

int main()
{
    setlocale(LC_ALL, "Rus");
    std::ofstream out("output.txt");

    Elem* root = nullptr;
    char kom;
    int num;
    int k = 0;

    std::cout << "введите команду в виде знака операции (+ добавление элемента, - удаление элемента, ? поиск элемента) и числа, для завершения ввода введите E и любое число" << std::endl;

    while (1)
    {
        std::cin >> kom >> num;



        if (kom == '+')
            ADD(num, root);

        if (kom == '-')
            DELETE(num, root);

        if (kom == '?')
        {
            int k = 1;
            SearchDepth(num, root, k);
            //std::cout << k << std::endl;
            out << k << " ";
        }

        if (kom == 'E')
        {
            break;
        }

        //std::cout << kom << std::endl;
        //std::cout << num << std::endl;
    }

    return 0;
}
