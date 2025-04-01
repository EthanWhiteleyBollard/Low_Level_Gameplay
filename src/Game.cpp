#include "Game.h"

//--------------------------------------------------------------------------------------------------------------------------
//Private Functions
void Game::InitVariables()
{
	window = nullptr;
	endGame = false;

	//Image variables setup.
	spriteSheet_Tilemap = sf::Image("Assets/tilemap_packed.png");
	spriteSheet_Backgrounds = sf::Image("Assets/tilemap-backgrounds_packed.png");
}

//--------------------------------------------------------------------------------------------------------------------------

void Game::InitWindow()
{
	videoMode.size = { 800, 600 };
	window = new sf::RenderWindow(videoMode, "Robotron", sf::Style::Close);
	window->setFramerateLimit(60);
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
			else if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>()) 
			{
				if (keyPressed->scancode == sf::Keyboard::Scancode::Escape) { window->close(); }
			}
		}
    }
}

//--------------------------------------------------------------------------------------------------------------------------

void Game::Update()
{
    PollEvents();
	player.Update(window);
	enemy.Update(player);
	UpdateCollisions();
}

//--------------------------------------------------------------------------------------------------------------------------

void Game::Render()
{
	window->clear();
	player.Render(*window);
	enemy.Render(window);
	window->display();
}

//--------------------------------------------------------------------------------------------------------------------------

void Game::UpdateCollisions()
{
	//Check Enemy Collision
	if (player.GetShape().getGlobalBounds().findIntersection(enemy.GetShape().getGlobalBounds())) 
	{
		std::cout << "Kill Player";
	}

	if (enemy.GetShape().getGlobalBounds().findIntersection(player.GetProjectile().GetShape().getGlobalBounds())) 
	{
		std::cout << "Kill Enemy";
	}
}

//--------------------------------------------------------------------------------------------------------------------------

