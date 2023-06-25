#ifndef Spisok_h
#define Spisok_h
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <locale.h>

using namespace std;

// запись односвязного списка
class Node
{
public:
    short int data;
    Node *next;

public:
    Node(short int x) // конструктор записи односвязного списка
    {
        this->data = x;
        this->next = NULL;
    }
};

class spis
{
public:
    Node *head, *tail;

public:
    spis();
    ~spis();
    void addBack(short int);
    bool isEmpty();
    void showSpis();
};

class Graf
{
    int numberVerties;
    spis *graf;

public:
    Graf(int);
    void addVert(short int, short int);
    void showGraf();
    bool DFSR();
    bool isTree();
};

#endif