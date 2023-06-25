#include <iostream>
#include <fstream>
#include <locale>
#include <time.h>

using namespace std;

#define N1 20000
#define N2 50000
#define N3 80000
#define N4 110000

void BubbleSort(unsigned long int *arr, unsigned long int n, unsigned long long int &n1, unsigned long long int &n2)
{
    int i, j, x;
    for (++n2, i = 1; i < n; ++n2, i++)
        for (++n2, j = n - 1; j >= i; ++n2, j--)
            if (arr[j - 1] > arr[j])
            {
                x = arr[j - 1];
                arr[j - 1] = arr[j];
                arr[j] = x;
                n1 += 3;
            }
}

// сортировка шейкера
void ShakerSort(unsigned long int *a, unsigned long int n, unsigned long long int &n1, unsigned long long int &n2)
{
    unsigned long long int j, k = n - 1, left = 1, right = n - 1, x;
    n2 += 3;
    do
    {
        for (++n2, j = right; j >= left; ++n2, j--) /*сначала просматриваем справа налево*/
            if (a[j - 1] > a[j])
            {
                x = a[j - 1];
                ++n1;
                a[j - 1] = a[j];
                ++n1;
                a[j] = x;
                ++n1;
                k = j;
                ++n2;
            }
        left = k + 1;
        ++n2;
        for (++n2, j = left; j <= right; ++n2, j++) /*а теперь просматриваем слева направо*/
            if (a[j - 1] > a[j])
            {
                x = a[j - 1];
                ++n1;
                a[j - 1] = a[j];
                ++n1;
                a[j] = x;
                ++n1;
                k = j;
                ++n2;
            }
        right = k - 1;
        ++n2;
    } while (left < right); /*и так до тех пор, пока есть что просматривать*/
}

// быстра€ сортировка
void QuickSort(unsigned long int *a, unsigned long int n, unsigned long long int &n1, unsigned long long int &n2)
{
    unsigned long long int x, w, i, j;
    x = a[n / 2]; /* опорный элемент */
    n2++;
    ++n2;
    i = 0;
    ++n2;
    j = n - 1;
    ++n2;
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
            a[j] = w; /* мен€ем найденные элементы местами */
            ++n1;
            i++;
            ++n2;
            j--;
            ++n2;
        }
    } while (i < j); /* по завершении цикла слева от опорного элемента ключи, меньшие х, а справа - большие */
    /* сортируем так же левую и правую части */
    if (j > 0)
        QuickSort(a, j + 1, n1, n2);
    if (i < n - 1)
        QuickSort(a + i, n - i, n1, n2);
}

// сортировка естественным сли€нием
void NaturalMergeSort(unsigned long int *a, unsigned long int n, unsigned long long int &n1, unsigned long long int &n2)
{
    int split; /* индекс, по которому делим массив */
    int end;
    unsigned long int *p = a, *tmp;
    char flag = 0, sorted = 0;
    int pos1, pos2, pos3;
    tmp = (unsigned long int *)malloc(n * sizeof(unsigned long int));
    n2 += 3;
    n1++;
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
                ;
            // cout << "1" << endl; /*перва€ сери€*/
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
            while (pos1 < split && pos2 < end) /*идет сли€ние, пока есть хоть один элемент в каждой серии*/
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
            while (pos2 < end && tmp[pos3 - 1] <= p[pos2]) /* пока втора€ последовательность не пуста */
            {
                tmp[pos3++] = p[pos2++];
                ++n1;
                n2 += 2;
            }
            while (pos1 < split) /* пока перва€ последовательность не пуста */
            {
                tmp[pos3++] = p[pos1++];
                ++n1;
                n2 += 2;
            }
        } while (pos3 < n);
        if (sorted)
            break;
        p = tmp;
        ++n1;
        tmp = a;
        ++n1;
        a = p;
        ++n1;
        flag = !flag;
        ++n2;
        for (int i = 0; i < n; i++)
            cout << a[i] << " ";
        cout << endl;
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

// считать нужное количество чисел из файла
void CreateArr(ifstream &file, unsigned long int N, unsigned long int *&Arr)
{
    if (file.is_open())
    {
        Arr = new (nothrow) unsigned long int[N];
        if (!Arr)
        {
            cout << "ќшибка выделени€ пам€ти" << endl;
            return;
        }
        for (int i = 0; i < N; i++)
            file >> Arr[i];
        cout << "—читывание завершено" << endl
             << endl;
    }
    else
        cout << "‘айл не найден" << endl;
}

int main()
{
    setlocale(LC_ALL, "");
    int Arr[10] = {3, 7, 11, 2, 29, 8, 4, 14, 5, 19};
    // unsigned long int *Arr;
    int N;
    unsigned long long int countAssign = 0, countAuxiliary = 0;
    sizeof(short int);
    ifstream in("DN1elements.txt");
    cin >> N;
    // CreateArr(in, N, Arr[10]);
    NaturalMergeSort(Arr, N, countAssign, countAuxiliary);
    cout << " оличество присваиваний элементов массива : " << countAssign << "  оличество вспомогательных присваиваний: " << countAuxiliary << endl;
    return 0;
}