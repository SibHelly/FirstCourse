#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>
#include <windows.h>

struct animal
{
    char name[30];
    char area[30];
    float money;
    unsigned int count;
    union numberPlace
    {
        char Val;
        int number;
    } numberPlace;
};

typedef struct animal DataType;

typedef struct Node
{
    DataType individual;
    struct Node *next, *prev;
} Node;

typedef struct List
{
    Node *head, *tail;
    int size;
} List;

List *createList();             // создание двусвязного списка
DataType InputIndividual(void); // заполнение одной записи о животном

void *addFront(List *, DataType);                              // добавить запись в начало двусвязного списка
void *addBack(List *, DataType);                               // добавить в конец списка
void *addOrdered(List *, DataType, int (*)(Node *, DataType)); // упорядоченная запись элементов в список(для создания дополнительных списоков, отсортированных по ключевым полям)

int sortName(Node *, DataType);  // сортировка по имени
int sortArea(Node *, DataType);  // сортировка по названию природной зоны
int sortMoney(Node *, DataType); // сортировка по затратм на корм за один день
int sortCount(Node *, DataType); // сортировка по количеству животных в вольере
int sortNumber(Node *, DataType);

List *createSortedList(List *, int (*)(Node *, DataType)); // создание отсортированного списка по ключевому полю

void showNode(Node *);       // показ одной записи двусвязного списка
void showList(List *);       // постраничный вывод двусвязного списка в прямом порядке
void showListInvert(List *); // постраничный вывод двусвязного списка в обратном порядке

List *readFile(char *);        // чтение записей из файла в двусвязный список
int writeFile(char *, List *); // запись записей двусвязного списка в бинарный файл
void Search(List *);           // функция поиска (количество животных определенного вида, или поиск затрат на корм для всех животной определенной природной зоны)
void deleteList(List *);       // функция очищения памяти

int nodeToDelete(char *, Node *); // функция для поиска записи для удаления сравнивает строку с полем записи двусвязного списка
void deleteNode(List *, Node *);  // функция меню удаления записи
void del(Node *, List *);         // удаление записи
Node *findNode(List *);           // поиск записи для удаления

int main(int argc, char *argv[])
{
    setlocale(LC_ALL, "");
    char filename[50];
    int menu, variant;
    List *zoo = createList();
    List *list;
    puts("Введите имя файла");
    gets(filename);
    zoo = readFile(filename);
    do
    {
        system("cls");
        puts("1. Добавить животное");
        puts("2. Показать список");
        puts("3. Поиск");
        puts("4. Удалить");
        puts("5. Выход");
        scanf("%d%*c", &menu);
        switch (menu)
        {
        case 1:
        {
            do
            {
                system("cls");
                puts("1. Добавить в начало");
                puts("2. Добавить в конец");
                puts("3. Вернуться в меню");
                scanf("%d%*c", &variant);
                switch (variant)
                {
                case 1:
                {
                    addFront(zoo, InputIndividual());
                    break;
                }
                case 2:
                {
                    addBack(zoo, InputIndividual());
                    break;
                }
                }
            } while (variant != 3);
            break;
        }
        case 2:
        {
            do
            {
                system("cls");
                puts("1. Вывести списко без сортировки");
                puts("2. Вывести список животных отсортировав имена от А до Я");
                puts("3. Вывести список животных отсортировав природные зоны от А до Я");
                puts("4. Вывести список животных отсортировав количество животных по возврастанию");
                puts("5. Вывести список животных отсортировав затраты на корм по возврастанию");
                puts("6. Вывести список животных отсортировав имена от Я до А");
                puts("7. Вывести список животных отсортировав природные зоны от Я до А");
                puts("8. Вывести список животных отсортировав количество животных по убыванию");
                puts("9. Вывести список животных отсортировав затраты на корм по убыванию");
                puts("10. Вывести список животных отсортированный по номеру вольера");
                puts("11. Вывести список без сортировок в обратном порядке");
                puts("12. Обратно в меню");
                scanf("%d%*c", &variant);
                switch (variant)
                {
                case 1:
                {
                    showList(zoo);
                    break;
                }
                case 2:
                {
                    list = createSortedList(zoo, sortName);
                    showList(list);
                    deleteList(list);
                    break;
                }
                case 3:
                {
                    list = createSortedList(zoo, sortArea);
                    showList(list);
                    deleteList(list);
                    break;
                }
                case 4:
                {
                    list = createSortedList(zoo, sortCount);
                    showList(list);
                    deleteList(list);
                    break;
                }
                case 5:
                {
                    list = createSortedList(zoo, sortMoney);
                    showList(list);
                    deleteList(list);
                    break;
                }
                case 6:
                {
                    list = createSortedList(zoo, sortName);
                    showListInvert(list);
                    deleteList(list);
                    break;
                }
                case 7:
                {
                    list = createSortedList(zoo, sortArea);
                    showListInvert(list);
                    deleteList(list);
                    break;
                }
                case 8:
                {
                    list = createSortedList(zoo, sortCount);
                    showListInvert(list);
                    deleteList(list);
                    break;
                }
                case 9:
                {
                    list = createSortedList(zoo, sortMoney);
                    showListInvert(list);
                    deleteList(list);
                    break;
                }
                case 10:
                {
                    list = createSortedList(zoo, sortNumber);
                    showListInvert(list);
                    deleteList(list);
                    break;
                }
                case 11:
                {
                    showListInvert(zoo);
                    break;
                }
                }
            } while (variant != 12);
            break;
        }
        case 3:
        {
            Search(zoo);
            break;
        }
        case 4:
        {
            deleteNode(zoo, findNode(zoo));
        }
        }
    } while (menu != 5);
    if (writeFile(filename, zoo))
        puts("Файл сохранен");
    else
        puts("Файл не сохранен");
    deleteList(zoo);
    return 0;
}

List *createList()
{
    List *temp = (List *)malloc(sizeof(List));
    if (!temp)
    {
        puts("Ошибка выделения памяти");
        exit(-1);
    }
    temp->head = temp->tail = NULL;
    temp->size = 0;
    return temp;
}

DataType InputIndividual(void)
{
    char *ptmp;
    DataType individual;
    puts("Название животного");
    // gets(individual.name);
    fgets(individual.name, 22, stdin);
    ptmp = strchr(individual.name, '\n');
    if (ptmp)
        *ptmp = '\0';
    else
        while (getchar() != '\n')
            ;
    puts("Название природной зоны");
    fgets(individual.area, 20, stdin);
    ptmp = strchr(individual.area, '\n');
    if (ptmp)
        *ptmp = '\0';
    else
        while (getchar() != '\n')
            ;
    // gets(individual.area);
    do
    {
        puts("Затраты на корм за один день");
        scanf("%f", &individual.money);
    } while (individual.money < 0);
    // scanf("%f", &individual.money);
    do
    {
        puts("Количество животных этого вида");
        scanf("%d", &individual.count);
    } while (individual.count <= 0);
    do
    {
        puts("Есть ли номер вольера? (y/n)");
        getchar();
        individual.numberPlace.Val = getchar();
    } while (individual.numberPlace.Val != 'y' && individual.numberPlace.Val != 'Y' && individual.numberPlace.Val != 'n' && individual.numberPlace.Val != 'N');
    if (individual.numberPlace.Val == 'y' || individual.numberPlace.Val == 'Y')
    {
        do
        {
            puts("Введите номер вольера");
            scanf("%d", &individual.numberPlace.number);
        } while (individual.numberPlace.number < 0);
    }
    getchar();
    puts("Информация о животном добавлена");
    puts("Для возврата в меню нажмите любую клавишу");
    getchar();
    return individual;
}
// добавить в начало
void *addFront(List *list, DataType individual)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (!newNode)
    {
        puts("Ошибка выделения памяти");
        exit(-1);
    }
    newNode->individual = individual;
    newNode->next = list->head;
    newNode->prev = NULL;

    if (list->head)
        list->head->prev = newNode;
    else
        list->tail = newNode;
    list->head = newNode;
    list->size++;
}
// добавить в конец
void *addBack(List *list, DataType individual)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (!newNode)
    {
        puts("Ошибка выделения памяти");
        exit(-1);
    }
    newNode->individual = individual;
    newNode->next = NULL;
    newNode->prev = list->tail;
    if (list->tail)
        list->tail->next = newNode;
    else
        list->head = newNode;
    list->tail = newNode;
    list->size++;
}
// сортировки по ключевым полям
int sortCount(Node *cur, DataType data)
{
    return cur->individual.count < data.count;
}

int sortMoney(Node *cur, DataType data)
{
    return cur->individual.money < data.money;
}

int sortName(Node *cur, DataType data)
{
    return strcmp(cur->individual.name, data.name) < 0;
}

int sortArea(Node *cur, DataType data)
{
    return strcmp(cur->individual.area, data.area) < 0;
}

int sortNumber(Node *cur, DataType data)
{
    if (cur->individual.numberPlace.Val == 'n')
        return 1;
    if (data.numberPlace.Val == 'n')
        return 0;
    return cur->individual.numberPlace.number < data.numberPlace.number;
}
// создание отсортированного списка
List *createSortedList(List *list, int (*sort)(Node *cur, DataType data))
{
    List *sortedList = createList();
    Node *cur = list->head;
    while (cur)
    {
        addOrdered(sortedList, cur->individual, sort);
        cur = cur->next;
    }
    return sortedList;
}
// упорядоченное добавление по ключевому полю
void *addOrdered(List *list, DataType data, int (*sort)(Node *cur, DataType data))
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (!newNode)
    {
        puts("Ошибка выделения памяти");
        exit(-1);
    }
    newNode->next = NULL;
    newNode->prev = NULL;
    Node *cur = list->head, *previous = NULL;
    while (cur) // ищем место для вставки
    {
        if (sort(cur, data)) // если надо вставить после текущего
        {
            previous = cur;
            cur = cur->next;
        }
        else // если до текущего
        {
            cur = previous;
            break;
        }
    }
    if (cur) // если  не первый элемент
    {
        newNode->individual = data;
        newNode->next = cur->next;
        cur->next = newNode;
        newNode->prev = cur;
        newNode->next->prev = newNode;
        list->size++;
    }
    else
    {
        if (previous)
            addBack(list, data);
        else
            addFront(list, data);
    }
}

void showNode(Node *data)
{
    puts("Название животного");
    printf("%s\n", data->individual.name);
    puts("Название природной зоны");
    printf("%s\n", data->individual.area);
    puts("Затраты на корм за один день");
    printf("%.2f\n", data->individual.money);
    puts("Количество этого животного");
    printf("%d\n", data->individual.count);
    puts("Номер вальера");
    data->individual.numberPlace.Val == 'n' ? printf("%s\n", "Нет") : printf("%d\n", data->individual.numberPlace.number);
}
// поиск записи для удаления
Node *findNode(List *list)
{
    system("cls");
    char name[30];
    Node *temp = list->head;
    Node *del = NULL;
    int count = 0;
    puts("Введите название животного для удаления");
    fgets(name, 30, stdin);
    {
        char *ptmp = strchr(name, '\n');
        if (ptmp)
            *ptmp = '\0';
        else
            while (getchar() != '\n')
                ;
    }
    while (temp) // поиск элемента для удаления
    {
        if (nodeToDelete(name, temp))
        {
            count++;
            del = temp;
            return del;
        }
        temp = temp->next;
    }
    if (count == 0)
        return del;
}
// сравнение при поиске удаления
int nodeToDelete(char *name, Node *temp)
{
    return !strcmp(name, temp->individual.name);
}
// меню удаления записи
void deleteNode(List *list, Node *delNode)
{
    char yes;
    system("cls");
    if (list->head == NULL)
    {
        puts("Список пуст");
        puts("Для возврата в меню нажмите Enter");
        getchar();
        return;
    }
    if (delNode == NULL)
    {
        puts("Это животное не было найдено");
        puts("Для возврата в меню нажмите Enter");
        getchar();
        return;
    }
    else
    {
        showNode(delNode);
        puts("Удалить животное из списка?(y/n)");
        do
        {
            yes = getchar();
            getchar();
        } while (yes != 'y' && yes != 'Y' && yes != 'n' && yes != 'N');
        if (yes == 'y' || yes == 'Y')
        {
            del(delNode, list);
            puts("Удалено");
        }
        else
        {
            puts("Удаление отменено");
        }
    }
    puts("Для возврата в меню нажмите Enter");
    getchar();
    return;
}
// удаление записи
void del(Node *del, List *list)
{
    if (del->prev)
        del->prev->next = del->next;
    if (del->next)
        del->next->prev = del;
    if (list->head == del)
        list->head = del->next;
    if (list->tail == del)
        list->tail = del->prev;
    list->size--;
    free(del);
}
// вывод в прямом порядке
void showList(List *list)
{
    system("cls");
    Node *temp = list->head;
    char yes;
    int n = 0, str = 1, k = 0, i, l, size = list->size, nStr;
    if (temp == NULL)
    {
        puts("Список пуст");
        puts("Для возврата в меню нажмите Enter");
        getchar();
        return;
    }
    while (n <= 0)
    {
        system("cls");
        printf("Введите количество записей на странице: ");
        scanf("%d", &n);
        if (n > 0)
        {
            getchar();
            puts("Для просмотра нажмите Enter");
            while (getchar() != '\n')
                ;
            system("cls");
            break;
        }
        else
        {
            fflush(stdin);
        }
    }
    nStr = size / n + 1;
    puts("|  N |    Название животного    |    Природная зона    |         Затраты на день        |   Количество животных   |   Номер вольера   |");
    puts("---------------------------------------------------------------------------------------------------------------------------------------");
    while (temp)
    {
        printf("|%3d |%-26.26s|%-22.22s|%32.2f|%25.d|", ++k, temp->individual.name, temp->individual.area, temp->individual.money, temp->individual.count);
        temp->individual.numberPlace.Val == 'n' ? printf("%19s|\n", "Нет") : printf("%19.d|\n", temp->individual.numberPlace.number);
        temp = temp->next;
        if (k % n == 0 && str == 1 && size > n)
        {
            puts("---------------------------------------------------------------------------------------------------------------------------------------");
            printf("                                                                 %d                                                           \n", str);
            puts("Вперед или выход? (f/e)");
            do
            {
                yes = getchar();
                getchar();
            } while (yes != 'F' && yes != 'f' && yes != 'e' && yes != 'E');
            if (yes == 'e' || yes == 'E')
                return;
            if (yes == 'f' || yes == 'F')
            {
                system("cls");
                str++;
                puts("|  N |    Название животного    |    Природная зона    |         Затраты на день        |   Количество животных   |   Номер вольера   |");
                puts("---------------------------------------------------------------------------------------------------------------------------------------");
            }
        }
        if (k % n == 0 && str > 1 && k > n && str < nStr && k < size)
        {
            puts("---------------------------------------------------------------------------------------------------------------------------------------");
            printf("                                                                 %d                                                           \n", str);
            puts("Вперед или назад или выход? (f/b/e)");
            do
            {
                yes = getchar();
                getchar();
            } while (yes != 'F' && yes != 'f' && yes != 'e' && yes != 'E' && yes != 'B' && yes != 'b');
            if (yes == 'e' || yes == 'E')
                return;
            if (yes == 'f' || yes == 'F')
            {
                system("cls");
                str++;
                puts("|  N |    Название животного    |    Природная зона    |         Затраты на день        |   Количество животных   |   Номер вольера   |");
                puts("---------------------------------------------------------------------------------------------------------------------------------------");
            }
            if (yes == 'b' || yes == 'B')
            {
                str--;
                system("cls");
                k -= 2 * n;
                for (i = 0; i < 2 * n; i++)
                    temp = temp->prev;
                if (temp == NULL)
                    temp = list->head;
                puts("|  N |    Название животного    |    Природная зона    |         Затраты на день        |   Количество животных   |   Номер вольера   |");
                puts("---------------------------------------------------------------------------------------------------------------------------------------");
            }
        }
        if (k == size)
        {
            puts("---------------------------------------------------------------------------------------------------------------------------------------");
            printf("                                                                 %d                                                           \n", str);
            if (n < size)
            {
                puts("Назад или выход? (b/e)");
                do
                {
                    yes = getchar();
                    getchar();
                } while (yes != 'b' && yes != 'B' && yes != 'e' && yes != 'E');
                if (yes == 'e' || yes == 'E')
                    return;
                if (yes == 'b' || yes == 'B')
                {
                    system("cls");
                    str--;
                    if (temp == NULL)
                        temp = list->tail;
                    l = k - n * str;
                    k = k - n - l;
                    for (i = 0; i < n + l; i++)
                        temp = temp->prev;
                    puts("|  N |    Название животного    |    Природная зона    |         Затраты на день        |   Количество животных   |   Номер вольера   |");
                    puts("---------------------------------------------------------------------------------------------------------------------------------------");
                }
            }
            if (n >= size)
            {
                puts("Выход? (e)");
                do
                {
                    yes = getchar();
                    getchar();
                } while (yes != 'e' && yes != 'E');
                if (yes == 'e' || yes == 'E')
                    return;
            }
        }
    }
}
// вывод в обратном порядке
void showListInvert(List *list)
{
    system("cls");
    Node *temp = list->tail;
    char yes;
    int n = 0, str = 1, k = 0, i, l, size = list->size, nStr;
    if (temp == NULL)
    {
        puts("Список пуст");
        puts("Для возврата в меню нажмите Enter");
        getchar();
        return;
    }
    while (n <= 0)
    {
        system("cls");
        printf("Введите количество записей на странице: ");
        scanf("%d", &n);
        if (n > 0)
        {
            getchar();
            puts("Для просмотра нажмите Enter");
            while (getchar() != '\n')
                ;
            system("cls");
            break;
        }
        else
        {
            fflush(stdin);
        }
    }
    nStr = size / n + 1;
    puts("|  N |    Название животного    |    Природная зона    |         Затраты на день        |   Количество животных   |   Номер вольера   |");
    puts("---------------------------------------------------------------------------------------------------------------------------------------");
    while (temp)
    {
        printf("|%3d |%-26.26s|%-22.22s|%32.2f|%25.d|", ++k, temp->individual.name, temp->individual.area, temp->individual.money, temp->individual.count);
        temp->individual.numberPlace.Val == 'n' ? printf("%19s|\n", "Нет") : printf("%19.d|\n", temp->individual.numberPlace.number);
        temp = temp->prev;
        if (k % n == 0 && str == 1 && size > n)
        {
            puts("---------------------------------------------------------------------------------------------------------------------------------------");
            printf("                                                                 %d                                                           \n", str);
            puts("Вперед или выход? (f/e)");
            do
            {
                yes = getchar();
                getchar();
            } while (yes != 'F' && yes != 'f' && yes != 'e' && yes != 'E');
            if (yes == 'e' || yes == 'E')
                return;
            if (yes == 'f' || yes == 'F')
            {
                system("cls");
                str++;
                puts("|  N |    Название животного    |    Природная зона    |         Затраты на день        |   Количество животных   |   Номер вольера   |");
                puts("---------------------------------------------------------------------------------------------------------------------------------------");
            }
        }
        if (k % n == 0 && str > 1 && k > n && str < nStr && k < size)
        {
            puts("---------------------------------------------------------------------------------------------------------------------------------------");
            printf("                                                                 %d                                                           \n", str);
            puts("Вперед или назад или выход? (f/b/e)");
            do
            {
                yes = getchar();
                getchar();
            } while (yes != 'F' && yes != 'f' && yes != 'e' && yes != 'E' && yes != 'B' && yes != 'b');
            if (yes == 'e' || yes == 'E')
                return;
            if (yes == 'f' || yes == 'F')
            {
                system("cls");
                str++;
                puts("|  N |    Название животного    |    Природная зона    |         Затраты на день        |   Количество животных   |   Номер вольера   |");
                puts("---------------------------------------------------------------------------------------------------------------------------------------");
            }
            if (yes == 'b' || yes == 'B')
            {
                str--;
                system("cls");
                k -= 2 * n;
                for (i = 0; i < 2 * n; i++)
                    temp = temp->next;
                if (temp == NULL)
                    temp = list->tail;
                puts("|  N |    Название животного    |    Природная зона    |         Затраты на день        |   Количество животных   |   Номер вольера   |");
                puts("---------------------------------------------------------------------------------------------------------------------------------------");
            }
        }
        if (k == size)
        {
            puts("---------------------------------------------------------------------------------------------------------------------------------------");
            printf("                                                                 %d                                                           \n", str);
            if (n < size)
            {
                puts("Назад или выход? (b/e)");
                do
                {
                    yes = getchar();
                    getchar();
                } while (yes != 'b' && yes != 'B' && yes != 'e' && yes != 'E');
                if (yes == 'e' || yes == 'E')
                    return;
                if (yes == 'b' || yes == 'B')
                {
                    system("cls");
                    str--;
                    if (temp == NULL)
                        temp = list->head;
                    l = k - n * str;
                    k = k - n - l;
                    for (i = 0; i < n + l; i++)
                        temp = temp->next;
                    puts("|  N |    Название животного    |    Природная зона    |         Затраты на день        |   Количество животных   |   Номер вольера   |");
                    puts("---------------------------------------------------------------------------------------------------------------------------------------");
                }
            }
            if (n >= size)
            {
                puts("Выход? (e)");
                do
                {
                    yes = getchar();
                    getchar();
                } while (yes != 'e' && yes != 'E');
                if (yes == 'e' || yes == 'E')
                    return;
            }
        }
    }
}
// чтение файла
List *readFile(char *filename)
{
    FILE *f;
    DataType individual;
    List *list = createList();
    Node *cur;
    if ((f = fopen(filename, "rb")) == NULL)
    {
        perror("Ошибка открытия файла");
        puts("Для продолжения нажмите Enter");
        getchar();
        return list;
    }
    if (fread(&individual, sizeof(individual), 1, f))
        addFront(list, individual);
    else
        return list;
    while (fread(&individual, sizeof(individual), 1, f))
    {
        addBack(list, individual);
    }
    fclose(f);
    return list;
}
// запись в файл
int writeFile(char *filename, List *list)
{
    FILE *f;
    Node *temp = list->head;
    if ((f = fopen(filename, "wb")) == NULL)
    {
        perror("Ошибка создания файла");
        getchar();
        return 0;
    }
    while (temp)
    {
        if (fwrite(&temp->individual, sizeof(DataType), 1, f))
            temp = temp->next;
        else
            return 0;
    }
    return 1;
}
// меню поиска
void Search(List *list)
{
    char name[30], area[30];
    float money;
    int count = 0, k = 0, menu;
    DataType individual;
    Node *temp = list->head;
    system("cls");
    if (temp == NULL)
    {
        puts("Список пуст");
        puts("Для возврата в меню нажмите Enter");
        while (getchar() != '\n')
            ;
        return;
    }
    do
    {
        puts("1. Найти количество животных одного вида");
        puts("2. Найти затраты на корм за месяц для всех животных определенного вида");
        puts("3. Обратно в меню");
        scanf("%d%*c", &menu);
        switch (menu)
        {
        case 1:
        {
            puts("Введите имя животного для поиска");
            fgets(name, 30, stdin);
            {
                char *ptmr = strchr(name, '\n');
                if (ptmr)
                    *ptmr = '\0';
                else
                    while (getchar() != '\n')
                        ;
            }
            while (temp)
            {
                if (!strcmp(name, temp->individual.name))

                    k = k + 1 * temp->individual.count;
                temp = temp->next;
            }
            if (k > 0)
                printf("Количество животных этого вида: %d\n", k);
            else
                puts("Такого животного нет");
            puts("Для возврата в меню нажмите Enter");
            while (getchar() != '\n')
                ;
            return;
        }
        case 2:
        {
            puts("Введите название природной зоны для поиска затрат на корм для всех ее животных за месяц");
            fgets(area, 30, stdin);
            {
                char *ptmr = strchr(area, '\n');
                if (ptmr)
                    *ptmr = '\0';
                else
                    while (getchar() != '\n')
                        ;
            }
            while (temp)
            {
                if (!strcmp(area, temp->individual.area))
                    money += temp->individual.money * 30 * temp->individual.count;
                temp = temp->next;
            }
            if (money > 0)
                printf("Затрты на корм за один месяц для всех животных этой природной зоны: %.2f\n", money);
            else
                puts("Данная природная зона не найдена");
            puts("Для возврата в меню нажмите Enter");
            while (getchar() != '\n')
                ;
            return;
        }
        case 3:
        {
            return;
        }
        }
    } while (menu != 3);
    return;
}

void deleteList(List *list)
{
    Node *temp;
    while (list->head)
    {
        temp = list->head;
        list->head = list->head->next;
        list->size--;
        free(temp);
    }
}
