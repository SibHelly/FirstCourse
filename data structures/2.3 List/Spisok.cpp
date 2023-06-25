#ifndef Spisok_CPP
#define Spisok_CPP
#include "spisok.h"
#include "func.h"
#include <string>
using namespace std;

// ������� ������
// ����������� ������ ��� ����������
spis::spis()
{
    this->head = this->tail = NULL;
}
// ��������� ������ �� �������
bool spis::isEmpty()
{
    return (!head);
}
// ���������� ������
spis::~spis()
{
    // cout << "Destructor spis" << endl;
    while (head != NULL)
    {
        deleteHead();
    }
    head = NULL;
}
// ���������� �������� � ����� ������������ ������
void spis::addBack(short int x)
{
    Node *newNode = new (nothrow) Node(x);
    if (isEmpty())
        head = newNode;
    if (tail != NULL)
        tail->next = newNode;
    tail = newNode;
}
// ����� ������
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
// �������� �� ������� ��������� �������� � ������
bool spis::findThis(int x)
{
    Node *temp = head;
    bool flag = false;
    while (temp != NULL)
    {
        if (temp->data == x)
            flag = true;
        temp = temp->next;
    }
    return flag;
}
// �������� �������� � ������ ������������ ������
void spis::deleteHead()
{
    if (isEmpty()) // ���� ������ ����
        return;
    if (head == tail) // ���� ���� �������
    {
        delete tail;
        head = tail = NULL;
        return;
    }
    // ���� �� ����
    Node *temp = head;
    head = temp->next;
    delete temp;
}

// ������� �������� �����
Graf::Graf(int V) // ���������� �������� ����� � ����������
{
    this->numberVerties = V;
    if (!graf)
    {
        cout << "������ ��������� ������" << endl;
        return;
    }
}
// ����������� ����� ��� ����������
Graf::Graf()
{
    this->numberVerties = 0;
    graf = NULL;
}
// ����������� �����������
Graf::Graf(const Graf &x)
{
    this->numberVerties = x.numberVerties;                // ����������� ���������� ������
    this->graf = new (nothrow) spis[this->numberVerties]; // �������� ������ ��� ������ �������
    if (!this->graf)
    {
        cout << "������ ��������� ������" << endl;
        this->graf = NULL;
        return;
    }
    for (int i = 0; i < this->numberVerties; i++) // ��������� ��� ����������� ������
    {
        Node *temp = x.graf[i].head; // ������ ������� ������������ ������
        while (temp != NULL)         // ���� ���� �������� ��������
        {
            this->graf[i].addBack(temp->data);
            temp = temp->next;
        }
    }
}
// ������� ��� ������ ����� �� ����� � ��� ���������� � ��� ��������
// ���������� �����
Graf::~Graf()
{
    for (int i = 0; i < numberVerties + 1; i++) // �������� �� ���� ��������� �������
    {
        graf[i].head = NULL;
    }
    delete[] this->graf; // ������� ����
    graf = NULL;
}

Graf &Graf::operator=(const Graf &x)
{
    this->numberVerties = x.numberVerties;                // ����������� ���������� ������
    this->graf = new (nothrow) spis[this->numberVerties]; // �������� ������ ��� ������ �������
    if (!this->graf)
    {
        cout << "������ ��������� ������" << endl;
        this->graf = NULL;
        return *this;
    }
    for (int i = 0; i < this->numberVerties; i++) // ��������� ��� ����������� ������
    {
        Node *temp = x.graf[i].head;
        while (temp != NULL)
        {
            this->graf[i].addBack(temp->data);
            temp = temp->next;
        }
    }
    return *this;
}
// ����� �����
void Graf::showGraf()
{
    if (graf != NULL)
        for (int i = 0; i < numberVerties; i++)
        {
            cout << i << " :";
            graf[i].showSpis();
        }
    else
        cout << "���� ����" << endl;
}
// �������� ������ ������� �� �������
bool Empty(int *arr, int count)
{
    for (int i = 0; i < count; i++)
        if (arr[i] != 0)
            return false;
    return true;
}

Graf::Graf(ifstream &in)
{
    if (in.is_open()) // ���� ���� ����
    {
        in.seekg(0, ios::beg);
        string s;
        int x;
        in >> x;                   // ��������� ��� ������������� ����� � �����
        in >> this->numberVerties; // ��������� ���������� ������ �����
        getline(in, s);            // �������� ������ � ������� ��
        s.clear();
        if (x == 0)
        {
            cout << "� ����� ������� ���������" << endl;
            this->graf = new (nothrow) spis[this->numberVerties]; // �������� ������
            if (!this->graf)
            {
                cout << "������ ��������� ������" << endl;
                return;
            }
            for (int i = 0; i < this->numberVerties; i++) // �������� ��������� ��������� ���� � ��������� ����������� ������
            {
                getline(in, s);                   // ������� ������
                int countS = this->numberVerties; // ���������� ����� � ������ ������� ���������
                int *arr = strToArr(s, countS);   // �������� ������ ����� �� ������
                if (arr == NULL)
                {

                    cout << "������ ��������� ������" << endl;
                    return;
                }
                if (Empty(arr, numberVerties)) // ���� ��� ���� ������ ��� ������� ������
                {
                    this->graf[i].addBack(-1);
                }
                else // ���� ���� ������� �������
                {
                    for (int j = 0; j < countS; j++)
                    {
                        if (arr[j] == 1 && !this->graf[i].findThis(j)) // ���� 1 � ������ �� ������� � ����� �������� ��� ��� � ����������� ������
                            this->graf[i].addBack(j);                  // ��������� � �����
                    }
                }
                s.clear();    // ������� ������
                delete[] arr; // ������� ������
            }
        }
        if (x == 1) // ���� � ����� ������ ���������
        {
            cout << "� ����� ������ ������� ������" << endl;
            this->graf = new (nothrow) spis[this->numberVerties]; // �������� ������
            if (!this->graf)
            {
                cout << "������ ��������� ������" << endl;
                return;
            }
            for (int i = 0; i < this->numberVerties; i++) // ��������� ������
            {
                getline(in, s);
                int countS = search_count(s);   // �������� ���������� ������� ������
                int *arr = strToArr(s, countS); // ������� ������ �� ������
                if (arr == NULL)
                {
                    cout << "������ ��������� ������" << endl;
                    return;
                }
                if (arr[0] == -1) // ���� -1 , �� ��� ������� ������
                {
                    this->graf[i].addBack(-1);
                }
                else // ���� ���� ������� �������
                {
                    for (int j = 0; j < countS; j++)
                    {
                        if (!this->graf[i].findThis(arr[j])) // ���� �������� �� ������� ��� ��� � ����������� ������ ��������� ���
                            this->graf[i].addBack(arr[j]);
                    }
                }
                s.clear();    // �������
                delete[] arr; // ������� ������
            }
        }
    }
    else // ���� ������ ����� ���
    {
        cout << "���� �� ������" << endl;
    }
}

Node *findTodel(spis &x, int k) // ����� ��������� �� ��������� �������(�� ���� �������������� ����������)
{
    Node *temp = x.head;
    bool flag = true;
    while (temp != NULL)
    {
        if (temp->data == k) // ���� ������ �������
            break;
        if (temp->next->data == k) // ���� ��������� ������� ������������ ������ ����� �����, �� ���������� ����� ����� ������
        {
            break;
        }
        temp = temp->next;
    }
    return temp;
}
// �������� �� ������������ ������ � ������������ �������
void delFrom(spis &x, int k)
{
    Node *node = findTodel(x, k); // ������� �������������� ������� ��� ����������
    Node *temp;
    bool flag = true;
    if (x.head->data == k && x.head == x.tail) // ���� ���� ������� �� ������ ������� ���
    {
        flag = false;
        delete x.tail;
        x.head = x.tail = NULL;
    }
    if (x.head->data == k && x.head == node) // ���� ������ ������� ������
    {
        flag = false;
        temp = node;
        x.head = node = node->next;
        delete temp;
    }
    if (temp = node->next) // ���� �� � ������
    {
        if (flag == true) // ���� �� ���������
        {
            node->next->data = node->next->data; // �������� �������� ��������
            node->next = node->next->next;       // ��������� ��������� �� ��������� ����� ����������
            delete temp;
        }
    }
    else // ���� � �����
    {
        if (flag == true)
        {
            delete node;
            node = NULL;
        }
    }
}

bool findK(spis &x, int k) // ��������� �� ������ �������� � ����������� ������
{
    Node *temp = x.head;
    while (temp != NULL)
    {
        if (temp->data == k)
            return true;
        temp = temp->next;
    }
    return false;
}
// ������ ���������� ��������� � ����������� ������
int countEl(spis &x)
{
    int count = 0;
    Node *temp = x.head;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

void newInd(spis &x, int k) // �������� ������� ����� ��������
{
    Node *temp = x.head;
    while (temp != NULL)
    {
        if (temp->data != -1 && temp->data >= k) // ���� ���� ������� ������� � ������� ������� ������ ��� ����� ��������� �� ���������� �������� �� �������
            temp->data--;                        // ��������� ������ �� 1
        temp = temp->next;
    }
}

void delVert(Graf &x, int k)
{
    int j, count = 0;
    spis *temp;
    int n = x.numberVerties - 1;
    for (j = 0; j < n; j++) // �������� ������� �� �������
    {
        temp = &x.graf[j];            // �������� ����� ������������ ������
        if (findK(*temp, k) && j < k) // ���� ���� ������� � ������ � ��� ������ �� ���� ���������� ��� ��������
        {
            if (countEl(*temp) != 1) // ���� �� ���� �������
            {
                delFrom(*temp, k);
            }
            else // ���� ���� �������, �� ������ ������� ��� �������
            {
                delFrom(*temp, k);
                x.graf[j].addBack(-1);
            }
        }
        if (j >= k) // ���� ���� ������� � ������������� ��������
        {
            x.graf[j] = x.graf[j + 1]; // ��������� ��������� �������
            temp = &x.graf[j];         // �������� ����� ������������ ������
            if (findK(*temp, k))       // ���� ���� ������� ������� ���� �������
            {
                if (countEl(*temp) > 1) // ���� �� ���� �������
                {
                    delFrom(*temp, k);
                }
                else // ���� ���� ������� �� ������ ��� ��� ������� ������
                {
                    x.graf[j].deleteHead();
                    x.graf[j].addBack(-1);
                }
            }
        }
    }
    x.numberVerties--;                    // ��������� ������ �����
    for (j = 0; j < x.numberVerties; j++) // ������������� ������� ��� ���� ������
    {
        temp = &x.graf[j];
        newInd(*temp, k);
    }
}

#endif
