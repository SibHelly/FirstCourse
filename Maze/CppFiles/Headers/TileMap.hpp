#ifndef TILEMAP_HPP
#define TILEMAP_HPP

#include "Tile.hpp"

class TileMap
{
private:
    void clearTileMap();
    Texture tilesheet;                  // текструы для тайлов
    float gridSizeF;                    // размер сетки
    unsigned gridSize;                  // размер сетки
    Vector2f maxWorldSize;              // максимальный размер карты по координатам
    Vector2u maxSize;                   // размер сетки по количеству элементов
    vector<vector<vector<Tile *>>> map; // карта
    unsigned layers;                    // слой
    string tileName;                    // имя фалйа с текстурами

    // для колизий координаты
    int firstX;
    int secondX;
    int firstY;
    int secondY;

public:
    TileMap();
    TileMap(const string file_name);                                    // создание из фалйа
    ~TileMap() { this->clearTileMap(); };                               // очистка памяти
    const Vector2f &getMaxSizeF() const { return this->maxWorldSize; }; // получить максимальный размер
    void updateWorldCollision(Entity *player);                          // колизия с границами карты
    bool updateWallCollision(Entity *player, const float &deltaTime);   // колизия со стенами

    void render(RenderTarget &target); // прорисовка карты
};

#endif