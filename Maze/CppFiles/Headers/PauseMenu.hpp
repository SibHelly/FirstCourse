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
    Font &font;    // шрифт
    Text menuText; // заголовок

    RectangleShape background; // задний фон
    RectangleShape container;  // контейнер

    map<string, Button *> buttons; // кнопки

public:
    PauseMenu(RenderWindow &window, Font &font); // создание
    virtual ~PauseMenu();

    const bool isButtonPressed(const string key); // проверка нажатия

    void AddButton(const string key, float y, const string Text); // добавить кнопку
    void update(const Vector2f &mousePos);                        // обновление
    void render(RenderTarget &target);                            // прорисовка
};

#endif