#include "DeqOutList.hpp"
#include "DeqOutVector.hpp"
#include <iostream>
#include <conio.h>
#include <time.h>
#include <limits>
#include <iomanip>
#include <locale>

using namespace std;
// ��������� ���������� �������
template <class DataType>
DataType *randomFill(DataType *a, int n)
{
    srand(time(0)); // ���������� ������
    a = new (nothrow) DataType[n];
    if (!a)
    {
        cout << "������ ���������� ������" << endl;
        n = 0;
        return NULL;
    }
    if (typeid(DataType) == typeid(unsigned char)) // ���� unsigned char
        for (int i = 0; i < n; i++)
            a[i] = rand() % 256;
    if (typeid(DataType) == typeid(float)) // ���� float
        for (int i = 0; i < n; i++)
            a[i] = -100 + static_cast<float>(rand()) / static_cast<float>(RAND_MAX / (200));
    return a;
}
// ����� ��������� �������
template <class DataType>
void showArray(DataType *a, int n)
{
    system("cls");
    if (a == NULL || n == 0)
    {
        cout << "������  ����" << endl;
    }
    else // ���� ������ �� ����
    {
        cout << "����� ��������� �������" << endl;
        for (int i = 0; i < n; i++)
            cout << +a[i] << " ";
        cout << endl;
    }
}
// ������ ����� ��������� �������
template <class DataType>
float getSum(DataType *a, int n)
{
    system("cls");
    float sum = 0;
    if (a == NULL || n == 0) // ���� ����
    {
        cout << "������  ����" << endl;
        return 0;
    }
    else // ���� �� ����
    {
        cout << "���������� ����� ������������� ��������� �������" << endl;
        {
            for (int i = 0; i < n; i++)
                if (a[i] > 0)
                    sum += a[i];
            return sum;
        }
    }
}
// ���� ����������� �������
int inputSizeArray()
{
    int n;
    system("cls");
    cout << "������� ���������� ��������� ������� ��� ��������" << endl;
    while (1)
    {
        cin >> n;
        if (n > 0)
            return n;
        else // ���� ������������ ���� ��� �� �� ��
        {
            cout << "������� ���������� ���������� ��������� �������" << endl;
            cin.clear(); // ������� ����
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}
// ���� ������������ �������
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
        cout << "������������ ������� �������" << endl;
        cout << "1. ����� ��������� �������" << endl
             << "2. ������ ����� ������������� ��������� �������" << endl
             << "3. ������� � ����" << endl;
        cin >> variant;
        if (variant < 1 || variant > 3)
        {
            cin.clear(); // ������� ����
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        switch (variant)
        {
        case 1:
        {
            showArray(arr, n);
            cout << "��� �������� � ���� ������� escape" << endl;
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
                cout << "������ ����" << endl;
            }
            cout << "����� ������������� ��������� �������: " << +sum << endl;
            cout << "��� �������� � ���� ������� escape" << endl;
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
// ���� ������ ������� ��� ������������
void menuArray()
{
    char c;
    int n;
    int menu;
    do
    {
        system("cls");
        cout << "1. ������� ������ � ���������� ���� unsigned char" << endl
             << "2. ������� ������ � ���������� ���� float " << endl
             << "3. ������� � ����" << endl;
        cin >> menu;
        if (menu < 1 || menu > 3)
        {
            cin.clear(); // ������� ����
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
// ���� ������������ ���� � ������������ �����
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
        cout << "�������� ��������" << endl
             << "1. �������� ������� � ������� ����� ����" << endl
             << "2. �������� ������� � �������� ����� ����" << endl
             << "3. ������� ������� � ��������� �����" << endl
             << "4. ������� � ���� " << endl;
        cin >> menu;
        if (menu < 1 || menu > 4)
        {
            cin.clear(); // ������� ����
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        switch (menu)
        {
        case 1:
        {
            system("cls");
            cout << "���������� �������� � �������� ����� ����(� ������)" << endl;
            cout << "������� ������� ��� ����������" << endl;
            cin >> x;
            Deq->addFront(x);
            cout << "��� �������� � ���� ������� escape" << endl;
            do
            {
                c = getch();
            } while (c != 27);
            break;
        }
        case 2:
        {
            system("cls");
            cout << "���������� �������� � �������� ����� ����" << endl;
            cout << "������� ������� ��� ����������" << endl;
            cin >> x;
            Deq->addBack(x);
            cout << "��� �������� � ���� ������� escape" << endl;
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
                cout << "���������� �������� � ��������� ����� ����" << endl;
                cout << "�������� ������� � ��������� �����: " << Deq->outHead() << endl;
            }
            else
                cout << "��� ����" << endl;
            cout << "��� �������� � ���� ������� escape" << endl;
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
// ���� ����
void menuDeq()
{
    char c;
    int i;
    int menu;
    do
    {
        system("cls");
        cout << "1. �������������� ��� � ���������� ���� unsigned char" << endl
             << "2. �������������� ��� � ���������� ���� float" << endl
             << "3. ������� � ����" << endl;
        cin >> menu;
        if (menu < 1 || menu > 3)
        {
            cin.clear(); // ������� ����
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        switch (menu)
        {
        case 1: // unsigned char
        {
            BaseDeqOut<unsigned char> *Deq;
            system("cls");
            cout << "�������� �������� �������� ��� ����" << endl
                 << "1. ��������� ��������� ��������" << endl
                 << "2. ������� ��������� ��������" << endl;
            do
            {
                cin >> i;
                if (i < 1 || i > 3) // ���� ������� ���-�� �����������
                {
                    cout << "������� ���������� �����, 1 ��� 2" << endl;
                    cin.clear(); // ������� ����
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
            } while (i != 1 && i != 2);
            if (i == 1) // ���� ���������
            {
                Deq = new DeqOutVector<unsigned char>(3);
            }
            if (i == 2) // ���� �������
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
            cout << "�������� �������� �������� ��� ����" << endl
                 << "1. ��������� ��������� ��������" << endl
                 << "2. ������� ��������� ��������" << endl;
            do
            {
                cin >> i;
                if (i < 1 || i > 3) // ���� ������� ���-�� �����������
                {
                    cout << "������� ���������� �����, 1 ��� 2" << endl;
                    cin.clear(); // ������� ����
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
            } while (i != 1 && i != 2);
            if (i == 1) // ���� ���������
            {
                Deq = new DeqOutVector<float>(3);
            }
            if (i == 2) // ���� �������
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
        cout << "1. �������������� ������ ������� � ��������" << endl
             << "2. �������������� ��� � ������������ �������" << endl
             << "3. Exit" << endl;
        cin >> menu;
        if (menu < 1 || menu > 3)
        {
            cin.clear(); // ������� ����
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