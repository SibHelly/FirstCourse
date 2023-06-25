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

enum movement // движение
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
    Sprite &sprite;     // спрайт
    float MaxVelocity;  // максимальная скорость
    Vector2f Velocity;  // скорость
    float acceleration; // ускорение
    float deceleration; // замедлеение

public:
    Movement(Sprite &sprite, float maxVelocity, float acceleration, float deceleration); // создание движения и его составных
    virtual ~Movement();

    const bool getState(const short unsigned state) const; // получить состояние

    void stop(); // остновка
    void stopY();
    void stopX();

    const Vector2f &getVelocity() const;                               // получить скорость
    void move(const float dx, const float dy, const float &deltaTime); // движение
    void update(const float &deltaTime);                               // обновление
};

#endif