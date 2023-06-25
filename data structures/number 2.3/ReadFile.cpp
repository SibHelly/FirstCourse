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

// проверка на содержимое матрицы в файле
bool isMatrix(ifstream &in)
{
    if (in.is_open())
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
        return true;
    }
    else
    {
        cout << "Файл не найден" << endl;
        return false;
    }
    in.close();
}
// если в файле список смежных вершин
bool isList(ifstream &in)
{
    if (in.is_open())
    {
        int n, i, j, count, k, numberVer = 0;
        int *x;
        string s;
        in >> n; // читаем количество вершин в графе
        getline(in, s);
        s.clear();
        for (i = 0; i < n; i++)
        {
            getline(in, s);
            if (!s.empty())
            {
                count = search_count(s); // узнаем количество чисел в строке
                if (count > n)
                    return false;
                x = strToArr(s, count);
                for (j = 0; j < count; j++)
                    for (int k = j + 1; k < count; k++)
                    {
                        if (x[j] == x[k] || x[j] >= n || x[k] >= n)
                        {
                            return false;
                        }
                    }
                s.clear();
            }
            else
            {
                continue;
            }
        }
        return true;
    }
    else
    {
        cout << "Файл не найден" << endl;
        return false;
    }
    in.close();
}
#endif