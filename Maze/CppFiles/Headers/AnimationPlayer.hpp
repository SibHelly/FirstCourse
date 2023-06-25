#ifndef AnimationPlayer_HPP
#define AnimationPlayer_HPP

#include <iostream>
#include <string>
#include <map>

#include <SFML\System.hpp>
#include <SFML\Window.hpp>
#include <SFML\Graphics.hpp>
#include <SFML\Audio.hpp>
#include <SFML\Network.hpp>

using namespace std;
using namespace sf;

class AnimationPlayer
{
private:
    class Animation
    {
    public:
        Texture &textureSheet; // текстура спрайта
        Sprite &sprite;        // спрайт
        float timer;           // таймер для переключения анимации
        float speedTimer;      // время когда необходимо переключить
        int width;             // высота и ширина спрайта
        int height;            // высота спрайта
        IntRect BegintRect;    // первый вырез с текстуры
        IntRect CurRect;       // текущий вырез из текстуры
        IntRect EndRect;       // последний вырез данного типа из текстуры

        // создании анимации
        Animation(Sprite &sprite, Texture &textureSheet, float speed, int BeginFrameX, int BeginFrameY, int FrameX, int FrameY, int width, int height) : sprite(sprite), textureSheet(textureSheet), speedTimer(speed), width(width), height(height)
        {
            this->BegintRect = IntRect(BeginFrameX * width, BeginFrameY * height, width, height);
            this->CurRect = this->BegintRect;
            this->EndRect = IntRect(FrameX * width, FrameY * height, width, height);
            this->sprite.setTexture(this->textureSheet, true);
            this->sprite.setTextureRect(this->BegintRect);
            this->timer = 0.f;
        }
        ~Animation(){};
        // переключение аниамаций
        void play(const float &deltaTime)
        {
            this->timer += 100.f * deltaTime;
            if (this->timer >= this->speedTimer)
            {
                this->timer = 0.f;
                if (this->CurRect != this->EndRect)
                {
                    this->CurRect.left += this->width;
                }
                else
                {
                    this->CurRect.left = this->BegintRect.left;
                }
            }
            this->sprite.setTextureRect(this->CurRect);
        }

        void reset()
        {
            this->timer = 0.f;
            this->CurRect = this->BegintRect;
        }
    };

    Sprite &sprite;
    Texture &textureSheet;
    map<string, Animation *> animations;
    Animation *lastAnimation;

public:
    AnimationPlayer(Sprite &sprite, Texture &textureSheet);
    virtual ~AnimationPlayer();

    void AddAnimation(string key, float speed, int BeginFrameX, int BeginFrameY, int FrameX, int FrameY, int width, int height);
    void play(const string key, const float &deltaTime);
};

#endif