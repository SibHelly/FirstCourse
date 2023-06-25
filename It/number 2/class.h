#ifndef CLASS_H
#define CLASS_H
#include "iostream"

using namespace std;
// ������� �����
class groundEquip
{
    string make;           // �����
    double engineCapacity; // ����� ���������
    double maxSpeed;       // ������������ ��������

public:
    groundEquip();                       // ����������� ��� ����������
    groundEquip(string, double, double); // ����������� � ����������� ��� �������� �����
    ~groundEquip();                      // ����������

    string GetMake();     // �������� �����
    double GetCapacity(); // �������� ����� ���������
    double GetSpeed();    // �������� ��������

    virtual void printName();        // ������� ��� ������
    virtual void printInformation(); // ������� ��� ���������� �� �������

    virtual void toStart() = 0; // ����� �������
    virtual void toRide() = 0;  // ����� �������
    virtual void toFill() = 0;  // ����� ���������

    friend istream &operator>>(istream &, groundEquip &); // ���������� ��������� �����
};

class Auto : public groundEquip // ����� ���������
{
    string typeBodie; // ��� ������

public:
    Auto();                               // �����������
    Auto(string, double, double, string); // ����������� � �����������
    ~Auto();                              // ����������

    void printName() override;        // ����� ����� ������
    void printInformation() override; // ����� ���������� �� ������� ����� ������

    void toStart() override;                                                       // �������
    void toRide() override;                                                        // �������
    void toFill() override;                                                        // ���������
    void breakRule() { cout << "The driver violated the traffic rules" << endl; }; // �������� �������

    friend istream &operator>>(istream &, Auto &); // ���������� ��������� �����
};

class Tank : public groundEquip // ����� ��������� ����
{
    string typeTank; // ��� �����

public:
    Tank();                               // ����������� ��� ����������
    Tank(string, double, double, string); // ����������� � �����������
    ~Tank();                              // ����������

    void printName() override;        // ����� ������ ������
    void printInformation() override; // ����� ���� ���������� �� �����

    void toStart() override;                                // �������
    void toRide() override;                                 // ��������
    void toFill() override;                                 // ���������
    void toShoot() { cout << "Tank is shooting" << endl; }; // ��������

    friend istream &operator>>(istream &, Tank &); // ���������� ��������� �����
};

class electricScooter : public groundEquip // ����� ��������� ��������������
{
    double sizeBattery; // ������ �������

public:
    electricScooter();                               // �����������
    electricScooter(string, double, double, double); // ����������� � �����������
    ~electricScooter();                              // ����������

    void printName() override;        // ����� ����� ������
    void printInformation() override; // ����� ���� ���������� �� ������� ��������

    void toStart() override;                                            // �������
    void toRide() override;                                             // �������
    void toFill() override;                                             // ��������
    void toCrash() { cout << "A scooter crashed into a man" << endl; }; // ���������

    friend istream &operator>>(istream &, electricScooter &);
};
#endif
