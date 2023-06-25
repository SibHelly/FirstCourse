#ifndef PAUSEMENU_HPP
#define PAUSEMENU_HPP
#include "Button.hpp"

#include <iostream>

#include <vector>
#include <fstream>
#include <stack>
#include <map>

#include <ctime>
#include <cstdlib>

#include <SFML\System.hpp>
#include <SFML\Window.hpp>
#include <SFML\Graphics.hpp>
#include <SFML\Audio.hpp>
#include <SFML\Network.hpp>

using namespace std;
using namespace sf;

class PauseMenu
{
private:
    Font &font;    // �����
    Text menuText; // ���������

    RectangleShape background; // ������ ���
    RectangleShape container;  // ���������

    map<string, Button *> buttons; // ������

public:
    PauseMenu(RenderWindow &window, Font &font); // ��������
    virtual ~PauseMenu();

    const bool isButtonPressed(const string key); // �������� �������

    void AddButton(const string key, float y, const string Text); // �������� ������
    void update(const Vector2f &mousePos);                        // ����������
    void render(RenderTarget &target);                            // ����������
};

#endif