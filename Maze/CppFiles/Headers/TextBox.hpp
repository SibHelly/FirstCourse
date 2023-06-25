#ifndef TEXTBOX_HPP
#define TEXTBOX_HPP

#include "Button.hpp"

using namespace std;
using namespace sf;

class TextBox // ����� ��� ������ �����
{
private:
    bool pressed; // ������ ��

    RectangleShape shape; // ������� ��� �����
    Font *font;           // �����
    Text text;            // �����

    map<int, string> keys; // ������� ��� �����
    vector<bool> flags;    // ����� ��� �������� ��������������� �������

    int max; // ������������ �����
    int cur; // ������� �����

    string name; // ���

    Color idleColor; // ����
    Color textIdCol;

    void IntitKeys();  // ������
    void InitVector(); // ������� ������ ���������� ��������

public:
    TextBox(float x, float y, float width, float height, Font *font, unsigned sizeText, Color BoxColor, Color TextColor, bool pressed);
    ~TextBox();

    // �������

    void addChar(string key); // ����������
    void deleteChar();        // �������� �������

    void KeyPressed(int i, const bool &x); // ������� ������

    string getName() // �������� ���
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

    void update(Vector2f mousePos);    // ����������
    void render(RenderTarget &target); // ����������
};

#endif
