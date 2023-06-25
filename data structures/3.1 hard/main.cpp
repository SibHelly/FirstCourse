#include <iostream>
#include <fstream>
#include <iomanip>
#include <chrono>

using namespace std;

void CreateArr(ifstream &, unsigned long int, unsigned long int *&); // создание массива
void CreateFile(unsigned long int *, unsigned long int, string);     // создание файла из массива

void BubbleSort(unsigned long int *, unsigned long int, unsigned long long int &, unsigned long long int &, unsigned long int &, unsigned long int &);       // сортировка пузырьком
void ShakerSort(unsigned long int *, unsigned long int, unsigned long long int &, unsigned long long int &, unsigned long int &, unsigned long int &);       // сортировка шейкера
void QuickSort(unsigned long int *, unsigned long int, unsigned long long int &, unsigned long long int &, unsigned long int &, unsigned long int &);        // быстрая сортировка
void NaturalMergeSort(unsigned long int *, unsigned long int, unsigned long long int &, unsigned long long int &, unsigned long int &, unsigned long int &); // сортировка естесвенным слиянием

struct Arrays
{
    unsigned long int *arr;
    unsigned long int N;
    string Type;
    string Repeat;
    string Name;
};

// создание массивов из файлов
void CreateArraysFromFiles(string, string, string, string, struct Arrays *, int);
void CreateStruct(string *, string *, struct Arrays *, unsigned long int *);
// использования сортировок для нескольких массивов
void UseSort(struct Arrays *, void (*)(unsigned long int *, unsigned long int, unsigned long long int &, unsigned long long int &, unsigned long int &, unsigned long int &));

int main()
{
    setlocale(LC_ALL, "");
    unsigned long int size[4] = {20000, 50000, 80000, 110000}; // размерность массивов
    string Types[3] = {
        "По возврастанию",
        "По убыванию",
        "Не упорядоченное",
    }; // типы файлов
    string Names[24] = {"AN1elements.txt", "AN2elements.txt", "AN3elements.txt", "AN4elements.txt", "DN1elements.txt", "DN2elements.txt", "DN3elements.txt", "DN4elements.txt", "N1elements.txt", "N2elements.txt", "N3elements.txt", "N4elements.txt", "R10A.txt", "R100A.txt", "R500A.txt", "R1000A.txt", "R10D.txt", "R100d.txt", "R500D.txt", "R1000D.txt", "R10.txt", "R100.txt", "R500.txt", "R1000.txt"};
    struct Arrays Arr[24]; // структура массивов
    int menu = 0;
    CreateStruct(Names, Types, Arr, size);

    cout << "Выберите сортировку для тестирования" << endl
         << "1. Сортировка пузырьком" << endl
         << "2. Сортировка шейкера" << endl
         << "3. Быстрая сортировка" << endl
         << "4. Сортировка естественным слиянием" << endl;
    do
    {
        cout << "- ";
        cin >> menu;
        switch (menu)
        {
        case 1:
        {

            cout << "Тип сортировки: Сортировка пузырьком" << endl;
            UseSort(Arr, BubbleSort);
            break;
        }
        case 2:
        {
            cout << "Тип сортировки: Шейкерная сортировка" << endl;
            UseSort(Arr, ShakerSort);
            break;
        }
        case 3:
        {
            cout << "Тип сортировки: Быстрая сортировка" << endl;
            UseSort(Arr, QuickSort);
            break;
        }
        case 4:
        {
            cout << "Тип сортировки: Сортировка естественным слиянием" << endl;
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
            Arr[i].Repeat = "С повторениями";
        else
            Arr[i].Repeat = "Без повторений";
        in.close();
    }
}
// вызываем поочередно для всех массивов выбранную сортировку
void UseSort(struct Arrays *Arr, void (*Sort)(unsigned long int *a, unsigned long int n, unsigned long long int &cAs, unsigned long long int &cAu, unsigned long int &cS, unsigned long int &cMS))
{
    unsigned long long int countAssign, countAuxiliary;
    unsigned long int size = 0, msize = 0;
    cout << "| Количество элементов массива | Тип элементов в массиве |   Тип файла   | Количество присваиваний элементов массива | Количество вспомогательных присваиваний | Время сортировки | Объем выделенной памяти |" << endl;
    cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    for (int i = 0; i < 24; i++)
    {
        countAssign = 0;
        countAuxiliary = 0;
        size = 0;
        msize = 0;
        auto start = std::chrono::steady_clock::now(); // начало отсчета
        Sort(Arr[i].arr, Arr[i].N, countAssign, countAuxiliary, size, msize);
        auto end = std::chrono::steady_clock::now(); // конец отсчета
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

// считать нужное количество чисел из файла
void CreateArr(ifstream &file, unsigned long int N, unsigned long int *&Arr)
{
    if (file.is_open())
    {
        Arr = new (nothrow) unsigned long int[N];
        if (!Arr)
        {
            cout << "Ошибка выделения памяти" << endl;
            return;
        }
        for (int i = 0; i < N; i++)
            file >> Arr[i];
    }
    else
        cout << "Файл не найден" << endl;
}

// создать файл с массива
void CreateFile(unsigned long int *Arr, unsigned long int N, string s)
{
    ofstream file(s);
    if (file.is_open())
        for (int i = 0; i < N; i++)
            file << Arr[i] << " ";
    else
        cout << "Не удалось создать файл" << endl;
    file.close();
}
// сортировка пузырьком
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

// сортировка шейкера
void ShakerSort(unsigned long int *a, unsigned long int n, unsigned long long int &n1, unsigned long long int &n2, unsigned long int &size, unsigned long int &msize)
{
    unsigned long long int j, k = n - 1, left = 1, right = n - 1, x;
    n2 += 3;
    do
    {
        for (++n2, j = right; j >= left; ++n2, j--) /*сначала просматриваем справа налево*/
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
        for (++n2, j = left; j <= right; ++n2, j++) /*а теперь просматриваем слева направо*/
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
    } while (left < right); /*и так до тех пор, пока есть что просматривать*/
    size = sizeof(j) + sizeof(k) + sizeof(left) + sizeof(right) + sizeof(x);
    msize = size;
}

// быстрая сортировка
void QuickSort(unsigned long int *a, unsigned long int n, unsigned long long int &n1, unsigned long long int &n2, unsigned long int &size, unsigned long int &msize)
{
    unsigned long long int x, w, i, j;
    x = a[n / 2]; /* опорный элемент */
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
            i++; /* слева находим элемент больше опорного */
            ++n2;
        }
        while (x < a[j])
        {
            j--; /* справа находим элемент меньше опорного */
            ++n2;
        }
        if (i <= j)
        {
            w = a[i];
            ++n1;
            a[i] = a[j];
            ++n1;
            a[j] = w; /* меняем найденные элементы местами */
            ++n1;
            i++;
            ++n2;
            j--;
            ++n2;
        }
    } while (i < j); /* по завершении цикла слева от опорного элемента ключи, меньшие х, а справа - большие */
    /* сортируем так же левую и правую части */
    if (j > 0)
        QuickSort(a, j + 1, n1, n2, size, msize);
    if (i < n - 1)
        QuickSort(a + i, n - i, n1, n2, size, msize);
    size -= size;
}

// сортировка естественным слиянием
void NaturalMergeSort(unsigned long int *a, unsigned long int n, unsigned long long int &n1, unsigned long long int &n2, unsigned long int &size, unsigned long int &msize)
{
    int split; /* индекс, по которому делим массив */
    int end;
    unsigned long int *p = a, *tmp;
    char flag = 0, sorted = 0;
    int pos1, pos2, pos3;
    tmp = (unsigned long int *)malloc(n * sizeof(unsigned long int));
    size = sizeof(split) + sizeof(end) + sizeof(p) + sizeof(flag) + sizeof(sorted) + sizeof(pos1) + sizeof(pos2) + sizeof(pos3) + sizeof(tmp) * n;
    msize = size;
    n2 += 4;
    do /* если есть более 1 элемента */
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
                ; /*первая серия*/
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
            while (pos1 < split && pos2 < end) /*идет слияние, пока есть хоть один элемент в каждой серии*/
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
            /* одна последовательность закончилась - копировать остаток другой в конец буфера */
            while (pos2 < end && tmp[pos3 - 1] <= p[pos2]) /* пока вторая последовательность не пуста */
            {
                tmp[pos3++] = p[pos2++];
                ++n1;
                n2 += 2;
            }
            while (pos1 < split) /* пока первая последовательность не пуста */
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