#include "class.h"
#include "cmath"
#include "limits"

// ����������� ��� ����������
Triangle::Triangle()
{
    cout << "---Constructor without parametrs---" << endl;
    cout << "----------Create Triangle-----------" << endl;
    cout << endl;
    LenghtSide = 0;
    FirstCorner = 0;
    SecondCorner = 0;
}

// ����������� � �����������
Triangle ::Triangle(double a, double b, double c) : LenghtSide(a), FirstCorner(b), SecondCorner(c)
{
    cout << "---Constructor with parametrs---" << endl;
    cout << "--------Create Tringle----------" << endl;
    cout << endl;
}

// ����������� �����������
Triangle::Triangle(const Triangle &triangle)
{
    cout << "--------Copy constructor---------" << endl;
    cout << "----------Create copy------------" << endl;
    cout << endl;
    LenghtSide = triangle.LenghtSide;
    FirstCorner = triangle.FirstCorner;
    SecondCorner = triangle.SecondCorner;
}

// ����������
Triangle::~Triangle()
{
    cout << "-----------Destructor-----------" << endl;
}

// ���������� ��������� ������
ostream &operator<<(ostream &out, const Triangle &output)
{
    cout << "Outputing triangle values" << endl;
    out << "Lenght of side: " << output.LenghtSide << "\n"
        << "First corner: " << output.FirstCorner << "\n"
        << "Second corner: " << output.SecondCorner << endl;

    return out;
}

// ���������� ��������� �����
istream &operator>>(istream &stream, Triangle &triangle)
{
    cout << "Entering triangle values" << endl;
    cout << "Input lenght of side: "; // ���� �������
    while (1)
    {
        stream >> triangle.LenghtSide;
        if (triangle.LenghtSide > 0)
            break;
        else // ���� �������� ������������� ����� ��� ���������� ����� ��������
        {
            cout << "Input correct lenght of side: ";
            cin.clear(); // ������� ����
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
    cout << "Input value of first corner: "; // ���� �������� ������� ����������� ����
    while (1)
    {
        stream >> triangle.FirstCorner;
        if (triangle.FirstCorner > 0 && triangle.FirstCorner < 180)
            break;
        else
        {
            cout << "Input correct value of first corner: "; // ���� ������ ����������� �������� �����
            cin.clear();                                     // ������� ����
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
    cout << "Input value of second corner: "; // ���� ������� ����������� ����
    while (1)
    {
        stream >> triangle.SecondCorner;
        if (triangle.SecondCorner > 0 && triangle.SecondCorner < 180)
            break;
        else // ���� ������� ����������� ��������
        {
            cout << "Input correct value of second corner: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
    return stream;
}

// �������� �������� �� ���� ����� �������
double Triangle::GetLenghtSide()
{
    cout << "Return of the side length value" << endl;
    return LenghtSide;
}

// �������� �������� �� ���� ������� ����
double Triangle::GetFirstCorner()
{
    cout << "Return the value of the first angle" << endl;
    return FirstCorner;
}

// �������� �������� �� ���� ������� ����
double Triangle::GetSecondCorner()
{
    cout << "Return the value of the second angle" << endl;
    return SecondCorner;
}

// ��������� ������ �������� ��� �������
void Triangle::SetLenght(double side)
{
    cout << "Setting the side length value" << endl;
    LenghtSide = side;
}

// ��������� ������ �������� ��� ������� ����
void Triangle ::SetFirstCorner(double first)
{
    cout << "Setting the value of the first angle" << endl;
    FirstCorner = first;
}

// ��������� ������ �������� ��� ������� ����
void Triangle::SetSecondCorner(double second)
{
    cout << "Setting the value of the second angle" << endl;
    SecondCorner = second;
}

// �������� ������������ �� ������������
bool Triangle::CorrectTriangle()
{
    cout << "Checking the triangle for existence" << endl;
    if (FirstCorner + SecondCorner >= 180 || FirstCorner <= 0 || SecondCorner <= 0 || LenghtSide <= 0)
        return false;
    else
        return true;
}

// ������� ���� � �������
double Triangle::GetRadian(double a)
{
    cout << "Converting an angle to radians" << endl;
    double m = 3.14 / 180;
    return m * a;
}

// ����� �������� ���� (�������� ��������� ����)
double Triangle::SearchThirdCorner()
{
    cout << "Search of third corner" << endl;
    return 180 - FirstCorner - SecondCorner;
}

// ����� ������� �� ������� ������� ������� �������� ������� ����
double Triangle::SearchSideB()
{
    cout << "Finding the side opposite the first corner" << endl;
    return LenghtSide * sin(GetRadian(FirstCorner)) / sin(GetRadian(SearchThirdCorner()));
}

// ����� ������� �������� ������� ����
double Triangle::SearchSideC()
{
    cout << "Finding the side opposite the second corner" << endl;
    return LenghtSide * sin(GetRadian(SecondCorner)) / sin(GetRadian(SearchThirdCorner()));
}

// ����� ������� ������������
double Triangle::SearchArea()
{
    cout << "Finding the area of a triangle" << endl;
    return (SearchSideB() * SearchSideC() * sin(GetRadian(SearchThirdCorner()))) / 2;
}

// ����� ������ ����������� �� ����������� ����
double Triangle::SearchHeight()
{
    cout << "Finding the height drawn from a larger angle" << endl;
    double alfa = SearchThirdCorner(), area = SearchArea(), b = SearchSideB(), c = SearchSideC();
    double max = SearchMax(FirstCorner, SecondCorner, alfa); // ����� ������������� ����
    if (max == FirstCorner)                                  // ���� ������������ ���� ������ ���� ������ ����� ������� �������
        return 2 * area / b;
    if (max == SecondCorner) // ���� ������ ���� ������������
        return 2 * area / c;
    if (max == alfa)
        return 2 * area / LenghtSide;
}

// ����� ������������� �������� �� ����
double Triangle::SearchMax(double a, double b, double c)
{
    cout << "Search for the maximum" << endl;
    double max = a >= b ? (a >= c ? a : c) : (b >= c ? b : c);
    return max;
}

// ����� �������
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

// ��������� ���������� �����
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
        else // ���� �������� ������������� ����� ��� ���������� ����� ��������
        {
            cout << "Input correct lenght of side: ";
            cin.clear(); // ������� ����
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
        else // ���� �������� ������������� ����� ��� ���������� ����� ��������
        {
            cout << "Input correct value of corner: ";
            cin.clear(); // ������� ����
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}
