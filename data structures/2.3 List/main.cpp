#include <iostream>
#include <memory.h>
#include <limits>
#include <locale.h>
#include <fstream>
#include "spisok.h"
#include "func.h"

using namespace std;

bool DFS(Graf const &, int, bool *&, int); // ����� � �������
bool Tree(Graf const &, int, bool *&);     // �������� �� ������
bool Can(Graf const &);                    // ����� �� ������ ������� �������� ������

int main()
{
    setlocale(LC_ALL, "Rus");
    ifstream in("7.txt");
    int numberVerties;
    bool flag = false;
    bool *P = NULL;
    Graf nG;
    Graf x(in);
    x.showGraf();
    numberVerties = x.numberVerties;
    P = new (nothrow) bool[numberVerties];
    if (!P)
    {
        cout << "������ ��������� ������" << endl;
        return 1;
    }
    memset(P, false, sizeof(P));
    if (Tree(x, numberVerties, P))
        cout << "��� ������" << endl;
    else
        cout << "��� �� ������" << endl;
    delete[] P;
    cout << endl;
    cout << endl;
    if (Can(x))
        cout << "�����" << endl;
    else
        cout << "������" << endl;
    return 0;
}

bool Can(Graf const &x)
{
    bool *P;
    for (int i = 0; i < x.numberVerties; i++) // ���������� ������� ������� � ��������� ������ ��
    {
        Graf Ng(x);                               // ����������� �����������
        int k = i;                                // ��������� �������
        delVert(Ng, k);                           // ������� �������
        P = new (nothrow) bool[Ng.numberVerties]; // ������ ���������� ������
        if (!P)
        {
            cout << "������ ��������� ������" << endl;
            return 1;
        }
        memset(P, false, sizeof(P));       // ���������� ��������, ��� ��� ��� �� ��������
        if (Tree(Ng, Ng.numberVerties, P)) // ���� ������
        {
            cout << "����� �������, ������ ������� ����� �������� ������: " << i << endl;
            return true;
        }
        delete[] P; // �������  ������, ��� Ng �������� ����������
    }
    return false;
}

bool DFS(Graf const &graf, int start, bool *&P, int parent) // ������������ ����� � �������
{
    Node *temp = graf.graf[start].head; // ��� ����������� � ��������� �������
    P[start] = true;                    // �������� ���������
    while (temp != NULL)
    {
        int nextVer = temp->data; // �������� ��������� �������
        if (nextVer == -1)        // ���� ��� ������� � ������� ������ ����� �� ����� �������
            return false;
        if (!P[nextVer]) // ���� ������� �� �������� ���������� � ��� �����
        {
            if (!DFS(graf, nextVer, P, start))
            {
                return false;
            }
        }
        else if (nextVer != parent) // ���� ��������� ������� �������� � ��� ����� �� ��������, ������ ���� ���� � ���� ���� �� ����� ���� �������
        {
            return false;
        }
        temp = temp->next; // ��������� � ���������� �������
    }
    return true;
}

bool Tree(Graf const &graph, int n, bool *&discovered)
{
    // ����� �����������, ������� ������� ��� ���
    // ���������� ���� ��� ��������, �������� �� graph ������� ��� ���
    // ��������� ����� � ������� �� ������ �������
    bool isTree;
    isTree = true;
    isTree = DFS(graph, 0, discovered, -1);
    for (int i = 0; isTree && i < n; i++)
    {
        if (!discovered[i]) // ���� ���� �� ��������� ��� ������� ��� �������� �����
        {
            isTree = false;
        }
    }
    return isTree;
}