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
    Sprite &sprite;        // ������
    RectangleShape HitBox; // ���� ��� ������������
    float SX;              // ��������� x
    float SY;              // ��������� y
    FloatRect nexPos;      // ��������� ����� �������� ����

public:
    CollisionComponent(Sprite &sprite, float sx, float sy, float width, float height); // �������� ����� ������������
    virtual ~CollisionComponent();

    const Vector2f &getPosition() const;                            // �������� ������
    const FloatRect getGlobalBounds() const;                        // �������� ������������
    const FloatRect &getNextPosition(const sf::Vector2f &velocity); // �������� ��������� ������������
    void setPosition(const sf::Vector2f &position);                 // ���������� ������� �� �������
    void setPosition(const float x, const float y);                 // ���������� ���������� �� �����������

    bool checkIntersect(const FloatRect &rect); // ��������� ������������

    void update();                     // ����������
    void render(RenderTarget &target); // ����������
};

#endif