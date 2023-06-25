#include "DeqOutVector.h"
// конструктор дека с парметром
DeqOutVector::DeqOutVector(int n) : size(n)
{
    data = new (nothrow) DataType[size];
    if (!data)
    {
        cout << "Ошибка выделения памяти" << endl;
        return;
    }
    head = 0;
    tail = -1;
    this->size = size;
}
// конструктор копирования
DeqOutVector::DeqOutVector(const DeqOutVector &deq)
{
    data = new (nothrow) DataType[deq.size];
    if (!data)
    {
        cout << "Ошибка выделения памяти" << endl;
        return;
    }
    for (int i = 0; i < deq.size; i++)
        data[i] = deq.data[i];
    size = deq.size;
    head = deq.head;
    tail = deq.tail;
}
// перегрузка оператора присваивания
const DeqOutVector &DeqOutVector::operator=(const DeqOutVector &deq)
{
    if (this != &deq)
    {
        delete[] data;
        data = new (nothrow) DataType[deq.size];
        if (!data)
        {
            cout << "Ошибка выдеения памяти" << endl;
            return NULL;
        }
        for (int i = 0; i < deq.size; i++)
            data[i] = deq.data[i];
        size = deq.size;
        head = deq.head;
        tail = deq.tail;
    }
    return *this;
}
// деструктор дека
DeqOutVector::~DeqOutVector()
{
    delete[] data;
}
// проверка на пустоту
bool DeqOutVector::isEmpty()
{
    return (tail == -1);
}
// проверка на заполненность
bool DeqOutVector::isFull()
{
    return (tail == 0 && head == size - 1 || tail == head + 1);
}
// неразрушающее чтения
DataType DeqOutVector::getHead()
{
    if (isEmpty())
        return -100;
    return data[head];
}
// добавление сообщения в начало дека
void DeqOutVector::addFront(DataType x)
{
    if (isFull())
    {
        cout << "Дек заполнен" << endl;
        cout << "Сообщение не было добавлено" << endl
             << endl;
    }
    else
    {
        if (isEmpty())
        {
            head = 0;
            tail = 0;
        }
        else if (head == size - 1)
            head = 0;
        else
            head += 1;
        data[head] = x;
    }
}
// добавление сообщения в конец дека
void DeqOutVector::addBack(DataType x)
{
    if (isFull())
    {
        cout << "Дек заполнен" << endl;
        cout << "Сообщение не было добавлено" << endl
             << endl;
    }
    else
    {
        if (isEmpty())
        {
            head = 0;
            tail = 0;
        }
        else if (tail == 0)
            tail = size - 1;
        else
            tail = tail - 1;
        data[tail] = x;
    }
}
// удаление элемента с открытого конца
void DeqOutVector::deleteHead()
{
    if (isEmpty())
        return;
    if (tail == head)
    {
        head = -1;
        tail = -1;
    }
    else if (head == 0)
        head = size - 1;
    else
        head = head - 1;
}
// извлечение сообщения с открытого конца
DataType DeqOutVector::outHead()
{
    if (isEmpty())
        return -100;
    int temp = data[head];
    deleteHead();
    return temp;
}
