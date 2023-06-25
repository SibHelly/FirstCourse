#ifndef DeqOutVector_H
#define DeqOutVector_H
#include "BaseClass.h"
#include <iostream>

using namespace std;

typedef int DataType;

class DeqOutVector : public BaseDeqOut
{
    int head, tail; // ������ ������� � ��������� ��������
    int size;       // ������ �������
    DataType *data; // ������ ���������

public:
    DeqOutVector(int);                                   // ����������� ���� � ���������
    ~DeqOutVector();                                     // ���������� ����
    DeqOutVector(const DeqOutVector &);                  // ����������� �����������
    const DeqOutVector &operator=(const DeqOutVector &); // ���������� ��������� ������������
    void addFront(DataType);                             // ���������� ��������� � ������ ����
    void addBack(DataType);                              // ���������� ��������� � ����� ����
    bool isEmpty();                                      // �������� �� �������
    bool isFull();                                       // �������� �� �������������
    DataType getHead();                                  // ������������� ������
    int getSize() { return size; };                      // ��������� ������� ����
    void deleteHead();                                   // �������� ��������� � ��������� �����
    DataType outHead();                                  // ���������� ��������� � ��������� �����
};

#endif