#ifndef MENUSTATE_HPP
#define MENUSTATE_HPP
#include "LevelState.hpp"
#include "ResultState.hpp"
#include "RulesState.hpp"
#include "State.hpp"
#include "Button.hpp"

class MenuState : public State
{

private:
    Texture BackGrounTexture;  // �������� ����
    RectangleShape BackGround; // ������������� ��� ����
    Font font;                 // �����

    RectangleShape container; // ��������� ��� ���������
    Text text;                // ���������

    map<string, Button *> buttons; // ������

    void InitBackGround(); // �������� ����
    void InitFonts();      // �������� ������
    void InitKeyBinds();   // ������� ������
    void InitButtons();    // �������� ������

public:
    MenuState(BaseStateData *BaseState); // �������� ���������
    virtual ~MenuState();

    // �������
    void updateInput(const float &deltaTime); // ���������� �����
    void updateButtons();                     // ���������� ������
    void update(const float &deltaTime);      // ����������

    void renderButtons(RenderTarget &target); // ���������� ������
    void render(RenderTarget *target = NULL); // ����������
};

#endif