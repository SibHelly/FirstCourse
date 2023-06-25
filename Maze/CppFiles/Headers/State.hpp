#ifndef STATE_HPP
#define STATE_HPP

#include "Player.hpp"

class Player;
class State;

class BaseStateData // ������� ������ ��� ���������
{
private:
public:
    BaseStateData(){};
    float grizSize;
    RenderWindow *window;
    map<string, int> *supportKeys;
    stack<State *> *situations;
};

class State // ����� ��������� ���� �����������.
{
private:
protected:
    BaseStateData *BaseState; // ������ ��� ���������
    RenderWindow *window;     // ���� ���������

    stack<State *> *situations; // ���� ��������� ����

    map<string, int> *supportKeys; // map ��� ������ ����
    map<string, int> keyBinds;     // ����� map ��� ������
    map<string, Texture> textures; // map ��������
    bool quit;                     // �����
    bool paused;                   // ��������� �����
    bool pressed;
    float gridSize; // ������ �����

    // ������� ����
    Vector2i mousePosScreen;
    Vector2i mousePosWindow;
    Vector2f mousePosView;

    virtual void InitKeyBinds() = 0; // ������������� ������ ��� ��������� ����

public:
    State(BaseStateData *BaseState); // ����������� � ����������� ��� ���������
    virtual ~State();                // ����������� ����������

    const bool &getQuit() const; // �����

    void Paused();                                // �����
    void UnPaused();                              // �������� �����
    void endState();                              // �������� ���������
    void Selected() { this->pressed = true; };    // ����� textbox
    void UnSelected() { this->pressed = false; }; // �������� textbox

    virtual void updateMousePosition(View *view = NULL);  // ���������� ������� ����
    virtual void updateInput(const float &deltaTime) = 0; // ���������� ����� ��������
    virtual void update(const float &deltaTime) = 0;      // ���������� ������
    virtual void render(RenderTarget *target = NULL) = 0; // ���������� ������
};

#endif
