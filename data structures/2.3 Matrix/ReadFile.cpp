#ifndef ReadFile_CPP
#define ReadFile_CPP
#include <iostream>
#include <memory.h>
#include <limits>
#include <locale.h>
#include <fstream>
#include <string>
#include "func.h"
using namespace std;

// ��������� ������� ��������� �� �����
int **readMatrix(ifstream &in, int numberVerties)
{
    string s;
    int **G;
    int i, j;
    getline(in, s);
    s.clear();
    G = new (nothrow) int *[numberVerties];
    if (!G)
    {
        cout << "������ ��������� ������" << endl;
        return NULL;
    }
    for (i = 0; i < numberVerties; i++)
    {
        G[i] = new (nothrow) int[numberVerties];
        if (!G[i])
        {
            cout << "������ ��������� ������" << endl;
            return NULL;
        }
    }
    for (i = 0; i < numberVerties; i++)
        for (j = 0; j < numberVerties; j++)
        {
            in >> G[i][j];
        }
    return G;
}
// ��������� ������ ��������� � ������� ���������
int **ListToMatrix(ifstream &in, int numberVerties)
{
    string s;
    int **G;
    int i, j;
    G = new (nothrow) int *[numberVerties];
    getline(in, s);
    cout << s << endl;
    s.clear();
    if (!G)
    {
        cout << "������ ��������� ������" << endl;
        return NULL;
    }
    for (i = 0; i < numberVerties; i++)
    {
        G[i] = new (nothrow) int[numberVerties];
        if (!G[i])
        {
            cout << "������ ��������� ������" << endl;
            return NULL;
        }
        getline(in, s);
        int countS = search_count(s);
        int *arr = strToArr(s, countS);
        s.clear();
        if (arr[0] == -1) // ���� ������ ������
        {
            memset(G[i], 0, sizeof(int) * numberVerties);
        }
        else
        {
            memset(G[i], 0, sizeof(int) * numberVerties);
            for (int k = 0; k < countS; k++)
                G[i][arr[k]] = 1;
        }
        delete[] arr;
    }
    return G;
}

// ����� �������
void showMatrix(int **&G, int numberVerties)
{
    int i, j;
    for (i = 0; i < numberVerties; i++)
    {
        for (j = 0; j < numberVerties; j++)
        {
            cout << G[i][j] << " ";
        }
        cout << endl;
    }
}

#endif