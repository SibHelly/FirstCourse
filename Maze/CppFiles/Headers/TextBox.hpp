#ifndef TEXTBOX_HPP
#define TEXTBOX_HPP

#include "Button.hpp"

using namespace std;
using namespace sf;

class TextBox // класс для записи имени
{
private:
    bool pressed; // нажато ли

    RectangleShape shape; // область для ввода
    Font *font;           // шрифт
    Text text;            // текст

    map<int, string> keys; // клавиши для ввода
    vector<bool> flags;    // флаги для проверки единовременного нажатия

    int max; // максимальная длина
    int cur; // текущая длина

    string name; // имя

    Color idleColor; // цвет
    Color textIdCol;

    void IntitKeys();  // кнопки
    void InitVector(); // булевый вектор заполнение пустотой

public:
    TextBox(float x, float y, float width, float height, Font *font, unsigned sizeText, Color BoxColor, Color TextColor, bool pressed);
    ~TextBox();

    // Функции

    void addChar(string key); // добавление
    void deleteChar();        // удаление символа

    void KeyPressed(int i, const bool &x); // нажатие кнопки

    string getName() // получить имя
    {
        if (this->cur == this->max)
            return this->name;
        if (this->name == "_")
            return "PLAYER";
        if (this->cur < this->max)
        {
            this->name.pop_back();
            return this->name;
        }
    };

    void update(Vector2f mousePos);    // обновление
    void render(RenderTarget &target); // прорисовка
};

#endif
