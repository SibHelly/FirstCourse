#ifndef DeqOut_H
#define DeqOut_H
#include <iostream>

typedef int DataType;

class BaseDeqOut
{
public:
    virtual ~BaseDeqOut(){};             // ����������� ����������
    virtual void addFront(DataType) = 0; // ���������� ��������� � ������ ����
    virtual void addBack(DataType) = 0;  // ��������� ��������� � ����� ����
    virtual bool isEmpty() = 0;          // �������� �� �������
    virtual bool isFull() = 0;           // �������� �� �������������
    virtual DataType getHead() = 0;      // ������������� ������
    virtual DataType outHead() = 0;      // ���������� ��������� � ��������� �����
};

#endif