#include "Headers/State.hpp"

State::State(BaseStateData *BaseState)
{
    this->BaseState = BaseState;
    this->window = BaseState->window;
    this->supportKeys = BaseState->supportKeys;
    this->situations = BaseState->situations;
    this->quit = false;
    this->paused = false;
    this->pressed = false;
    this->gridSize = BaseState->grizSize;
}

State::~State()
{
}

void State::endState()
{
    this->quit = true;
}

const bool &State::getQuit() const
{
    return this->quit;
}

void State::Paused()
{
    this->paused = true;
}

void State::UnPaused()
{
    this->paused = false;
}

void State::updateMousePosition(View *view)
{
    this->mousePosScreen = Mouse::getPosition();
    this->mousePosWindow = Mouse::getPosition(*this->window);

    if (view)
        this->window->setView(*view);

    this->mousePosView = this->window->mapPixelToCoords(Mouse::getPosition(*this->window));

    this->window->setView(this->window->getDefaultView());
}