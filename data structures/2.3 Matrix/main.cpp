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
    ifstream in("8.txt"); // ����� ������
    int **x = NULL;       // ��������� ������ ��� �������� �����
    int numberVerties, l; // ���������� ������ � �����
    bool flag = false;    // ��� ��������� ��� � �����
    in.seekg(0, ios::beg);
    in >> l;
    in >> numberVerties;
    if (l == 0)
    {
        cout << "� ����� ������� ���������" << endl;
        x = readMatrix(in, numberVerties);
    }
    if (l == 1)
    {
        cout << "� ����� ������ ������� ������" << endl;
        x = ListToMatrix(in, numberVerties);
    }
    if (x != NULL)
        showMatrix(x, numberVerties);
    bool *P = new (nothrow) bool[numberVerties];
    if (!P)
    {
        cout << "������ ��������� ������" << endl;
        return 1;
    }
    memset(P, false, sizeof(P));
    if (isTree(x, numberVerties, P))
        cout << "������" << endl;
    else
        cout << "�� ������" << endl;
    cout << endl;
    cout << endl;
    if (Can(x, numberVerties))
    {
        cout << "�����" << endl;
    }
    else
        cout << "������" << endl;
    delete[] x;
    return 0;
}

bool Can(int **&x, int numberVerties) // ������, ������� ��������� ����� �� ������� �� ����� ������� � �������� ������
{
    bool flag = false; // ���������� ������� ���������� ����� ��� ������
    int **newX = NULL; // ������ �� �������� ����� �������
    int j;
    for (int i = 0; i < numberVerties; i++)
    {
        newX = arrayCopy(x, numberVerties);        // �������� ���� � ����� ��������� ������ �� �������� ����� �������
        newX = removeVert(i, newX, numberVerties); // ������� i ������� �� �����
        int n = numberVerties - 1;                 // ��������� ������ ������� ������������� �����
        bool *P = new (nothrow) bool[n];           // ������ � ������� ���������� ����� ������� ���������� ��� ������ � �������
        if (!P)
        {
            cout << "������ ��������� ������" << endl;
            return false;
        }
        memset(P, false, n * sizeof(bool)); // ��������� ������  false, ��� ����� ��� �� ������
        if (isTree(newX, n, P))             // ��������� ������ �� ���� ����� �������� ������� �������
        {
            cout << "����� ������� ������ ������� �� ����� �������� ������: " << i << endl;
            return true; // ���� �� ��������� ��������
        }
        delete[] newX; // ������� ��������� �������
        delete[] P;
    }
    return flag;
}

int **arrayCopy(int **&x, int numberVerties) // ����������� �������
{
    int **G;
    int i, j;
    G = new (nothrow) int *[numberVerties]; // �������� ������
    if (!G)
    {
        cout << "������ ��������� ������" << endl;
        return NULL;
    }
    for (i = 0; i < numberVerties; i++)
    {
        G[i] = new (nothrow) int[numberVerties]; // �������� ������
        if (!G[i])
        {
            cout << "������ ��������� ������" << endl;
            return NULL;
        }
    }
    for (i = 0; i < numberVerties; i++)
        for (j = 0; j < numberVerties; j++)
            G[i][j] = x[i][j]; // ��������� ���������� �� ��������� �������
    return G;
}