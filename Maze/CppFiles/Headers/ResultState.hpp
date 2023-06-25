#ifndef RESULTSTATE_HPP
#define RESULTSTATE_HPP
#include "State.hpp"
#include "Button.hpp"
#include "TableState.hpp"

class ResultState : public State // ��������� ����������
{
private:
    Font font;                 // �����
    Text menuText;             // ���������
    Texture BackGrounTexture;  // �������� ����
    RectangleShape BackGround; // ������ ������� ����

    int level; // �������

    RectangleShape container; // ��������� ��� ������

    map<string, Button *> buttons;

    void InitBackGround(); // ������ ���
    void InitButtons();    // �������� ������
    void InitFonts();      // �������� �������
    void InitKeyBinds(){}; // �������

public:
    ResultState(BaseStateData *BaseState); // �������� ���������
    virtual ~ResultState();

    void updateButtons();                     // ���������� ������
    void updateInput(const float &deltaTime); // ���������� �����
    void update(const float &deltaTime);      // �����������

    void renderButtons(RenderTarget &target); // ���������� ������
    void render(RenderTarget *target = NULL); // ����������
};

#endif