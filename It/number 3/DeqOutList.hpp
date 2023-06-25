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
        Node(DataType x) // ����������� ������ ������������ ������
        {
            this->data = x;
            this->next = NULL;
        }
    };
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

// ����������� ��� ��������� ����
template <class DataType>
DeqOutList<DataType>::DeqOutList()
{
    this->head = this->tail = NULL;
}
// ����������� �����������
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
            cout << "��� �� ����� ���� �������� ����������" << endl;
            delete this;
            break;
        }
    }
}
// ���������� ��������� ������������
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
                cout << "��� �� ����� ���� �������� ����������" << endl;
                delete this;
                break;
            }
        }
    }
    return *this;
}
// ���������� ����
template <class DataType>
DeqOutList<DataType>::~DeqOutList()
{
    while (head != NULL)
    {
        deleteHead();
    }
}
// �������� ��������� � ��������� �����
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
// ���������� ��������� � ������ ����
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
        cout << "������ ������� �� ��������" << endl;
}
// ���������� ��������� � ����� ����
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
        cout << "������ ������� �� ��������" << endl;
}
// �������� �� �������
template <class DataType>
bool DeqOutList<DataType>::isEmpty()
{
    return (!head);
}
// �������� �� �������������
template <class DataType>
bool DeqOutList<DataType>::isFull()
{

    Node *newNode = new (nothrow) Node(0);
    if (!newNode)
    {
        cout << "������ ��������� ������" << endl;
        cout << "��� ��������" << endl;
        delete newNode;
        return true;
    }
    else
    {
        return false;
    }
}
// ������������� ������
template <class DataType>
DataType DeqOutList<DataType>::getHead()
{
    if (isEmpty())
        return -100;
    else
        return head->data;
}
// ���������� ��������� � ��������� �����
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