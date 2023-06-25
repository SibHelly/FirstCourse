#ifndef func_H
#define func_H
#include <iostream>
#include <string>
#include <memory.h>
#include <limits>
#include <locale.h>
#include <fstream>
using namespace std;

int search_count(string);   // ������� ���������� ��������� � ������ ��� ������
int *strToArr(string, int); // ��������� ������ � ������

int **readMatrix(ifstream &, int);   // ������ ������� �� �����
int **ListToMatrix(ifstream &, int); // ������ ������ �� ����� � ������� ���������
void showMatrix(int **&, int);       // ����� �������

int next(int, int, int, int **&);           // ������� � ��������� ������� � dfs
bool DFSR(int, int **&, int, bool *, char); // ����������� ����� � �������, ������� ���������� false, ���� ��������� ���������� ������� �� ������������

bool isTree(int **&, int, bool *&); // �������� �� ���� �������
int **removeVert(int, int **, int); // �������� ������� �� �����

#endif