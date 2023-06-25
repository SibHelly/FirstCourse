#include "class.h"
#include <cmath>
#include <limits>
// конструктор без параметров
groundEquip::groundEquip()
{
    cout << "Constructor without parametrs" << endl;
    make = "No make";
    engineCapacity = 0;
    maxSpeed = 0;
}
// конструктор с параметрами автомобиля
Auto::Auto(string a, double b, double c, string d) : groundEquip(a, b, c)
{
    cout << "Constructor for auto" << endl;
    typeBodie = d;
}
// конструктор с параметрами танка
Tank::Tank(string a, double b, double c, string d) : groundEquip(a, b, c)
{
    cout << "Constructor for tank" << endl;
    typeTank = d;
}
// конструктор с параметрами электросамоката
electricScooter::electricScooter(string a, double b, double c, double d) : groundEquip(a, b, c)
{
    cout << "Constructor for electric scooter" << endl;
    sizeBattery = d;
}
// конструктор без параметров для автомобиля
Auto::Auto() : groundEquip()
{
    cout << "Constructor for auto" << endl;
    typeBodie = "No type bodie";
}
// конструктор без параметров для танка
Tank::Tank() : groundEquip()
{
    cout << "Constructor for tank" << endl;
    typeTank = "No type tank";
}
// конструктор без параметров для электро самоката
electricScooter::electricScooter() : groundEquip()
{
    cout << "Constructor for electric scooter" << endl;
    sizeBattery = 1;
}
// деструктор
groundEquip::~groundEquip()
{
    cout << "Destructor" << endl;
}
// деструктор автомобиля
Auto::~Auto()
{
    cout << "Destructor Auto" << endl;
}
// деструтор танка
Tank::~Tank()
{
    cout << "Destructor Tank" << endl;
}
// деструтор электросамоката
electricScooter::~electricScooter()
{
    cout << "Destructor electricScooter" << endl;
}
// конструктор с параметрами для базавого класс
groundEquip::groundEquip(string a, double b, double c)
{
    cout << "Constructor with parametrs" << endl;
    make = a;
    engineCapacity = b;
    maxSpeed = c;
}
// получение имен классов и получение значений полей базового класса
string groundEquip::GetMake() { return make; }
double groundEquip::GetCapacity() { return engineCapacity; }
double groundEquip::GetSpeed() { return maxSpeed; }
void groundEquip::printName() { cout << "Ground equip" << endl; }
void Auto::printName() { cout << "Auto" << endl; }
void Tank::printName() { cout << "Tank" << endl; }
void electricScooter::printName() { cout << "Electric scooter" << endl; }
// пергрузка оператора ввода для базавого класса
istream &operator>>(istream &in, groundEquip &machine)
{
    cout << "Entering values " << endl;
    cout << "Input make" << endl;
    in >> machine.make;
    cout << "Input engine capasity" << endl;
    while (1)
    {
        in >> machine.engineCapacity;
        if (machine.engineCapacity > 0)
            break;
        else
        {
            cout << "Input correct value of engine capacity" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
    cout << "Input max speed" << endl;
    while (1)
    {
        in >> machine.maxSpeed;
        if (machine.maxSpeed > 0)
            break;
        else
        {
            cout << "Input correct value of max speed" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
    return in;
}
// перегрузка оператора ввода для класса авто наследника класса наземная техника
istream &operator>>(istream &in, Auto &car)
{
    in >> static_cast<groundEquip &>(car);
    cout << "Input type bodie of auto" << endl;
    in >> car.typeBodie;
    return in;
}
// перегрузка оператора присваивания для класса танк наследника класса наземная техника
istream &operator>>(istream &in, Tank &t)
{
    in >> static_cast<groundEquip &>(t);
    cout << "Input type of tank" << endl;
    in >> t.typeTank;
    return in;
}
// перегрузка оператора присваивания для класса электро самокат наследника класса наземная техника
istream &operator>>(istream &in, electricScooter &scooter)
{
    in >> static_cast<groundEquip &>(scooter);
    cout << "Input size of battery" << endl;
    while (1)
    {
        in >> scooter.sizeBattery;
        if (scooter.sizeBattery > 0)
            break;
        else
        {
            cout << "Input corect size of battery" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), ('\n'));
        }
    }
    return in;
}
// вывод информации для базавого класса
void groundEquip ::printInformation()
{
    const type_info &capacity = typeid(GetCapacity());
    const type_info &speed = typeid(GetSpeed());
    cout << "Outputing information about ground equipment" << endl;
    cout << "Type of ground equipment: "
         << "groundEquip;"
         << " Data type of make: "
         << "string"
         << "; Make: " << GetMake()
         << "; Data ype of engine capacity :" << capacity.name() << "; Engine capacity: " << GetCapacity()
         << " Data type of max speed: " << speed.name() << "; Max speed: " << GetSpeed() << endl;
}
// вывод информации об авто
void Auto ::printInformation()
{
    const type_info &capacity = typeid(GetCapacity());
    const type_info &speed = typeid(GetSpeed());
    cout << "Outputing information about auto" << endl;
    cout << "Type of ground equipment: "
         << "Auto;"
         << " Data type of make: "
         << "string;"
         << " Make: " << GetMake()
         << "; Data type of engine capacity :" << capacity.name() << "; Engine capacity: " << GetCapacity()
         << "; Data type of max speed: " << speed.name() << "; Max speed: " << GetSpeed() << " Data type of typeBodie: string; "
         << " Type of Bodie: " << typeBodie << endl;
}
// вывод информации об танке
void Tank ::printInformation()
{
    const type_info &capacity = typeid(GetCapacity());
    const type_info &speed = typeid(GetSpeed());
    cout << "Outputing information about tank" << endl;
    cout << "Type of ground equipment: "
         << "Tank;"
         << " Data type of make: "
         << "string;"
         << " Make: " << GetMake()
         << "; Data type of engine capacity :" << capacity.name() << "; Engine capacity: " << GetCapacity()
         << "; Data type of max speed: " << speed.name() << "; Max speed: " << GetSpeed() << "Data type of typeTank: string; "
         << "Type of tank: " << typeTank << endl;
}
// вывод информации об электросамокате
void electricScooter ::printInformation()
{
    cout << "Outputing information about electric scooter" << endl;
    cout << "Type of ground equipment: "
         << "electricScooter"
         << " Data type of make: "
         << "string"
         << " Make: " << GetMake()
         << " Data type of engine capacity :" << typeid(GetCapacity()).name() << " Engine capacity: " << GetCapacity()
         << " Data type of max speed: " << typeid(GetSpeed()).name() << " Max speed: " << GetSpeed() << "Data type of sizeBattery: " << typeid(sizeBattery).name()
         << ";Size battery: " << sizeBattery << endl;
}
// завести авто
void Auto::toStart()
{
    cout << "The car starts" << endl;
}
// завести танк
void Tank::toStart()
{
    cout << "The Tank starts" << endl;
}
// завести самокат
void electricScooter::toStart()
{
    cout << "The electric scooter starts" << endl;
}
// поехать на авто
void Auto::toRide()
{
    cout << "The car drove 120km " << endl;
}
// поехать на танке
void Tank::toRide()
{
    cout << "The tank drove 50km " << endl;
}
// поехать на электросамокате
void electricScooter::toRide()
{
    cout << "The electric scooter drove 20km " << endl;
}
// заправить авто
void Auto::toFill()
{
    cout << "Petrol is poured into the car" << endl;
}
// заправить танк
void Tank::toFill()
{
    cout << "Diesel is poured into the tank" << endl;
}
// зарядить электросамокат
void electricScooter::toFill()
{
    cout << "The scooter is charging" << endl;
}

/*Auto::Auto(string a, double b, double c, string d) : groundEquip(a, b, c)
{
    // cout << "Constructor without parametrs" << endl;
    typeBodie = d;
}

Tank::Tank(string a, double b, double c, string d) : groundEquip(a, b, c)
{
    typeTank = d;
}

electricScooter::electricScooter(string a, double b, double c, double d) : groundEquip(a, b, c)
{
    sizeBattery = d;
}

Tank::Tank() : groundEquip()
{
    typeTank = "Usual";
}

Tank::~Tank()
{
    cout << "Destructor" << endl;
}

electricScooter::electricScooter() : groundEquip()
{
    sizeBattery = 0;
}


void groundEquip::inputInformation(groundEquip &machine)
{
    cout << "Entering values" << endl;
    cout << "Input make" << endl;
    cin >> machine.make;
    cout << "Input engine capasity" << endl;
    while (1)
    {
        cin >> machine.engineCapacity;
        if (machine.engineCapacity > 0)
            break;
        else
        {
            cout << "Input correct value of engine capacity" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
    cout << "Input max speed" << endl;
    while (1)
    {
        cin >> machine.maxSpeed;
        if (machine.maxSpeed > 0)
            break;
        else
        {
            cout << "Input correct value of max speed" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}

void Auto::inputInformation(Auto &machine)
{
    inputInformation(machine);
    cout << "Input type bodie of auto" << endl;
    cin >> machine.typeBodie;
}

ostream &operator<<(ostream &out, groundEquip &equip)
{
    const type_info &make = typeid(equip.make);
    const type_info &capacity = typeid(equip.engineCapacity);
    const type_info &speed = typeid(equip.maxSpeed);
    out << "Type of make: " << make.name() << "Make: " << equip.make << "Type of engine capacity :" << capacity.name() << " Engine capacity: " << equip.engineCapacity << "Type of max speed: " << speed.name() << " Max speed: " << equip.maxSpeed;
    return out;
}

ostream &operator<<(ostream &out, Auto &car)
{
    const type_info &cl = typeid(car);
    const type_info &bodie = typeid(car.typeBodie);
    out << "Type of ground equipment: " << cl.name() << static_cast<groundEquip &>(car) << "Type of bodies: " << bodie.name() << "Bodie: " << car.typeBodie;
    return out;
}

ostream &operator<<(ostream &out, Tank &t)
{
    const type_info &cl = typeid(t);
    const type_info &typ = typeid(t.typeTank);
    out << "Type of ground equipment: " << cl.name() << static_cast<groundEquip &>(t) << "Type of tank: " << typ.name() << " Tank: " << t.typeTank;
    return out;
}

ostream &operator<<(ostream &out, electricScooter &scooter)
{
    const type_info &cl = typeid(scooter);
    const type_info &battery = typeid(scooter.sizeBattery);
    out << "Type of ground equipment: " << cl.name() << static_cast<groundEquip &>(scooter) << "Type of size battery: " << battery.name() << " Size of battery: " << scooter.sizeBattery;
    return out;

istream &operator>>(istream &in, Auto &car)
{
    in >> static_cast<groundEquip &>(car);
    cout << "Input type bodie of auto" << endl;
    in >> car.typeBodie;
    return in;
}

istream &operator>>(istream &in, Tank &t)
{
    in >> static_cast<groundEquip &>(t);
    cout << "Input type of tank" << endl;
    in >> t.typeTank;
    return in;
}

istream &operator>>(istream &in, electricScooter &scooter)
{
    in >> static_cast<groundEquip &>(scooter);
    cout << "Input size of battery" << endl;
    while (1)
    {
        in >> scooter.sizeBattery;
        if (scooter.sizeBattery > 0)
            break;
        else
        {
            cout << "Input corect size of battery" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), ('\n'));
        }
    }
    return in;
}*/