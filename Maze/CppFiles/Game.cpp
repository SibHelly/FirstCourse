#include "Headers/Game.hpp"

void Game::InitVariables()
{
    this->window = NULL;
    this->deltaTime = 0.f;
    this->gridSize = 50.f;
}

void Game::InitWindow()
{
    ifstream in("Config//window.txt");

    string title = "None";
    VideoMode windowBounds = VideoMode::getDesktopMode();
    bool fullscreen = false;
    unsigned frameRateLimits = 120;
    bool verticalSyncEnabl = false;
    if (in.is_open())
    {
        getline(in, title);
        in >> windowBounds.width >> windowBounds.height;
        in >> fullscreen;
        in >> frameRateLimits;
        in >> verticalSyncEnabl;
    }
    in.close();
    this->fullscreen = fullscreen;
    if (this->fullscreen)
        this->window = new RenderWindow(windowBounds, title, Style::Fullscreen);
    else
        this->window = new RenderWindow(windowBounds, title, Style::Titlebar | Style::Close);
    this->window->setFramerateLimit(frameRateLimits);
    this->window->setVerticalSyncEnabled(verticalSyncEnabl);
}

void Game::InitKeys()
{
    ifstream in("Config//supportKeys.txt");

    if (in.is_open())
    {
        string s = "";
        int value = 0;
        while (in >> s >> value)
            this->SupportKeys[s] = value;
    }
    in.close();
}

void Game::InitFont()
{
    if (!this->font.loadFromFile("Font//1font.ttf"))
    {
        cout << "Error::Game::could not load font";
    }
}

void Game::InitMusic()
{
    if (!this->music.openFromFile("Resourses//music.ogg"))
    {
        cout << "Error::Game::could not load font";
    }
    this->music.play();
}

void Game::InitPreview()
{
    this->BackGround.setSize(Vector2f(static_cast<float>(this->window->getSize().x), static_cast<float>(this->window->getSize().y)));
    if (!this->BackGrounTexture.loadFromFile("Resourses//level.png"))
    {
        cout << "Error: Game could not load background texture for preview";
    }
    this->BackGround.setTexture(&this->BackGrounTexture);

    this->container.setSize(Vector2f(static_cast<float>(this->window->getSize().x) / 2.f - 300.f, static_cast<float>(this->window->getSize().y) - 100.f));
    this->container.setFillColor(Color(20, 20, 20, 0));
    this->container.setPosition(this->window->getSize().x / 2.f - this->window->getSize().x / 8.f, 100.f);

    this->text.setFont(font);
    this->text.setFillColor(Color(255, 40, 50, 255));
    this->text.setCharacterSize(50);
    this->text.setString("\t\t\tЛАБИРИНТ\n\n\n\n\n\n\nВыполнил студент группы О722Б\n\n\t\tВяткин Никита");
    this->text.setPosition(this->container.getPosition().x + this->container.getSize().x / 2.f - this->text.getGlobalBounds().width / 2.f, this->container.getPosition().y + 30.f);
}

void Game::InitBaseState()
{
    this->BaseState.window = this->window;
    this->BaseState.supportKeys = &this->SupportKeys;
    this->BaseState.situations = &this->situations;
    this->BaseState.grizSize = this->gridSize;
}

void Game::InitStates()
{
    this->situations.push(new MenuState(&this->BaseState));
}

Game::Game()
{
    this->InitVariables();
    this->InitWindow();
    this->InitFont();
    this->InitMusic();
    this->InitPreview();
    this->InitKeys();
    this->InitBaseState();
    this->InitStates();
}

Game::~Game()
{
    delete this->window;
    while (!this->situations.empty())
    {
        delete this->situations.top();
        this->situations.pop();
    }
}
// Функции
void Game::updateSFMLEvents()
{
    while (this->window->pollEvent(this->event))
    {
        if (this->event.type == Event::Closed)
            this->window->close();
    }
}

void Game::UpdateDeltaTime()
{
    this->deltaTime = this->deltaClock.restart().asSeconds();
    this->time = this->timer.getElapsedTime().asSeconds();
}

void Game::update()
{
    this->updateSFMLEvents();
    if (!this->situations.empty())
    {
        this->situations.top()->update(this->deltaTime);

        if (this->situations.top()->getQuit())
        {
            this->situations.top()->endState();
            delete this->situations.top();
            this->situations.pop();
        }
    }
    else
    {
        this->window->close();
    }
}

void Game::render()
{
    this->window->clear();
    if (!this->situations.empty())
    {
        if (this->time < 5.f)
        {
            this->window->draw(this->BackGround);
            this->window->draw(this->container);
            this->window->draw(this->text);
        }
        else
            this->situations.top()->render(this->window);
    }
    this->window->display();
}

void Game::run()
{

    while (this->window->isOpen())
    {
        this->UpdateDeltaTime();
        this->update();
        this->render();
    }
}
