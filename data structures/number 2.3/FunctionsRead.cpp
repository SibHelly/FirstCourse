#ifndef FunctionsRead_CPP
#define FunctionsRead_CPP
#include <iostream>
#include <fstream>
#include <string>
#include <locale.h>

using namespace std;

struct node
{
    short int numberNode;
    node *next;
};

// ���������� ����� � ������
int search_count(string s)
{
    bool flag = false;
    int i = 0, count = 0;
    while (s[i])
    {
        if (isdigit(s[i]))
        {
            if (!flag)
            {
                count++;
                flag = true;
            }
        }
        else
            flag = false;
        i++;
    }
    return count;
}

int *strToArr(string s, int n)
{
    int *a = new (nothrow) int[n];
    int i = 0, j = 0;
    string ch;
    if (!a)
    {
        cout << "������ ��������� ������" << endl;
        return NULL;
    }
    while (s[i])
    {
        ch.push_back(s[i]);
        if (s[i] == ' ' || s[i] == '\0')
        {
            a[j++] = stoi(ch);
            ch.clear();
        }
        i++;
    }
    a[j] = stoi(ch);
    return a;
}

bool isMatrix(ifstream &in)
{
    int n, count, numberVer = 0;
    int *x;
    string s;
    in >> n;
    getline(in, s);
    s.clear();
    for (int i = 0; i < n; i++)
    {
        getline(in, s);
        count = search_count(s);
        if (count != 0)
            numberVer++;
        if (count != n)
        {
            return false;
        }
        x = strToArr(s, count);
        for (int j = 0; j < count; j++)
        {
            if (x[j] > 1)
            {
                return false;
            }
        }
        s.clear();
    }
    if (numberVer != n)
        return false;
    return true;
}
// ��������� ������� ��������� �� �����
int **readMatrix(ifstream &in, int numberVerties)
{
    int **G;
    int i, j;
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

// �������� ������� ��������� �� �����
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
// �������� ������� �� ���� � ������
bool isList(ifstream &in)
{
    int n, i, j, count, k, numberVer = 0;
    int *x;
    string s;
    in >> n;
    getline(in, s);
    s.clear();
    for (i = 0; i < n; i++)
    {
        getline(in, s);
        count = search_count(s);
        if (count != 0)
            numberVer++;
        if (count > n)
            return false;
        x = strToArr(s, count);
        for (j = 0; j < count; j++)
            for (int k = j + 1; k < count; k++)
            {
                if (x[j] == x[k] || x[j] > n)
                {
                    return false;
                }
            }
        s.clear();
    }
    if (numberVer != n)
        return false;
    return true;
}

// ���������� ������ � ������
/*node *createVerties(node *start, int x) // ���������� ������� ������
{
    node *temp = new (nothrow) node;
    if (!temp)
    {
        cout << "������ ��������� ������" << endl;
        return NULL;
    }
    temp->numberNode = x;
    temp->next = start;
    return temp;
}
// ����� ������
void show(node *cur)
{
    if (cur == NULL)
    {
        cout << "��� ������� ������" << endl;
        return;
    }
    while (cur)
    {
        cout << cur->numberNode << " ";
        cur = cur->next;
    }
}

node **readList(ifstream &in, int numberVerties)
{
    node **g;
    string s;
    int i, j;
    int *x;
    getline(in, s);
    s.clear();
    g = new (nothrow) node *[numberVerties];
    if (!g)
    {
        cout << "������ ��������� ������" << endl;
        return NULL;
    }
    for (i = 0; i < numberVerties; i++)
    {
        g[i] = NULL;
        getline(in, s);
        int n = search_count(s);
        x = strToArr(s, n);
        if (x == NULL)
        {
            cout << "������ ��������� ������" << endl;
            return NULL;
        };
        for (j = 0; j < n; j++)
            g[i] = createVerties(g[i], x[j]);
        delete[] x;
        s.clear();
    }
    return g;
}

void showList(node **g, int numberVerties)
{
    for (int i = 0; i < numberVerties; i++)
    {
        show(g[i]);
        cout << endl;
    }
}*/

#endif