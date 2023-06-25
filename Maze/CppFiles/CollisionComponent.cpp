#include "Headers/CollisionComponent.hpp"

CollisionComponent::CollisionComponent(Sprite &sprite, float sx, float sy, float width, float height) : sprite(sprite), SX(sx), SY(sy)
{

    this->nexPos.left = 0.f;
    this->nexPos.top = 0.f;
    this->nexPos.width = width;
    this->nexPos.height = height;

    this->HitBox.setPosition(this->sprite.getPosition().x + sx, this->sprite.getPosition().y + sy);
    this->HitBox.setSize(Vector2f(width, height));
    this->HitBox.setFillColor(Color::Transparent);
    this->HitBox.setOutlineThickness(-1.f);
    this->HitBox.setOutlineColor(Color(20, 20, 20, 0));
}

CollisionComponent::~CollisionComponent()
{
}

bool CollisionComponent::checkIntersect(const FloatRect &rect)
{
    return this->HitBox.getGlobalBounds().intersects(rect);
}

void CollisionComponent::render(RenderTarget &target)
{
    target.draw(this->HitBox);
}
const sf::Vector2f &CollisionComponent::getPosition() const
{
    this->HitBox.getPosition();
}

const sf::FloatRect CollisionComponent::getGlobalBounds() const
{
    return this->HitBox.getGlobalBounds();
}

const sf::FloatRect &CollisionComponent::getNextPosition(const sf::Vector2f &velocity)
{
    this->nexPos.left = this->HitBox.getPosition().x + velocity.x;
    this->nexPos.top = this->HitBox.getPosition().y + velocity.y;

    return this->nexPos;
}

void CollisionComponent::setPosition(const sf::Vector2f &position)
{
    this->HitBox.setPosition(position);
    this->sprite.setPosition(position.x - this->SX, position.y - SY);
}

void CollisionComponent::setPosition(const float x, const float y)
{
    this->HitBox.setPosition(x, y);
    this->sprite.setPosition(x - this->SX, y - this->SY);
}

void CollisionComponent::update()
{
    this->HitBox.setPosition(this->sprite.getPosition().x + this->SX, this->sprite.getPosition().y + SY);
}
