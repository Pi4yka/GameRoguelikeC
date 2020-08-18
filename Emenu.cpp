#include "Game.h"
using namespace sf;
void Game::end_menu(sf::RenderWindow & window) 
{
	Texture menuTexture1, menuTexture2;
	menuTexture1.loadFromFile("textures/menu/dead.png");
	menuTexture2.loadFromFile("textures/menu/dexit.png");
	
	Sprite menu1(menuTexture1), menu2(menuTexture2);
	bool isMenu = 1;
	int menuNum = 0;
	menu1.setPosition(0, 0);
	menu2.setPosition(120, 120);
	



	//////////////////////////////лемч///////////////////
	while (isMenu)
	{
		
		menuNum = 0;
		window.clear(Color(200, 200, 200));

		
		if (IntRect(300, 360, 164, 100).contains(Mouse::getPosition(window))) { menu2.setColor(Color::Blue); menuNum = 2; }

		if (Mouse::isButtonPressed(Mouse::Left))
		{
			
			if (menuNum == 2) { window.close(); isMenu = false; }

		}


		window.draw(menu1);
		window.draw(menu2);

		window.display();
	}
	////////////////////////////////////////////////////
}