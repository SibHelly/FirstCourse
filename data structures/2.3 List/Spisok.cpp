#ifndef Spisok_CPP
#define Spisok_CPP
#include "spisok.h"
#include "func.h"
#include <string>
using namespace std;

// функции списка
// конструткор списка без параметров
spis::spis()
{
    this->head = this->tail = NULL;
}
// проверкак списка на пустоту
bool spis::isEmpty()
{
    return (!head);
}
// деструктор списка
spis::~spis()
{
    // cout << "Destructor spis" << endl;
    while (head != NULL)
    {
        deleteHead();
    }
    head = NULL;
}
// добавление элемента в конец односвязного списка
void spis::addBack(short int x)
{
    Node *newNode = new (nothrow) Node(x);
    if (isEmpty())
        head = newNode;
    if (tail != NULL)
        tail->next = newNode;
    tail = newNode;
}
// показ списка
void spis::showSpis()
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
// проверка на наличие заданного элемента в списке
bool spis::findThis(int x)
{
    Node *temp = head;
    bool flag = false;
    while (temp != NULL)
    {
        if (temp->data == x)
            flag = true;
        temp = temp->next;
    }
    return flag;
}
// удаление элемента с головы односвзяного списка
void spis::deleteHead()
{
    if (isEmpty()) // если список пуст
        return;
    if (head == tail) // если один элемент
    {
        delete tail;
        head = tail = NULL;
        return;
    }
    // если не один
    Node *temp = head;
    head = temp->next;
    delete temp;
}

// функции создания графа
Graf::Graf(int V) // конструтор создания графа с параметром
{
    this->numberVerties = V;
    if (!graf)
    {
        cout << "Ошибка выделения памяти" << endl;
        return;
    }
}
// конструктор графа без параметров
Graf::Graf()
{
    this->numberVerties = 0;
    graf = NULL;
}
// конструктор копирования
Graf::Graf(const Graf &x)
{
    this->numberVerties = x.numberVerties;                // присваиваем количество вершин
    this->graf = new (nothrow) spis[this->numberVerties]; // выделяем память под массив списков
    if (!this->graf)
    {
        cout << "Ошибка выделения памяти" << endl;
        this->graf = NULL;
        return;
    }
    for (int i = 0; i < this->numberVerties; i++) // заполняем все односвязные спсики
    {
        Node *temp = x.graf[i].head; // первый элемент односвязного спсика
        while (temp != NULL)         // пока есть элементы копируем
        {
            this->graf[i].addBack(temp->data);
            temp = temp->next;
        }
    }
}
// функции для чтения графа из файла и его заполнения и для удаления
// деструктор графа
Graf::~Graf()
{
    for (int i = 0; i < numberVerties + 1; i++) // проходим по всем элементам массива
    {
        graf[i].head = NULL;
    }
    delete[] this->graf; // удаляем граф
    graf = NULL;
}

Graf &Graf::operator=(const Graf &x)
{
    this->numberVerties = x.numberVerties;                // присваиваем количество вершин
    this->graf = new (nothrow) spis[this->numberVerties]; // выделяем память под массив списков
    if (!this->graf)
    {
        cout << "Ошибка выделения памяти" << endl;
        this->graf = NULL;
        return *this;
    }
    for (int i = 0; i < this->numberVerties; i++) // заполняем все односвязные спсики
    {
        Node *temp = x.graf[i].head;
        while (temp != NULL)
        {
            this->graf[i].addBack(temp->data);
            temp = temp->next;
        }
    }
    return *this;
}
// показ графа
void Graf::showGraf()
{
    if (graf != NULL)
        for (int i = 0; i < numberVerties; i++)
        {
            cout << i << " :";
            graf[i].showSpis();
        }
    else
        cout << "Граф пуст" << endl;
}
// проверка строки матрицы на пустоту
bool Empty(int *arr, int count)
{
    for (int i = 0; i < count; i++)
        if (arr[i] != 0)
            return false;
    return true;
}

Graf::Graf(ifstream &in)
{
    if (in.is_open()) // если файл есть
    {
        in.seekg(0, ios::beg);
        string s;
        int x;
        in >> x;                   // считываем тип представления графа в файле
        in >> this->numberVerties; // считываем количество вершин графа
        getline(in, s);            // получаем строку и очищаем ее
        s.clear();
        if (x == 0)
        {
            cout << "В файле матрица смежности" << endl;
            this->graf = new (nothrow) spis[this->numberVerties]; // выделяем память
            if (!this->graf)
            {
                cout << "Ошибка выделения памяти" << endl;
                return;
            }
            for (int i = 0; i < this->numberVerties; i++) // начинаем построчно считывать файл и заполнять односвязные списки
            {
                getline(in, s);                   // считали строку
                int countS = this->numberVerties; // количество чисел в строке матрицы смежности
                int *arr = strToArr(s, countS);   // получаем массив чисел из строки
                if (arr == NULL)
                {

                    cout << "Ошибка выделения памяти" << endl;
                    return;
                }
                if (Empty(arr, numberVerties)) // если все нули значит нет смежных вершин
                {
                    this->graf[i].addBack(-1);
                }
                else // если есть смежные вершины
                {
                    for (int j = 0; j < countS; j++)
                    {
                        if (arr[j] == 1 && !this->graf[i].findThis(j)) // если 1 в строке из матрицы и этого элемента еще нет в односвязном списке
                            this->graf[i].addBack(j);                  // добовляем в конец
                    }
                }
                s.clear();    // очищаем строку
                delete[] arr; // очищаем память
            }
        }
        if (x == 1) // если в файле список смежности
        {
            cout << "В файле список смежных вершин" << endl;
            this->graf = new (nothrow) spis[this->numberVerties]; // выделяем память
            if (!this->graf)
            {
                cout << "Ошибка выделения памяти" << endl;
                return;
            }
            for (int i = 0; i < this->numberVerties; i++) // заполняем списки
            {
                getline(in, s);
                int countS = search_count(s);   // получаем количество смежных вершин
                int *arr = strToArr(s, countS); // получем массив из строки
                if (arr == NULL)
                {
                    cout << "Ошибка выделения памяти" << endl;
                    return;
                }
                if (arr[0] == -1) // если -1 , то нет смежных вершин
                {
                    this->graf[i].addBack(-1);
                }
                else // если есть смежные вершины
                {
                    for (int j = 0; j < countS; j++)
                    {
                        if (!this->graf[i].findThis(arr[j])) // если элемента из массива еще нет в односвязном списке добавляем его
                            this->graf[i].addBack(arr[j]);
                    }
                }
                s.clear();    // очищаем
                delete[] arr; // удаляем массив
            }
        }
    }
    else // если такого файла нет
    {
        cout << "Файл не найден" << endl;
    }
}

Node *findTodel(spis &x, int k) // поиск указателя на удаляемый элемент(то есть предшествующий удаляемому)
{
    Node *temp = x.head;
    bool flag = true;
    while (temp != NULL)
    {
        if (temp->data == k) // если первый элемент
            break;
        if (temp->next->data == k) // если следующий элемент односвязного спсика равен ключу, то прекращаем поиск нашли нужное
        {
            break;
        }
        temp = temp->next;
    }
    return temp;
}
// удаление из односвязного списка с произвольной позиции
void delFrom(spis &x, int k)
{
    Node *node = findTodel(x, k); // находим предшествующий элемент для удаляемого
    Node *temp;
    bool flag = true;
    if (x.head->data == k && x.head == x.tail) // если один элемент то просто удаляем его
    {
        flag = false;
        delete x.tail;
        x.head = x.tail = NULL;
    }
    if (x.head->data == k && x.head == node) // если нужный элемент первый
    {
        flag = false;
        temp = node;
        x.head = node = node->next;
        delete temp;
    }
    if (temp = node->next) // если не в начале
    {
        if (flag == true) // если не последний
        {
            node->next->data = node->next->data; // изменяем значение элемента
            node->next = node->next->next;       // переносим указатель на следующий после удаляемого
            delete temp;
        }
    }
    else // если в конце
    {
        if (flag == true)
        {
            delete node;
            node = NULL;
        }
    }
}

bool findK(spis &x, int k) // проверяем на наличе элемента в односвязном списке
{
    Node *temp = x.head;
    while (temp != NULL)
    {
        if (temp->data == k)
            return true;
        temp = temp->next;
    }
    return false;
}
// узнаем количество элементов в односвязном спсике
int countEl(spis &x)
{
    int count = 0;
    Node *temp = x.head;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

void newInd(spis &x, int k) // изменяем индексы после удаления
{
    Node *temp = x.head;
    while (temp != NULL)
    {
        if (temp->data != -1 && temp->data >= k) // если есть смежные вершины и смежная вершина больше или равна удаляемой то необходимо изменить ее индексы
            temp->data--;                        // уменьшаем индекс на 1
        temp = temp->next;
    }
}

void delVert(Graf &x, int k)
{
    int j, count = 0;
    spis *temp;
    int n = x.numberVerties - 1;
    for (j = 0; j < n; j++) // удаление элемнта из массива
    {
        temp = &x.graf[j];            // получаем адрес односвязного списка
        if (findK(*temp, k) && j < k) // если есть элемент в строке и эту строку не надо переносить при удалении
        {
            if (countEl(*temp) != 1) // если не один элемент
            {
                delFrom(*temp, k);
            }
            else // если один елемент, то делаем вершину без смежных
            {
                delFrom(*temp, k);
                x.graf[j].addBack(-1);
            }
        }
        if (j >= k) // если надо удалять и перетаскивать элементы
        {
            x.graf[j] = x.graf[j + 1]; // переносим удаляемый элемент
            temp = &x.graf[j];         // получаем адрес односвязного списка
            if (findK(*temp, k))       // если есть элемент который надо удалить
            {
                if (countEl(*temp) > 1) // если не один элемент
                {
                    delFrom(*temp, k);
                }
                else // если рдин элемент то делаем его без смежных вершин
                {
                    x.graf[j].deleteHead();
                    x.graf[j].addBack(-1);
                }
            }
        }
    }
    x.numberVerties--;                    // уменьшаем размер графа
    for (j = 0; j < x.numberVerties; j++) // пересчитываем индексы для всех вершин
    {
        temp = &x.graf[j];
        newInd(*temp, k);
    }
}

#endif
