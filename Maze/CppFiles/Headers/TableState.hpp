#ifndef TableState_HPP
#define TableState_HPP
#include "State.hpp"
#include "Button.hpp"
#include "GameState.hpp"
#include <algorithm>
#include <string>
#include <cstdio>

struct node // ��������� ������ ������ ����������
{
    string name;
    int level;
    float time;
};

class TableState : public State
{
private:
    Font font;     // �����
    Text menuText; // ��������� ���������
    Text head;     // ��������� �������

    // ������ ���
    Texture BackGrounTexture;
    RectangleShape BackGround;

    int level;

    int count; // ���������� �������

    // ���������� ��� ������
    RectangleShape container;
    RectangleShape heading;

    // ��� �����������
    vector<node> fromFile;
    vector<RectangleShape> results;
    vector<Text> res;

    // ������
    map<string, Button *> buttons;

    // �������� ������������ ��� ���������
    void InitBackGround();
    void InitButtons();
    void InitFonts();
    void InitKeyBinds(){};

public:
    TableState(BaseStateData *BaseState, const int &level);
    virtual ~TableState();

    void clearTable(); // ������� �������
    void createTxt();  // ���� ��� ������

    void updateButtons();                       // ���������� ������
    void updateInput(const float &deltaTime){}; // ���������� �����

    void update(const float &deltaTime);      // ����������
    void renderButtons(RenderTarget &target); // ���������� ������
    void render(RenderTarget *target = NULL); // ���������� ���������
};

#endif