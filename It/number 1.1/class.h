#ifndef CLASS_H
#define CLASS_H
#include "iostream"

using namespace std;

class Triangle
{
private:
    double LenghtSide;   // ����� �������
    double FirstCorner;  // ������ ����������� ����
    double SecondCorner; // ������ ���������� ����

public:
    Triangle();                       // ����������� ��� ����������
    Triangle(double, double, double); // ����������� � �����������
    Triangle(const Triangle &);       // ����������� �����������
    ~Triangle();                      // ����������

    double GetLenghtSide();   // ��������� �������� ���� �������
    double GetFirstCorner();  // ��������� �������� ������� ����
    double GetSecondCorner(); // ��������� �������� ������� ����

    void SetLenght(double);       // ���������� �������� ���� �������
    void SetFirstCorner(double);  // ���������� �������� ���� ������� ����
    void SetSecondCorner(double); // ���������� �������� ���� ������� ����

    double InputNewLenght(); // ���� ������ �������� ��� �������
    double InputNewCorner(); // ���� ������ �������� ��� ����

    bool CorrectTriangle();                   // �������� ������������ �� ������������
    double GetRadian(double);                 // ������� ���� � �������
    double SearchMax(double, double, double); // ����� ��������� �� ��� ���������

    double SearchThirdCorner(); // ����� �������� ���� (���� �������� ��������� �������)
    double SearchSideB();       // ����� ������� �������� ������� ����
    double SearchSideC();       // ����� ������� �������� ������� ����

    double SearchArea();   // ����� ������� ������������
    double SearchHeight(); // ����� ������ ����������� �� �������� ����
    double SearchMedian(); // ����� ������� ����������� � ������� �������

    friend ostream &operator<<(ostream &, const Triangle &); // ���������� ��������� ������
    friend istream &operator>>(istream &, Triangle &);       // ���������� ��������� �����
    bool operator==(const Triangle &);                       // ���������� ��������� �����
};

#endif