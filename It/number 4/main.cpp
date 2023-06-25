#include <iostream>
#include <fstream>
#include <string>
#include <locale.h>
#include <iterator>
#include <map>
#include <list>
#include <set>
#include <time.h>
#include <algorithm>
#include <random>
#include "dep\single_include\nlohmann\json.hpp"

using namespace std;
using json = nlohmann::json;

struct node
{
    string name;
    int standart;
    int secondory;
};

void to_json(json &j, const node &t)
{
    j = json{{"name", t.name}, {"standart", t.standart}, {"secondary", t.secondory}};
}

void from_json(json const &j, node &t)
{
    j.at("name").get_to(t.name);
    j.at("standart").get_to(t.standart);
    j.at("secondary").get_to(t.secondory);
}

void tokenize(string const &, const char, set<string> &);
void createDictionary(string const &, const char, map<char, int> &);
int GetRand(map<char, int> &);

int main()
{
    setlocale(LC_ALL, "Rus");
    srand(time(0));
    string s;
    list<node> spisok, newSpisok, spisokFile;
    set<string> words;
    map<char, int> dictionary;
    string str;
    node info, x, y, z;
    const char razdel = '-';
    int i, j, pr, n;
    json js{}, jf;
    ifstream in("test.txt");
    if (in.is_open())
    {
        getline(in, str);
    }
    else
    {
        cout << "���� �� ������" << endl;
    }
    in.close();
    cout << "���������" << endl;
    tokenize(str, razdel, words); // ������� ��������� �� ���� �����
    for (auto i : words)
        cout << i << endl;

    system("pause");
    cout << "�������" << endl;
    createDictionary(str, razdel, dictionary); // ������� ������� ����� -���������� � �����
    for (const auto &elem : dictionary)
    {
        cout << elem.first << " " << elem.second << endl;
    }

    system("pause"); // ������� ������ �� ������ ��������� � �������
    cout << "������" << endl;
    map<char, int>::iterator item = dictionary.begin();
    for (auto i : words)
    {
        info.name = i; // name
        for (j = 0, pr = 1; j < 3; j++)
        {
            pr *= GetRand(dictionary);
        }
        info.standart = pr; // standart
        item = dictionary.find(i[0]);
        info.secondory = item->second * item->second; // secondary
        spisok.push_back(info);
    }
    for (auto i : spisok) // ������� ���������� ������
        cout << "��������: " << i.name << "; �������� ��������: " << i.standart << "; ��������� ��������: " << i.secondory << endl;
    system("pause");

    // ��������� ������ �� �������� (Z to A)
    cout << "������ �� �������� ��������" << endl;
    n = spisok.size();
    node ar[n];
    j = 0;
    for (auto i : spisok)
        ar[j++] = i;
    sort(ar, ar + n, [](const node &x, const node &y)
         { return x.name[0] > y.name[0]; });
    spisok.clear();
    for (j = 0; j < n; j++)
        spisok.push_back(ar[j]);

    /*spisok.sort([](const node &x, const node &y)
                    { return x.name[0] > y.name[0]; });*/
    for (auto i : spisok) // ������� ������ ��������������� �� ��������
        cout << "��������: " << i.name << "; �������� ��������: " << i.standart << "; ��������� ��������: " << i.secondory << endl;
    system("pause");

    // ������� ����� ������ ������ �� ������� �� ��������� ���������� ����
    cout << "������ �� ���� ��������� �� ��������� ���������� ����" << endl;
    copy_if(spisok.begin(), spisok.end(), back_inserter(newSpisok), [](const node &x)
            { return x.name.length() % 2 != 0; });
    for (auto i : newSpisok) // ������� ������ ��������������� �� �������� � �� ���� �� ��������� ���������� ����
        cout << "��������: " << i.name << "; �������� ��������: " << i.standart << "; ��������� ��������: " << i.secondory << endl;
    system("pause");

    // ���������� ���������� ������ � json ����
    cout << "������ � ���� json" << endl;
    ofstream NewFile("file.json");
    for (auto i : newSpisok)
    {
        js.push_back(i);
    }
    NewFile << js;
    NewFile.close();
    system("pause");

    // ������ ������ �� json �����
    cout << "������ �� json � ������" << endl;
    fstream file("file.json");
    file >> jf;
    file.close();
    for (auto i : jf)
    {
        spisokFile.push_back(i);
    }

    system("pause");
    cout << "������ �� �����" << endl;
    for (auto i : spisokFile) // ������� ������ �� �����
        cout << "��������: " << i.name << "; �������� ��������: " << i.standart << "; ��������� ��������: " << i.secondory << endl;
    system("pause");

    // ����������� ������
    cout << "���������� ������" << endl;
    n = spisokFile.size();
    node arr[n];
    j = 0;
    for (auto i : spisokFile)
        arr[j++] = i;
    unsigned seed = std::chrono::system_clock::now()
                        .time_since_epoch()
                        .count();
    shuffle(arr, arr + n, default_random_engine(seed));
    spisokFile.clear();
    for (j = 0; j < n; j++)
        spisokFile.push_back(arr[j]);

    for (auto i : spisokFile) // ������� �������������� ������
        cout
            << "��������: " << i.name << "; �������� ��������: " << i.standart << "; ��������� ��������: " << i.secondory << endl;
    return 0;
}

int CountSymbol(string s, char symbol)
{
    int i, n = s.length(), count = 0;
    for (i = 0; i < n; i++)
        if (s[i] == symbol)
            count++;
    return count;
}

void tokenize(string const &str, const char delim, set<string> &out)
{
    // ������ ����� �� ������
    stringstream ss(str);
    string s;
    while (getline(ss, s, delim))
        out.insert(s);
}

void createDictionary(string const &str, const char delim, map<char, int> &out)
{
    stringstream ss(str);
    string word, s;
    char symbol;
    while (getline(ss, word, delim))
        s.append(word);
    int i;
    for (i = 97; i < 123; i++)
    {
        symbol = static_cast<char>(i);
        out.insert(pair<char, int>(symbol, CountSymbol(s, symbol)));
    }
}

int GetRand(map<char, int> &dictionary)
{
    int j, pr;
    map<char, int>::iterator item = dictionary.begin();
    int random = rand() % dictionary.size();
    std::advance(item, random);
    return item->second;
}