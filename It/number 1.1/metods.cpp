#include "class.h"
#include "cmath"
#include "limits"

// конструктор без параметров
Triangle::Triangle()
{
    cout << "---Constructor without parametrs---" << endl;
    cout << "----------Create Triangle-----------" << endl;
    cout << endl;
    LenghtSide = 0;
    FirstCorner = 0;
    SecondCorner = 0;
}

// конструктор с параметрами
Triangle ::Triangle(double a, double b, double c) : LenghtSide(a), FirstCorner(b), SecondCorner(c)
{
    cout << "---Constructor with parametrs---" << endl;
    cout << "--------Create Tringle----------" << endl;
    cout << endl;
}

// конструктор копирования
Triangle::Triangle(const Triangle &triangle)
{
    cout << "--------Copy constructor---------" << endl;
    cout << "----------Create copy------------" << endl;
    cout << endl;
    LenghtSide = triangle.LenghtSide;
    FirstCorner = triangle.FirstCorner;
    SecondCorner = triangle.SecondCorner;
}

// деструктор
Triangle::~Triangle()
{
    cout << "-----------Destructor-----------" << endl;
}

// перегрузка оператора вывода
ostream &operator<<(ostream &out, const Triangle &output)
{
    cout << "Outputing triangle values" << endl;
    out << "Lenght of side: " << output.LenghtSide << "\n"
        << "First corner: " << output.FirstCorner << "\n"
        << "Second corner: " << output.SecondCorner << endl;

    return out;
}

// перегрузка оператора ввода
istream &operator>>(istream &stream, Triangle &triangle)
{
    cout << "Entering triangle values" << endl;
    cout << "Input lenght of side: "; // ввод стороны
    while (1)
    {
        stream >> triangle.LenghtSide;
        if (triangle.LenghtSide > 0)
            break;
        else // если введенно отрицательное число или непонятный набор символов
        {
            cout << "Input correct lenght of side: ";
            cin.clear(); // очищаем поле
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
    cout << "Input value of first corner: "; // ввод значение первого прилежащего угла
    while (1)
    {
        stream >> triangle.FirstCorner;
        if (triangle.FirstCorner > 0 && triangle.FirstCorner < 180)
            break;
        else
        {
            cout << "Input correct value of first corner: "; // если введно некоректное значение числа
            cin.clear();                                     // очищаем поле
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
    cout << "Input value of second corner: "; // ввод второго прилежащего угла
    while (1)
    {
        stream >> triangle.SecondCorner;
        if (triangle.SecondCorner > 0 && triangle.SecondCorner < 180)
            break;
        else // если введено некоректное значение
        {
            cout << "Input correct value of second corner: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
    return stream;
}

// получить значения из поля длина стороны
double Triangle::GetLenghtSide()
{
    cout << "Return of the side length value" << endl;
    return LenghtSide;
}

// получить значение из поля первого угла
double Triangle::GetFirstCorner()
{
    cout << "Return the value of the first angle" << endl;
    return FirstCorner;
}

// получить значение из поля второго угла
double Triangle::GetSecondCorner()
{
    cout << "Return the value of the second angle" << endl;
    return SecondCorner;
}

// установка нового значения для стороны
void Triangle::SetLenght(double side)
{
    cout << "Setting the side length value" << endl;
    LenghtSide = side;
}

// установка нового значения для первого угла
void Triangle ::SetFirstCorner(double first)
{
    cout << "Setting the value of the first angle" << endl;
    FirstCorner = first;
}

// устанвока нового значения для второго угла
void Triangle::SetSecondCorner(double second)
{
    cout << "Setting the value of the second angle" << endl;
    SecondCorner = second;
}

// проверка треугольника на корректность
bool Triangle::CorrectTriangle()
{
    cout << "Checking the triangle for existence" << endl;
    if (FirstCorner + SecondCorner >= 180 || FirstCorner <= 0 || SecondCorner <= 0 || LenghtSide <= 0)
        return false;
    else
        return true;
}

// перевод угла в радианы
double Triangle::GetRadian(double a)
{
    cout << "Converting an angle to radians" << endl;
    double m = 3.14 / 180;
    return m * a;
}

// поиск третьего угла (напротив известнго угла)
double Triangle::SearchThirdCorner()
{
    cout << "Search of third corner" << endl;
    return 180 - FirstCorner - SecondCorner;
}

// поиск стороны по теореме синусов стороны напротив первого угла
double Triangle::SearchSideB()
{
    cout << "Finding the side opposite the first corner" << endl;
    return LenghtSide * sin(GetRadian(FirstCorner)) / sin(GetRadian(SearchThirdCorner()));
}

// поиск стороны напротив второго угла
double Triangle::SearchSideC()
{
    cout << "Finding the side opposite the second corner" << endl;
    return LenghtSide * sin(GetRadian(SecondCorner)) / sin(GetRadian(SearchThirdCorner()));
}

// поиск площади треугольника
double Triangle::SearchArea()
{
    cout << "Finding the area of a triangle" << endl;
    return (SearchSideB() * SearchSideC() * sin(GetRadian(SearchThirdCorner()))) / 2;
}

// поиск высоты проведенной из наибольшего угла
double Triangle::SearchHeight()
{
    cout << "Finding the height drawn from a larger angle" << endl;
    double alfa = SearchThirdCorner(), area = SearchArea(), b = SearchSideB(), c = SearchSideC();
    double max = SearchMax(FirstCorner, SecondCorner, alfa); // поиск максимального угла
    if (max == FirstCorner)                                  // если максимальный угол первый ищем высоту через формулу площади
        return 2 * area / b;
    if (max == SecondCorner) // если второй угол максимальный
        return 2 * area / c;
    if (max == alfa)
        return 2 * area / LenghtSide;
}

// поиск максимального значения из трех
double Triangle::SearchMax(double a, double b, double c)
{
    cout << "Search for the maximum" << endl;
    double max = a >= b ? (a >= c ? a : c) : (b >= c ? b : c);
    return max;
}

// поиск медианы
double Triangle::SearchMedian()
{
    cout << "Median Search" << endl;
    double a = LenghtSide, b = SearchSideB(), c = SearchSideC();
    double max = SearchMax(a, b, c);
    if (max == a)
        return sqrt(2 * b * b + 2 * c * c - a * a) / 2;
    if (max == b)
        return sqrt(2 * a * a + 2 * c * c - b * b) / 2;
    if (max == c)
        return sqrt(2 * b * b + 2 * a * a - c * c) / 2;
}

// пергрузка операторов равно
bool Triangle::operator==(const Triangle &triangle)
{
    cout << "Comparison of triangles" << endl;
    if (this->LenghtSide == triangle.LenghtSide && this->FirstCorner == triangle.FirstCorner && this->SecondCorner == triangle.SecondCorner)
        return true;
    else
        return false;
}

double Triangle::InputNewLenght()
{
    double a;
    cout << "Entering a new side value";
    cout << "Input value of side: ";
    while (1)
    {
        cin >> a;
        if (a > 0)
        {
            return a;
            break;
        }
        else // если введенно отрицательное число или непонятный набор символов
        {
            cout << "Input correct lenght of side: ";
            cin.clear(); // очищаем поле
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}

double Triangle::InputNewCorner()
{
    double a;
    cout << "Entering a new angle value" << endl;
    cout << "Input value of corner: ";
    while (1)
    {
        cin >> a;
        if (a > 0 && a < 180)
        {
            return a;
            break;
        }
        else // если введенно отрицательное число или непонятный набор символов
        {
            cout << "Input correct value of corner: ";
            cin.clear(); // очищаем поле
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}
