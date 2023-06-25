#ifndef WINSTATE_HPP
#define WINSTATE_HPP
#include "State.hpp"
#include "Button.hpp"
#include "GameState.hpp"

class WinState : public State // состояние когда уроввень пройден
{
private:
    Font font;                 // шрифт
    Text menuText;             // текст заголовка
    Text res;                  // результаты
    Texture BackGrounTexture;  // текстура фона
    RectangleShape BackGround; // размер заднего фона

    string NamePlayer; // имя игрока
    int level;         // уровень

    // контейнры для текста
    RectangleShape container;
    RectangleShape results;

    map<string, Button *> buttons; // кнопки

    void InitBackGround();
    void InitButtons();
    void InitFonts();
    void InitKeyBinds(){};

public:
    WinState(BaseStateData *BaseState, const int &level, const float time, const string name);
    virtual ~WinState();

    void updateButtons(); // обновление кнопок
    void updateInput(const float &deltaTime){};

    void update(const float &deltaTime);      // обновление
    void renderButtons(RenderTarget &target); // прорисовка кнопок
    void render(RenderTarget *target = NULL); // прорисовка
};

#endif