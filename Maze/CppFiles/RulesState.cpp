#include "Headers/RulesState.hpp"

void RulesState::InitBackGround()
{
    this->BackGround.setSize(Vector2f(static_cast<float>(this->window->getSize().x), static_cast<float>(this->window->getSize().y)));
    if (!this->BackGrounTexture.loadFromFile("Resourses//win.png"))
    {
        throw("Error: Rule_State could not load background texture");
    }
    this->BackGround.setTexture(&this->BackGrounTexture);
}

void RulesState::InitFonts()
{
    if (!this->font.loadFromFile("Font//1font.ttf"))
    {
        throw("Error::Rule_State::could not load font");
    }
}

void RulesState::InitButtons()
{

    this->button = new Button(this->window->getSize().x / 2.f - this->window->getSize().x / 8.f, this->window->getSize().y / 2.f + 3.f * this->window->getSize().y / 8.f, static_cast<float>(window->getSize().x) / 4.f, 80.f, &this->font, "Выход", 30, Color(255, 0, 0, 255), Color(250, 250, 250, 250), Color(20, 20, 20, 50), Color(100, 100, 100, 0), Color(150, 150, 150, 0), Color(20, 20, 20, 0));
}

RulesState::RulesState(BaseStateData *BaseState) : State(BaseState)
{
    this->InitBackGround();
    this->InitFonts();
    this->InitKeyBinds();
    this->InitButtons();

    this->heading.setSize(Vector2f(static_cast<float>(window->getSize().x) / 2.f + static_cast<float>(window->getSize().x) / 4.f, static_cast<float>(window->getSize().y) - 100.f));
    this->heading.setFillColor(Color(20, 20, 20, 200));
    this->heading.setPosition(static_cast<float>(window->getSize().x) / 2.f - this->heading.getSize().x / 2.f, this->window->getSize().y / 8.f - 100.f);

    this->history.setSize(Vector2f(static_cast<float>(window->getSize().x) / 2.f, static_cast<float>(window->getSize().y) / 4.f + static_cast<float>(window->getSize().y) / 8.f - 100.f));
    this->history.setFillColor(Color(20, 20, 20, 0));
    this->history.setPosition(static_cast<float>(window->getSize().x) / 2.f - this->history.getSize().x / 2.f, this->window->getSize().y / 8.f);

    this->rule.setSize(Vector2f(static_cast<float>(window->getSize().x) / 2.f, static_cast<float>(window->getSize().y) / 4.f + static_cast<float>(window->getSize().y) / 8.f));
    this->rule.setFillColor(Color(20, 20, 20, 0));
    this->rule.setPosition(static_cast<float>(window->getSize().x) / 2.f - this->rule.getSize().x / 2.f, this->window->getSize().y / 8.f + 200.f);

    this->RulesText.setFont(font);
    this->RulesText.setFillColor(Color(255, 0, 0, 255));
    this->RulesText.setCharacterSize(30);
    this->RulesText.setString("\t Управление\n\nW - двигаться вверх\nS - двигаться вниз\nD - двигаться вправо\nA - двигаться влево\nEscape - пауза");
    this->RulesText.setPosition(this->rule.getPosition().x + this->rule.getSize().x / 2.f - this->RulesText.getGlobalBounds().width / 2.f, this->rule.getPosition().y + 30.f);

    this->HistoryText.setFont(font);
    this->HistoryText.setFillColor(Color(255, 0, 0, 255));
    this->HistoryText.setCharacterSize(30);
    this->HistoryText.setString("\t\t\t\tСправка\n\n\tЧтобы пройти игру, вам придется\nвыбраться из 5 захватывающих лаби-\nринтов, управляя мышью.");
    this->HistoryText.setPosition(this->history.getPosition().x + this->history.getSize().x / 2.f - this->HistoryText.getGlobalBounds().width / 2.f, this->history.getPosition().y + 30.f);

    this->HeadingText.setFont(font);
    this->HeadingText.setFillColor(Color(255, 0, 0, 255));
    this->HeadingText.setCharacterSize(64);
    this->HeadingText.setString("Правила и справка");
    this->HeadingText.setPosition(this->heading.getPosition().x + this->heading.getSize().x / 2.f - this->HeadingText.getGlobalBounds().width / 2.f, this->heading.getPosition().y + 30.f);
}

RulesState::~RulesState()
{
    delete this->button;
}

void RulesState::updateInput(const float &deltaTime)
{
}
void RulesState::updateButtons()
{
    this->button->update(this->mousePosView);

    if (this->button->isPressed())
    {
        this->endState();
    }
}

void RulesState::update(const float &deltaTime)
{
    this->updateMousePosition();
    this->updateInput(deltaTime);
    this->updateButtons();
}

void RulesState::renderButtons(RenderTarget &target)
{
    this->button->render(target);
}

void RulesState::render(RenderTarget *target)
{
    if (!target)
        target = this->window;

    target->draw(this->BackGround);
    target->draw(this->heading);
    target->draw(this->history);
    target->draw(this->rule);
    this->renderButtons(*target);

    target->draw(this->HeadingText);
    target->draw(this->HistoryText);
    target->draw(this->RulesText);
}
