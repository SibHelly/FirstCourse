#ifndef TILE_HPP
#define TILE_HPP

#include "Entity.hpp"

class Tile
{
private:
    Sprite tile;    // ������ ��� �����
    short type;     // ��� �����
    bool collision; // �������

public:
    Tile();
    Tile(float x, float y, float gridSizeF, Texture &texture, int inx, int iny, int type, bool collision); // �������� �����

    virtual ~Tile();

    const short &getType() const;                        // �������� ���
    const bool &getCollision() const;                    // �������� �������
    const Vector2f &getPosition() const;                 // �������� �������
    const FloatRect getGloabalBounds() const;            // �������� ������������
    const bool intersects(const FloatRect bounds) const; // �������� ��������� �� ������������ ��� ���

    void render(RenderTarget &target); // ����������
};

#endif