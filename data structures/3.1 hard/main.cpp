#include <iostream>
#include <fstream>
#include <iomanip>
#include <chrono>

using namespace std;

void CreateArr(ifstream &, unsigned long int, unsigned long int *&); // �������� �������
void CreateFile(unsigned long int *, unsigned long int, string);     // �������� ����� �� �������

void BubbleSort(unsigned long int *, unsigned long int, unsigned long long int &, unsigned long long int &, unsigned long int &, unsigned long int &);       // ���������� ���������
void ShakerSort(unsigned long int *, unsigned long int, unsigned long long int &, unsigned long long int &, unsigned long int &, unsigned long int &);       // ���������� �������
void QuickSort(unsigned long int *, unsigned long int, unsigned long long int &, unsigned long long int &, unsigned long int &, unsigned long int &);        // ������� ����������
void NaturalMergeSort(unsigned long int *, unsigned long int, unsigned long long int &, unsigned long long int &, unsigned long int &, unsigned long int &); // ���������� ����������� ��������

struct Arrays
{
    unsigned long int *arr;
    unsigned long int N;
    string Type;
    string Repeat;
    string Name;
};

// �������� �������� �� ������
void CreateArraysFromFiles(string, string, string, string, struct Arrays *, int);
void CreateStruct(string *, string *, struct Arrays *, unsigned long int *);
// ������������� ���������� ��� ���������� ��������
void UseSort(struct Arrays *, void (*)(unsigned long int *, unsigned long int, unsigned long long int &, unsigned long long int &, unsigned long int &, unsigned long int &));

int main()
{
    setlocale(LC_ALL, "");
    unsigned long int size[4] = {20000, 50000, 80000, 110000}; // ����������� ��������
    string Types[3] = {
        "�� ������������",
        "�� ��������",
        "�� �������������",
    }; // ���� ������
    string Names[24] = {"AN1elements.txt", "AN2elements.txt", "AN3elements.txt", "AN4elements.txt", "DN1elements.txt", "DN2elements.txt", "DN3elements.txt", "DN4elements.txt", "N1elements.txt", "N2elements.txt", "N3elements.txt", "N4elements.txt", "R10A.txt", "R100A.txt", "R500A.txt", "R1000A.txt", "R10D.txt", "R100d.txt", "R500D.txt", "R1000D.txt", "R10.txt", "R100.txt", "R500.txt", "R1000.txt"};
    struct Arrays Arr[24]; // ��������� ��������
    int menu = 0;
    CreateStruct(Names, Types, Arr, size);

    cout << "�������� ���������� ��� ������������" << endl
         << "1. ���������� ���������" << endl
         << "2. ���������� �������" << endl
         << "3. ������� ����������" << endl
         << "4. ���������� ������������ ��������" << endl;
    do
    {
        cout << "- ";
        cin >> menu;
        switch (menu)
        {
        case 1:
        {

            cout << "��� ����������: ���������� ���������" << endl;
            UseSort(Arr, BubbleSort);
            break;
        }
        case 2:
        {
            cout << "��� ����������: ��������� ����������" << endl;
            UseSort(Arr, ShakerSort);
            break;
        }
        case 3:
        {
            cout << "��� ����������: ������� ����������" << endl;
            UseSort(Arr, QuickSort);
            break;
        }
        case 4:
        {
            cout << "��� ����������: ���������� ������������ ��������" << endl;
            UseSort(Arr, NaturalMergeSort);
            break;
        }
        }
    } while (menu <= 0 || menu > 4);
    for (int i = 0; i < 24; i++)
        delete[] Arr[i].arr;
    return 0;
}
void CreateStruct(string *s, string *type, struct Arrays *Arr, unsigned long int *size)
{
    int i, j, l = 0;
    ifstream in;
    for (i = 0, j = 0; i < 24; i++, j++)
    {
        if (j == 4)
        {
            j = 0;
            l++;
        }
        if (i == 12)
        {
            for (l = 0; l < 4; l++)
                size[l] = 110000;
            l = 0;
        }
        Arr[i].N = size[j];
        Arr[i].Name = "t" + to_string(i);
        Arr[i].Type = type[l];
        in.open(s[i]);
        CreateArr(in, Arr[i].N, Arr[i].arr);
        if (i >= 12)
            Arr[i].Repeat = "� ������������";
        else
            Arr[i].Repeat = "��� ����������";
        in.close();
    }
}
// �������� ���������� ��� ���� �������� ��������� ����������
void UseSort(struct Arrays *Arr, void (*Sort)(unsigned long int *a, unsigned long int n, unsigned long long int &cAs, unsigned long long int &cAu, unsigned long int &cS, unsigned long int &cMS))
{
    unsigned long long int countAssign, countAuxiliary;
    unsigned long int size = 0, msize = 0;
    cout << "| ���������� ��������� ������� | ��� ��������� � ������� |   ��� �����   | ���������� ������������ ��������� ������� | ���������� ��������������� ������������ | ����� ���������� | ����� ���������� ������ |" << endl;
    cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    for (int i = 0; i < 24; i++)
    {
        countAssign = 0;
        countAuxiliary = 0;
        size = 0;
        msize = 0;
        auto start = std::chrono::steady_clock::now(); // ������ �������
        Sort(Arr[i].arr, Arr[i].N, countAssign, countAuxiliary, size, msize);
        auto end = std::chrono::steady_clock::now(); // ����� �������
        auto t = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

        cout << "|" << setw(30) << Arr[i].N << "|";
        cout << setw(25) << Arr[i].Type << "|";
        cout << setw(15) << Arr[i].Repeat << "|";
        cout << setw(43) << countAssign << "|";
        cout << setw(41) << countAuxiliary << "|";
        cout << setw(18) << t.count() / 1000. << "|";
        cout << setw(25) << msize << "|" << endl;
        cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
        CreateFile(Arr[i].arr, Arr[i].N, Arr[i].Name);
    }
}

// ������� ������ ���������� ����� �� �����
void CreateArr(ifstream &file, unsigned long int N, unsigned long int *&Arr)
{
    if (file.is_open())
    {
        Arr = new (nothrow) unsigned long int[N];
        if (!Arr)
        {
            cout << "������ ��������� ������" << endl;
            return;
        }
        for (int i = 0; i < N; i++)
            file >> Arr[i];
    }
    else
        cout << "���� �� ������" << endl;
}

// ������� ���� � �������
void CreateFile(unsigned long int *Arr, unsigned long int N, string s)
{
    ofstream file(s);
    if (file.is_open())
        for (int i = 0; i < N; i++)
            file << Arr[i] << " ";
    else
        cout << "�� ������� ������� ����" << endl;
    file.close();
}
// ���������� ���������
void BubbleSort(unsigned long int *arr, unsigned long int n, unsigned long long int &n1, unsigned long long int &n2, unsigned long int &size, unsigned long int &msize)
{
    int i, j;
    unsigned long int x;
    for (++n2, i = 1; i < n; ++n2, i++)
        for (++n2, j = n - 1; j >= i; ++n2, j--)
            if (arr[j - 1] > arr[j])
            {
                x = arr[j - 1];
                arr[j - 1] = arr[j];
                arr[j] = x;
                n1 += 3;
            }
    size = sizeof(i) + sizeof(j) + sizeof(x);
    msize = size;
}

// ���������� �������
void ShakerSort(unsigned long int *a, unsigned long int n, unsigned long long int &n1, unsigned long long int &n2, unsigned long int &size, unsigned long int &msize)
{
    unsigned long long int j, k = n - 1, left = 1, right = n - 1, x;
    n2 += 3;
    do
    {
        for (++n2, j = right; j >= left; ++n2, j--) /*������� ������������� ������ ������*/
            if (a[j - 1] > a[j])
            {
                x = a[j - 1];
                a[j - 1] = a[j];
                a[j] = x;
                n1 += 3;
                k = j;
                ++n2;
            }
        left = k + 1;
        ++n2;
        for (++n2, j = left; j <= right; ++n2, j++) /*� ������ ������������� ����� �������*/
            if (a[j - 1] > a[j])
            {
                x = a[j - 1];
                a[j - 1] = a[j];
                a[j] = x;
                n1 += 3;
                k = j;
                ++n2;
            }
        right = k - 1;
        ++n2;
    } while (left < right); /*� ��� �� ��� ���, ���� ���� ��� �������������*/
    size = sizeof(j) + sizeof(k) + sizeof(left) + sizeof(right) + sizeof(x);
    msize = size;
}

// ������� ����������
void QuickSort(unsigned long int *a, unsigned long int n, unsigned long long int &n1, unsigned long long int &n2, unsigned long int &size, unsigned long int &msize)
{
    unsigned long long int x, w, i, j;
    x = a[n / 2]; /* ������� ������� */
    ++n2;
    i = 0;
    ++n2;
    j = n - 1;
    ++n2;
    size += sizeof(x) + sizeof(w) + sizeof(i) + sizeof(j);
    if (size > msize)
        msize = size;
    do
    {
        while (a[i] < x)
        {
            i++; /* ����� ������� ������� ������ �������� */
            ++n2;
        }
        while (x < a[j])
        {
            j--; /* ������ ������� ������� ������ �������� */
            ++n2;
        }
        if (i <= j)
        {
            w = a[i];
            ++n1;
            a[i] = a[j];
            ++n1;
            a[j] = w; /* ������ ��������� �������� ������� */
            ++n1;
            i++;
            ++n2;
            j--;
            ++n2;
        }
    } while (i < j); /* �� ���������� ����� ����� �� �������� �������� �����, ������� �, � ������ - ������� */
    /* ��������� ��� �� ����� � ������ ����� */
    if (j > 0)
        QuickSort(a, j + 1, n1, n2, size, msize);
    if (i < n - 1)
        QuickSort(a + i, n - i, n1, n2, size, msize);
    size -= size;
}

// ���������� ������������ ��������
void NaturalMergeSort(unsigned long int *a, unsigned long int n, unsigned long long int &n1, unsigned long long int &n2, unsigned long int &size, unsigned long int &msize)
{
    int split; /* ������, �� �������� ����� ������ */
    int end;
    unsigned long int *p = a, *tmp;
    char flag = 0, sorted = 0;
    int pos1, pos2, pos3;
    tmp = (unsigned long int *)malloc(n * sizeof(unsigned long int));
    size = sizeof(split) + sizeof(end) + sizeof(p) + sizeof(flag) + sizeof(sorted) + sizeof(pos1) + sizeof(pos2) + sizeof(pos3) + sizeof(tmp) * n;
    msize = size;
    n2 += 4;
    do /* ���� ���� ����� 1 �������� */
    {
        end = n;
        ++n2;
        pos2 = pos3 = 0;
        n2 += 2;
        do
        {
            p += pos2;
            ++n2;
            end = n - pos3;
            ++n2;
            for (++n2, split = 1; split < end && p[split - 1] <= p[split]; ++n2, split++)
                ; /*������ �����*/
            if (split == n)
            {
                sorted = 1;
                ++n2;
                break;
            }
            pos1 = 0;
            ++n2;
            pos2 = split;
            ++n2;
            while (pos1 < split && pos2 < end) /*���� �������, ���� ���� ���� ���� ������� � ������ �����*/
            {
                if (p[pos1] < p[pos2])
                {
                    tmp[pos3++] = p[pos1++];
                    ++n1;
                    n2 += 2;
                }
                else
                {
                    tmp[pos3++] = p[pos2++];
                    ++n1;
                    n2 += 2;
                    if (p[pos2] < p[pos2 - 1])
                        break;
                }
            }
            /* ���� ������������������ ����������� - ���������� ������� ������ � ����� ������ */
            while (pos2 < end && tmp[pos3 - 1] <= p[pos2]) /* ���� ������ ������������������ �� ����� */
            {
                tmp[pos3++] = p[pos2++];
                ++n1;
                n2 += 2;
            }
            while (pos1 < split) /* ���� ������ ������������������ �� ����� */
            {
                tmp[pos3++] = p[pos1++];
                ++n1;
                n2 += 2;
            }
        } while (pos3 < n);
        if (sorted)
            break;
        p = tmp;
        n2++;
        tmp = a;
        n2++;
        a = p;
        n2++;
        flag = !flag;
        ++n2;
    } while (split < n);
    if (flag)
    {
        for (++n2, pos1 = 0; pos1 < n; ++n2, pos1++)
        {
            tmp[pos1] = a[pos1];
            n1++;
        }
        free(a);
    }
    else
        free(tmp);
}