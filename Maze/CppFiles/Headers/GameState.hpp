#ifndef GAMESTATE_HPP
#define GAMESTATE_HPP

#include "State.hpp"
#include "PauseMenu.hpp"
#include "TileMap.hpp"
#include "WinState.hpp"

class GameState : public State // ��������� ����
{
private:
    Font font; // ����� ��� �����

    PauseMenu *pause_menu; // ���� �����
    Player *player;        // ����� ����
    Texture texture;       // ��������

    TileMap *map; // �����

    string NamePlayer; // ��� ������
    int level;         // �������

    // ����� �����������
    Clock time1;
    float timeGame;

    // �����
    View view;

    void InitView();      // �������� ������
    void InitKeyBinds();  // ���� ������ ��� ��������
    void InitTextures();  // �������� ����
    void InitPauseMenu(); // �������� �����
    void InitPlayers();   // �������� ������
    void InitFonts();     // �������� ������
    void InitTileMap();   // �������� �����

public:
    GameState(BaseStateData *BaseState, string name, const int level);
    virtual ~GameState();

    // �������
    void updateTime();                         // ���������� ������
    void updateView(const float &deltaTime);   // ���������� ������ � ����������� �� ���� � ������
    void updateInput(const float &deltaTime);  // ���������� ��������
    void updatePauseButtons();                 // ���������� ������ �����
    void updatePlayer(const float &deltaTime); // ���������� ������� ������
    void update(const float &deltaTime);       // ����������
    void render(RenderTarget *target = NULL);  // ����������
};

#endif