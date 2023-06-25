#ifndef DeqOut_H
#define DeqOut_H
#include <iostream>

typedef int DataType;

class BaseDeqOut
{
public:
    virtual ~BaseDeqOut(){};             // виртуальный деструктор
    virtual void addFront(DataType) = 0; // добавление сообщения в начало дека
    virtual void addBack(DataType) = 0;  // доавление сообщения в конец дека
    virtual bool isEmpty() = 0;          // проверка на пустоту
    virtual bool isFull() = 0;           // проверка на заполненность
    virtual DataType getHead() = 0;      // неразрушающее чтение
    virtual DataType outHead() = 0;      // извлечение сообщения с открытого конца
};

#endif