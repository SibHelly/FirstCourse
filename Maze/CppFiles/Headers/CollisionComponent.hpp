#ifndef CollisionComponent_HPP
#define CollisionComponent_HPP

#include <iostream>

#include <ctime>
#include <cstdlib>

#include <SFML\System.hpp>
#include <SFML\Window.hpp>
#include <SFML\Graphics.hpp>
#include <SFML\Audio.hpp>
#include <SFML\Network.hpp>

using namespace std;
using namespace sf;

class CollisionComponent
{
private:
    Sprite &sprite;        // спрайт
    RectangleShape HitBox; // ящик для столкновения
    float SX;              // начальный x
    float SY;              // начальный y
    FloatRect nexPos;      // следующий после движения ящик

public:
    CollisionComponent(Sprite &sprite, float sx, float sy, float width, float height); // создание ящика столкновений
    virtual ~CollisionComponent();

    const Vector2f &getPosition() const;                            // получить позицю
    const FloatRect getGlobalBounds() const;                        // получить столкновение
    const FloatRect &getNextPosition(const sf::Vector2f &velocity); // получить следующие расположение
    void setPosition(const sf::Vector2f &position);                 // установить позицию по вектору
    void setPosition(const float x, const float y);                 // установить координату по координатам

    bool checkIntersect(const FloatRect &rect); // проверить столкновение

    void update();                     // обновление
    void render(RenderTarget &target); // прорисовка
};

#endif