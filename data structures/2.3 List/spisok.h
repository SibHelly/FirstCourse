#ifndef Spisok_h
#define Spisok_h
#include <iostream>
#include <memory.h>
#include <limits>
#include <locale.h>
#include <fstream>
using namespace std;

// ������ ������������ ������
class Node
{
public:
    short int data;
    Node *next;

public:
    Node(short int x) // ����������� ������ ������������ ������
    {
        this->data = x;
        this->next = NULL;
    }
};

class spis
{
public:
    Node *head, *tail; // ������ � �����

public:
    spis();
    ~spis();
    void addBack(short int); // ���������� �������� � ����� ������������ ������
    bool isEmpty();          // �������� �� �������
    void showSpis();         // ����� ������
    bool findThis(int);      // ����� ��������
    void deleteHead();       // �������� �������� � ������
};

class Graf
{
public:
    int numberVerties; // ���������� ������ � �����
    spis *graf;        // ������ ����������� �������

public:
    Graf();                        // ����������� ��� ����������
    Graf(int);                     // ����������� � �����������
    Graf(const Graf &x);           // ����������� �����������
    ~Graf();                       // ����������
    void showGraf();               // ����� �����
    Graf(ifstream &);              // ������ ����� �� �����
    Graf &operator=(const Graf &); // ��������� ��������� ������������
};

void delVert(Graf &, int);    // �������� ������� �� �����
Node *findTodel(spis &, int); // ����� ������� �������� � ������ ��� ��������
void delFrom(spis &, int);    // �������� �� ������������ ������
bool Empty(int *, int);       // �������� ������� �� ������ ����� � �������
void newInd(spis &, int);     // ���������� �������� ����� �������� �������
int countEl(spis &);          // ������� ���������� ������� ������ � ����������� ������
bool findK(spis &, int);      // ��������� ������� �������� � ����������� ������

#endif