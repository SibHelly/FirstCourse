#ifndef TableState_HPP
#define TableState_HPP
#include "State.hpp"
#include "Button.hpp"
#include "GameState.hpp"
#include <algorithm>
#include <string>
#include <cstdio>

struct node // структура данных одного результата
{
    string name;
    int level;
    float time;
};

class TableState : public State
{
private:
    Font font;     // шрифт
    Text menuText; // заголовок состояния
    Text head;     // заголовок таблицы

    // задний фон
    Texture BackGrounTexture;
    RectangleShape BackGround;

    int level;

    int count; // количество записей

    // контейнеры для текста
    RectangleShape container;
    RectangleShape heading;

    // для результатов
    vector<node> fromFile;
    vector<RectangleShape> results;
    vector<Text> res;

    // кнопки
    map<string, Button *> buttons;

    // создание необходимого для состояния
    void InitBackGround();
    void InitButtons();
    void InitFonts();
    void InitKeyBinds(){};

public:
    TableState(BaseStateData *BaseState, const int &level);
    virtual ~TableState();

    void clearTable(); // очистка таблицы
    void createTxt();  // файл для печати

    void updateButtons();                       // обновление кнопок
    void updateInput(const float &deltaTime){}; // обновление ввода

    void update(const float &deltaTime);      // обновление
    void renderButtons(RenderTarget &target); // прорисовка кнопок
    void render(RenderTarget *target = NULL); // прорисовка состояния
};

#endif