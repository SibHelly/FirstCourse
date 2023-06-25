#ifndef DeqOutVector_HPP
#define DeqOutVector_HPP
#include "BaseDeq.h"
#include <iostream>

using namespace std;

template <class DataType>

class DeqOutVector : public BaseDeqOut<DataType>
{
    int head, tail; // ������ ������� � ��������� ��������
    int size;       // ������ �������
    DataType *data; // ������ ���������

public:
    DeqOutVector(int);                                   // ����������� ���� � ���������
    ~DeqOutVector();                                     // ���������� ����
    DeqOutVector(const DeqOutVector &);                  // ����������� �����������
    const DeqOutVector &operator=(const DeqOutVector &); // ���������� ��������� ������������
    void addFront(DataType);                             // ���������� �������� � ������ ����
    void addBack(DataType);                              // ���������� �������� � ����� ����
    bool isEmpty();                                      // �������� �� �������
    bool isFull();                                       // �������� �� �������������
    DataType getHead();                                  // ������������� ������
    int getSize() { return size; };                      // ��������� ������� ����
    void deleteHead();                                   // �������� ��������� � ��������� �����
    DataType outHead();                                  // ���������� ��������� � ��������� �����
};

// ����������� ���� � ���������
template <class DataType>
DeqOutVector<DataType>::DeqOutVector(int n) : size(n)
{
    data = new (nothrow) DataType[size];
    if (!data)
    {
        cout << "������ ��������� ������" << endl;
        return;
    }
    head = 0;
    tail = -1;
    this->size = size;
}
// ����������� �����������
template <class DataType>
DeqOutVector<DataType>::DeqOutVector(const DeqOutVector &deq)
{
    data = new (nothrow) DataType[deq.size];
    if (!data)
    {
        cout << "������ ��������� ������" << endl;
        return;
    }
    for (int i = 0; i < deq.size; i++)
        data[i] = deq.data[i];
    size = deq.size;
    head = deq.head;
    tail = deq.tail;
}
// ���������� ��������� ������������
template <class DataType>
const DeqOutVector<DataType> &DeqOutVector<DataType>::operator=(const DeqOutVector &deq)
{
    if (this != &deq)
    {
        delete[] data;
        data = new (nothrow) DataType[deq.size];
        if (!data)
        {
            cout << "������ �������� ������" << endl;
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
// ���������� ����
template <class DataType>
DeqOutVector<DataType>::~DeqOutVector()
{
    delete[] data;
}
// �������� �� �������
template <class DataType>
bool DeqOutVector<DataType>::isEmpty()
{
    return (tail == -1);
}
// �������� �� �������������
template <class DataType>
bool DeqOutVector<DataType>::isFull()
{
    return (tail == 0 && head == size - 1 || tail == head + 1);
}
// ������������� ������
template <class DataType>
DataType DeqOutVector<DataType>::getHead()
{
    if (isEmpty())
        return -100;
    return data[head];
}
// ���������� ��������� � ������ ����
template <class DataType>
void DeqOutVector<DataType>::addFront(DataType x)
{
    if (isFull())
    {
        cout << "��� ��������" << endl;
        cout << "������ ������� �� ��������" << endl;
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
// ���������� ��������� � ����� ����
template <class DataType>
void DeqOutVector<DataType>::addBack(DataType x)
{
    if (isFull())
    {
        cout << "��� ��������" << endl;
        cout << "������ ������� �� ��������" << endl;
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
// �������� �������� � ��������� �����
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
// ���������� ��������� � ��������� �����
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