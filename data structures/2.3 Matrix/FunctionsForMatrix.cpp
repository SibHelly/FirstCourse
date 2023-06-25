#ifndef FunctionsForMatrix_CPP
#define FunctionsForMatrix_CPP
#include <iostream>
#include "func.h"

using namespace std;

int next(int start, int cur, int N, int **&Matrix) // получение индекса следующей смежно вершины
{
    cur++;
    while (cur < N && !Matrix[start][cur])
        cur++;
    if (cur < N)
        return cur;
    return -1;
}

bool DFSR(int start, int **&Matrix, int N, bool *P, char parent)
{
    int nextVer;                              // следующая вершины
    P[start] = true;                          // делаем посещенной вершну
    nextVer = next(start, parent, N, Matrix); // получаем следующую вершину
    while (nextVer != -1)                     // пока следующая вершина не -1
    {
        if (!P[nextVer]) // если вершина не посещна то продожаем с нее обход
        {
            if (!DFSR(nextVer, Matrix, N, P, start)) // если DFS false , значит у следующей вершины следующая вершина посещена и не равна родительской
                return false;
        }
        else if (nextVer != parent) // если следующая вершина посещена и не равна родительской возвращаем false
            return false;
        nextVer = next(start, nextVer, N, Matrix);
    }
    return true;
}

bool isTree(int **&graph, int n, bool *&discovered)
{
    // чтобы отслеживать, открыта вершина или нет
    // логический флаг для хранения, является ли graph деревом или нет
    bool isTree = true;
    // Выполняем обход в глубину из первой вершины
    isTree = DFSR(0, graph, n, discovered, 0); // если у графа есть вершины которые имеют как-бы несколько родителей
    for (int i = 0; isTree && i < n; i++)
    {
        // любая неоткрытая вершина означает, что graph несвязен
        if (!discovered[i])
        {
            isTree = false;
        }
    }
    return isTree;
}

int **removeVert(int del, int **g, int numberVer) // удаление вершины перемещением удаляемой вершины в конец, и уменьшением размера массива
{
    int i, j;
    for (i = del + 1; i < numberVer; i++)
        for (j = 0; j < numberVer; j++)
            g[i - 1][j] = g[i][j];
    for (j = del + 1; j < numberVer; j++)
        for (i = 0; i < numberVer; i++)
            g[i][j - 1] = g[i][j];
    return g;
}

#endif