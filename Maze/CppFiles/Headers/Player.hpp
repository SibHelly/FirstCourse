#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "Entity.hpp"

class Player : public Entity
{
private:
public:
    Player(float x, float y, Texture &textureSheet); // �������� ������
    virtual ~Player();

    virtual void update(const float &deltatime); // ���������� ������
};

#endif