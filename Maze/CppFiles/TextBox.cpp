#include "Headers/TextBox.hpp"

void TextBox::IntitKeys()
{
    ifstream in("Config//TextBoxKeys.txt");
    if (in.is_open())
    {
        int s = 0;
        string s1 = "";
        while (in >> s >> s1)
            this->keys[s] = s1;
    }
    in.close();
}
void TextBox::InitVector()
{
    for (int i = 0; i <= 35; i++)
        this->flags.push_back(false);
}

TextBox::TextBox(float x, float y, float width, float height, Font *font, unsigned sizeText, Color BoxColor, Color TextColor, bool pressed)
{
    this->IntitKeys();
    this->InitVector();
    this->cur = 0;
    this->max = 8;
    this->name = "_";
    this->pressed = pressed;
    this->font = font;
    this->shape.setSize(Vector2f(width, height));
    this->shape.setFillColor(BoxColor);
    this->shape.setPosition(Vector2f(x, y));

    this->text.setFont(*this->font);
    this->text.setFillColor(Color(255, 255, 255, 200));
    this->text.setCharacterSize(sizeText);
    this->text.setPosition(Vector2f(x + width / 24.f, y + height / 4.f));
    if (pressed)
    {
        this->text.setString(this->name);
    }
    else
    {
        this->text.setString("¬ведите им€ игрока");
    }
}

void TextBox::addChar(string key)
{
    if (this->cur < this->max)
    {
        this->name.pop_back();
        this->name = this->name + key + "_";
        this->cur++;
        if (this->cur >= this->max)
            this->name.pop_back();
    }
}

void TextBox::deleteChar()
{
    if ((this->cur < this->max) && this->cur >= 1)
    {
        this->name.pop_back();
        this->name.pop_back();
        this->name = this->name + "_";
        this->cur--;
    }
    if (this->cur < 1)
    {
        this->name = "_";
        this->cur = 0;
    }
    if (this->cur == this->max)
    {
        this->name.pop_back();
        this->name = this->name + "_";
        this->cur--;
    }
}

void TextBox::KeyPressed(int i, const bool &isPressed)
{
    if (isPressed && !flags[i])
    {
        this->addChar(this->keys[i]);
    }
    if (isPressed && flags[i])
    {
    }
    if (!isPressed && flags[i])
    {
    }

    flags[i] = isPressed;
}

void TextBox::update(Vector2f mousePos)
{
    bool isPressed;
    if (this->shape.getGlobalBounds().contains(mousePos))
    {
        static bool flag = false;
        bool isPress = Mouse::isButtonPressed(Mouse::Left);
        if (isPress && !flag)
        {
            if (this->pressed == false)
                this->pressed = true;
            else
                this->pressed = false;
        }
        if (isPress && flag)
        {
        }
        if (!isPress && flag)
        {
        }
        flag = isPress;
    }
    switch (this->pressed)
    {
    case true:
        this->text.setString(this->name);
        break;
    case false:
        this->text.setString("¬ведите им€ игрока");
        break;
    }
    static bool flagB = false;
    if (this->pressed && this->cur <= this->max)
    {

        bool isPressedB = Keyboard::isKeyPressed(Keyboard::BackSpace);
        if (isPressedB && !flagB)
        {
            this->deleteChar();
        }
        if (isPressedB && flagB)
        {
        }
        if (!isPressedB && flagB)
        {
        }
        flagB = isPressedB;
        for (int i = Keyboard::A; i < Keyboard::Num9; i++)
            this->KeyPressed(i, Keyboard::isKeyPressed(static_cast<Keyboard::Key>(i)));
    }
}
void TextBox::render(RenderTarget &target)
{
    target.draw(this->shape);
    target.draw(this->text);
}
