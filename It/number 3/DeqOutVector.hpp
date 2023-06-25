#ifndef DeqOutVector_HPP
#define DeqOutVector_HPP
#include "BaseDeq.h"
#include <iostream>

using namespace std;

template <class DataType>

class DeqOutVector : public BaseDeqOut<DataType>
{
    int head, tail; // индекс первого и конечного элемента
    int size;       // размер массива
    DataType *data; // массив сообщений

public:
    DeqOutVector(int);                                   // конструктор дека с парметром
    ~DeqOutVector();                                     // деструктор дека
    DeqOutVector(const DeqOutVector &);                  // конструктор копировани€
    const DeqOutVector &operator=(const DeqOutVector &); // перегрузка оператора присваивани€
    void addFront(DataType);                             // добавление элемента в начало дека
    void addBack(DataType);                              // добавление элемента в конец дека
    bool isEmpty();                                      // проверка на пустоту
    bool isFull();                                       // проверка на заполненность
    DataType getHead();                                  // неразрушающее чтени€
    int getSize() { return size; };                      // получение размера дека
    void deleteHead();                                   // удаление сообщени€ с открытого конца
    DataType outHead();                                  // извлечение сообщени€ с открытого конца
};

// конструктор дека с парметром
template <class DataType>
DeqOutVector<DataType>::DeqOutVector(int n) : size(n)
{
    data = new (nothrow) DataType[size];
    if (!data)
    {
        cout << "ќшибка выделени€ пам€ти" << endl;
        return;
    }
    head = 0;
    tail = -1;
    this->size = size;
}
// конструктор копировани€
template <class DataType>
DeqOutVector<DataType>::DeqOutVector(const DeqOutVector &deq)
{
    data = new (nothrow) DataType[deq.size];
    if (!data)
    {
        cout << "ќшибка выделени€ пам€ти" << endl;
        return;
    }
    for (int i = 0; i < deq.size; i++)
        data[i] = deq.data[i];
    size = deq.size;
    head = deq.head;
    tail = deq.tail;
}
// перегрузка оператора присваивани€
template <class DataType>
const DeqOutVector<DataType> &DeqOutVector<DataType>::operator=(const DeqOutVector &deq)
{
    if (this != &deq)
    {
        delete[] data;
        data = new (nothrow) DataType[deq.size];
        if (!data)
        {
            cout << "ќшибка выдеени€ пам€ти" << endl;
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
template <class DataType>
DeqOutVector<DataType>::~DeqOutVector()
{
    delete[] data;
}
// проверка на пустоту
template <class DataType>
bool DeqOutVector<DataType>::isEmpty()
{
    return (tail == -1);
}
// проверка на заполненность
template <class DataType>
bool DeqOutVector<DataType>::isFull()
{
    return (tail == 0 && head == size - 1 || tail == head + 1);
}
// неразрушающее чтени€
template <class DataType>
DataType DeqOutVector<DataType>::getHead()
{
    if (isEmpty())
        return -100;
    return data[head];
}
// добавление сообщени€ в начало дека
template <class DataType>
void DeqOutVector<DataType>::addFront(DataType x)
{
    if (isFull())
    {
        cout << "ƒек заполнен" << endl;
        cout << "ƒанный элемент не добавлен" << endl;
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
// добавление сообщени€ в конец дека
template <class DataType>
void DeqOutVector<DataType>::addBack(DataType x)
{
    if (isFull())
    {
        cout << "ƒек заполнен" << endl;
        cout << "ƒанный элемент не добавлен" << endl;
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
template <class DataType>
void DeqOutVector<DataType>::deleteHead()
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
// извлечение сообщени€ с открытого конца
template <class DataType>
DataType DeqOutVector<DataType>::outHead()
{
    if (isEmpty())
        return -100;
    DataType temp = data[head];
    deleteHead();
    return temp;
}

#endif