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
    Texture BackGrounTexture;  // текстура фона
    RectangleShape BackGround; // прямоугольник для фона
    Font font;                 // шрифт

    RectangleShape container; // контейнер для заголовка
    Text text;                // заголовок

    map<string, Button *> buttons; // кнопки

    void InitBackGround(); // загрузка фона
    void InitFonts();      // загрузка шрифта
    void InitKeyBinds();   // загрука кнопок
    void InitButtons();    // загрузка кнопок

public:
    MenuState(BaseStateData *BaseState); // создание состояния
    virtual ~MenuState();

    // Функции
    void updateInput(const float &deltaTime); // обновление ввода
    void updateButtons();                     // обновление кнопок
    void update(const float &deltaTime);      // обновление

    void renderButtons(RenderTarget &target); // прорисовка кнопка
    void render(RenderTarget *target = NULL); // прорисовка
};

#endif