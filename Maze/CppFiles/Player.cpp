#include "Headers/Player.hpp"

Player::Player(float x, float y, Texture &textureSheet)
{

    this->SetPosition(x, y);

    this->CreateHitBox(this->sprite, 40.f, 10.f, 38.f, 40.f);
    this->CreateMovement(200.f, 200.f, 100.f);
    this->CreateAnimation(textureSheet);

    this->animation->AddAnimation("Idle", 10.f, 0, 0, 3, 0, 128, 60);
    this->animation->AddAnimation("Walk", 10.f, 0, 1, 7, 1, 128, 60);
}

void Player::update(const float &deltatime)
{
    this->movement->update(deltatime);
    if (this->movement->getState(Idle))
        this->animation->play("Idle", deltatime);
    else if (this->movement->getState(MOVE_RIGHT))
    {
        this->sprite.setOrigin(0.f, 0.f);
        this->sprite.setScale(1.f, 1.f);
        this->animation->play("Walk", deltatime);
    }
    else if (this->movement->getState(MOVE_LEFT))
    {
        this->sprite.setOrigin(113.f, 0.f);
        this->sprite.setScale(-1.f, 1.f);
        this->animation->play("Walk", deltatime);
    }
    else if (this->movement->getState(MOVE_UP))
    {
        this->animation->play("Walk", deltatime);
    }
    else if (this->movement->getState(MOVE_DOWN))
    {

        this->animation->play("Walk", deltatime);
    }

    this->hitbox->update();
}

Player::~Player()
{
}
