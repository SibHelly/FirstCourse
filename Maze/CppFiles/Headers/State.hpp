#ifndef STATE_HPP
#define STATE_HPP

#include "Player.hpp"

class Player;
class State;

class BaseStateData // базовое данные для состояния
{
private:
public:
    BaseStateData(){};
    float grizSize;
    RenderWindow *window;
    map<string, int> *supportKeys;
    stack<State *> *situations;
};

class State // класс состояние игры абстрактный.
{
private:
protected:
    BaseStateData *BaseState; // данные для состояний
    RenderWindow *window;     // окно состояния

    stack<State *> *situations; // стек состояний игры

    map<string, int> *supportKeys; // map для клавиш игры
    map<string, int> keyBinds;     // также map для клавиш
    map<string, Texture> textures; // map текструр
    bool quit;                     // выход
    bool paused;                   // состояние паузы
    bool pressed;
    float gridSize; // размер сетки

    // позиции мыши
    Vector2i mousePosScreen;
    Vector2i mousePosWindow;
    Vector2f mousePosView;

    virtual void InitKeyBinds() = 0; // инициализация клавиш для состояния игры

public:
    State(BaseStateData *BaseState); // конструктор с параметрами для состояния
    virtual ~State();                // виртуальный деструктор

    const bool &getQuit() const; // выход

    void Paused();                                // пауза
    void UnPaused();                              // отменить паузу
    void endState();                              // покинуть состояние
    void Selected() { this->pressed = true; };    // выбор textbox
    void UnSelected() { this->pressed = false; }; // отменить textbox

    virtual void updateMousePosition(View *view = NULL);  // обновление позиции мыши
    virtual void updateInput(const float &deltaTime) = 0; // обновление ввода действий
    virtual void update(const float &deltaTime) = 0;      // обновление кадров
    virtual void render(RenderTarget *target = NULL) = 0; // прорисовка кадров
};

#endif
