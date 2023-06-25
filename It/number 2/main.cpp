#include <iostream>
#include "class.h"
#include <vector>
#define n 3

using namespace std;

int main(void)
{
    int menu, variant, i = 0, k, count; // переменные для меню, i индекс для заполнения массива,count количество совпадений, k индекс для вывода и поисков в массиве
    string yes;                         // переменная для возврата в меню
    groundEquip **arr;                  // массив указателей на объекты базового класса
    arr = new groundEquip *[n];         // выделяем память под массив
    *arr = NULL;
    do
    {
        system("cls");
        cout << "1. Add ground equipment" << endl
             << "2. Show all objects" << endl
             << "3. Select and execute a specific class method for all objects" << endl
             << "4. Select type of objects and execute his special method" << endl
             << "5. Exit" << endl;
        cin >> menu;
        switch (menu)
        {
        case 1: // добавление объекта в массив
        {
            if (i == n - 1) // если массив полон
            {
                system("cls");
                cout << "Array is full" << endl;
                cout << "For return to the menu, press e or E" << endl;
                do
                {
                    cin >> yes;
                } while (yes != "e" && yes != "E");
                break;
            }
            do
            {
                if (i == n - 1) // если массив полон
                {
                    system("cls");
                    cout << "Array is full" << endl;
                    cout << "For return to the menu, press e or E" << endl;
                    do
                    {
                        cin >> yes;
                    } while (yes != "e" && yes != "E");
                    break;
                }
                system("cls"); // меню выбора для пользователя
                cout << "1. Add auto" << endl
                     << "2. Add tank" << endl
                     << "3. Add electric scooter" << endl
                     << "4. Return to the menu" << endl;
                cin >> variant;
                switch (variant)
                {
                case 1:
                {
                    system("cls");
                    cout << "Input information about auto" << endl;
                    arr[i] = new Auto();
                    cin >> *static_cast<Auto *>(arr[i++]);
                    cout << "For return to the menu, press e or E" << endl;
                    do
                    {
                        cin >> yes;
                    } while (yes != "e" && yes != "E");
                    break;
                }
                case 2:
                {
                    system("cls");
                    cout << "Input information about tank" << endl;
                    arr[i] = new Tank();
                    cin >> *static_cast<Tank *>(arr[i++]);
                    cout << "For return to the menu, press e or E" << endl;
                    do
                    {
                        cin >> yes;
                    } while (yes != "e" && yes != "E");
                    break;
                }
                case 3:
                {
                    system("cls");
                    cout << "Input information about electric scooter" << endl;
                    arr[i] = new electricScooter();
                    cin >> *static_cast<electricScooter *>(arr[i++]);
                    cout << "For return to the menu, press e or E" << endl;
                    do
                    {
                        cin >> yes;
                    } while (yes != "e" && yes != "E");
                    break;
                }
                }
            } while (variant != 4);
            break;
        }
        case 2: // вывод всех объектов массива
        {
            system("cls");
            if (i == 0) // если пуст
            {
                cout << "The array is still empty, add objects" << endl;
                cout << "For return to the menu, press e or E" << endl;
                do
                {
                    cin >> yes;
                } while (yes != "e" && yes != "E");
                break;
            }
            cout << "Outputing information about objects" << endl;
            for (k = 0; k < i; k++)
                arr[k]->printInformation();
            cout << "For return to the menu, press e or E" << endl;
            do
            {
                cin >> yes;
            } while (yes != "e" && yes != "E");

            break;
        }
        case 3: // выполнения общих методов, пользователь выбирает какой общий метод выполнить
        {
            system("cls"); // если пуст
            if (i == 0)
            {
                cout << "The array is still empty, add objects" << endl;
                cout << "For return to the menu, press e or E" << endl;
                do
                {
                    cin >> yes;
                } while (yes != "e" && yes != "E");
                break;
            }
            do
            {
                system("cls"); // пользователь выбирает какой общий метод выполнить
                cout << "1. Execute the start method for all objects" << endl
                     << "2. Execute the drive distance method for all objects" << endl
                     << "3. Execute the fill method for all objects" << endl
                     << "4. Return to the menu" << endl;
                cin >> variant;
                switch (variant)
                {
                case 1:
                {
                    system("cls");
                    for (k = 0; k < i; k++)
                    {
                        cout << arr[k]->GetMake() << endl;
                        arr[k]->toStart();
                    }
                    cout << "For return to the menu, press e or E" << endl;
                    do
                    {
                        cin >> yes;
                    } while (yes != "e" && yes != "E");
                    break;
                }
                case 2:
                {
                    system("cls");
                    for (k = 0; k < i; k++)
                    {
                        cout << arr[k]->GetMake() << endl;
                        arr[k]->toRide();
                    }
                    cout << "For return to the menu, press e or E" << endl;
                    do
                    {
                        cin >> yes;
                    } while (yes != "e" && yes != "E");
                    break;
                }
                case 3:
                {
                    system("cls");
                    for (k = 0; k < i; k++)
                    {
                        cout << arr[k]->GetMake() << endl;
                        arr[k]->toFill();
                    }
                    cout << "For return to the menu, press e or E" << endl;
                    do
                    {
                        cin >> yes;
                    } while (yes != "e" && yes != "E");
                    break;
                }
                }
            } while (variant != 4);
            break;
        }
        case 4:
        {
            system("cls");
            if (i == 0) // если пуст
            {
                cout << "The array is still empty, add objects" << endl;
                cout << "For return to the menu, press e or E" << endl;
                do
                {
                    cin >> yes;
                } while (yes != "e" && yes != "E");
                break;
            }
            do
            {
                count = 0;
                system("cls"); // пользователь выбирает для какого класса наземной техники выполнить его конкретный специальный метод
                cout << "1. Execute the violate trafic method for all objects type Auto(violate traffic rules)" << endl
                     << "2. Execute the shoot method for all objects type Tank(shoot)" << endl
                     << "3. Execute the crash method for all objects type electricScooter(crash)" << endl
                     << "4. Return to the menu" << endl;
                cin >> variant;
                switch (variant)
                {
                case 1:
                {
                    system("cls");
                    for (k = 0; k < i; k++)
                    {
                        if (typeid(*arr[k]) == typeid(Auto)) // поиск данного класса
                        {
                            count++;
                            cout << arr[k]->GetMake() << endl;
                            static_cast<Auto *>(arr[k])->breakRule();
                        }
                    }
                    if (count == 0)
                        cout << "Objects of this class not found" << endl;
                    cout << "For return to the menu, press e or E" << endl;
                    do
                    {
                        cin >> yes;
                    } while (yes != "e" && yes != "E");
                    break;
                }
                case 2:
                {
                    system("cls");
                    for (k = 0; k < i; k++)
                    {
                        if (typeid(*arr[k]) == typeid(Tank)) // поиск данного класса
                        {
                            count++;
                            cout << arr[k]->GetMake() << endl;
                            static_cast<Tank *>(arr[k])->toShoot();
                        }
                    }
                    if (count == 0)
                        cout << "Objects of this class not found" << endl;
                    cout << "For return to the menu, press e or E" << endl;
                    do
                    {
                        cin >> yes;
                    } while (yes != "e" && yes != "E");
                    break;
                }
                case 3:
                {
                    system("cls");
                    for (k = 0; k < i; k++)
                    {
                        if (typeid(*arr[k]) == typeid(electricScooter)) // поиск данного класса
                        {
                            count++;
                            cout << arr[k]->GetMake() << endl;
                            static_cast<electricScooter *>(arr[k])->toCrash();
                        }
                    }
                    if (count == 0)
                        cout << "Objects of this class not found" << endl;
                    cout << "For return to the menu, press e or E" << endl;
                    do
                    {
                        cin >> yes;
                    } while (yes != "e" && yes != "E");
                    break;
                }
                }
            } while (variant != 4);
            break;
        }
        }
    } while (menu != 5);
    delete[] arr;
    return 0;
}
