#include "Headers/ResultState.hpp"

void ResultState::InitBackGround()
{
    this->BackGround.setSize(Vector2f(static_cast<float>(this->window->getSize().x), static_cast<float>(this->window->getSize().y)));
    if (!this->BackGrounTexture.loadFromFile("Resourses//level.png"))
    {
        throw("Error: Menu_State could not load background texture");
    }
    this->BackGround.setTexture(&this->BackGrounTexture);
}

void ResultState::InitFonts()
{
    if (!this->font.loadFromFile("Font//1font.ttf"))
    {
        throw("Error::MenuState::could not load font");
    }
}

void ResultState::InitButtons()
{
    this->buttons["FIRST"] = new Button(this->window->getSize().x / 2.f - this->window->getSize().x / 8.f, 200.f, static_cast<float>(window->getSize().x) / 4.f, 60.f, &this->font, "Первый уровень", 30, Color(255, 0, 40, 255), Color(250, 250, 250, 250), Color(20, 20, 20, 50), Color(100, 100, 100, 0), Color(150, 150, 150, 0), Color(20, 20, 20, 0));
    this->buttons["SECOND"] = new Button(this->window->getSize().x / 2.f - this->window->getSize().x / 8.f, 320.f, static_cast<float>(window->getSize().x) / 4.f, 60.f, &this->font, "Второй уровень", 30, Color(255, 0, 40, 255), Color(250, 250, 250, 250), Color(20, 20, 20, 50), Color(100, 100, 100, 0), Color(150, 150, 150, 0), Color(20, 20, 20, 0));
    this->buttons["THIRD"] = new Button(this->window->getSize().x / 2.f - this->window->getSize().x / 8.f, 440.f, static_cast<float>(window->getSize().x) / 4.f, 60.f, &this->font, "Третий уровень", 30, Color(255, 0, 40, 255), Color(250, 250, 250, 250), Color(20, 20, 20, 50), Color(100, 100, 100, 0), Color(150, 150, 150, 0), Color(20, 20, 20, 0));
    this->buttons["FOURTH"] = new Button(this->window->getSize().x / 2.f - this->window->getSize().x / 8.f, 560.f, static_cast<float>(window->getSize().x) / 4.f, 60.f, &this->font, "Четвертый уровень", 30, Color(255, 0, 40, 255), Color(250, 250, 250, 250), Color(20, 20, 20, 50), Color(100, 100, 100, 0), Color(150, 150, 150, 0), Color(20, 20, 20, 0));
    this->buttons["FIVETH"] = new Button(this->window->getSize().x / 2.f - this->window->getSize().x / 8.f, 680.f, static_cast<float>(window->getSize().x) / 4.f, 60.f, &this->font, "Пятый уровень", 30, Color(255, 0, 40, 255), Color(250, 250, 250, 250), Color(20, 20, 20, 50), Color(100, 100, 100, 0), Color(150, 150, 150, 0), Color(20, 20, 20, 0));
    this->buttons["EXIT"] = new Button(this->window->getSize().x / 2.f - this->window->getSize().x / 8.f, 850.f, static_cast<float>(window->getSize().x) / 4.f, 60.f, &this->font, "Выход", 30, Color(255, 0, 40, 255), Color(250, 250, 250, 250), Color(20, 20, 20, 50), Color(100, 100, 100, 0), Color(150, 150, 150, 0), Color(20, 20, 20, 0));
}

ResultState::ResultState(BaseStateData *BaseState) : State(BaseState)
{
    this->level = -1;
    this->InitBackGround();
    this->InitFonts();
    this->InitKeyBinds();
    this->InitButtons();

    this->container.setSize(Vector2f(static_cast<float>(window->getSize().x) / 2.f, static_cast<float>(window->getSize().y) - 100.f));
    this->container.setFillColor(Color(20, 20, 20, 200));
    this->container.setPosition(static_cast<float>(window->getSize().x) / 2.f - this->container.getSize().x / 2.f, 50.f);

    this->menuText.setFont(font);
    this->menuText.setFillColor(Color(255, 0, 40, 255));
    this->menuText.setCharacterSize(64);
    this->menuText.setString("Лучшие результаты");
    this->menuText.setPosition(this->container.getPosition().x + this->container.getSize().x / 2.f - this->menuText.getGlobalBounds().width / 2.f, this->container.getPosition().y + 30.f);
}

ResultState::~ResultState()
{
    auto i = this->buttons.begin();
    for (i = this->buttons.begin(); i != this->buttons.end(); ++i)
    {
        delete i->second;
    }
}

void ResultState::updateInput(const float &deltaTime)
{
}

void ResultState::updateButtons()
{
    for (auto &i : this->buttons)
    {
        i.second->update(this->mousePosView);
    }
    bool flag = 0;
    if (this->buttons["FIRST"]->isPressed())
    {
        this->level = 1;
        flag = 1;
    }
    if (this->buttons["SECOND"]->isPressed())
    {
        this->level = 2;
        flag = 1;
    }
    if (this->buttons["THIRD"]->isPressed())
    {
        this->level = 3;
        flag = 1;
    }
    if (this->buttons["FOURTH"]->isPressed())
    {
        this->level = 4;
        flag = 1;
    }
    if (this->buttons["FIVETH"]->isPressed())
    {
        this->level = 5;
        flag = 1;
    }
    if (this->buttons["EXIT"]->isPressed())
    {
        this->endState();
    }
    if (flag == 1)
    {
        this->situations->push(new TableState(this->BaseState, this->level));
    }
}

void ResultState::update(const float &deltaTime)
{
    this->updateMousePosition();
    this->updateInput(deltaTime);
    this->updateButtons();
}

void ResultState::renderButtons(RenderTarget &target)
{
    for (auto &i : this->buttons)
    {
        i.second->render(target);
    }
}

void ResultState::render(RenderTarget *target)
{
    if (!target)
        target = this->window;

    target->draw(this->BackGround);
    target->draw(this->container);

    this->renderButtons(*target);

    target->draw(this->menuText);
}
