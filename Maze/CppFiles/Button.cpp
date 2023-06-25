#include "Headers/Button.hpp"

Button::Button(float x, float y, float width, float height, Font *font, const string Text, unsigned sizeText, Color textIdCol, Color textHovCol, Color textActCol, Color idleColor, Color hoverColor, Color activeColor)
{
    this->shape.setPosition(Vector2f(x, y));
    this->shape.setSize(Vector2f(width, height));
    this->shape.setFillColor(idleColor);

    this->buttonState = BTN_IDLE;

    this->font = font;
    this->text.setFont(*this->font);

    this->text.setString(Text);
    this->text.setFillColor(textIdCol);
    this->text.setCharacterSize(sizeText);
    this->text.setPosition(
        this->shape.getPosition().x + this->shape.getGlobalBounds().width / 2.f - this->text.getGlobalBounds().width / 2.f,
        this->shape.getPosition().y + this->shape.getGlobalBounds().height / 2.f - this->text.getGlobalBounds().height / 2.f);

    this->textIdCol = textIdCol;
    this->textHovCol = textHovCol;
    this->textActCol = textActCol;

    this->idleColor = idleColor;
    this->hoverColor = hoverColor;
    this->activeColor = activeColor;

    this->shape.setFillColor(this->idleColor);
}

Button::~Button()
{
}

const bool Button::isPressed() const
{
    if (this->buttonState == BTN_ACTIVE)
        return true;
    return false;
}
void Button::update(Vector2f mousePos)
{

    this->buttonState = BTN_IDLE;
    if (this->shape.getGlobalBounds().contains(mousePos))
    {
        this->buttonState = BTN_HOVER;

        if (Mouse::isButtonPressed(Mouse::Left))
        {
            this->buttonState = BTN_ACTIVE;
        }
    }

    switch (this->buttonState)
    {
    case BTN_IDLE:
        this->shape.setFillColor(this->idleColor);
        this->text.setFillColor(this->textIdCol);
        break;
    case BTN_HOVER:
        this->shape.setFillColor(this->hoverColor);
        this->text.setFillColor(this->textHovCol);
        break;
    case BTN_ACTIVE:
        this->shape.setFillColor(this->activeColor);
        this->text.setFillColor(this->textActCol);
        break;

    default:
        this->shape.setFillColor(Color::Red);
        this->text.setFillColor(Color::Red);
        break;
    }
}

void Button::render(RenderTarget &target)
{
    target.draw(this->shape);
    target.draw(this->text);
}
