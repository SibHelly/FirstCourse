#include "Headers/MenuState.hpp"
void MenuState::InitBackGround()
{
    this->BackGround.setSize(Vector2f(static_cast<float>(this->window->getSize().x), static_cast<float>(this->window->getSize().y)));
    if (!this->BackGrounTexture.loadFromFile("Resourses//2.png"))
    {
        throw("Error: Menu_State could not load background texture");
    }
    this->BackGround.setTexture(&this->BackGrounTexture);
    this->container.setSize(Vector2f(static_cast<float>(this->BaseState->window->getSize().x) / 4.f, static_cast<float>(this->BaseState->window->getSize().y) - 100.f));
    this->container.setFillColor(Color(100, 100, 100, 0));
    this->container.setPosition(this->window->getSize().x / 2.f - this->window->getSize().x / 8.f, 100.f);

    this->text.setFont(font);
    this->text.setFillColor(Color(0, 255, 250, 255));
    this->text.setCharacterSize(64);
    this->text.setString("Дикий ЛАБИРИНТ");
    this->text.setPosition(this->container.getPosition().x + this->container.getSize().x / 2.f - this->text.getGlobalBounds().width / 2.f, this->container.getPosition().y + 30.f);
}

void MenuState::InitFonts()
{
    if (!this->font.loadFromFile("Font//1font.ttf"))
    {
        throw("Error::MenuState::could not load font");
    }
}

void MenuState::InitKeyBinds()
{
}
void MenuState::InitButtons()
{
    this->buttons["GAME"] = new Button(this->window->getSize().x / 2.f - this->window->getSize().x / 8.f, 300.f, 380.f, 80.f, &this->font, "Новая игра", 30, Color(0, 255, 250, 255), Color(250, 250, 250, 250), Color(20, 20, 20, 50), Color(100, 100, 100, 0), Color(150, 150, 150, 0), Color(20, 20, 20, 0));
    this->buttons["CONTROL_RULES"] = new Button(this->window->getSize().x / 2.f - this->window->getSize().x / 8.f, 450.f, 380.f, 80.f, &this->font, "Правила игры и справка", 30, Color(0, 255, 250, 255), Color(250, 250, 250, 250), Color(20, 20, 20, 50), Color(100, 100, 100, 0), Color(150, 150, 150, 0), Color(20, 20, 20, 0));
    this->buttons["RESULTS"] = new Button(this->window->getSize().x / 2.f - this->window->getSize().x / 8.f, 600.f, 380.f, 80.f, &this->font, "Результаты", 30, Color(0, 255, 250, 255), Color(250, 250, 250, 250), Color(20, 20, 20, 50), Color(100, 100, 100, 0), Color(150, 150, 150, 0), Color(20, 20, 20, 0));
    this->buttons["EXIT"] = new Button(this->window->getSize().x / 2.f - this->window->getSize().x / 8.f, 750.f, 380.f, 80.f, &this->font, "Выход", 30, Color(0, 255, 250, 255), Color(250, 250, 250, 250), Color(20, 20, 20, 50), Color(100, 100, 100, 0), Color(150, 150, 150, 0), Color(20, 20, 20, 0));
}

MenuState::MenuState(BaseStateData *BaseState) : State(BaseState)
{
    this->InitFonts();
    this->InitBackGround();
    this->InitKeyBinds();
    this->InitButtons();
}
MenuState::~MenuState()
{
    auto i = this->buttons.begin();
    for (i = this->buttons.begin(); i != this->buttons.end(); ++i)
    {
        delete i->second;
    }
}

void MenuState::updateInput(const float &deltaTime)
{
}
void MenuState::updateButtons()
{
    for (auto &i : this->buttons)
    {
        i.second->update(this->mousePosView);
    }
    if (this->buttons["GAME"]->isPressed())
    {
        this->situations->push(new LevelState(this->BaseState));
    }
    if (this->buttons["CONTROL_RULES"]->isPressed())
    {
        this->situations->push(new RulesState(this->BaseState));
    }
    if (this->buttons["RESULTS"]->isPressed())
    {
        this->situations->push(new ResultState(this->BaseState));
    }
    if (this->buttons["EXIT"]->isPressed())
    {
        this->endState();
    }
}

void MenuState ::update(const float &deltaTime)
{
    this->updateMousePosition();
    this->updateInput(deltaTime);
    this->updateButtons();
}

void MenuState::renderButtons(RenderTarget &target)
{
    for (auto &i : this->buttons)
    {
        i.second->render(target);
    }
}

void MenuState ::render(RenderTarget *target)
{
    if (!target)
        target = this->window;

    target->draw(this->BackGround);
    target->draw(this->container);
    target->draw(this->text);
    this->renderButtons(*target);
}
