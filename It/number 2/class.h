#ifndef CLASS_H
#define CLASS_H
#include "iostream"

using namespace std;
// базовый класс
class groundEquip
{
    string make;           // марка
    double engineCapacity; // обьем двигателя
    double maxSpeed;       // максимальная скорость

public:
    groundEquip();                       // конструктор без параметров
    groundEquip(string, double, double); // конструктор с параметрами для базавого класс
    ~groundEquip();                      // деструктор

    string GetMake();     // получить марку
    double GetCapacity(); // получить обьем двигателя
    double GetSpeed();    // получить скорость

    virtual void printName();        // вывести имя класса
    virtual void printInformation(); // вывести всю информацию об объекте

    virtual void toStart() = 0; // метод завести
    virtual void toRide() = 0;  // метод поехать
    virtual void toFill() = 0;  // метод заправить

    friend istream &operator>>(istream &, groundEquip &); // перегрузка оператора ввода
};

class Auto : public groundEquip // класс наследник
{
    string typeBodie; // тип кузова

public:
    Auto();                               // констурктор
    Auto(string, double, double, string); // конструктор с параметрами
    ~Auto();                              // деструктор

    void printName() override;        // вывод имени класса
    void printInformation() override; // вывод информации об объекте этого класса

    void toStart() override;                                                       // завести
    void toRide() override;                                                        // поехать
    void toFill() override;                                                        // заправить
    void breakRule() { cout << "The driver violated the traffic rules" << endl; }; // нарушить правила

    friend istream &operator>>(istream &, Auto &); // перегрузка оператора ввода
};

class Tank : public groundEquip // класс наследник танк
{
    string typeTank; // тип танка

public:
    Tank();                               // конструктор без параметров
    Tank(string, double, double, string); // конструктор с параметрами
    ~Tank();                              // деструктор

    void printName() override;        // вывод имения класса
    void printInformation() override; // вывод всей информации об танке

    void toStart() override;                                // завести
    void toRide() override;                                 // проехать
    void toFill() override;                                 // заправить
    void toShoot() { cout << "Tank is shooting" << endl; }; // стрелять

    friend istream &operator>>(istream &, Tank &); // перегрузка оператора ввода
};

class electricScooter : public groundEquip // класс наследник электросамокат
{
    double sizeBattery; // размер батареи

public:
    electricScooter();                               // конструктор
    electricScooter(string, double, double, double); // конструктор с параметрами
    ~electricScooter();                              // деструктор

    void printName() override;        // вывод имени класса
    void printInformation() override; // вывод всей информации об электро самокате

    void toStart() override;                                            // завести
    void toRide() override;                                             // поехать
    void toFill() override;                                             // зарядить
    void toCrash() { cout << "A scooter crashed into a man" << endl; }; // врезаться

    friend istream &operator>>(istream &, electricScooter &);
};
#endif
