#ifndef FunctionsForList_CPP
#define FunctionsForList_CPP
#include <iostream>
#include "FunctionsRead.cpp"

using namespace std;

bool DFSR(int, node **&, int, bool *&, char);

bool isTree(node **&graph, int n, bool *&discovered)
{
    // ����� �����������, ������� ������� ��� ���
    // ���������� ���� ��� ��������, �������� �� graph ������� ��� ���
    bool isTree = true;
    // ��������� ����� � ������� �� ������ �������
    isTree = DFSR(0, graph, n, discovered, -1);
    for (int i = 0; isTree && i < n; i++)
    {
        // ����� ���������� ������� ��������, ��� graph ��������
        if (!discovered[i])
        {
            isTree = false;
        }
    }
    return isTree;
}

bool DFSR(int start, node **&x, int N, bool *&P, char parent)
{
    node *spis = x[start];
    node *temp = spis;
    P[start] = true;
    while (temp != NULL)
    {
        int connectVer = temp->numberNode;
        if (!P[connectVer])
        {
            if (connectVer, x, N, P, start)
                return false;
        }
        else if (connectVer != parent)
            return false;
        temp = temp->next;
    }
    return true;
}

#endif

/*for (int i = start; i < N; i++)
    {
        if (!P[i])
        {
            if (!DFSR(i, x, N, P, start))
                return false;
        }
        else if (i != parent)
            return false;
    }
    return true;*/