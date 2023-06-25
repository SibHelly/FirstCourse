#include <iostream>
#include <memory.h>
#include <limits>
#include <locale.h>
#include <fstream>
#include "spisok.h"
#include "func.h"

using namespace std;

bool DFS(Graf const &, int, bool *&, int); // обход в глубину
bool Tree(Graf const &, int, bool *&);     // проверка на дерево
bool Can(Graf const &);                    // можно ли удалив вершину получить дерево

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
        cout << "ќшибка выделени€ пам€ти" << endl;
        return 1;
    }
    memset(P, false, sizeof(P));
    if (Tree(x, numberVerties, P))
        cout << "Ёто дерево" << endl;
    else
        cout << "Ёто не дерево" << endl;
    delete[] P;
    cout << endl;
    cout << endl;
    if (Can(x))
        cout << "ћожно" << endl;
    else
        cout << "Ќельз€" << endl;
    return 0;
}

bool Can(Graf const &x)
{
    bool *P;
    for (int i = 0; i < x.numberVerties; i++) // поочередно удал€ем вершины и провер€ем дерево ли
    {
        Graf Ng(x);                               // конструктор копировани€
        int k = i;                                // удал€ема€ вершины
        delVert(Ng, k);                           // удал€ем вершину
        P = new (nothrow) bool[Ng.numberVerties]; // массив посещенных вершин
        if (!P)
        {
            cout << "ќшибка выделени€ пам€ти" << endl;
            return 1;
        }
        memset(P, false, sizeof(P));       // заполн€чем пустотой, так как еще не посещали
        if (Tree(Ng, Ng.numberVerties, P)) // если дерево
        {
            cout << "Ќомер вершины, удалив которую можно получить дерево: " << i << endl;
            return true;
        }
        delete[] P; // очищаем  пам€ть, дл€ Ng работает деструктор
    }
    return false;
}

bool DFS(Graf const &graf, int start, bool *&P, int parent) // рекурстивный обход в глубину
{
    Node *temp = graf.graf[start].head; // дл€ перемещени€ к следующей вершины
    P[start] = true;                    // помечаем посещнной
    while (temp != NULL)
    {
        int nextVer = temp->data; // получаем следующею вершину
        if (nextVer == -1)        // если эта вершина с которой начали обход не имеет смежных
            return false;
        if (!P[nextVer]) // если вершина не посещена продолжаем с нее обход
        {
            if (!DFS(graf, nextVer, P, start))
            {
                return false;
            }
        }
        else if (nextVer != parent) // если следующа€ вершина посещена и она равна не родителю, значит есть цикл и этот граф не может быть деревом
        {
            return false;
        }
        temp = temp->next; // переходим к следующему элемнту
    }
    return true;
}

bool Tree(Graf const &graph, int n, bool *&discovered)
{
    // чтобы отслеживать, открыта вершина или нет
    // логический флаг дл€ хранени€, €вл€етс€ ли graph деревом или нет
    // ¬ыполн€ем обход в глубину из первой вершины
    bool isTree;
    isTree = true;
    isTree = DFS(graph, 0, discovered, -1);
    for (int i = 0; isTree && i < n; i++)
    {
        if (!discovered[i]) // если есть не посещнные или вершины без смежжных ребер
        {
            isTree = false;
        }
    }
    return isTree;
}