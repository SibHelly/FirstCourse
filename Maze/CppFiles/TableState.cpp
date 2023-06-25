#include "Headers/TableState.hpp"

void TableState::InitBackGround()
{
    this->BackGround.setSize(Vector2f(static_cast<float>(this->window->getSize().x), static_cast<float>(this->window->getSize().y)));
    if (!this->BackGrounTexture.loadFromFile("Resourses//win.png"))
    {
        throw("Error: Wint_State could not load background texture");
    }
    this->BackGround.setTexture(&this->BackGrounTexture);
}

void TableState::InitFonts()
{
    if (!this->font.loadFromFile("Font//1font.ttf"))
    {
        throw("Error::TableState::could not load font");
    }
}

void TableState::InitButtons()
{
    if (this->count != 0)
    {
        this->buttons["EXIT"] = new Button(this->window->getSize().x / 8.f - 50.f, this->window->getSize().y / 2.f + this->window->getSize().y / 4.f, static_cast<float>(window->getSize().x) / 4.f, 80.f, &this->font, "Выход", 30, Color::Black, Color(250, 250, 250, 250), Color(20, 20, 20, 50), Color(100, 100, 100, 0), Color(150, 150, 150, 0), Color(20, 20, 20, 0));
        this->buttons["CREATE"] = new Button(this->window->getSize().x / 8.f - 50.f + static_cast<float>(window->getSize().x) / 4.f + 30.f, this->window->getSize().y / 2.f + this->window->getSize().y / 4.f, static_cast<float>(window->getSize().x) / 4.f, 80.f, &this->font, "Создать файл для печати", 30, Color::Black, Color(250, 250, 250, 250), Color(20, 20, 20, 50), Color(100, 100, 100, 0), Color(150, 150, 150, 0), Color(20, 20, 20, 0));
        this->buttons["CLEAR"] = new Button(this->window->getSize().x / 8.f - 50.f + 2.f * (static_cast<float>(window->getSize().x) / 4.f + 100.f), this->window->getSize().y / 2.f + this->window->getSize().y / 4.f - 5.f, static_cast<float>(window->getSize().x) / 4.f, 80.f, &this->font, "Очистить результаты", 30, Color::Black, Color(250, 250, 250, 250), Color(20, 20, 20, 50), Color(100, 100, 100, 0), Color(150, 150, 150, 0), Color(20, 20, 20, 0));
    }
    else
    {
        this->buttons["EXIT"] = new Button(this->window->getSize().x / 2.f - this->window->getSize().x / 8.f, this->window->getSize().y / 2.f + this->window->getSize().y / 3.f, static_cast<float>(window->getSize().x) / 4.f, 80.f, &this->font, "Выход", 30, Color::Black, Color(250, 250, 250, 250), Color(20, 20, 20, 50), Color(100, 100, 100, 0), Color(150, 150, 150, 0), Color(20, 20, 20, 0));
    }
}

TableState::TableState(BaseStateData *BaseState, const int &level) : State(BaseState), level(level)
{
    int n = 0;
    this->count = 0;
    this->InitBackGround();
    this->InitFonts();
    this->InitKeyBinds();

    this->container.setSize(Vector2f(static_cast<float>(window->getSize().x) / 4.f, static_cast<float>(window->getSize().y) - 100.f));
    this->container.setFillColor(Color(20, 20, 20, 0));
    this->container.setPosition(static_cast<float>(window->getSize().x) / 2.f - this->container.getSize().x / 2.f, this->window->getSize().y / 8.f - 100.f);

    this->menuText.setFont(font);
    this->menuText.setFillColor(Color::Black);
    this->menuText.setCharacterSize(56);
    this->menuText.setString("Результаты");
    this->menuText.setPosition(this->container.getPosition().x + this->container.getSize().x / 2.f - this->menuText.getGlobalBounds().width / 2.f, this->container.getPosition().y + 30.f);

    this->heading.setSize(Vector2f(static_cast<float>(window->getSize().x) / 2.f + 200.f, 60.f));
    this->heading.setFillColor(Color(20, 20, 20, 200));
    this->heading.setPosition(static_cast<float>(window->getSize().x) / 2.f - this->heading.getSize().x / 2.f, this->window->getSize().y / 8.f);

    string result;
    ifstream in("Results//" + to_string(level));
    if (in.is_open())
    {
        string name = "";
        int lev = 0;
        float time = 0;

        while (in >> name >> lev >> time)
        {
            node x;
            x.name = name;
            x.level = lev;
            x.time = time;
            this->fromFile.push_back(x);
            this->count++;
        }
    }
    in.close();
    this->InitButtons();
    if (this->count == 0)
    {
        this->head.setFont(font);
        this->head.setFillColor(Color(255, 0, 40, 255));
        this->head.setCharacterSize(30);
        this->head.setString("Результатов пока нет");
        this->head.setPosition(this->heading.getPosition().x + this->heading.getSize().x / 2.f - this->head.getGlobalBounds().width / 2.f, this->heading.getPosition().y + 20.f);
    }
    else
    {
        this->head.setFont(font);
        this->head.setFillColor(Color(255, 0, 40, 255));
        this->head.setCharacterSize(30);
        this->head.setString("Имя игрока\tУровень\tВремя прохождения");
        this->head.setPosition(this->heading.getPosition().x + this->heading.getSize().x / 2.f - this->head.getGlobalBounds().width / 2.f, this->heading.getPosition().y + 20.f);
        sort(this->fromFile.begin(), this->fromFile.end(), [](const node &x, const node &y)
             { return x.time < y.time; });
        if (this->count < 10)
        {
            n = this->count;
        }
        else
            n = 10;
        for (int i = 0; i < n; i++)
        {
            string name = fromFile[i].name;
            name.resize(10, ' ');
            string level = to_string(fromFile[i].level);
            level.resize(20, ' ');
            string time = to_string(fromFile[i].time);
            time.resize(20, ' ');
            string text = name + "\t" + "\t" + level + time;

            RectangleShape temp;
            temp.setSize(Vector2f(static_cast<float>(window->getSize().x) / 2.f + 200.f, 60.f));
            temp.setFillColor(Color(20, 20, 20, 200));
            temp.setPosition(static_cast<float>(window->getSize().x) / 2.f - this->heading.getSize().x / 2.f, this->window->getSize().y / 8.f + (i + 1) * 60.f);

            Text tmp;
            tmp.setFont(font);
            tmp.setFillColor(Color(255, 0, 40, 255));
            tmp.setCharacterSize(30);
            tmp.setString(text);
            tmp.setPosition(temp.getPosition().x + temp.getSize().x / 2.f - tmp.getGlobalBounds().width / 2.f + 120.f, temp.getPosition().y + 10.f);

            this->results.push_back(temp);
            this->res.push_back(tmp);
        }
    }
}

TableState::~TableState()
{
    auto i = this->buttons.begin();
    for (i = this->buttons.begin(); i != this->buttons.end(); ++i)
    {
        delete i->second;
    }
}

void TableState::clearTable()
{
    this->heading.setFillColor(Color(20, 20, 20, 200));
    this->head.setFont(font);
    this->head.setFillColor(Color(255, 0, 40, 255));
    this->head.setCharacterSize(30);
    this->head.setString("Результатов пока нет");
    this->head.setPosition(this->heading.getPosition().x + this->heading.getSize().x / 2.f - this->head.getGlobalBounds().width / 2.f, this->heading.getPosition().y + 20.f);
    int n = this->count < 10 ? this->count : 10;
    for (int i = 0; i < n; i++)
    {
        string text = "";
        RectangleShape temp;
        temp.setSize(Vector2f(static_cast<float>(window->getSize().x) / 2.f + 100.f, 60.f));
        temp.setFillColor(Color(100, 100, 100, 0));
        temp.setPosition(static_cast<float>(window->getSize().x) / 2.f - this->heading.getSize().x / 2.f, this->window->getSize().y / 8.f + (i + 1) * 60.f);

        Text tmp;
        tmp.setFont(font);
        tmp.setFillColor(Color(100, 100, 100, 0));
        tmp.setCharacterSize(30);
        tmp.setString(text);
        tmp.setPosition(temp.getPosition().x + temp.getSize().x / 2.f - tmp.getGlobalBounds().width / 2.f, temp.getPosition().y + 10.f);

        this->results[i] = temp;
        this->res[i] = tmp;
    }
    string txtFile = to_string(this->level);
    string file = "Results//" + txtFile;
    remove(file.c_str());
    ofstream results("Results//" + txtFile, ios::app | ios::binary);
    results.close();
    this->count = 0;
}

void TableState::createTxt()
{
    string txtFile = to_string(this->level);
    string file = "Results//" + txtFile + ".txt";
    remove(file.c_str());
    ofstream in(file, ios::app);
    if (in.is_open())
    {
        for (int i = 0; i < this->count; i++)
        {
            in << this->fromFile[i].name;
            in << " ";
            in << this->fromFile[i].level;
            in << " ";
            in << this->fromFile[i].time;
            in << "\n";
        }
    }
    in.close();
}

void TableState::updateButtons()
{
    for (auto &i : this->buttons)
    {
        i.second->update(this->mousePosView);
    }
    if (this->count != 0)
    {
        if (this->buttons["CREATE"]->isPressed())
        {
            if (this->count != 0)
            {
                this->createTxt();
            }
        }
        if (this->buttons["EXIT"]->isPressed())
        {
            this->endState();
        }
        if (this->buttons["CLEAR"]->isPressed())
        {
            this->clearTable();
        }
    }
    else
    {
        if (this->buttons["EXIT"]->isPressed())
        {
            this->endState();
        }
    }
}

void TableState::update(const float &deltaTime)
{
    this->updateMousePosition();
    this->updateInput(deltaTime);
    this->updateButtons();
}

void TableState::renderButtons(RenderTarget &target)
{
    for (auto &i : this->buttons)
    {
        i.second->render(target);
    }
}

void TableState::render(RenderTarget *target)
{
    if (!target)
        target = this->window;

    target->draw(this->BackGround);
    target->draw(this->container);
    target->draw(this->heading);
    this->renderButtons(*target);

    target->draw(this->menuText);
    target->draw(this->head);
    if (this->count < 10)
    {
        for (int i = 0; i < this->count; i++)
        {
            target->draw(this->results[i]);
            target->draw(this->res[i]);
        }
    }
    else
    {
        for (int i = 0; i < 10; i++)
        {
            target->draw(this->results[i]);
            target->draw(this->res[i]);
        }
    }
}
