#ifndef CLASS_H
#define CLASS_H
#include "iostream"

using namespace std;

class Triangle
{
private:
    double LenghtSide;   // длины стороны
    double FirstCorner;  // первый прилежащщий угол
    double SecondCorner; // второй прилежайщи угол

public:
    Triangle();                       // конструктор без параметров
    Triangle(double, double, double); // конструктор с параметрами
    Triangle(const Triangle &);       // конструктор копирования
    ~Triangle();                      // деструктор

    double GetLenghtSide();   // получение значения поля стороны
    double GetFirstCorner();  // получение значения первого угла
    double GetSecondCorner(); // получение значения второго угла

    void SetLenght(double);       // установить значение поля сторона
    void SetFirstCorner(double);  // установить значение поля первого угла
    void SetSecondCorner(double); // установить значение поля второго угла

    double InputNewLenght(); // ввод нового значения для стороны
    double InputNewCorner(); // ввод нового значения для угла

    bool CorrectTriangle();                   // проверка треугольника на корректность
    double GetRadian(double);                 // перевод угла в радианы
    double SearchMax(double, double, double); // поиск максимума из трёх элементов

    double SearchThirdCorner(); // поиск третьего угла (угла напротив известной стороны)
    double SearchSideB();       // поиск стороны напротив первого угла
    double SearchSideC();       // поиск стороны напротив второго угла

    double SearchArea();   // поиск площади треугольника
    double SearchHeight(); // поиск высоты проведенной из большего угла
    double SearchMedian(); // поиск медианы проведенной к большей стороне

    friend ostream &operator<<(ostream &, const Triangle &); // перегрузка оператора вывода
    friend istream &operator>>(istream &, Triangle &);       // перегрузка оператора ввода
    bool operator==(const Triangle &);                       // перегрузка оператора равно
};

#endif