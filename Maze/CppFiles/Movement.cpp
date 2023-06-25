#include "Headers/Movement.hpp"

Movement::Movement(Sprite &sprite, float maxVelocity, float acceleration, float deceleration) : sprite(sprite), MaxVelocity(maxVelocity), acceleration(acceleration), deceleration(deceleration)
{
}

Movement::~Movement()
{
}

const bool Movement::getState(const short unsigned state) const
{
    switch (state)
    {
    case Idle:
        if (this->Velocity.x == 0.f && this->Velocity.y == 0.f)
            return true;
        break;

    case MOVE:
        if (this->Velocity.x != 0.f || this->Velocity.y != 0.f)
            return true;
        break;

    case MOVE_LEFT:
        if (this->Velocity.x < 0.f)
            return true;
        break;
    case MOVE_RIGHT:
        if (this->Velocity.x > 0.f)
            return true;
        break;
    case MOVE_UP:
        if (this->Velocity.y < 0.f)
            return true;
        break;
    case MOVE_DOWN:
        if (this->Velocity.y > 0.f)
            return true;
        break;
    }
    return false;
}

const Vector2f &Movement::getVelocity() const
{
    return this->Velocity;
}

void Movement::move(const float dx, const float dy, const float &deltaTime)
{
    this->Velocity.x += this->acceleration * dx * deltaTime;
    this->Velocity.y += this->acceleration * dy * deltaTime;
}

void Movement::update(const float &deltaTime)
{
    if (this->Velocity.x > 0.f)
    {
        if (this->Velocity.x > this->MaxVelocity)
            this->Velocity.x = this->MaxVelocity;

        this->Velocity.x -= deceleration * deltaTime;
        if (this->Velocity.x < 0.f)
            this->Velocity.x = 0.f;
    }
    else if (this->Velocity.x < 0.f)
    {

        if (this->Velocity.x < -this->MaxVelocity)
            this->Velocity.x = -this->MaxVelocity;

        this->Velocity.x += deceleration * deltaTime;
        if (this->Velocity.x > 0.f)
            this->Velocity.x = 0.f;
    }

    if (this->Velocity.y > 0.f)
    {
        if (this->Velocity.y > this->MaxVelocity)
            this->Velocity.y = this->MaxVelocity;

        this->Velocity.y -= deceleration * deltaTime;
        if (this->Velocity.y < 0.f)
            this->Velocity.y = 0.f;
    }
    else if (this->Velocity.y < 0.f)
    {
        if (this->Velocity.y < -this->MaxVelocity)
            this->Velocity.y = -this->MaxVelocity;

        this->Velocity.y += deceleration * deltaTime;
        if (this->Velocity.y > 0.f)
            this->Velocity.y = 0.f;
    }

    this->sprite.move(this->Velocity * deltaTime);
}

void Movement::stop()
{
    this->Velocity.x = 0.f;
    this->Velocity.y = 0.f;
}

void Movement::stopX()
{
    this->Velocity.x = 0.f;
}

void Movement::stopY()
{
    this->Velocity.y = 0.f;
}