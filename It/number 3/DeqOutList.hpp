#ifndef DeqOutList_HPP
#define DeqOutList_HPP
#include "BaseDeq.h"
#include <iostream>

using namespace std;

template <class DataType>
class DeqOutList : public BaseDeqOut<DataType>
{
    class Node
    {
    public:
        DataType data;
        Node *next;

    public:
        Node(DataType x) // конструктор записи односвязного списка
        {
            this->data = x;
            this->next = NULL;
        }
    };
    Node *head, *tail; // адреса начала и конца дека

public:
    DeqOutList();                                    // конструктор без параметро дека
    ~DeqOutList();                                   // деструктор дека
    DeqOutList(const DeqOutList &);                  // конструктор копирования
    const DeqOutList &operator=(const DeqOutList &); // перегрузка оператора присваивания
    void addFront(DataType);                         // добавление сообщения в начало дека
    void addBack(DataType);                          // добавление сообщения в конец дека
    bool isEmpty();                                  // проверка на пустоту
    bool isFull();                                   // проверка на заполненность
    DataType getHead();                              // неразрушающее чтения
    void deleteHead();                               // удаление сообщения с открытого конца
    DataType outHead();                              // извлечение сообщения с открытого конца
};

// конструктор без параметро дека
template <class DataType>
DeqOutList<DataType>::DeqOutList()
{
    this->head = this->tail = NULL;
}
// конструктор копирования
template <class DataType>
DeqOutList<DataType>::DeqOutList(const DeqOutList &deq)
{
    head = deq.head;
    Node *temp = head;
    while (temp != NULL)
    {
        addBack(temp->data);
        temp = temp->next;
        if (isFull())
        {
            cout << "Дек не может быть полнстью скопирован" << endl;
            delete this;
            break;
        }
    }
}
// перегрузка оператора присваивания
template <class DataType>
const DeqOutList<DataType> &DeqOutList<DataType>::operator=(const DeqOutList &deq)
{
    if (this != &deq)
    {
        head = deq.head;
        Node *temp = head;
        while (temp != NULL)
        {
            addBack(temp->data);
            temp = temp->next;
            if (isFull())
            {
                cout << "Дек не может быть полнстью скопирован" << endl;
                delete this;
                break;
            }
        }
    }
    return *this;
}
// деструктор дека
template <class DataType>
DeqOutList<DataType>::~DeqOutList()
{
    while (head != NULL)
    {
        deleteHead();
    }
}
// удаление сообщения с открытого конца
template <class DataType>
void DeqOutList<DataType>::deleteHead()
{
    if (isEmpty())
        return;
    if (head == tail)
    {
        delete tail;
        head = tail = NULL;
        return;
    }

    Node *temp = head;
    head = temp->next;
    delete temp;
}
// добавление сообщения в начало дека
template <class DataType>
void DeqOutList<DataType>::addFront(DataType x)
{
    if (!isFull())
    {
        Node *newNode = new (nothrow) Node(x);
        newNode->next = head;
        head = newNode;
        if (tail == NULL)
            tail = newNode;
    }
    else
        cout << "Данный элемент не добавлен" << endl;
}
// добавление сообщения в конец дека
template <class DataType>
void DeqOutList<DataType>::addBack(DataType x)
{
    if (!isFull())
    {
        Node *newNode = new (nothrow) Node(x);
        if (isEmpty())
            head = newNode;
        if (tail != NULL)
            tail->next = newNode;
        tail = newNode;
    }
    else
        cout << "Данный элемент не добавлен" << endl;
}
// проверка на пустоту
template <class DataType>
bool DeqOutList<DataType>::isEmpty()
{
    return (!head);
}
// проверка на заполненность
template <class DataType>
bool DeqOutList<DataType>::isFull()
{

    Node *newNode = new (nothrow) Node(0);
    if (!newNode)
    {
        cout << "Ошибка выделения памяти" << endl;
        cout << "Дек заполнен" << endl;
        delete newNode;
        return true;
    }
    else
    {
        return false;
    }
}
// неразрушающее чтения
template <class DataType>
DataType DeqOutList<DataType>::getHead()
{
    if (isEmpty())
        return -100;
    else
        return head->data;
}
// извлечение сообщения с открытого конца
template <class DataType>
DataType DeqOutList<DataType>::outHead()
{
    if (isEmpty())
        return -100;
    DataType x = head->data;
    deleteHead();
    return x;
}

#endif