#ifndef RULESSTATE_HPP
#define RULESSTATE_HPP
#include "State.hpp"
#include "Button.hpp"

class RulesState : public State
{
private:
    Font font;        // �����
    Text RulesText;   // �������
    Text HistoryText; // �������
    Text HeadingText; // ���������

    Texture BackGrounTexture;  // ������ ���
    RectangleShape BackGround; // ��� ����

    RectangleShape heading; // ������� ��� ���������
    RectangleShape rule;    // ������� ��� ������
    RectangleShape history; // ������� ��������

    Button *button; // ������ ������

    void InitBackGround(); // ������ ���
    void InitButtons();    // ������
    void InitFonts();      // �����
    void InitKeyBinds(){}; // �������

public:
    RulesState(BaseStateData *BaseState); // ��������
    virtual ~RulesState();

    void updateButtons();                     // ���������� ������
    void updateInput(const float &deltaTime); // ���������� �����
    void update(const float &deltaTime);      // ����������

    void renderButtons(RenderTarget &target); // ���������� ������
    void render(RenderTarget *target = NULL); // ���������� ���������
};

#endif