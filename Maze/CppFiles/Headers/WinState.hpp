#ifndef WINSTATE_HPP
#define WINSTATE_HPP
#include "State.hpp"
#include "Button.hpp"
#include "GameState.hpp"

class WinState : public State // ��������� ����� �������� �������
{
private:
    Font font;                 // �����
    Text menuText;             // ����� ���������
    Text res;                  // ����������
    Texture BackGrounTexture;  // �������� ����
    RectangleShape BackGround; // ������ ������� ����

    string NamePlayer; // ��� ������
    int level;         // �������

    // ��������� ��� ������
    RectangleShape container;
    RectangleShape results;

    map<string, Button *> buttons; // ������

    void InitBackGround();
    void InitButtons();
    void InitFonts();
    void InitKeyBinds(){};

public:
    WinState(BaseStateData *BaseState, const int &level, const float time, const string name);
    virtual ~WinState();

    void updateButtons(); // ���������� ������
    void updateInput(const float &deltaTime){};

    void update(const float &deltaTime);      // ����������
    void renderButtons(RenderTarget &target); // ���������� ������
    void render(RenderTarget *target = NULL); // ����������
};

#endif