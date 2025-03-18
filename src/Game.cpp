#include "Game.h"

//--------------------------------------------------------------------------------------------------------------------------
//Private Functions
void Game::InitVariables()
{
	window = nullptr;

	//Image variables setup.
	spriteSheet_Tilemap = sf::Image("Assets/tilemap_packed.png");
	spriteSheet_Backgrounds = sf::Image("Assets/tilemap-backgrounds_packed.png");
	spriteSheet_Characters = sf::Image("Assets/tilemap-characters_packed.png");
}

//--------------------------------------------------------------------------------------------------------------------------

void Game::InitWindow()
{
	videoMode.size = { 800, 600 };
	window = new sf::RenderWindow(videoMode, "SFML works!", sf::Style::Close);
}

//--------------------------------------------------------------------------------------------------------------------------
//Construct & Destruct
Game::Game()
{
	InitVariables();
	InitWindow();
}

//--------------------------------------------------------------------------------------------------------------------------

Game::~Game()
{
	delete window;
}

//--------------------------------------------------------------------------------------------------------------------------

const bool Game::getWindowIsOpen() const
{
	return window->isOpen();
}

//--------------------------------------------------------------------------------------------------------------------------
//Functions
void Game::PollEvents()
{
    while (window->pollEvent())
    {
		while (const std::optional event = window->pollEvent()) 
		{
			if (event->is<sf::Event::Closed>())
				window->close();
		}
    }
}

//--------------------------------------------------------------------------------------------------------------------------

void Game::Update()
{
    PollEvents();
}

//--------------------------------------------------------------------------------------------------------------------------

void Game::Render()
{
	SpriteManager sprite = SpriteManager::SpriteManager(spriteSheet_Characters, sf::Vector2i{ 0,0 }, sf::Vector2i{ 24, 24 });

	sprite.fixedUpdate();

	window->clear();
	sprite.render(*window);
	window->display();
}

//--------------------------------------------------------------------------------------------------------------------------

