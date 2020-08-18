#include "Game.h"
using namespace sf;
void Game::menu(sf::RenderWindow & window) {
	Texture menuTexture1, menuTexture2, menuTexture3, aboutTexture, menuBackground, credits;
	menuTexture1.loadFromFile("textures/menu/play.png");
	menuTexture2.loadFromFile("textures/menu/help.png");
	menuTexture3.loadFromFile("textures/menu/exit.png");
	aboutTexture.loadFromFile("textures/menu/helpOpen.png");
	menuBackground.loadFromFile("textures/menu/back.png");
	credits.loadFromFile("textures/menu/credits.png");
	Sprite menu1(menuTexture1), menu2(menuTexture2), menu3(menuTexture3), about(aboutTexture), menuBg(menuBackground), creditsS(credits);
	bool isMenu = 1;
	int menuNum = 0;
	menu1.setPosition(200, 120);
	menu2.setPosition(200, 220);
	menu3.setPosition(200, 320);
	about.setPosition(0, 0);
	creditsS.setPosition(350, 500);
	menuBg.setPosition(0, 0);
	

	//////////////////////////////лемч///////////////////
	while (isMenu)
	{
		
		menu1.setColor(Color::White);
		menu2.setColor(Color::White);
		menu3.setColor(Color::White);
		menuNum = 0;
		window.clear(Color(200, 200, 200));

		if (IntRect(200, 100, 416, 88).contains(Mouse::getPosition(window))) { menu1.setColor(Color::Blue); menuNum = 1; }
		if (IntRect(200, 200, 416, 88).contains(Mouse::getPosition(window))) { menu2.setColor(Color::Blue); menuNum = 2; }
		if (IntRect(200, 300, 416, 88).contains(Mouse::getPosition(window))) { menu3.setColor(Color::Blue); menuNum = 3; }

		if (Mouse::isButtonPressed(Mouse::Left))
		{
			if (menuNum == 1) { isMenu = false; InMenu = false; }
			if (menuNum == 2) { window.draw(about); window.display(); while (!Keyboard::isKeyPressed(Keyboard::Escape)); }
			if (menuNum == 3) { window.close(); isMenu = false;  }

		}

		window.draw(menuBg);
		window.draw(menu1);
		window.draw(menu2);
		window.draw(menu3);
		window.draw(creditsS);
		
		window.display();
	}
	////////////////////////////////////////////////////
}