#include "Headers/Entity.hpp"

void Entity::InitVariables()
{
    this->movement = NULL;
    this->hitbox = NULL;
    this->animation = NULL;
}

Entity::Entity()
{
    this->InitVariables();
}

Entity::~Entity()
{
    delete this->hitbox;
    delete this->movement;
    delete this->animation;
}

void Entity::SetTexture(Texture &texture)
{
    this->sprite.setTexture(texture);
}

void Entity::CreateMovement(const float MaxVelocity, const float acceleration, const float deceleration)
{
    this->movement = new Movement(this->sprite, MaxVelocity, acceleration, deceleration);
}
void Entity::CreateAnimation(Texture &textureSheet)
{
    this->animation = new AnimationPlayer(sprite, textureSheet);
}
void Entity::CreateHitBox(Sprite &sprite, float sx, float sy, float width, float height)
{
    this->hitbox = new CollisionComponent(sprite, sx, sy, width, height);
}

const Vector2f &Entity::getPosition() const
{
    if (this->hitbox)
        return this->hitbox->getPosition();

    return this->sprite.getPosition();
}

const Vector2f &Entity::getPositionSprite() const
{
    return this->sprite.getPosition();
}

const FloatRect Entity::getGlobalBounds() const
{
    if (this->hitbox)
        return this->hitbox->getGlobalBounds();

    return this->sprite.getGlobalBounds();
}

const Vector2u Entity::getGridPosition(const unsigned gridSize) const
{
    if (this->hitbox)
        return Vector2u(static_cast<unsigned>(this->hitbox->getPosition().x) / gridSize,
                        static_cast<unsigned>(this->hitbox->getPosition().y) / gridSize);

    return Vector2u(static_cast<unsigned>(this->sprite.getPosition().x) / gridSize,
                    static_cast<unsigned>(this->sprite.getPosition().y) / gridSize);
}

void Entity::stopX()
{
    if (this->movement)
        this->movement->stopX();
}

void Entity::stopY()
{
    if (this->movement)
        this->movement->stopY();
}

void Entity::SetPosition(const float x, const float y)
{
    if (this->hitbox)
        this->hitbox->setPosition(x, y);
    else
        this->sprite.setPosition(x, y);
}

void Entity::move(const float dx, const float dy, const float &deltaTime)
{
    if (this->movement)
    {
        this->movement->move(dx, dy, deltaTime);
    }
}

void Entity::update(const float &deltaTime)
{
}

void Entity::render(RenderTarget &target)
{
    target.draw(this->sprite);

    if (this->hitbox)
        this->hitbox->render(target);
}

const FloatRect Entity::getNextBounds(const float &deltaTime) const
{
    if (this->hitbox && this->movement)
        return this->hitbox->getNextPosition(this->movement->getVelocity() * deltaTime);

    return FloatRect();
}
