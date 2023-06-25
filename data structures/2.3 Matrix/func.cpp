#ifndef func_CPP
#define func_CPP
#include <iostream>
#include <string>
#include <memory.h>
#include <limits>
#include <locale.h>
#include <fstream>
#include "func.h"
using namespace std;
// количество чисел в строке
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
// строку в массив
int *strToArr(string s, int n)
{
    int *a = new (nothrow) int[n];
    int i = 0, j = 0;
    string ch;
    if (!a)
    {
        cout << "Ошибка выделения памяти" << endl;
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

#endif