#ifndef BUTTON_HPP
#define BUTTON_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <locale>

#include <ctime>
#include <cstdlib>

#include <SFML\System.hpp>
#include <SFML\Window.hpp>
#include <SFML\Graphics.hpp>
#include <SFML\Audio.hpp>
#include <SFML\Network.hpp>

using namespace std;
using namespace sf;

class Button // ����� ������
{
private:
    enum button_states // ��������� ������
    {
        BTN_IDLE = 0, // �� ��������
        BTN_HOVER,    // ��������
        BTN_ACTIVE    // ������
    };
    short unsigned buttonState; // ��������� ������

    RectangleShape shape; // ������������� ��� ������
    Font *font;           // ����� ������
    Text text;            // �����

    // ����� ��� ���� ���������
    Color idleColor;
    Color hoverColor;
    Color activeColor;
    Color textIdCol;
    Color textHovCol;
    Color textActCol;

public:
    Button(float x, float y, float width, float height, Font *font, const string Text, unsigned sizeText, Color textIdCol, Color textHovCol, Color textActCol, Color idleColor, Color hoverColor, Color activeColor);
    ~Button();

    // �������
    const bool isPressed() const;      // ������ ��
    void update(Vector2f mousePos);    // ���������� ������������ ����
    void render(RenderTarget &target); // ����������
};

#endif