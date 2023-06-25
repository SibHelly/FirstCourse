#include "Headers/PauseMenu.hpp"

PauseMenu::PauseMenu(RenderWindow &window, Font &font) : font(font)
{
    this->background.setSize(Vector2f(static_cast<float>(window.getSize().x), static_cast<float>(window.getSize().y)));
    this->background.setFillColor(Color(20, 20, 20, 100));

    this->container.setSize(Vector2f(static_cast<float>(window.getSize().x) / 4.f, static_cast<float>(window.getSize().y) - 100.f));
    this->container.setFillColor(Color(20, 20, 20, 200));
    this->container.setPosition(static_cast<float>(window.getSize().x) / 2.f - this->container.getSize().x / 2.f, 50.f);

    this->menuText.setFont(font);
    this->menuText.setFillColor(Color(255, 255, 255, 200));
    this->menuText.setCharacterSize(64);
    this->menuText.setString("ÏÀÓÇÀ");
    this->menuText.setPosition(this->container.getPosition().x + this->container.getSize().x / 2.f - this->menuText.getGlobalBounds().width / 2.f, this->container.getPosition().y + 30.f);
}

PauseMenu::~PauseMenu()
{
    auto i = this->buttons.begin();
    for (i = this->buttons.begin(); i != this->buttons.end(); ++i)
    {
        delete i->second;
    }
}

const bool PauseMenu::isButtonPressed(const string key)
{
    return this->buttons[key]->isPressed();
}

void PauseMenu::AddButton(const string key, float y, const string Text)
{
    float width = 380.f;
    float x = this->container.getPosition().x + this->container.getSize().x / 2.f - width / 2.f;
    this->buttons[key] = new Button(x, y, width, 80.f, &this->font, Text, 30, Color(70, 70, 70, 200), Color(250, 250, 250, 250), Color(20, 20, 20, 50), Color(100, 100, 100, 0), Color(150, 150, 150, 0), Color(20, 20, 20, 0));
}

void PauseMenu::update(const Vector2f &mousePos)
{
    for (auto i : this->buttons)
    {
        i.second->update(mousePos);
    }
}

void PauseMenu::render(RenderTarget &target)
{
    target.draw(this->background);
    target.draw(this->container);

    for (auto &i : this->buttons)
    {
        i.second->render(target);
    }

    target.draw(this->menuText);
}
