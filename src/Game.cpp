#include "Game.h"

//Private Functions
void Game::InitVariables()
{
	this->window = nullptr;
}

void Game::InitWindow()
{
	this->videoMode.size = { 800, 600 };
	this->window = new sf::RenderWindow(this->videoMode, "SFML works!", sf::Style::Close);
}

//Construct & Destruct
Game::Game()
{
	this->InitVariables();
	this->InitWindow();
}

Game::~Game()
{
	delete this->window;
}

const bool Game::getWindowIsOpen() const
{
	return this->window->isOpen();
}

//Functions
void Game::PollEvents()
{
    while (this->window->pollEvent())
    {
        switch (this->ev.type)
        {
        case sf::Event::Closed:
            this->window->close();
        case sf::Event::KeyPressed:
            if ()
        }
    }
}

void Game::Update()
{
    this->PollEvents();
}

void Game::Render()
{
}

