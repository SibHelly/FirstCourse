#ifndef func_H
#define func_H
#include <iostream>
#include <string>
#include <memory.h>
#include <limits>
#include <locale.h>
#include <fstream>
using namespace std;

int search_count(string);   // подчсет количества элементов в строке для чтения
int *strToArr(string, int); // преврщаем строку в массив

int **readMatrix(ifstream &, int);   // чтение матрицы из файла
int **ListToMatrix(ifstream &, int); // чтение списка из файла в матрицу смежности
void showMatrix(int **&, int);       // показ матрицы

int next(int, int, int, int **&);           // переход к следующей вершине в dfs
bool DFSR(int, int **&, int, bool *, char); // рекурсивный обход в глубину, который возвращает false, если следующая посещенная вершина не родительская

bool isTree(int **&, int, bool *&); // является ли граф деревом
int **removeVert(int, int **, int); // удаление вершины из графа

#endif