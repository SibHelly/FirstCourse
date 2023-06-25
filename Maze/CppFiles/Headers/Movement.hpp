#ifndef MOVEMENT_HPP
#define MOVEMENT_HPP

#include <iostream>

#include <vector>
#include <fstream>
#include <stack>
#include <map>

#include <ctime>
#include <cmath>
#include <cstdlib>

#include <SFML\System.hpp>
#include <SFML\Window.hpp>
#include <SFML\Graphics.hpp>
#include <SFML\Audio.hpp>
#include <SFML\Network.hpp>

using namespace std;
using namespace sf;

enum movement // ��������
{
    Idle = 0,
    MOVE,
    MOVE_LEFT,
    MOVE_RIGHT,
    MOVE_UP,
    MOVE_DOWN
};

class Movement
{
private:
    Sprite &sprite;     // ������
    float MaxVelocity;  // ������������ ��������
    Vector2f Velocity;  // ��������
    float acceleration; // ���������
    float deceleration; // �����������

public:
    Movement(Sprite &sprite, float maxVelocity, float acceleration, float deceleration); // �������� �������� � ��� ���������
    virtual ~Movement();

    const bool getState(const short unsigned state) const; // �������� ���������

    void stop(); // ��������
    void stopY();
    void stopX();

    const Vector2f &getVelocity() const;                               // �������� ��������
    void move(const float dx, const float dy, const float &deltaTime); // ��������
    void update(const float &deltaTime);                               // ����������
};

#endif