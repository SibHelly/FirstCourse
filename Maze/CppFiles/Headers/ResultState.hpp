#ifndef RESULTSTATE_HPP
#define RESULTSTATE_HPP
#include "State.hpp"
#include "Button.hpp"
#include "TableState.hpp"

class ResultState : public State // состояние результаты
{
private:
    Font font;                 // шрифт
    Text menuText;             // заголовок
    Texture BackGrounTexture;  // текстура фона
    RectangleShape BackGround; // размер заднего фона

    int level; // уровень

    RectangleShape container; // контейнер для текста

    map<string, Button *> buttons;

    void InitBackGround(); // задний фон
    void InitButtons();    // создание кнопок
    void InitFonts();      // создание шрифтов
    void InitKeyBinds(){}; // клавиши

public:
    ResultState(BaseStateData *BaseState); // создание состояния
    virtual ~ResultState();

    void updateButtons();                     // обновление кнопок
    void updateInput(const float &deltaTime); // обновление ввода
    void update(const float &deltaTime);      // обновлениеы

    void renderButtons(RenderTarget &target); // прорисовка кнопок
    void render(RenderTarget *target = NULL); // прорисовка
};

#endif