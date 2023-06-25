#include "DeqOutList.h"
// конструктор без параметро дека
DeqOutList::DeqOutList()
{
    this->head = this->tail = NULL;
}
// конструктор копирования
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
// перегрузка оператора присваивания
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
// деструктор дека
DeqOutList::~DeqOutList()
{
    while (head != NULL)
    {
        deleteHead();
    }
}
// удаление сообщения с открытого конца
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
// добавление сообщения в начало дека
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
// добавление сообщения в конец дека
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
// проверка на пустоту
bool DeqOutList::isEmpty()
{
    return (!head);
}
// проверка на заполненность
bool DeqOutList::isFull()
{

    Node *newNode = new (nothrow) Node(0);
    if (!newNode)
    {
        cout << "Ошибка выделения памяти" << endl;
        cout << "Дек заполнен" << endl;
        cout << "Сообщение не было добавлено" << endl
             << endl;
        delete newNode;
        return true;
    }
    else
    {
        return false;
    }
}
// неразрушающее чтения
DataType DeqOutList::getHead()
{
    if (isEmpty())
        return -100;
    else
        return head->data;
}
// извлечение сообщения с открытого конца
DataType DeqOutList::outHead()
{
    if (isEmpty())
        return -100;
    DataType x = head->data;
    deleteHead();
    return x;
}
