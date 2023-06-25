#ifndef DeqOutList_H
#define DeqOutList_H
#include "BaseClass.h"
#include <iostream>

using namespace std;

typedef int DataType;

// запись односвязного списка
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

class DeqOutList : public BaseDeqOut
{
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

#endif