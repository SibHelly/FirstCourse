#ifndef FunctionsForMatrix_CPP
#define FunctionsForMatrix_CPP
#include <iostream>

using namespace std;

int next(int start, int cur, int N, int **&Matrix)
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
    int nextVer;
    P[start] = true;
    nextVer = next(start, parent, N, Matrix);
    while (nextVer != -1)
    {
        if (!P[nextVer])
        {
            if (!DFSR(nextVer, Matrix, N, P, start))
                return false;
        }
        else if (nextVer != parent)
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
    isTree = DFSR(0, graph, n, discovered, -1);
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

int **removeVert(int del, int **g, int numberVer)
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