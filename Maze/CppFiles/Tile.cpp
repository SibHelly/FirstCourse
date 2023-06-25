#include "Headers/Tile.hpp"

Tile::Tile()
{
    this->collision = false;
    this->type = 0;
}

Tile::Tile(float x, float y, float gridSizeF, Texture &texture, int inx, int iny, int type, bool collision)
{

    this->tile.setTexture(texture);
    this->tile.setTextureRect(IntRect(inx, iny, static_cast<int>(gridSizeF), static_cast<int>(gridSizeF)));
    this->tile.setPosition(x, y);
    this->type = type;
    this->collision = collision;
}
const short &Tile::getType() const
{
    return this->type;
}

const bool &Tile::getCollision() const
{
    return this->collision;
}

const Vector2f &Tile::getPosition() const
{
    this->tile.getPosition();
}

const FloatRect Tile::getGloabalBounds() const
{
    return this->tile.getGlobalBounds();
}

const bool Tile::intersects(const FloatRect bounds) const
{
    return this->tile.getGlobalBounds().intersects(bounds);
}

Tile::~Tile()
{
}

void Tile::render(RenderTarget &target)
{
    target.draw(this->tile);
}
