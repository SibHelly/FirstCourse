#include "Headers/AnimationPlayer.hpp"

AnimationPlayer::AnimationPlayer(Sprite &sprite, Texture &textureSheet) : sprite(sprite), textureSheet(textureSheet), lastAnimation(NULL)
{
}

AnimationPlayer::~AnimationPlayer()
{
    for (auto &i : this->animations)
        delete i.second;
}

void AnimationPlayer::AddAnimation(string key, float speed, int BeginFrameX, int BeginFrameY, int FrameX, int FrameY, int width, int height)
{
    this->animations[key] = new Animation(this->sprite, this->textureSheet, speed, BeginFrameX, BeginFrameY, FrameX, FrameY, width, height);
}

void AnimationPlayer::play(const string key, const float &deltaTime)
{
    if (this->lastAnimation != this->animations[key])
    {
        if (this->lastAnimation == NULL)
            this->lastAnimation = this->animations[key];
        else
        {
            this->lastAnimation->reset();
            this->lastAnimation = this->animations[key];
        }
    }
    this->animations[key]->play(deltaTime);
}
