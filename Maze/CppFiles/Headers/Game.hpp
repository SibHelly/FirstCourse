#ifndef GAME_HPP
#define GAME_HPP

#include "MenuState.hpp"

class Game // класс игра
{
private:
    Texture BackGrounTexture;  // текстура фона
    RectangleShape BackGround; // пр€моугольник дл€ фона
    Font font;                 // шрифт

    RectangleShape container; // контейнер дл€ заголовка
    Text text;                // заголовок

    Music music;

    // инициализаци€ окна и событи€
    RenderWindow *window;    // окно игры
    Event event;             // событие
    BaseStateData BaseState; // все данные дл€ состо€ни€
    bool fullscreen;         // тип

    Clock timer;
    float time;

    // врем€ дл€ перерисовки и обновлени€ кадров
    Clock deltaClock;
    float deltaTime;

    float gridSize; // размер сетки

    stack<State *> situations; // стек состо€ний

    map<string, int> SupportKeys; // клавиши дл€ игры

    void InitWindow();    // создание окна
    void InitFont();      // шрифт дл€ заставки
    void InitPreview();   // заставка
    void InitBaseState(); // создание базового состо€ни€
    void InitKeys();      // добавление клавиш дл€ игры
    void InitStates();    // создание первого состо€ни€
    void InitVariables(); // изначальное обнуление
    void InitMusic();     // музыка

public:
    Game();
    virtual ~Game();

    // ‘ункции
    void UpdateDeltaTime();  // обновленеи времени
    void update();           // обновление
    void render();           // показ
    void run();              // запуск
    void updateSFMLEvents(); // обновление событи€
};

#endif