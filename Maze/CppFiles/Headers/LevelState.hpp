#ifndef LEVELSTATE_HPP
#define LEVELSTATE_HPP

#include "State.hpp"
#include "Button.hpp"
#include "GameState.hpp"
#include "TextBox.hpp"

class GameState;

class LevelState : public State // состояние выбора уровня и ввода имени
{
private:
    Font font;                 // шрифт
    Text menuText;             // текст заголовка
    Texture BackGrounTexture;  // текстура фона
    RectangleShape BackGround; // область для тексутры

    TextBox *text; // поле для ввода имени

    String NamePlayer; // имя игрока
    int level;         // уровень

    RectangleShape container;

    // кнопки состояния
    map<string, Button *> buttons;

    void InitBackGround(); // загрузка заднего фона
    void InitButtons();    // создание кнопок
    void InitFonts();      // загрузка шрифта
    void InitKeyBinds(){}; //

public:
    LevelState(BaseStateData *BaseState); // создание состояния
    virtual ~LevelState();

    void updateButtons(); // обновление кнопок
    void updateInput(const float &deltaTime);

    void update(const float &deltaTime);      // обновление
    void renderButtons(RenderTarget &target); // прорисовка кнопок
    void render(RenderTarget *target = NULL); // прорисовка текстов и фона
};

#endif