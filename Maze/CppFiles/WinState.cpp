#include "Headers/WinState.hpp"

void WinState::InitBackGround()
{
    this->BackGround.setSize(Vector2f(static_cast<float>(this->window->getSize().x), static_cast<float>(this->window->getSize().y)));
    if (!this->BackGrounTexture.loadFromFile("Resourses//win.png"))
    {
        throw("Error: Wint_State could not load background texture");
    }
    this->BackGround.setTexture(&this->BackGrounTexture);
}

void WinState::InitFonts()
{
    if (!this->font.loadFromFile("Font//1font.ttf"))
    {
        throw("Error::WinState::could not load font");
    }
}

void WinState::InitButtons()
{
    if (this->level < 5)
    {
        this->buttons["NEXT"] = new Button(this->window->getSize().x / 2.f - this->window->getSize().x / 8.f, this->window->getSize().y / 2.f - this->window->getSize().y / 8.f, static_cast<float>(window->getSize().x) / 4.f, 80.f, &this->font, "Следующий уровень", 30, Color(255, 255, 0, 255), Color(250, 250, 250, 250), Color(20, 20, 20, 50), Color(100, 100, 100, 0), Color(150, 150, 150, 0), Color(20, 20, 20, 0));
        this->buttons["EXIT"] = new Button(this->window->getSize().x / 2.f - this->window->getSize().x / 8.f, this->window->getSize().y / 2.f, static_cast<float>(window->getSize().x) / 4.f, 80.f, &this->font, "Выход", 30, Color(255, 255, 0, 255), Color(250, 250, 250, 250), Color(20, 20, 20, 50), Color(100, 100, 100, 0), Color(150, 150, 150, 0), Color(20, 20, 20, 0));
    }
    else
    {
        this->buttons["EXIT"] = new Button(this->window->getSize().x / 2.f - this->window->getSize().x / 8.f, this->window->getSize().y / 2.f - this->window->getSize().y / 8.f, static_cast<float>(window->getSize().x) / 4.f, 80.f, &this->font, "Выход", 30, Color(255, 255, 0, 255), Color(250, 250, 250, 250), Color(20, 20, 20, 50), Color(100, 100, 100, 0), Color(150, 150, 150, 0), Color(20, 20, 20, 0));
    }
}

WinState::WinState(BaseStateData *BaseState, const int &level, const float time, const string name) : State(BaseState), NamePlayer(name), level(level)
{
    this->InitBackGround();
    this->InitFonts();
    this->InitKeyBinds();
    this->InitButtons();

    string result;

    result = "Имя игрока: " + this->NamePlayer + " " + "Уровень: " + to_string(this->level) + " Время: " + to_string(time);

    this->container.setSize(Vector2f(static_cast<float>(window->getSize().x) / 2.f + 100.f, static_cast<float>(window->getSize().y) - static_cast<float>(window->getSize().y) / 4.f));
    this->container.setFillColor(Color(20, 20, 20, 200));
    this->container.setPosition(static_cast<float>(window->getSize().x) / 2.f - this->container.getSize().x / 2.f, this->window->getSize().y / 8.f);

    this->results.setSize(Vector2f(static_cast<float>(window->getSize().x) / 4.f, static_cast<float>(window->getSize().y) - 100.f));
    this->results.setFillColor(Color(20, 20, 20, 0));
    this->results.setPosition(static_cast<float>(window->getSize().x) / 2.f - this->results.getSize().x / 2.f, this->window->getSize().y / 8.f + 150.f);

    this->menuText.setFont(font);
    this->menuText.setFillColor(Color(255, 255, 0, 255));
    this->menuText.setCharacterSize(64);
    this->menuText.setString("Вы выиграли");
    this->menuText.setPosition(this->container.getPosition().x + this->container.getSize().x / 2.f - this->menuText.getGlobalBounds().width / 2.f, this->container.getPosition().y + 30.f);

    this->res.setFont(font);
    this->res.setFillColor(Color(255, 255, 0, 255));
    this->res.setCharacterSize(30);
    this->res.setString(result);
    this->res.setPosition(this->results.getPosition().x + this->results.getSize().x / 2.f - this->res.getGlobalBounds().width / 2.f, this->results.getPosition().y + 30.f);
}

WinState::~WinState()
{
    auto i = this->buttons.begin();
    for (i = this->buttons.begin(); i != this->buttons.end(); ++i)
    {
        delete i->second;
    }
}

void WinState::updateButtons()
{
    for (auto &i : this->buttons)
    {
        i.second->update(this->mousePosView);
    }
    if (this->level < 5)
    {
        if (this->buttons["NEXT"]->isPressed())
        {
            this->situations->pop();
            this->situations->push(new GameState(this->BaseState, this->NamePlayer, this->level + 1));
        }
        if (this->buttons["EXIT"]->isPressed())
        {
            this->endState();
        }
    }
    else if (this->buttons["EXIT"]->isPressed())
    {
        this->endState();
    }
}

void WinState::update(const float &deltaTime)
{
    this->updateMousePosition();
    this->updateInput(deltaTime);
    this->updateButtons();
}

void WinState::renderButtons(RenderTarget &target)
{
    for (auto &i : this->buttons)
    {
        i.second->render(target);
    }
}

void WinState::render(RenderTarget *target)
{
    if (!target)
        target = this->window;

    target->draw(this->BackGround);

    target->draw(this->container);
    target->draw(this->results);

    this->renderButtons(*target);

    target->draw(this->menuText);
    target->draw(this->res);
}
