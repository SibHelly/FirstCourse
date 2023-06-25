#ifndef BaseDeqOut_H
#define BaseDeqOut_H
#include <iostream>

template <class DataType>
class BaseDeqOut
{
public:
    virtual ~BaseDeqOut(){};             // ����������� ����������
    virtual void addFront(DataType) = 0; // ���������� �������� � ������ ����
    virtual void addBack(DataType) = 0;  // ��������� �������� � ����� ����
    virtual bool isEmpty() = 0;          // �������� �� �������
    virtual bool isFull() = 0;           // �������� �� �������������
    virtual DataType getHead() = 0;      // ������������� ������
    virtual DataType outHead() = 0;      // ���������� �������� � ��������� �����
};

#endif