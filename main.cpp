#include "Game.h"
#include <iostream>
Game* game = new Game;
void Game::process(sf::RenderWindow& window)
{

	if (game->InMenu)
	{
		menu(window);

	}
	if (game->endM) {
		end_menu(window);
	}
	if (!InMenu && !endM)
	{
		update();
		window.clear();
		DrawWindow(window);
		
		
	};
};
void Game::start()
{
	
	sf::RenderWindow window(sf::VideoMode(800, 600), "Game");//sf::Style::Fullscreen
	InitGame(window);
	while (window.isOpen())
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))window.close();
		process(window);
	}
	delete game;
}


int main()
{

	game->start();

	return 0;

}