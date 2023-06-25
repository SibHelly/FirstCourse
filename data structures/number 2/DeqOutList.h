#ifndef DeqOutList_H
#define DeqOutList_H
#include "BaseClass.h"
#include <iostream>

using namespace std;

typedef int DataType;

// ������ ������������ ������
class Node
{
public:
    DataType data;
    Node *next;

public:
    Node(DataType x) // ����������� ������ ������������ ������
    {
        this->data = x;
        this->next = NULL;
    }
};

class DeqOutList : public BaseDeqOut
{
    Node *head, *tail; // ������ ������ � ����� ����

public:
    DeqOutList();                                    // ����������� ��� ��������� ����
    ~DeqOutList();                                   // ���������� ����
    DeqOutList(const DeqOutList &);                  // ����������� �����������
    const DeqOutList &operator=(const DeqOutList &); // ���������� ��������� ������������
    void addFront(DataType);                         // ���������� ��������� � ������ ����
    void addBack(DataType);                          // ���������� ��������� � ����� ����
    bool isEmpty();                                  // �������� �� �������
    bool isFull();                                   // �������� �� �������������
    DataType getHead();                              // ������������� ������
    void deleteHead();                               // �������� ��������� � ��������� �����
    DataType outHead();                              // ���������� ��������� � ��������� �����
};

#endif