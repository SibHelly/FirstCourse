#include <iostream>
#include "class.h"

using namespace std;

int main()
{
    int menu, variant;
    bool flag;
    Triangle first, second(5, 90, 45), third(second);
    string yes;
    do
    {
        system("pause");
        system("cls");
        cout << "1. Processing of a triangle created by the constructor without parmeters" << endl;
        cout << "2. Processing of a triangle created by the constructor with parmeters" << endl;
        cout << "3. Processing of a triangle created by the constructor with copy" << endl;
        cout << "4. Compare triangle" << endl;
        cout << "5. Exit" << endl;
        cin >> menu;
        switch (menu)
        {
        case 1:
        {
            system("cls");
            do
            {
                system("cls");
                cout << first << endl;
                flag = first.CorrectTriangle(); // проверяем треугольник на корректность
                if (flag == false)              // если треугольник не корректный
                {
                    cout << "Enter correct value of corners or side" << endl;
                    cout << "1. Enter new values of triangle" << endl
                         << "2. Input and set value of lenght side" << endl
                         << "3. Input and set value of first corner" << endl
                         << "4. Input and set value of second corner" << endl
                         << "For return to menu press 9" << endl;
                    cin >> variant;
                    switch (variant)
                    {
                    case 1: // заполнение новыми значениями
                    {
                        system("cls");
                        cin >> first;
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
                        cout << "Changing the value of the length of the side of the triangle" << endl;
                        first.SetLenght(first.InputNewLenght());
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
                        cout << "Changing the value of the first corner of the triangle" << endl;
                        first.SetFirstCorner(first.InputNewCorner());
                        cout << "For return to the menu, press e or E" << endl;
                        do
                        {
                            cin >> yes;
                        } while (yes != "e" && yes != "E");

                        break;
                    }
                    case 4:
                    {
                        system("cls");
                        cout << "Changing the value of the second corner of the triangle" << endl;
                        first.SetSecondCorner(first.InputNewCorner());
                        cout << "For return to the menu, press e or E" << endl;
                        do
                        {
                            cin >> yes;
                        } while (yes != "e" && yes != "E");

                        break;
                    }
                    }
                }
                else // если треугольник существует
                {
                    cout << "1. Enter new values" << endl;
                    cout << "2. Input and set value of lenght side" << endl;
                    cout << "3. Input and set value of first corner" << endl;
                    cout << "4. Input and set value of second corner" << endl;
                    cout << "5. Calculate the lengths of the sides" << endl;
                    cout << "6. Calculate the area of tringle" << endl;
                    cout << "7. Calculate the height of tringle " << endl;
                    cout << "8. Calculate the median drawn to the larger side" << endl;
                    cout << "9. For return to menu press 9" << endl;
                    cin >> variant;
                    switch (variant)
                    {
                    case 1: // ввод новых значений
                    {
                        system("cls");
                        cin >> first;
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
                        cout << "Changing the value of the length of the side of the triangle" << endl;
                        first.SetLenght(first.InputNewLenght());
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
                        cout << "Changing the value of the first corner of the triangle" << endl;
                        first.SetFirstCorner(first.InputNewCorner());
                        cout << "For return to the menu, press e or E" << endl;
                        do
                        {
                            cin >> yes;
                        } while (yes != "e" && yes != "E");

                        break;
                    }
                    case 4:
                    {
                        system("cls");
                        cout << "Changing the value of the second corner of the triangle" << endl;
                        first.SetSecondCorner(first.InputNewCorner());
                        cout << "For return to the menu, press e or E" << endl;
                        do
                        {
                            cin >> yes;
                        } while (yes != "e" && yes != "E");

                        break;
                    }
                    case 5: // вывод сторон на экран
                    {
                        system("cls");
                        cout << "Lenghts of sides" << endl;
                        cout << "Lenght of side a: " << endl
                             << first.GetLenghtSide() << endl;
                        cout << "Lenght of side b: " << endl
                             << first.SearchSideB() << endl;
                        cout << "Lenght of side c: " << endl
                             << first.SearchSideC() << endl;
                        cout << "For return to the menu, press e or E" << endl;
                        do
                        {
                            cin >> yes;
                        } while (yes != "e" && yes != "E");

                        break;
                    }
                    case 6: // вывод площади
                    {
                        system("cls");
                        cout << "Area of tringle" << endl;
                        cout << "Area this tringle: " << endl
                             << first.SearchArea() << endl;
                        cout << "For return to the menu, press e or E" << endl;
                        do
                        {
                            cin >> yes;
                        } while (yes != "e" && yes != "E");

                        break;
                    }
                    case 7: // вывод высоты проведенной из большего угла
                    {
                        system("cls");
                        cout << "Height of tringle drawn from lager corner: " << endl
                             << first.SearchHeight() << endl;
                        cout << "For return to the menu, press e or E" << endl;
                        do
                        {
                            cin >> yes;
                        } while (yes != "e" && yes != "E");

                        break;
                    }
                    case 8: // вывод медианы проведенной к большей стороне
                    {
                        system("cls");
                        cout << "Mediana of tringle drawn to lager side: " << first.SearchMedian() << endl;
                        cout << "For return to the menu, press e or E" << endl;
                        do
                        {
                            cin >> yes;
                        } while (yes != "e" && yes != "E");

                        break;
                    }
                    }
                }
            } while (variant != 9);
            break;
        }
        case 2: // работа с треугольником созданным с параметрами
        {
            system("cls");
            do
            {
                system("cls");
                cout << second << endl;
                flag = second.CorrectTriangle();
                if (flag == false) // если не существует, просим ввести новые значения
                {
                    cout << "Enter correct value of corners or side" << endl;
                    cout << "1. Enter new values of triangle" << endl
                         << "2. Input and set value of lenght side" << endl
                         << "3. Input and set value of first corner" << endl
                         << "4. Input and set value of second corner" << endl
                         << "For return to menu press 9" << endl;
                    cin >> variant;
                    switch (variant)
                    {
                    case 1: // заполнение новыми значениями
                    {
                        system("cls");
                        cin >> second;
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
                        cout << "Changing the value of the length of the side of the triangle" << endl;
                        second.SetLenght(second.InputNewLenght());
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
                        cout << "Changing the value of the first corner of the triangle" << endl;
                        second.SetFirstCorner(second.InputNewCorner());
                        cout << "For return to the menu, press e or E" << endl;
                        do
                        {
                            cin >> yes;
                        } while (yes != "e" && yes != "E");

                        break;
                    }
                    case 4:
                    {
                        system("cls");
                        cout << "Changing the value of the second corner of the triangle" << endl;
                        second.SetSecondCorner(second.InputNewCorner());
                        cout << "For return to the menu, press e or E" << endl;
                        do
                        {
                            cin >> yes;
                        } while (yes != "e" && yes != "E");

                        break;
                    }
                    }
                }
                else // если треугольник существует
                {
                    cout << "1. Enter new values" << endl;
                    cout << "2. Input and set value of lenght side" << endl;
                    cout << "3. Input and set value of first corner" << endl;
                    cout << "4. Input and set value of second corner" << endl;
                    cout << "5. Calculate the lengths of the sides" << endl;
                    cout << "6. Calculate the area of tringle" << endl;
                    cout << "7. Calculate the height of tringle " << endl;
                    cout << "8. Calculate the median drawn to the larger side" << endl;
                    cout << "9. For return to menu press 9" << endl;
                    cin >> variant;
                    switch (variant)
                    {
                    case 1: // новые значения
                    {
                        system("cls");
                        cin >> second;
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
                        cout << "Changing the value of the length of the side of the triangle" << endl;
                        second.SetLenght(second.InputNewLenght());
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
                        cout << "Changing the value of the first corner of the triangle" << endl;
                        second.SetFirstCorner(second.InputNewCorner());
                        cout << "For return to the menu, press e or E" << endl;
                        do
                        {
                            cin >> yes;
                        } while (yes != "e" && yes != "E");

                        break;
                    }
                    case 4:
                    {
                        system("cls");
                        cout << "Changing the value of the second corner of the triangle" << endl;
                        second.SetSecondCorner(second.InputNewCorner());
                        cout << "For return to the menu, press e or E" << endl;
                        do
                        {
                            cin >> yes;
                        } while (yes != "e" && yes != "E");

                        break;
                    }
                    case 5: // вывод сторон
                    {
                        system("cls");
                        cout << "Lenghts of sides" << endl;
                        cout << "Lenght of side a: " << endl
                             << second.GetLenghtSide() << endl;
                        cout << "Lenght of side b: " << endl
                             << second.SearchSideB() << endl;
                        cout << "Lenght of side c: " << endl
                             << second.SearchSideC() << endl;
                        cout << "For return to the menu, press e or E" << endl;
                        do
                        {
                            cin >> yes;
                        } while (yes != "e" && yes != "E");

                        break;
                    }
                    case 6: // вывод площади
                    {
                        system("cls");
                        cout << "Area of tringle" << endl;
                        cout << "Area this tringle: " << endl
                             << second.SearchArea() << endl;
                        cout << "For return to the menu, press e or E" << endl;
                        do
                        {
                            cin >> yes;
                        } while (yes != "e" && yes != "E");

                        break;
                    }
                    case 7: // вывод высоты
                    {
                        system("cls");
                        cout << "Height of tringle drawn from lager corner: " << endl
                             << second.SearchHeight() << endl;
                        cout << "For return to the menu, press e or E" << endl;
                        do
                        {
                            cin >> yes;
                        } while (yes != "e" && yes != "E");

                        break;
                    }
                    case 8: // вывод медианы
                    {
                        system("cls");
                        cout << "Mediana of tringle drawn to lager side: " << endl
                             << second.SearchMedian() << endl;
                        cout << "For return to the menu, press e or E" << endl;
                        do
                        {
                            cin >> yes;
                        } while (yes != "e" && yes != "E");

                        break;
                    }
                    }
                }
            } while (variant != 9);
            break;
        }
        case 3: // обрабортка треугольника построеннного конструктором копирования
        {

            system("cls");
            do
            {
                system("cls");
                cout << third << endl;
                flag = third.CorrectTriangle();
                if (flag == false)
                {
                    cout << "Enter correct value of corners or side" << endl;
                    cout << "1. Enter new values of triangle" << endl
                         << "2. Input and set value of lenght side" << endl
                         << "3. Input and set value of first corner" << endl
                         << "4. Input and set value of second corner" << endl
                         << "For return to menu press 9" << endl;
                    cin >> variant;
                    switch (variant)
                    {
                    case 1: // заполнение новыми значениями
                    {
                        system("cls");
                        cin >> third;
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
                        cout << "Changing the value of the length of the side of the triangle" << endl;
                        third.SetLenght(third.InputNewLenght());
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
                        cout << "Changing the value of the first corner of the triangle" << endl;
                        third.SetFirstCorner(third.InputNewCorner());
                        cout << "For return to the menu, press e or E" << endl;
                        do
                        {
                            cin >> yes;
                        } while (yes != "e" && yes != "E");

                        break;
                    }
                    case 4:
                    {
                        system("cls");
                        cout << "Changing the value of the second corner of the triangle" << endl;
                        third.SetSecondCorner(third.InputNewCorner());
                        cout << "For return to the menu, press e or E" << endl;
                        do
                        {
                            cin >> yes;
                        } while (yes != "e" && yes != "E");

                        break;
                    }
                    }
                }
                else
                {
                    cout << "1. Enter new values" << endl;
                    cout << "2. Input and set value of lenght side" << endl;
                    cout << "3. Input and set value of first corner" << endl;
                    cout << "4. Input and set value of second corner" << endl;
                    cout << "5. Calculate the lengths of the sides" << endl;
                    cout << "6. Calculate the area of tringle" << endl;
                    cout << "7. Calculate the height of tringle " << endl;
                    cout << "8. Calculate the median drawn to the larger side" << endl;
                    cout << "9. For return to menu press 9" << endl;
                    cin >> variant;
                    switch (variant)
                    {
                    case 1:
                    {
                        system("cls");
                        cin >> third;
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
                        cout << "Changing the value of the length of the side of the triangle" << endl;
                        third.SetLenght(third.InputNewLenght());
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
                        cout << "Changing the value of the first corner of the triangle" << endl;
                        third.SetFirstCorner(third.InputNewCorner());
                        cout << "For return to the menu, press e or E" << endl;
                        do
                        {
                            cin >> yes;
                        } while (yes != "e" && yes != "E");

                        break;
                    }
                    case 4:
                    {
                        system("cls");
                        cout << "Changing the value of the second corner of the triangle" << endl;
                        third.SetSecondCorner(third.InputNewCorner());
                        cout << "For return to the menu, press e or E" << endl;
                        do
                        {
                            cin >> yes;
                        } while (yes != "e" && yes != "E");

                        break;
                    }
                    case 5:
                    {
                        system("cls");
                        cout << "Lenghts of sides" << endl;
                        cout << "Lenght of side a: " << endl
                             << third.GetLenghtSide() << endl;
                        cout << "Lenght of side b: " << endl
                             << third.SearchSideB() << endl;
                        cout << "Lenght of side c: " << endl
                             << third.SearchSideC() << endl;
                        cout << "For return to the menu, press e or E" << endl;
                        do
                        {
                            cin >> yes;
                        } while (yes != "e" && yes != "E");

                        break;
                    }
                    case 6:
                    {
                        system("cls");
                        cout << "Area of tringle" << endl;
                        cout << "Area this tringle: " << endl
                             << third.SearchArea() << endl;
                        cout << "For return to the menu, press e or E" << endl;
                        do
                        {
                            cin >> yes;
                        } while (yes != "e" && yes != "E");

                        break;
                    }
                    case 7:
                    {
                        system("cls");
                        cout << "Height of tringle drawn from lager corner: " << endl
                             << third.SearchHeight() << endl;
                        cout << "For return to the menu, press e or E" << endl;
                        do
                        {
                            cin >> yes;
                        } while (yes != "e" && yes != "E");

                        break;
                    }
                    case 8:
                    {
                        system("cls");
                        cout << "Mediana of tringle drawn to lager side: " << endl
                             << third.SearchMedian() << endl;
                        cout << "For return to the menu, press e or E" << endl;
                        do
                        {
                            cin >> yes;
                        } while (yes != "e" && yes != "E");

                        break;
                    }
                    }
                }
            } while (variant != 9);
            break;
        }
        case 4: // сравнение треугольников
        {
            system("cls");
            do
            {
                system("cls");
                cout << "1. Compare first and second triangles" << endl;
                cout << "2. Compare first and third triangles" << endl;
                cout << "3. Compare third and second triangles" << endl;
                cout << "4. For return to the menu, press 4" << endl;
                cin >> variant;
                switch (variant) // выбор какие треугольники сравнивать
                {
                case 1: // сравнение первого и второго
                {
                    system("cls");
                    if ((first == second) == true)
                        cout << "Triangles first and second are equal" << endl;
                    else
                        cout << "Triangles first and second are not equal" << endl;
                    cout << "For return to the menu, press e or E" << endl;
                    do
                    {
                        cin >> yes;
                    } while (yes != "e" && yes != "E");

                    break;
                }
                case 2: // сравнение первого и третьего
                {
                    system("cls");
                    if ((first == third) == true)
                        cout << "Triangles first and third are equal" << endl;
                    else
                        cout << "Triangles first and third are not equal" << endl;
                    cout << "For return to the menu, press e or E" << endl;
                    do
                    {
                        cin >> yes;
                    } while (yes != "e" && yes != "E");

                    break;
                }
                case 3: // сравнение второго и третьего
                {
                    system("cls");
                    if ((third == second) == true)
                        cout << "Triangles second and third are equal" << endl;
                    else
                        cout << "Triangles second and third are not equal" << endl;
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
    return 0;
}
