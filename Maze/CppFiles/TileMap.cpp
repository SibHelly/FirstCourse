#include "Headers/TileMap.hpp"
void TileMap::clearTileMap()
{
    if (!this->map.empty())
        for (size_t x = 0; x < this->maxSize.x; x++)
        {
            for (size_t y = 0; y < this->maxSize.y; y++)
            {

                for (size_t z = 0; z < this->layers; z++)
                {
                    delete this->map[x][y][z];
                    this->map[x][y][z] = NULL;
                }
                this->map[x][y].clear();
            }
            this->map[x].clear();
        }
}

TileMap::TileMap()
{
    this->firstX = 0;
    this->secondX = 0;
    this->firstY = 0;
    this->secondY = 0;
    this->gridSizeF = 64.f;
    this->gridSize = static_cast<unsigned>(this->gridSizeF);
    this->maxSize.x = 25;
    this->maxSize.y = 25;
    this->layers = 1;
    if (!this->tilesheet.loadFromFile("Resourses//test.png"))
        cout << "Error of load tileshet for map";

    this->map.resize(this->maxSize.x);
    for (size_t x = 0; x < this->maxSize.x; x++)
    {
        this->map.push_back(vector<vector<Tile *>>());
        for (size_t y = 0; y < this->maxSize.y; y++)
        {
            this->map[x].resize(this->maxSize.y);
            this->map[x].push_back(vector<Tile *>());
            for (size_t z = 0; z < this->layers; z++)
            {
                this->map[x][y].resize(this->layers);
                this->map[x][y].push_back(new Tile(x * this->gridSizeF, y * this->gridSizeF, this->gridSizeF, this->tilesheet, 0, 0, 0, 0));
            }
        }
    }
}

TileMap::TileMap(const string fileName)
{
    ifstream in(fileName);
    this->firstX = 0;
    this->secondX = 0;
    this->firstY = 0;
    this->secondY = 0;
    int tileX = 0;
    int tileY = 0;
    int type = 0;
    bool collision = false;
    this->clearTileMap();
    if (in.is_open())
    {
        in >> this->gridSize;
        this->gridSizeF = static_cast<float>(this->gridSize);

        in >> this->maxSize.x >> this->maxSize.y >> layers;
        in >> tileName;

        this->maxWorldSize.x = static_cast<float>(this->maxSize.x) * gridSizeF;
        this->maxWorldSize.y = static_cast<float>(this->maxSize.y) * gridSizeF;

        this->map.resize(this->maxSize.x);
        if (!this->tilesheet.loadFromFile(tileName))
            cout << "Error of load tileshet for map";
        for (size_t x = 0; x < this->maxSize.x; x++)
        {
            this->map.push_back(vector<vector<Tile *>>());
            for (size_t y = 0; y < this->maxSize.y; y++)
            {
                this->map[x].resize(this->maxSize.y);
                this->map[x].push_back(vector<Tile *>());
                for (size_t z = 0; z < this->layers; z++)
                {
                    this->map[x][y].resize(this->layers);
                    in >> tileX >> tileY >> type >> collision;
                    this->map[x][y].push_back(new Tile(x * this->gridSizeF, y * this->gridSizeF, this->gridSizeF, this->tilesheet, tileX, tileY, type, collision));
                }
            }
        }
    }
    else
    {
        cout << "Error of open map file" << endl;
    }
}

void TileMap::updateWorldCollision(Entity *player)
{
    if (player->getPosition().x < 0.f)
    {
        // player->stopX();
        player->SetPosition(0.f, player->getPosition().y);
        player->stopX();
    }
    else if (player->getPosition().x + player->getGlobalBounds().width > this->maxWorldSize.x)
    {
        player->stopX();
        player->SetPosition(this->maxWorldSize.x - player->getGlobalBounds().width, player->getPosition().y);
        player->stopX();
    }
    if (player->getPosition().y < 0.f)
    {
        player->SetPosition(player->getPosition().x, 0.f);
        player->stopY();
    }
    else if (player->getPosition().y + player->getGlobalBounds().height > this->maxWorldSize.y)
    {
        player->SetPosition(player->getPosition().x, this->maxWorldSize.y - player->getGlobalBounds().height);
        player->stopY();
    }
}

bool TileMap::updateWallCollision(Entity *player, const float &deltaTime)
{
    this->layers = 1;
    this->firstX = player->getGridPosition(this->gridSize).x - 1;
    if (this->firstX < 0)
        this->firstX = 0;
    else if (this->firstX > this->maxSize.x)
        this->firstX = this->maxSize.x;

    this->secondX = player->getGridPosition(this->gridSize).x + 3;
    if (this->secondX < 0)
        this->secondX = 0;
    else if (this->secondX > this->maxSize.x)
        this->secondX = this->maxSize.x;

    this->firstY = player->getGridPosition(this->gridSize).y - 1;
    if (this->firstY < 0)
        this->firstY = 0;
    else if (this->firstY > this->maxSize.y)
        this->firstY = this->maxSize.y;

    this->secondY = player->getGridPosition(this->gridSize).y + 3;
    if (this->secondY < 0)
        this->secondY = 0;
    else if (this->secondY > this->maxSize.y)
        this->secondY = this->maxSize.y;

    for (int x = this->firstX; x < this->secondX; x++)
    {
        for (int y = this->firstY; y < this->secondY; y++)
        {
            FloatRect playerBounds = player->getGlobalBounds();
            FloatRect wallBounds = this->map[x][y][this->layers]->getGloabalBounds();
            FloatRect nextPositionBounds = player->getNextBounds(deltaTime);
            if (this->map[x][y][this->layers]->getCollision() && this->map[x][y][this->layers]->intersects(nextPositionBounds))
            {

                if (playerBounds.top < wallBounds.top && playerBounds.top + playerBounds.height < wallBounds.top + wallBounds.height && playerBounds.left < wallBounds.left + wallBounds.width && playerBounds.left + playerBounds.width > wallBounds.left)
                {
                    player->stopY();
                    player->SetPosition(playerBounds.left, wallBounds.top - playerBounds.height);
                }

                else if (playerBounds.top > wallBounds.top && playerBounds.top + playerBounds.height > wallBounds.top + wallBounds.height && playerBounds.left < wallBounds.left + wallBounds.width && playerBounds.left + playerBounds.width > wallBounds.left)
                {
                    player->stopY();
                    player->SetPosition(playerBounds.left, wallBounds.top + wallBounds.height);
                }

                if (playerBounds.left < wallBounds.left && playerBounds.left + playerBounds.width < wallBounds.left + wallBounds.width && playerBounds.top < wallBounds.top + wallBounds.height && playerBounds.top + playerBounds.height > wallBounds.top)
                {
                    player->stopX();
                    player->SetPosition(wallBounds.left - playerBounds.width, playerBounds.top);
                }

                else if (playerBounds.left > wallBounds.left && playerBounds.left + playerBounds.width > wallBounds.left + wallBounds.width && playerBounds.top < wallBounds.top + wallBounds.height && playerBounds.top + playerBounds.height > wallBounds.top)
                {
                    player->stopX();
                    player->SetPosition(wallBounds.left + wallBounds.width, playerBounds.top);
                }
            }
            if (this->map[x][y][this->layers]->intersects(nextPositionBounds) && this->map[x][y][this->layers]->getType() == 2)
                return true;
        }
    }
    return false;
}

void TileMap::render(RenderTarget &target)
{
    for (auto &x : this->map)
    {
        for (auto &y : x)
        {
            for (auto *z : y)
            {
                if (z != NULL)
                    z->render(target);
            }
        }
    }
}