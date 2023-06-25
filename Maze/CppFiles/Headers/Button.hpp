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

class Button // класс кнопки
{
private:
    enum button_states // состояния кнопок
    {
        BTN_IDLE = 0, // не наведена
        BTN_HOVER,    // наведена
        BTN_ACTIVE    // нажата
    };
    short unsigned buttonState; // состояние кнопки

    RectangleShape shape; // прямоугольник для кнопки
    Font *font;           // шрифт текста
    Text text;            // текст

    // цвета для всех состояний
    Color idleColor;
    Color hoverColor;
    Color activeColor;
    Color textIdCol;
    Color textHovCol;
    Color textActCol;

public:
    Button(float x, float y, float width, float height, Font *font, const string Text, unsigned sizeText, Color textIdCol, Color textHovCol, Color textActCol, Color idleColor, Color hoverColor, Color activeColor);
    ~Button();

    // Функции
    const bool isPressed() const;      // нажата ли
    void update(Vector2f mousePos);    // обновления относительно мыши
    void render(RenderTarget &target); // прорисовка
};

#endif