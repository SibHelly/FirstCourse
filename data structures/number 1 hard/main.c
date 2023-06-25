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

List *createList();             // �������� ����������� ������
DataType InputIndividual(void); // ���������� ����� ������ � ��������

void *addFront(List *, DataType);                              // �������� ������ � ������ ����������� ������
void *addBack(List *, DataType);                               // �������� � ����� ������
void *addOrdered(List *, DataType, int (*)(Node *, DataType)); // ������������� ������ ��������� � ������(��� �������� �������������� ��������, ��������������� �� �������� �����)

int sortName(Node *, DataType);  // ���������� �� �����
int sortArea(Node *, DataType);  // ���������� �� �������� ��������� ����
int sortMoney(Node *, DataType); // ���������� �� ������� �� ���� �� ���� ����
int sortCount(Node *, DataType); // ���������� �� ���������� �������� � �������
int sortNumber(Node *, DataType);

List *createSortedList(List *, int (*)(Node *, DataType)); // �������� ���������������� ������ �� ��������� ����

void showNode(Node *);       // ����� ����� ������ ����������� ������
void showList(List *);       // ������������ ����� ����������� ������ � ������ �������
void showListInvert(List *); // ������������ ����� ����������� ������ � �������� �������

List *readFile(char *);        // ������ ������� �� ����� � ���������� ������
int writeFile(char *, List *); // ������ ������� ����������� ������ � �������� ����
void Search(List *);           // ������� ������ (���������� �������� ������������� ����, ��� ����� ������ �� ���� ��� ���� �������� ������������ ��������� ����)
void deleteList(List *);       // ������� �������� ������

int nodeToDelete(char *, Node *); // ������� ��� ������ ������ ��� �������� ���������� ������ � ����� ������ ����������� ������
void deleteNode(List *, Node *);  // ������� ���� �������� ������
void del(Node *, List *);         // �������� ������
Node *findNode(List *);           // ����� ������ ��� ��������

int main(int argc, char *argv[])
{
    setlocale(LC_ALL, "");
    char filename[50];
    int menu, variant;
    List *zoo = createList();
    List *list;
    puts("������� ��� �����");
    gets(filename);
    zoo = readFile(filename);
    do
    {
        system("cls");
        puts("1. �������� ��������");
        puts("2. �������� ������");
        puts("3. �����");
        puts("4. �������");
        puts("5. �����");
        scanf("%d%*c", &menu);
        switch (menu)
        {
        case 1:
        {
            do
            {
                system("cls");
                puts("1. �������� � ������");
                puts("2. �������� � �����");
                puts("3. ��������� � ����");
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
                puts("1. ������� ������ ��� ����������");
                puts("2. ������� ������ �������� ������������ ����� �� � �� �");
                puts("3. ������� ������ �������� ������������ ��������� ���� �� � �� �");
                puts("4. ������� ������ �������� ������������ ���������� �������� �� ������������");
                puts("5. ������� ������ �������� ������������ ������� �� ���� �� ������������");
                puts("6. ������� ������ �������� ������������ ����� �� � �� �");
                puts("7. ������� ������ �������� ������������ ��������� ���� �� � �� �");
                puts("8. ������� ������ �������� ������������ ���������� �������� �� ��������");
                puts("9. ������� ������ �������� ������������ ������� �� ���� �� ��������");
                puts("10. ������� ������ �������� ��������������� �� ������ �������");
                puts("11. ������� ������ ��� ���������� � �������� �������");
                puts("12. ������� � ����");
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
        puts("���� ��������");
    else
        puts("���� �� ��������");
    deleteList(zoo);
    return 0;
}

List *createList()
{
    List *temp = (List *)malloc(sizeof(List));
    if (!temp)
    {
        puts("������ ��������� ������");
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
    puts("�������� ���������");
    // gets(individual.name);
    fgets(individual.name, 22, stdin);
    ptmp = strchr(individual.name, '\n');
    if (ptmp)
        *ptmp = '\0';
    else
        while (getchar() != '\n')
            ;
    puts("�������� ��������� ����");
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
        puts("������� �� ���� �� ���� ����");
        scanf("%f", &individual.money);
    } while (individual.money < 0);
    // scanf("%f", &individual.money);
    do
    {
        puts("���������� �������� ����� ����");
        scanf("%d", &individual.count);
    } while (individual.count <= 0);
    do
    {
        puts("���� �� ����� �������? (y/n)");
        getchar();
        individual.numberPlace.Val = getchar();
    } while (individual.numberPlace.Val != 'y' && individual.numberPlace.Val != 'Y' && individual.numberPlace.Val != 'n' && individual.numberPlace.Val != 'N');
    if (individual.numberPlace.Val == 'y' || individual.numberPlace.Val == 'Y')
    {
        do
        {
            puts("������� ����� �������");
            scanf("%d", &individual.numberPlace.number);
        } while (individual.numberPlace.number < 0);
    }
    getchar();
    puts("���������� � �������� ���������");
    puts("��� �������� � ���� ������� ����� �������");
    getchar();
    return individual;
}
// �������� � ������
void *addFront(List *list, DataType individual)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (!newNode)
    {
        puts("������ ��������� ������");
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
// �������� � �����
void *addBack(List *list, DataType individual)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (!newNode)
    {
        puts("������ ��������� ������");
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
// ���������� �� �������� �����
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
// �������� ���������������� ������
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
// ������������� ���������� �� ��������� ����
void *addOrdered(List *list, DataType data, int (*sort)(Node *cur, DataType data))
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (!newNode)
    {
        puts("������ ��������� ������");
        exit(-1);
    }
    newNode->next = NULL;
    newNode->prev = NULL;
    Node *cur = list->head, *previous = NULL;
    while (cur) // ���� ����� ��� �������
    {
        if (sort(cur, data)) // ���� ���� �������� ����� ��������
        {
            previous = cur;
            cur = cur->next;
        }
        else // ���� �� ��������
        {
            cur = previous;
            break;
        }
    }
    if (cur) // ����  �� ������ �������
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
    puts("�������� ���������");
    printf("%s\n", data->individual.name);
    puts("�������� ��������� ����");
    printf("%s\n", data->individual.area);
    puts("������� �� ���� �� ���� ����");
    printf("%.2f\n", data->individual.money);
    puts("���������� ����� ���������");
    printf("%d\n", data->individual.count);
    puts("����� �������");
    data->individual.numberPlace.Val == 'n' ? printf("%s\n", "���") : printf("%d\n", data->individual.numberPlace.number);
}
// ����� ������ ��� ��������
Node *findNode(List *list)
{
    system("cls");
    char name[30];
    Node *temp = list->head;
    Node *del = NULL;
    int count = 0;
    puts("������� �������� ��������� ��� ��������");
    fgets(name, 30, stdin);
    {
        char *ptmp = strchr(name, '\n');
        if (ptmp)
            *ptmp = '\0';
        else
            while (getchar() != '\n')
                ;
    }
    while (temp) // ����� �������� ��� ��������
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
// ��������� ��� ������ ��������
int nodeToDelete(char *name, Node *temp)
{
    return !strcmp(name, temp->individual.name);
}
// ���� �������� ������
void deleteNode(List *list, Node *delNode)
{
    char yes;
    system("cls");
    if (list->head == NULL)
    {
        puts("������ ����");
        puts("��� �������� � ���� ������� Enter");
        getchar();
        return;
    }
    if (delNode == NULL)
    {
        puts("��� �������� �� ���� �������");
        puts("��� �������� � ���� ������� Enter");
        getchar();
        return;
    }
    else
    {
        showNode(delNode);
        puts("������� �������� �� ������?(y/n)");
        do
        {
            yes = getchar();
            getchar();
        } while (yes != 'y' && yes != 'Y' && yes != 'n' && yes != 'N');
        if (yes == 'y' || yes == 'Y')
        {
            del(delNode, list);
            puts("�������");
        }
        else
        {
            puts("�������� ��������");
        }
    }
    puts("��� �������� � ���� ������� Enter");
    getchar();
    return;
}
// �������� ������
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
// ����� � ������ �������
void showList(List *list)
{
    system("cls");
    Node *temp = list->head;
    char yes;
    int n = 0, str = 1, k = 0, i, l, size = list->size, nStr;
    if (temp == NULL)
    {
        puts("������ ����");
        puts("��� �������� � ���� ������� Enter");
        getchar();
        return;
    }
    while (n <= 0)
    {
        system("cls");
        printf("������� ���������� ������� �� ��������: ");
        scanf("%d", &n);
        if (n > 0)
        {
            getchar();
            puts("��� ��������� ������� Enter");
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
    puts("|  N |    �������� ���������    |    ��������� ����    |         ������� �� ����        |   ���������� ��������   |   ����� �������   |");
    puts("---------------------------------------------------------------------------------------------------------------------------------------");
    while (temp)
    {
        printf("|%3d |%-26.26s|%-22.22s|%32.2f|%25.d|", ++k, temp->individual.name, temp->individual.area, temp->individual.money, temp->individual.count);
        temp->individual.numberPlace.Val == 'n' ? printf("%19s|\n", "���") : printf("%19.d|\n", temp->individual.numberPlace.number);
        temp = temp->next;
        if (k % n == 0 && str == 1 && size > n)
        {
            puts("---------------------------------------------------------------------------------------------------------------------------------------");
            printf("                                                                 %d                                                           \n", str);
            puts("������ ��� �����? (f/e)");
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
                puts("|  N |    �������� ���������    |    ��������� ����    |         ������� �� ����        |   ���������� ��������   |   ����� �������   |");
                puts("---------------------------------------------------------------------------------------------------------------------------------------");
            }
        }
        if (k % n == 0 && str > 1 && k > n && str < nStr && k < size)
        {
            puts("---------------------------------------------------------------------------------------------------------------------------------------");
            printf("                                                                 %d                                                           \n", str);
            puts("������ ��� ����� ��� �����? (f/b/e)");
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
                puts("|  N |    �������� ���������    |    ��������� ����    |         ������� �� ����        |   ���������� ��������   |   ����� �������   |");
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
                puts("|  N |    �������� ���������    |    ��������� ����    |         ������� �� ����        |   ���������� ��������   |   ����� �������   |");
                puts("---------------------------------------------------------------------------------------------------------------------------------------");
            }
        }
        if (k == size)
        {
            puts("---------------------------------------------------------------------------------------------------------------------------------------");
            printf("                                                                 %d                                                           \n", str);
            if (n < size)
            {
                puts("����� ��� �����? (b/e)");
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
                    puts("|  N |    �������� ���������    |    ��������� ����    |         ������� �� ����        |   ���������� ��������   |   ����� �������   |");
                    puts("---------------------------------------------------------------------------------------------------------------------------------------");
                }
            }
            if (n >= size)
            {
                puts("�����? (e)");
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
// ����� � �������� �������
void showListInvert(List *list)
{
    system("cls");
    Node *temp = list->tail;
    char yes;
    int n = 0, str = 1, k = 0, i, l, size = list->size, nStr;
    if (temp == NULL)
    {
        puts("������ ����");
        puts("��� �������� � ���� ������� Enter");
        getchar();
        return;
    }
    while (n <= 0)
    {
        system("cls");
        printf("������� ���������� ������� �� ��������: ");
        scanf("%d", &n);
        if (n > 0)
        {
            getchar();
            puts("��� ��������� ������� Enter");
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
    puts("|  N |    �������� ���������    |    ��������� ����    |         ������� �� ����        |   ���������� ��������   |   ����� �������   |");
    puts("---------------------------------------------------------------------------------------------------------------------------------------");
    while (temp)
    {
        printf("|%3d |%-26.26s|%-22.22s|%32.2f|%25.d|", ++k, temp->individual.name, temp->individual.area, temp->individual.money, temp->individual.count);
        temp->individual.numberPlace.Val == 'n' ? printf("%19s|\n", "���") : printf("%19.d|\n", temp->individual.numberPlace.number);
        temp = temp->prev;
        if (k % n == 0 && str == 1 && size > n)
        {
            puts("---------------------------------------------------------------------------------------------------------------------------------------");
            printf("                                                                 %d                                                           \n", str);
            puts("������ ��� �����? (f/e)");
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
                puts("|  N |    �������� ���������    |    ��������� ����    |         ������� �� ����        |   ���������� ��������   |   ����� �������   |");
                puts("---------------------------------------------------------------------------------------------------------------------------------------");
            }
        }
        if (k % n == 0 && str > 1 && k > n && str < nStr && k < size)
        {
            puts("---------------------------------------------------------------------------------------------------------------------------------------");
            printf("                                                                 %d                                                           \n", str);
            puts("������ ��� ����� ��� �����? (f/b/e)");
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
                puts("|  N |    �������� ���������    |    ��������� ����    |         ������� �� ����        |   ���������� ��������   |   ����� �������   |");
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
                puts("|  N |    �������� ���������    |    ��������� ����    |         ������� �� ����        |   ���������� ��������   |   ����� �������   |");
                puts("---------------------------------------------------------------------------------------------------------------------------------------");
            }
        }
        if (k == size)
        {
            puts("---------------------------------------------------------------------------------------------------------------------------------------");
            printf("                                                                 %d                                                           \n", str);
            if (n < size)
            {
                puts("����� ��� �����? (b/e)");
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
                    puts("|  N |    �������� ���������    |    ��������� ����    |         ������� �� ����        |   ���������� ��������   |   ����� �������   |");
                    puts("---------------------------------------------------------------------------------------------------------------------------------------");
                }
            }
            if (n >= size)
            {
                puts("�����? (e)");
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
// ������ �����
List *readFile(char *filename)
{
    FILE *f;
    DataType individual;
    List *list = createList();
    Node *cur;
    if ((f = fopen(filename, "rb")) == NULL)
    {
        perror("������ �������� �����");
        puts("��� ����������� ������� Enter");
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
// ������ � ����
int writeFile(char *filename, List *list)
{
    FILE *f;
    Node *temp = list->head;
    if ((f = fopen(filename, "wb")) == NULL)
    {
        perror("������ �������� �����");
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
// ���� ������
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
        puts("������ ����");
        puts("��� �������� � ���� ������� Enter");
        while (getchar() != '\n')
            ;
        return;
    }
    do
    {
        puts("1. ����� ���������� �������� ������ ����");
        puts("2. ����� ������� �� ���� �� ����� ��� ���� �������� ������������� ����");
        puts("3. ������� � ����");
        scanf("%d%*c", &menu);
        switch (menu)
        {
        case 1:
        {
            puts("������� ��� ��������� ��� ������");
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
                printf("���������� �������� ����� ����: %d\n", k);
            else
                puts("������ ��������� ���");
            puts("��� �������� � ���� ������� Enter");
            while (getchar() != '\n')
                ;
            return;
        }
        case 2:
        {
            puts("������� �������� ��������� ���� ��� ������ ������ �� ���� ��� ���� �� �������� �� �����");
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
                printf("������ �� ���� �� ���� ����� ��� ���� �������� ���� ��������� ����: %.2f\n", money);
            else
                puts("������ ��������� ���� �� �������");
            puts("��� �������� � ���� ������� Enter");
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
