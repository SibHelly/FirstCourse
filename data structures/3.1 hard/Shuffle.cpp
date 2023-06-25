#include <iostream>
#include <fstream>
#include <string>
#include <locale.h>
#include <iterator>
#include <map>
#include <list>
#include <set>
#include <time.h>
#include <algorithm>
#include <random>
#include <chrono>

#define N1 20000
#define N2 50000
#define N3 80000
#define N4 110000

using namespace std;

void CreateArr(ifstream &file, unsigned long int N, vector<unsigned long long int> &Arr)
{
    if (file.is_open())
    {
        Arr.resize(N);
        for (int i = 0; i < N; i++)
            file >> Arr[i];
        cout << "Считывание завершено" << endl
             << endl;
    }
    else
        cout << "Файл не найден" << endl;
}
// создать файл с повторениями
void createFileRepeat(vector<unsigned long long int> &Arr, unsigned long int N, int CountReapet, int flag)
{
    string s;
    int i, j;
    int n = N / CountReapet;
    cout << "Введите название файла с повторениями равному " << N << " " << endl;
    cout << " - ";
    cin >> s;
    ofstream file(s);
    if (file.is_open())
    {
        cout << "Файл создан" << endl
             << endl;
        if (flag == 1)
        {
            for (i = 0; i < n; i++)
                for (j = 0; j < CountReapet; j++)
                    file << Arr[i] << " ";
            cout << "Числа с повторениями записаны в файл" << endl;
        }
        if (flag == 2)
        {
            unsigned seed = std::chrono::system_clock::now()
                                .time_since_epoch()
                                .count();
            shuffle(Arr.begin(), Arr.end(), default_random_engine(seed));
            for (i = 0; i < N; i++)
                file << Arr[i] << " ";
            cout << "Числа с повторениями записаны в файл Shuffle" << endl;
        }
    }
    else
        cout << "Не удалось создать файл" << endl;
    file.close();
}

int main()
{
    setlocale(LC_ALL, "");
    string s;
    unsigned long long int N, choose, countRepeat;
    vector<unsigned long long int> Arr;
    cout << "Введите название файла для чтения чисел" << endl
         << "-";
    cin >> s;
    cout << endl;
    ifstream in(s);
    if (!in.is_open())
    {
        cout << "Файл не найден" << endl;
        return 1;
    }
    /*cout << "Выберите количество чисел для считывания из файла(В имени файла нужное количество для выбора)" << endl
         << "1. N1=20000" << endl
         << "2. N2=50000" << endl
         << "3. N3=80000" << endl
         << "4. N4=110000" << endl;
    do
    {
        cout << "- ";
        cin >> choose;
        switch (choose)
        {
        case 1:
            N = N1;
            break;
        case 2:
            N = N2;
            break;
        case 3:
            N = N3;
            break;
        case 4:
            N = N4;
            break;
        }
    } while (choose <= 0 || choose > 4);*/
    cout << "Выберите количество повторений чисел" << endl
         << "1. C=10" << endl
         << "2. C=100" << endl
         << "3. C=500" << endl
         << "4. С=1000" << endl;
    do
    {
        cout << "- ";
        cin >> choose;
        switch (choose)
        {
        case 1:
            countRepeat = 10;
            break;
        case 2:
            countRepeat = 100;
            break;
        case 3:
            countRepeat = 500;
            break;
        case 4:
            countRepeat = 1000;
            break;
        }
    } while (choose <= 0 || choose > 4);
    CreateArr(in, N4, Arr);
    createFileRepeat(Arr, N4, countRepeat, 2);
    return 0;
}