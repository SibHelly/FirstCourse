#ifndef RULESSTATE_HPP
#define RULESSTATE_HPP
#include "State.hpp"
#include "Button.hpp"

class RulesState : public State
{
private:
    Font font;        // шрифт
    Text RulesText;   // правила
    Text HistoryText; // справка
    Text HeadingText; // заголовко

    Texture BackGrounTexture;  // задний фон
    RectangleShape BackGround; // для фона

    RectangleShape heading; // область для заголовка
    RectangleShape rule;    // область для правил
    RectangleShape history; // область справики

    Button *button; // кнопка выхода

    void InitBackGround(); // задний фон
    void InitButtons();    // кнопка
    void InitFonts();      // шрифт
    void InitKeyBinds(){}; // клавиши

public:
    RulesState(BaseStateData *BaseState); // создание
    virtual ~RulesState();

    void updateButtons();                     // обновление кнопок
    void updateInput(const float &deltaTime); // обновление ввода
    void update(const float &deltaTime);      // обновление

    void renderButtons(RenderTarget &target); // прорисовка кнопок
    void render(RenderTarget *target = NULL); // прорисовка состояния
};

#endif