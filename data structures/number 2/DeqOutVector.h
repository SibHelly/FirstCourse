#ifndef DeqOutVector_H
#define DeqOutVector_H
#include "BaseClass.h"
#include <iostream>

using namespace std;

typedef int DataType;

class DeqOutVector : public BaseDeqOut
{
    int head, tail; // индекс первого и конечного элемента
    int size;       // размер массива
    DataType *data; // массив сообщений

public:
    DeqOutVector(int);                                   // конструктор дека с парметром
    ~DeqOutVector();                                     // деструктор дека
    DeqOutVector(const DeqOutVector &);                  // конструктор копирования
    const DeqOutVector &operator=(const DeqOutVector &); // перегрузка оператора присваивания
    void addFront(DataType);                             // добавление сообщения в начало дека
    void addBack(DataType);                              // добавление сообщения в конец дека
    bool isEmpty();                                      // проверка на пустоту
    bool isFull();                                       // проверка на заполненность
    DataType getHead();                                  // неразрушающее чтения
    int getSize() { return size; };                      // получение размера дека
    void deleteHead();                                   // удаление сообщения с открытого конца
    DataType outHead();                                  // извлечение сообщения с открытого конца
};

#endif