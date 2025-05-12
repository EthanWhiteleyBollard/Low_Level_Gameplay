#include "Game.h"
#include "vector"

//--------------------------------------------------------------------------------------------------------------------------
//Private Functions
void Game::InitVariables()
{
	window = nullptr;
	endGame = false;

	//Image variables setup.
	spriteSheet_Tilemap = sf::Image("Assets/tilemap_packed.png");
	spriteSheet_Backgrounds = sf::Image("Assets/tilemap-backgrounds_packed.png");

	//Enemies
	maxEnemies = 3;

	player = new Player;
	PlayerDead = false;
	currentScore = 0;
	livesScore = 0;

	//Score Text
	//sf::Font font;
	//if (!font.openFromFile("./Assets/Font/Roboto-VariableFont_wdth,wght.ttf"))
	//{
	//	exit(1);
	//}

	//scoreText->setFont(font);
	//scoreText->setString("0000");
	//scoreText->setCharacterSize(24);
	//scoreText->setFillColor(sf::Color::White);
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
	SpawnEnemies();
	player->SetPosition(sf::Vector2f{ (window->getSize().x - player->GetShape().getGlobalBounds().size.x) / 2, (window->getSize().y - player->GetShape().getGlobalBounds().size.y) / 2 });
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
	if (PlayerDead) { return; }

    PollEvents();
	player->Update(window);
	//Chase Player
	for (int i = 0; i < enemies.size(); i++)
	{
		enemies[i]->Update(player);
	}
	UpdateCollisions();

	if (enemies.size() <= 0) 
	{
		maxEnemies++;
		player->SetPosition(sf::Vector2f{ (window->getSize().x - player->GetShape().getGlobalBounds().size.x) / 2, (window->getSize().y - player->GetShape().getGlobalBounds().size.y) / 2 });
		SpawnEnemies();
	}
}

//--------------------------------------------------------------------------------------------------------------------------

void Game::Render()
{
	window->clear();
	player->Render(window);
	for (auto i : enemies) 
	{
		i->Render(*window);
	}
	window->display();
}

//--------------------------------------------------------------------------------------------------------------------------

void Game::UpdateCollisions()
{
	for (int e = 0; e < enemies.size(); e++) 
	{
		//Check Player
		if (player->GetShape().getGlobalBounds().findIntersection(enemies[e]->GetShape().getGlobalBounds()))
		{
			if (player->GetLives() <= 0)
			{
				PlayerDead = true;
				std::cout << "Final Score is: " << currentScore << std::endl;
			}
			else
			{
				player->SetLives(player->GetLives() - 1);
				player->SetPosition(sf::Vector2f{ (window->getSize().x - player->GetShape().getGlobalBounds().size.x) / 2, (window->getSize().y - player->GetShape().getGlobalBounds().size.y) / 2});
				enemies.erase(enemies.begin(), enemies.end());
				SpawnEnemies();
			}
		}

		//Check bullet
		for (size_t i = 0; i < player->GetBullets().size(); i++)
		{
			if (player->GetSetBullet(i)->getBounds().findIntersection(enemies[e]->GetShape().getGlobalBounds()))
			{
				player->DeleteBullet(i);
				currentScore += enemies[e]->GetScore();
				livesScore += enemies[e]->GetScore();
				if (livesScore >= 10000) 
				{
					player->SetLives(player->GetLives() + 1);
					std::cout << "Lives: " << player->GetLives() << std::endl;
					livesScore = 0;
				}
 				std::cout << "The score is: " << currentScore << std::endl;
				enemies.erase(enemies.begin() + e);
			}
		}
	}
}

//--------------------------------------------------------------------------------------------------------------------------

void Game::SpawnEnemies()
{
	while (enemies.size() < maxEnemies)
	{
		enemies.push_back(new EnemyBase(*window, *player));
	}
}

//--------------------------------------------------------------------------------------------------------------------------

