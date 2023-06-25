#include <iostream>
#include "FunctionsRead.cpp"
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
            cout << "Это список смежности" << endl;
            in.seekg(0, ios::beg);
            in >> numberVerties;
            x = readList(in, numberVerties);
        }
        else
        {
            in.seekg(0, ios::beg);
            if (isMatrix(in))
            {
                cout << "Это матрица смежности" << endl;
                in.seekg(0, ios::beg);
                in >> numberVerties;
                G = readMatrix(in, numberVerties);
            }
            else
                cout << "Это не матрица смежности и не список смежности" << endl;
        }
    }
    else
    {
        cout << "Файл не найден" << endl;
    }
    in.close();
    P = new (nothrow) bool[numberVerties];
    memset(P, false, sizeof(P));
    if (x != NULL)
        showList(x, numberVerties);
    system("pause");
    if (isTree(x, numberVerties, P))
        cout << "Это дерево" << endl;
    else
        cout << "Это не дерево" << endl;
    delete[] x;
    return 0;
}