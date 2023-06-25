#ifndef Spisok_h
#define Spisok_h
#include <iostream>
#include <memory.h>
#include <limits>
#include <locale.h>
#include <fstream>
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
    Node *head, *tail; // начало и конец

public:
    spis();
    ~spis();
    void addBack(short int); // добавление элемента в конец односвзяного списка
    bool isEmpty();          // проверка на пустоту
    void showSpis();         // показ списка
    bool findThis(int);      // поиск элемента
    void deleteHead();       // удаление элемента с начала
};

class Graf
{
public:
    int numberVerties; // количество вершин в графе
    spis *graf;        // массив односвязных списков

public:
    Graf();                        // конструктор без параметров
    Graf(int);                     // конструктор с параметрами
    Graf(const Graf &x);           // конструктор копирования
    ~Graf();                       // деструктор
    void showGraf();               // показ графа
    Graf(ifstream &);              // чтение графа из файла
    Graf &operator=(const Graf &); // прегрузка оператора присваивания
};

void delVert(Graf &, int);    // удаление вершины из графа
Node *findTodel(spis &, int); // поиск позиции элемента в списке для удаления
void delFrom(spis &, int);    // удаление из односвязного списка
bool Empty(int *, int);       // проверка массива на наличе ребер в вершины
void newInd(spis &, int);     // перерасчет индексов после удаления вершины
int countEl(spis &);          // подсчет количества смежных вершин в односвязном списке
bool findK(spis &, int);      // провекрка наличия элемента в односвязном списке

#endif