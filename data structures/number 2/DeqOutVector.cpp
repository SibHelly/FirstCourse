#include "DeqOutVector.h"
// ����������� ���� � ���������
DeqOutVector::DeqOutVector(int n) : size(n)
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
DeqOutVector::DeqOutVector(const DeqOutVector &deq)
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
const DeqOutVector &DeqOutVector::operator=(const DeqOutVector &deq)
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
DeqOutVector::~DeqOutVector()
{
    delete[] data;
}
// �������� �� �������
bool DeqOutVector::isEmpty()
{
    return (tail == -1);
}
// �������� �� �������������
bool DeqOutVector::isFull()
{
    return (tail == 0 && head == size - 1 || tail == head + 1);
}
// ������������� ������
DataType DeqOutVector::getHead()
{
    if (isEmpty())
        return -100;
    return data[head];
}
// ���������� ��������� � ������ ����
void DeqOutVector::addFront(DataType x)
{
    if (isFull())
    {
        cout << "��� ��������" << endl;
        cout << "��������� �� ���� ���������" << endl
             << endl;
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
void DeqOutVector::addBack(DataType x)
{
    if (isFull())
    {
        cout << "��� ��������" << endl;
        cout << "��������� �� ���� ���������" << endl
             << endl;
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
void DeqOutVector::deleteHead()
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
DataType DeqOutVector::outHead()
{
    if (isEmpty())
        return -100;
    int temp = data[head];
    deleteHead();
    return temp;
}
