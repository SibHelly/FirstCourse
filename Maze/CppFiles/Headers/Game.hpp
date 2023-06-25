#ifndef GAME_HPP
#define GAME_HPP

#include "MenuState.hpp"

class Game // ����� ����
{
private:
    Texture BackGrounTexture;  // �������� ����
    RectangleShape BackGround; // ������������� ��� ����
    Font font;                 // �����

    RectangleShape container; // ��������� ��� ���������
    Text text;                // ���������

    Music music;

    // ������������� ���� � �������
    RenderWindow *window;    // ���� ����
    Event event;             // �������
    BaseStateData BaseState; // ��� ������ ��� ���������
    bool fullscreen;         // ���

    Clock timer;
    float time;

    // ����� ��� ����������� � ���������� ������
    Clock deltaClock;
    float deltaTime;

    float gridSize; // ������ �����

    stack<State *> situations; // ���� ���������

    map<string, int> SupportKeys; // ������� ��� ����

    void InitWindow();    // �������� ����
    void InitFont();      // ����� ��� ��������
    void InitPreview();   // ��������
    void InitBaseState(); // �������� �������� ���������
    void InitKeys();      // ���������� ������ ��� ����
    void InitStates();    // �������� ������� ���������
    void InitVariables(); // ����������� ���������
    void InitMusic();     // ������

public:
    Game();
    virtual ~Game();

    // �������
    void UpdateDeltaTime();  // ���������� �������
    void update();           // ����������
    void render();           // �����
    void run();              // ������
    void updateSFMLEvents(); // ���������� �������
};

#endif