#include "DeqOutList.hpp"
#include "DeqOutVector.hpp"
#include <iostream>
#include <conio.h>
#include <time.h>
#include <limits>
#include <iomanip>
#include <locale>

using namespace std;
// случайное заполнение массива
template <class DataType>
DataType *randomFill(DataType *a, int n)
{
    srand(time(0)); // подключаем рандом
    a = new (nothrow) DataType[n];
    if (!a)
    {
        cout << "Ошибка выдедления памяти" << endl;
        n = 0;
        return NULL;
    }
    if (typeid(DataType) == typeid(unsigned char)) // если unsigned char
        for (int i = 0; i < n; i++)
            a[i] = rand() % 256;
    if (typeid(DataType) == typeid(float)) // елси float
        for (int i = 0; i < n; i++)
            a[i] = -100 + static_cast<float>(rand()) / static_cast<float>(RAND_MAX / (200));
    return a;
}
// вывод элементов массива
template <class DataType>
void showArray(DataType *a, int n)
{
    system("cls");
    if (a == NULL || n == 0)
    {
        cout << "Массив  пуст" << endl;
    }
    else // если массив не пуст
    {
        cout << "Вывод элементов массива" << endl;
        for (int i = 0; i < n; i++)
            cout << +a[i] << " ";
        cout << endl;
    }
}
// узнать сумму элементов массива
template <class DataType>
float getSum(DataType *a, int n)
{
    system("cls");
    float sum = 0;
    if (a == NULL || n == 0) // если пуст
    {
        cout << "Массив  пуст" << endl;
        return 0;
    }
    else // если не пуст
    {
        cout << "Вычисление суммы положительных элементов массива" << endl;
        {
            for (int i = 0; i < n; i++)
                if (a[i] > 0)
                    sum += a[i];
            return sum;
        }
    }
}
// ввод размерности массива
int inputSizeArray()
{
    int n;
    system("cls");
    cout << "Введите количество элементов массива для создания" << endl;
    while (1)
    {
        cin >> n;
        if (n > 0)
            return n;
        else // если пользователь ввел что то не то
        {
            cout << "Введите корректное количество элементов массива" << endl;
            cin.clear(); // очищаем поле
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}
// меню тестирования массива
template <class DataType>
void TestArray(DataType *arr, int n)
{
    char c;
    float sum;
    int variant;
    arr = randomFill(arr, n);
    do
    {
        system("cls");
        cout << "Тестирование функции массива" << endl;
        cout << "1. Вывод элементов массива" << endl
             << "2. Узнать сумму положительных элементов массива" << endl
             << "3. Обратно в меню" << endl;
        cin >> variant;
        if (variant < 1 || variant > 3)
        {
            cin.clear(); // очищаем поле
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        switch (variant)
        {
        case 1:
        {
            showArray(arr, n);
            cout << "Для возврата в меню нажмите escape" << endl;
            do
            {
                c = getch();
            } while (c != 27);
            break;
        }
        case 2:
        {
            sum = getSum(arr, n);
            if (+sum == 0)
            {
                cout << "Массив пуст" << endl;
            }
            cout << "Сумма положительных элементов массива: " << +sum << endl;
            cout << "Для возврата в меню нажмите escape" << endl;
            do
            {
                c = getch();
            } while (c != 27);
            break;
        }
        }

    } while (variant != 3);
    delete[] arr;
}
// меню выбора массива для тестирования
void menuArray()
{
    char c;
    int n;
    int menu;
    do
    {
        system("cls");
        cout << "1. Создать массив с элементами типа unsigned char" << endl
             << "2. Создать массив с элементами типа float " << endl
             << "3. Обратно в меню" << endl;
        cin >> menu;
        if (menu < 1 || menu > 3)
        {
            cin.clear(); // очищаем поле
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        switch (menu)
        {
        case 1:
        {
            n = inputSizeArray();
            unsigned char *arr = NULL;
            TestArray(arr, n);
            break;
        }
        case 2:
        {
            n = inputSizeArray();
            float *arr = NULL;
            TestArray(arr, n);
            break;
        }
        }
    } while (menu != 3);
}
// меню тестирования дека с ограниченным деком
template <class DataType>
void TestDeq(BaseDeqOut<DataType> *Deq)
{
    DataType x;
    DataType m;
    int menu;
    char c;
    do
    {
        system("cls");
        cout << "Выберите действие" << endl
             << "1. Добавить элемент в открытй конец дека" << endl
             << "2. Добавить элемент в закрытый конец дека" << endl
             << "3. Извлечь элемент с открытого конца" << endl
             << "4. Обратно в меню " << endl;
        cin >> menu;
        if (menu < 1 || menu > 4)
        {
            cin.clear(); // очищаем поле
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        switch (menu)
        {
        case 1:
        {
            system("cls");
            cout << "Добавление элемента в открытый конец дека(в начало)" << endl;
            cout << "Введите элемент для добавления" << endl;
            cin >> x;
            Deq->addFront(x);
            cout << "Для возврата в меню нажмите escape" << endl;
            do
            {
                c = getch();
            } while (c != 27);
            break;
        }
        case 2:
        {
            system("cls");
            cout << "Добавление элемента в закрытый конец дека" << endl;
            cout << "Введите элемент для добавления" << endl;
            cin >> x;
            Deq->addBack(x);
            cout << "Для возврата в меню нажмите escape" << endl;
            do
            {
                c = getch();
            } while (c != 27);
            break;
        }
        case 3:
        {
            system("cls");
            if (!Deq->isEmpty())
            {
                cout << "Извлечение элемента с открытого конца дека" << endl;
                cout << "Извлечен элемент с открытого конца: " << Deq->outHead() << endl;
            }
            else
                cout << "Дек пуст" << endl;
            cout << "Для возврата в меню нажмите escape" << endl;
            do
            {
                c = getch();
            } while (c != 27);
            break;
        }
        }
    } while (menu != 4);
    delete Deq;
}
// меню дека
void menuDeq()
{
    char c;
    int i;
    int menu;
    do
    {
        system("cls");
        cout << "1. Протестировать дек с элементами типа unsigned char" << endl
             << "2. Протестировать дек с элементами типа float" << endl
             << "3. Обратно в меню" << endl;
        cin >> menu;
        if (menu < 1 || menu > 3)
        {
            cin.clear(); // очищаем поле
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        switch (menu)
        {
        case 1: // unsigned char
        {
            BaseDeqOut<unsigned char> *Deq;
            system("cls");
            cout << "Выберите структру хранения для дека" << endl
                 << "1. Векторная структура хранения" << endl
                 << "2. Связная структура хранения" << endl;
            do
            {
                cin >> i;
                if (i < 1 || i > 3) // если введено что-то некоректное
                {
                    cout << "Введите корректное число, 1 или 2" << endl;
                    cin.clear(); // очищаем поле
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
            } while (i != 1 && i != 2);
            if (i == 1) // если векторная
            {
                Deq = new DeqOutVector<unsigned char>(3);
            }
            if (i == 2) // если связная
            {
                Deq = new DeqOutList<unsigned char>();
            }
            TestDeq(Deq);
            break;
        }
        case 2: // float
        {
            BaseDeqOut<float> *Deq;
            system("cls");
            cout << "Выберите структру хранения для дека" << endl
                 << "1. Векторная структура хранения" << endl
                 << "2. Связная структура хранения" << endl;
            do
            {
                cin >> i;
                if (i < 1 || i > 3) // если введено что-то некоректное
                {
                    cout << "Введите корректное число, 1 или 2" << endl;
                    cin.clear(); // очищаем поле
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
            } while (i != 1 && i != 2);
            if (i == 1) // если векторная
            {
                Deq = new DeqOutVector<float>(3);
            }
            if (i == 2) // если связная
            {
                Deq = new DeqOutList<float>();
            }
            TestDeq(Deq);
            break;
        }
        }
    } while (menu != 3);
}

int main(void)
{
    setlocale(LC_ALL, "Rus");
    int menu, variant;
    do
    {
        system("cls");
        cout << "1. Протестировать работу функции с массивом" << endl
             << "2. Протестировать дек с ограниченным выходом" << endl
             << "3. Exit" << endl;
        cin >> menu;
        if (menu < 1 || menu > 3)
        {
            cin.clear(); // очищаем поле
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        switch (menu)

        {
        case 1:
        {
            menuArray();
            break;
        }
        case 2:
        {
            menuDeq();
            break;
        }
        }
    } while (menu != 3);
    return 0;
}