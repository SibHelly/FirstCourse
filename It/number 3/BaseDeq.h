#ifndef BaseDeqOut_H
#define BaseDeqOut_H
#include <iostream>

template <class DataType>
class BaseDeqOut
{
public:
    virtual ~BaseDeqOut(){};             // виртуальный деструктор
    virtual void addFront(DataType) = 0; // добавление элемента в начало дека
    virtual void addBack(DataType) = 0;  // доавление элемента в конец дека
    virtual bool isEmpty() = 0;          // проверка на пустоту
    virtual bool isFull() = 0;           // проверка на заполненность
    virtual DataType getHead() = 0;      // неразрушающее чтение
    virtual DataType outHead() = 0;      // извлечение элемента с открытого конца
};

#endif