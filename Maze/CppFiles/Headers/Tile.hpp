#ifndef TILE_HPP
#define TILE_HPP

#include "Entity.hpp"

class Tile
{
private:
    Sprite tile;    // спрайт для тайла
    short type;     // тип тайла
    bool collision; // колизия

public:
    Tile();
    Tile(float x, float y, float gridSizeF, Texture &texture, int inx, int iny, int type, bool collision); // создание тайла

    virtual ~Tile();

    const short &getType() const;                        // получить тип
    const bool &getCollision() const;                    // получить колизию
    const Vector2f &getPosition() const;                 // получить позицию
    const FloatRect getGloabalBounds() const;            // получить столкновение
    const bool intersects(const FloatRect bounds) const; // получить произошло ли столкновение иои нет

    void render(RenderTarget &target); // прорисовка
};

#endif