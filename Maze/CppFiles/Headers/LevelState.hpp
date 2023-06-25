#ifndef LEVELSTATE_HPP
#define LEVELSTATE_HPP

#include "State.hpp"
#include "Button.hpp"
#include "GameState.hpp"
#include "TextBox.hpp"

class GameState;

class LevelState : public State // ��������� ������ ������ � ����� �����
{
private:
    Font font;                 // �����
    Text menuText;             // ����� ���������
    Texture BackGrounTexture;  // �������� ����
    RectangleShape BackGround; // ������� ��� ��������

    TextBox *text; // ���� ��� ����� �����

    String NamePlayer; // ��� ������
    int level;         // �������

    RectangleShape container;

    // ������ ���������
    map<string, Button *> buttons;

    void InitBackGround(); // �������� ������� ����
    void InitButtons();    // �������� ������
    void InitFonts();      // �������� ������
    void InitKeyBinds(){}; //

public:
    LevelState(BaseStateData *BaseState); // �������� ���������
    virtual ~LevelState();

    void updateButtons(); // ���������� ������
    void updateInput(const float &deltaTime);

    void update(const float &deltaTime);      // ����������
    void renderButtons(RenderTarget &target); // ���������� ������
    void render(RenderTarget *target = NULL); // ���������� ������� � ����
};

#endif