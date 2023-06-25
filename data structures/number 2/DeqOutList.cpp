#include "DeqOutList.h"
// ����������� ��� ��������� ����
DeqOutList::DeqOutList()
{
    this->head = this->tail = NULL;
}
// ����������� �����������
DeqOutList::DeqOutList(const DeqOutList &deq)
{
    head = deq.head;
    Node *temp = head;
    while (temp != NULL)
    {
        addBack(temp->data);
        temp = temp->next;
    }
}
// ���������� ��������� ������������
const DeqOutList &DeqOutList::operator=(const DeqOutList &deq)
{
    if (this != &deq)
    {
        head = deq.head;
        Node *temp = head;
        while (temp != NULL)
        {
            addBack(temp->data);
            temp = temp->next;
        }
    }
    return *this;
}
// ���������� ����
DeqOutList::~DeqOutList()
{
    while (head != NULL)
    {
        deleteHead();
    }
}
// �������� ��������� � ��������� �����
void DeqOutList::deleteHead()
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
void DeqOutList::addFront(DataType x)
{
    if (!isFull())
    {
        Node *newNode = new (nothrow) Node(x);
        newNode->next = head;
        head = newNode;
        if (tail == NULL)
            tail = newNode;
    }
}
// ���������� ��������� � ����� ����
void DeqOutList::addBack(DataType x)
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
}
// �������� �� �������
bool DeqOutList::isEmpty()
{
    return (!head);
}
// �������� �� �������������
bool DeqOutList::isFull()
{

    Node *newNode = new (nothrow) Node(0);
    if (!newNode)
    {
        cout << "������ ��������� ������" << endl;
        cout << "��� ��������" << endl;
        cout << "��������� �� ���� ���������" << endl
             << endl;
        delete newNode;
        return true;
    }
    else
    {
        return false;
    }
}
// ������������� ������
DataType DeqOutList::getHead()
{
    if (isEmpty())
        return -100;
    else
        return head->data;
}
// ���������� ��������� � ��������� �����
DataType DeqOutList::outHead()
{
    if (isEmpty())
        return -100;
    DataType x = head->data;
    deleteHead();
    return x;
}
