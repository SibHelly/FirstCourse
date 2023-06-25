#ifndef GAMESTATE_HPP
#define GAMESTATE_HPP

#include "State.hpp"
#include "PauseMenu.hpp"
#include "TileMap.hpp"
#include "WinState.hpp"

class GameState : public State // состояние игры
{
private:
    Font font; // шрифт для паузы

    PauseMenu *pause_menu; // меню паузы
    Player *player;        // игрок мышь
    Texture texture;       // текстура

    TileMap *map; // карта

    string NamePlayer; // имя игрока
    int level;         // уровень

    // время прохождения
    Clock time1;
    float timeGame;

    // обзор
    View view;

    void InitView();      // создание обзора
    void InitKeyBinds();  // ввод клавиш для движения
    void InitTextures();  // текстура мыши
    void InitPauseMenu(); // создание паузы
    void InitPlayers();   // создание игрока
    void InitFonts();     // загрузка шрифта
    void InitTileMap();   // создание карты

public:
    GameState(BaseStateData *BaseState, string name, const int level);
    virtual ~GameState();

    // Функции
    void updateTime();                         // обновление врмени
    void updateView(const float &deltaTime);   // обновление обзора в зависимости от мыши и игрока
    void updateInput(const float &deltaTime);  // обновление движения
    void updatePauseButtons();                 // обновление кнопок паузы
    void updatePlayer(const float &deltaTime); // обновление нажатия кнопок
    void update(const float &deltaTime);       // обновление
    void render(RenderTarget *target = NULL);  // прорисовка
};

#endif