#include <iostream>
#include "FunctionsRead.cpp"
#include "FunctionsForMatrix.cpp"
#include "FunctionsForList.cpp"
#include <memory.h>
#include <limits>
using namespace std;

int inputVerToRem(int);

int main()
{
    setlocale(LC_ALL, "Rus");
    int numberVerties, VerToDelete;
    int **G = NULL;
    node **x = NULL;
    bool *P = NULL;
    ifstream in("1.txt");
    if (in.is_open())
    {
        if (isList(in))
        {
            cout << "��� ������ ���������" << endl;
            in.seekg(0, ios::beg);
            in >> numberVerties;
            // x = readList(in, numberVerties);
        }
        else
        {
            in.seekg(0, ios::beg);
            if (isMatrix(in))
            {
                cout << "��� ������� ���������" << endl;
                in.seekg(0, ios::beg);
                in >> numberVerties;
                G = readMatrix(in, numberVerties);
            }
            else
                cout << "��� �� ������� ��������� � �� ������ ���������" << endl;
        }
    }
    else
    {
        cout << "���� �� ������" << endl;
    }
    in.close();
    P = new (nothrow) bool[numberVerties];
    memset(P, false, sizeof(P));
    if (G != NULL)
        showMatrix(G, numberVerties);
    VerToDelete = inputVerToRem(numberVerties);
    G = removeVert(VerToDelete, G, numberVerties);
    numberVerties--;
    cout << "������� ����� �������� ������� � ����������� �����" << endl;
    if (G != NULL)
        showMatrix(G, numberVerties);
    if (isTree(G, numberVerties, P))
        cout << "��� ������" << endl;
    else
        cout << "��� �� ������" << endl;
    delete[] G;
    return 0;
}

int inputVerToRem(int numberVer)
{
    int n;
    cout << "������� ����� ������� �� 1 �� " << numberVer << endl;
    do
    {
        cin >> n;
        if (n < 0 || n > numberVer)
        {
            cin.clear(); // ������� ����
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    } while (n < 0 || n > numberVer);
    n--;
    return n;
}
