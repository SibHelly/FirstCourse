#ifndef ENTITY_HPP
#define ENTITY_HPP

#include "CollisionComponent.hpp"
#include "Movement.hpp"
#include "AnimationPlayer.hpp"

class Entity // класс движущегося сущства
{
private:
    void InitVariables(); // обнуление всех частей

protected:
    Sprite sprite; // спрайт сущности

    Movement *movement;         // движение
    AnimationPlayer *animation; // анимация
    CollisionComponent *hitbox; // столкновения

public:
    Entity();
    virtual ~Entity();

    void SetTexture(Texture &texture);                                                                // установить текстуру
    void CreateMovement(const float MaxVelocity, const float acceleration, const float deceleration); // создать движение
    void CreateAnimation(Texture &textureSheet);                                                      // создать анимацию
    void CreateHitBox(Sprite &sprite, float sx, float sy, float width, float height);                 // создать столкновение

    // для коллизий
    virtual const Vector2f &getPosition() const;                           // получение позиции ящика столкновений
    virtual const Vector2f &getPositionSprite() const;                     // позиция спрайта
    virtual const FloatRect getGlobalBounds() const;                       // получить столкновение
    virtual const Vector2u getGridPosition(const unsigned gridSize) const; // получить позицию в сетке
    const FloatRect getNextBounds(const float &deltaTime) const;           // получить следующее столкновение

    // функции
    virtual void SetPosition(const float x, const float y);                  // установить позицию
    virtual void move(const float x, const float y, const float &deltaTime); // движение

    virtual void stopY(); // остановить по х
    virtual void stopX(); // остановить по y

    virtual void update(const float &deltaTime); // обновлени
    virtual void render(RenderTarget &target);   // прорисовка
};

#endif