#include <iostream>
#include <memory.h>
#include <limits>
#include <locale.h>
#include <fstream>
#include "func.h"

using namespace std;

int inputVerToRem(int);
bool Can(int **&, int);
int **arrayCopy(int **&, int);

int main()
{
    setlocale(LC_ALL, "Rus");
    ifstream in("8.txt"); // поток чтения
    int **x = NULL;       // двумерный массив для хранения графа
    int numberVerties, l; // количество вершин в графе
    bool flag = false;    // для понимания что в файле
    in.seekg(0, ios::beg);
    in >> l;
    in >> numberVerties;
    if (l == 0)
    {
        cout << "В файле матрица смежности" << endl;
        x = readMatrix(in, numberVerties);
    }
    if (l == 1)
    {
        cout << "В файле список смежных вершин" << endl;
        x = ListToMatrix(in, numberVerties);
    }
    if (x != NULL)
        showMatrix(x, numberVerties);
    bool *P = new (nothrow) bool[numberVerties];
    if (!P)
    {
        cout << "Ошибка выделения памяти" << endl;
        return 1;
    }
    memset(P, false, sizeof(P));
    if (isTree(x, numberVerties, P))
        cout << "Дерево" << endl;
    else
        cout << "Не дерево" << endl;
    cout << endl;
    cout << endl;
    if (Can(x, numberVerties))
    {
        cout << "Можно" << endl;
    }
    else
        cout << "Нельзя" << endl;
    delete[] x;
    return 0;
}

bool Can(int **&x, int numberVerties) // функци, которая проверяет можно ли удалить из графа вершину и получиьь дерево
{
    bool flag = false; // переменная которая показывает можно или нельзя
    int **newX = NULL; // массив из которого будем удалять
    int j;
    for (int i = 0; i < numberVerties; i++)
    {
        newX = arrayCopy(x, numberVerties);        // копируем граф в новый двумерный массив из которого будем удалять
        newX = removeVert(i, newX, numberVerties); // удаляем i вершину из графа
        int n = numberVerties - 1;                 // уменьшаем размер матрицы скопиравнного графа
        bool *P = new (nothrow) bool[n];           // массив в котором помечается какие вершины посещаются при обходе в глубину
        if (!P)
        {
            cout << "Ошибка выделения памяти" << endl;
            return false;
        }
        memset(P, false, n * sizeof(bool)); // заполняем массив  false, ибо обход еще не начали
        if (isTree(newX, n, P))             // проверяем являет ли граф после удаления вершины деревом
        {
            cout << "Номер вершины удалив которую мы можем получить дерево: " << i << endl;
            return true; // если да завершаем проверку
        }
        delete[] newX; // удаляем созданные массивы
        delete[] P;
    }
    return flag;
}

int **arrayCopy(int **&x, int numberVerties) // копирование массива
{
    int **G;
    int i, j;
    G = new (nothrow) int *[numberVerties]; // выделяем память
    if (!G)
    {
        cout << "Ошибка выделения памяти" << endl;
        return NULL;
    }
    for (i = 0; i < numberVerties; i++)
    {
        G[i] = new (nothrow) int[numberVerties]; // выделяем память
        if (!G[i])
        {
            cout << "Ошибка выделения памяти" << endl;
            return NULL;
        }
    }
    for (i = 0; i < numberVerties; i++)
        for (j = 0; j < numberVerties; j++)
            G[i][j] = x[i][j]; // заполняем значениями из исходного массива
    return G;
}