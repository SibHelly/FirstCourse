#include "spisok.h"
// функции списка
spis::spis()
{
    this->head = this->tail = NULL;
}

spis::~spis()
{
    delete[] this;
}

void spis::addBack(short int x)
{
    Node *newNode = new (nothrow) Node(x);
    if (isEmpty())
        head = newNode;
    if (tail != NULL)
        tail->next = newNode;
    tail = newNode;
}

void spis::showSpis()
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// функции создания графа
Graf::Graf(int V)
{
    this->numberVerties = V;
    graf = new spis[V];
}

void Graf::addVert(short int x, short int y)
{
    graf[x].addBack(y);
    graf[y].addBack(x);
}

void Graf::showGraf()
{
    for (int i = 0; i < numberVerties; i++)
    {
        graf[i].showSpis();
    }
}