#include "Headers/GameState.hpp"

void GameState::InitView()
{
    this->view.setSize(
        sf::Vector2f(
            static_cast<float>(this->window->getSize().x / 2),
            static_cast<float>(this->window->getSize().y / 2)));

    this->view.setCenter(
        sf::Vector2f(
            static_cast<float>(this->window->getSize().x) / 2.f,
            static_cast<float>(this->window->getSize().y) / 2.f));
}

void GameState::InitKeyBinds()
{
    ifstream in("Config//supportGameKeys.ini");
    if (in.is_open())
    {
        string s = "";
        string s1 = "";
        while (in >> s >> s1)
            this->keyBinds[s] = this->supportKeys->at(s1);
    }
    in.close();
}

void GameState::InitTextures()
{
    if (!this->textures["PLAYER"].loadFromFile("Resourses//spritesheet.png"))
        throw("Error load sprite in GameState");
}

void GameState::InitPauseMenu()
{
    this->pause_menu = new PauseMenu(*this->window, this->font);
    this->pause_menu->AddButton("QUIT", 300.f, "Выход");
    this->pause_menu->AddButton("GO", 200.f, "Продолжить");
}

void GameState::InitPlayers()
{
    this->player = new Player(0, 0, this->textures["PLAYER"]);
}
void GameState::InitFonts()
{
    if (!this->font.loadFromFile("Font//1font.ttf"))
    {
        throw("Error::MenuState::could not load font");
    }
}
void GameState::InitTileMap()
{
    if (this->level == 1)
        this->map = new TileMap("Resourses//first.txt");
    if (this->level == 2)
        this->map = new TileMap("Resourses//second.txt");
    if (this->level == 3)
        this->map = new TileMap("Resourses//third.txt");
    if (this->level == 4)
        this->map = new TileMap("Resourses//fourth.txt");
    if (this->level == 5)
        this->map = new TileMap("Resourses//five.txt");
}

GameState::GameState(BaseStateData *BaseState, string name, const int level) : State(BaseState), NamePlayer(name), level(level)
{
    this->InitView();
    this->InitKeyBinds();
    this->InitFonts();
    this->InitTextures();
    this->InitPauseMenu();
    this->InitPlayers();
    this->InitTileMap();
}

GameState::~GameState()
{
    delete this->pause_menu;
    delete this->player;
}

void GameState::updatePauseButtons()
{
    if (this->pause_menu->isButtonPressed("QUIT"))
    {
        this->endState();
    }
    if (this->pause_menu->isButtonPressed("GO"))
        this->UnPaused();
}

void GameState::updatePlayer(const float &deltaTime)
{
    if (Keyboard::isKeyPressed(Keyboard::Key(this->keyBinds.at("LEFT"))))
        this->player->move(-1.f, 0.f, deltaTime);
    if (Keyboard::isKeyPressed(Keyboard::Key(this->keyBinds.at("RIGHT"))))
        this->player->move(1.f, 0.f, deltaTime);
    if (Keyboard::isKeyPressed(Keyboard::Key(this->keyBinds.at("UP"))))
        this->player->move(0.f, -1.f, deltaTime);
    if (Keyboard::isKeyPressed(Keyboard::Key(this->keyBinds.at("DOWN"))))
        this->player->move(0.f, 1.f, deltaTime);
}

void GameState::updateInput(const float &deltaTime)
{
    static bool flag = false;
    bool pause = Keyboard::isKeyPressed(Keyboard::Key(this->keyBinds.at("CLOSE")));
    if (pause && !flag)
    {
        if (!this->paused)
            this->Paused();
        else
            this->UnPaused();
    }
    if (pause && flag)
    {
    }
    if (!pause && flag)
    {
    }
    flag = pause;
}

void GameState::updateTime()
{
    this->timeGame = this->time1.getElapsedTime().asSeconds();
}

void GameState::updateView(const float &deltaTime)
{
    this->view.setCenter(
        std::floor(this->player->getPosition().x + (static_cast<float>(this->mousePosWindow.x) - static_cast<float>(VideoMode::getDesktopMode().width / 2)) / 10.f),
        std::floor(this->player->getPosition().y + (static_cast<float>(this->mousePosWindow.y) - static_cast<float>(VideoMode::getDesktopMode().height / 2)) / 10.f));

    if (this->map->getMaxSizeF().x >= this->view.getSize().x)
    {
        if (this->view.getCenter().x - this->view.getSize().x / 2.f < 0.f)
        {
            this->view.setCenter(0.f + this->view.getSize().x / 2.f, this->view.getCenter().y);
        }
        else if (this->view.getCenter().x + this->view.getSize().x / 2.f > this->map->getMaxSizeF().x)
        {
            this->view.setCenter(this->map->getMaxSizeF().x - this->view.getSize().x / 2.f, this->view.getCenter().y);
        }
    }

    if (this->map->getMaxSizeF().y >= this->view.getSize().y)
    {
        if (this->view.getCenter().y - this->view.getSize().y / 2.f < 0.f)
        {
            this->view.setCenter(this->view.getCenter().x, 0.f + this->view.getSize().y / 2.f);
        }
        else if (this->view.getCenter().y + this->view.getSize().y / 2.f > this->map->getMaxSizeF().y)
        {
            this->view.setCenter(this->view.getCenter().x, this->map->getMaxSizeF().y - this->view.getSize().y / 2.f);
        }
    }
}

void GameState ::update(const float &deltaTime)
{
    this->updateMousePosition();
    this->updateInput(deltaTime);
    if (!this->paused)
    {
        this->updateTime();
        this->updateView(deltaTime);
        this->map->updateWorldCollision(this->player);
        this->updatePlayer(deltaTime);
        if (this->map->updateWallCollision(this->player, deltaTime))
        {
            time1.restart();
            string txtFile = to_string(this->level);
            ofstream results("Results//" + txtFile, ios::app | ios::binary);
            if (results.is_open())
            {
                results << this->NamePlayer;
                results << " ";
                results << this->level;
                results << " ";
                results << this->timeGame;
                results << "\n";
            }
            results.close();
            this->situations->pop();
            this->situations->push(new WinState(this->BaseState, this->level, this->timeGame, this->NamePlayer));
        }
        this->player->update(deltaTime);
    }
    else
    {
        this->pause_menu->update(this->mousePosView);
        this->updatePauseButtons();
    }
}

void GameState ::render(RenderTarget *target)
{
    if (!target)
        target = this->window;

    target->setView(this->view);

    this->map->render(*target);
    this->player->render(*target);

    if (this->paused)
    {
        target->setView(this->window->getDefaultView());
        this->pause_menu->render(*target);
    }
}