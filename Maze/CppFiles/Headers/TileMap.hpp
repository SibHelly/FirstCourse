#ifndef TILEMAP_HPP
#define TILEMAP_HPP

#include "Tile.hpp"

class TileMap
{
private:
    void clearTileMap();
    Texture tilesheet;                  // �������� ��� ������
    float gridSizeF;                    // ������ �����
    unsigned gridSize;                  // ������ �����
    Vector2f maxWorldSize;              // ������������ ������ ����� �� �����������
    Vector2u maxSize;                   // ������ ����� �� ���������� ���������
    vector<vector<vector<Tile *>>> map; // �����
    unsigned layers;                    // ����
    string tileName;                    // ��� ����� � ����������

    // ��� ������� ����������
    int firstX;
    int secondX;
    int firstY;
    int secondY;

public:
    TileMap();
    TileMap(const string file_name);                                    // �������� �� �����
    ~TileMap() { this->clearTileMap(); };                               // ������� ������
    const Vector2f &getMaxSizeF() const { return this->maxWorldSize; }; // �������� ������������ ������
    void updateWorldCollision(Entity *player);                          // ������� � ��������� �����
    bool updateWallCollision(Entity *player, const float &deltaTime);   // ������� �� �������

    void render(RenderTarget &target); // ���������� �����
};

#endif