#ifndef ENTITY_HPP
#define ENTITY_HPP

#include "CollisionComponent.hpp"
#include "Movement.hpp"
#include "AnimationPlayer.hpp"

class Entity // ����� ����������� �������
{
private:
    void InitVariables(); // ��������� ���� ������

protected:
    Sprite sprite; // ������ ��������

    Movement *movement;         // ��������
    AnimationPlayer *animation; // ��������
    CollisionComponent *hitbox; // ������������

public:
    Entity();
    virtual ~Entity();

    void SetTexture(Texture &texture);                                                                // ���������� ��������
    void CreateMovement(const float MaxVelocity, const float acceleration, const float deceleration); // ������� ��������
    void CreateAnimation(Texture &textureSheet);                                                      // ������� ��������
    void CreateHitBox(Sprite &sprite, float sx, float sy, float width, float height);                 // ������� ������������

    // ��� ��������
    virtual const Vector2f &getPosition() const;                           // ��������� ������� ����� ������������
    virtual const Vector2f &getPositionSprite() const;                     // ������� �������
    virtual const FloatRect getGlobalBounds() const;                       // �������� ������������
    virtual const Vector2u getGridPosition(const unsigned gridSize) const; // �������� ������� � �����
    const FloatRect getNextBounds(const float &deltaTime) const;           // �������� ��������� ������������

    // �������
    virtual void SetPosition(const float x, const float y);                  // ���������� �������
    virtual void move(const float x, const float y, const float &deltaTime); // ��������

    virtual void stopY(); // ���������� �� �
    virtual void stopX(); // ���������� �� y

    virtual void update(const float &deltaTime); // ���������
    virtual void render(RenderTarget &target);   // ����������
};

#endif