#include "Game.h"
#include "Const.h"
#include <iostream>
#include "Map.h"
#include <vector>
#include <list>

Player player;
//Enemy enemy;
CountEnemy counter;
std::list<Enemy*> entities;
std::list<Enemy*>::iterator it;
Background background;

int enemy_pos = 0;
void Game::init()
{

}
void Game::update()
{
	time = float(timer.getElapsedTime().asMicroseconds());
	timer.restart();
	time = time / 800;
	player.sphp.setPosition(player.sprite.getPosition().x - 4, player.sprite.getPosition().y - 10);
	counter.sprite.setPosition(player.sprite.getPosition().x - 50, player.sprite.getPosition().y - 50);
	player.health_bar();
	player.move(time);
	for (it = entities.begin(); it != entities.end(); it++) {
		(*it)->move(time); //рисуем entities объекты (сейчас это только враги)
		(*it)->animation_en(time);
		(*it)->mapInteraction(time);
	}
	
	if (player.Dead == true) { endM = true; }
	//enemy.move(time);
	player.attack(time);
	//counter.schetchik();
	counter.Count_Enemy();
	player.EnemyInteraction(time);
	
	player.Mapinteraction(time); 
	std::cout << player.sprite.getPosition().x<< ")(" << player.sprite.getPosition().y << "\n";


	
	if (player.sprite.getPosition().x <= 200)  cam_x = 200;
	else if (player.sprite.getPosition().x >= 746)  cam_x = 746;
	else cam_x = player.sprite.getPosition().x;
	if (player.sprite.getPosition().y <= 100)  cam_y = 100;
	else if (player.sprite.getPosition().y >= 538)  cam_y = 538;
	else cam_y = player.sprite.getPosition().y;
	
	if(!endM)view.setCenter(cam_x, cam_y);
	else view.setCenter(200, 100);


}
void Game::render() 
{


}

void Game::DrawWindow(sf::RenderWindow& window)
{
	window.setView(view);


	for (int i = 0; i < HEIGHT_MAP; i++)
		for (int j = 0; j < WIDTH_MAP; j++)
		{
			if (TileMap[i][j] == ' ')  background.sprite.setTextureRect(sf::IntRect(16, 16, 16, 16)); //если встретили символ пробел, то рисуем 1й квадратик
			if (TileMap[i][j] == 's')  background.sprite.setTextureRect(sf::IntRect(32, 0, 16, 16));//если встретили символ s, то рисуем 2й квадратик
			if ((TileMap[i][j] == 'd')) background.sprite.setTextureRect(sf::IntRect(48, 0, 16, 16));//если встретили символ 0, то рисуем 3й квадратик
			if ((TileMap[i][j] == 'q')) background.sprite.setTextureRect(sf::IntRect(112, 224, 16, 16));
			if ((TileMap[i][j] == 'a')) background.sprite.setTextureRect(sf::IntRect(64, 16, 16, 16));
			if ((TileMap[i][j] == 'w')) background.sprite.setTextureRect(sf::IntRect(128, 224, 16, 16));
			if ((TileMap[i][j] == '0')) background.sprite.setTextureRect(sf::IntRect(32, 128, 16, 16));//если встретили символ 0, то рисуем 3й квадратик
			if ((TileMap[i][j] == '1')) background.sprite.setTextureRect(sf::IntRect(0, 160, 16, 16));
			if ((TileMap[i][j] == '2')) background.sprite.setTextureRect(sf::IntRect(0, 128, 16, 16));
			if ((TileMap[i][j] == 'b')) background.sprite.setTextureRect(sf::IntRect(17, 128, 16, 16));
			if ((TileMap[i][j] == 'c')) background.sprite.setTextureRect(sf::IntRect(17, 128, 16, 16));
			if ((TileMap[i][j] == '3')) background.sprite.setTextureRect(sf::IntRect(0, 144, 16, 16));
			if ((TileMap[i][j] == '4')) background.sprite.setTextureRect(sf::IntRect(112, 192, 16, 16));
			if ((TileMap[i][j] == '6')) background.sprite.setTextureRect(sf::IntRect(128, 192, 16, 16));
			if ((TileMap[i][j] == '5')) background.sprite.setTextureRect(sf::IntRect(112, 208, 16, 16));
			if ((TileMap[i][j] == '7')) background.sprite.setTextureRect(sf::IntRect(128, 208, 16, 16));

			if ((TileMap[i][j] == 'g')) background.sprite.setTextureRect(sf::IntRect(224, 256, 16, 16));
			if ((TileMap[i][j] == 'z')) background.sprite.setTextureRect(sf::IntRect(240, 256, 16, 16));

			if ((TileMap[i][j] == 's')) background.sprite.setTextureRect(sf::IntRect(240, 240, 16, 16));
			if ((TileMap[i][j] == 't')) background.sprite.setTextureRect(sf::IntRect(256, 240, 16, 16));

			if ((TileMap[i][j] == 'k')) background.sprite.setTextureRect(sf::IntRect(256, 256, 16, 16));
			if ((TileMap[i][j] == 'e')) background.sprite.setTextureRect(sf::IntRect(272, 256, 16, 16));

			if ((TileMap[i][j] == 'n')) background.sprite.setTextureRect(sf::IntRect(288, 288, 16, 16));
			if ((TileMap[i][j] == 'p')) background.sprite.setTextureRect(sf::IntRect(272, 288, 16, 16));

			if ((TileMap[i][j] == 'j')) background.sprite.setTextureRect(sf::IntRect(176, 208, 16, 16));
			if ((TileMap[i][j] == 'i')) background.sprite.setTextureRect(sf::IntRect(192, 208, 16, 16));

			if ((TileMap[i][j] == 'h')) background.sprite.setTextureRect(sf::IntRect(208, 208, 16, 16));
			if ((TileMap[i][j] == 'v')) background.sprite.setTextureRect(sf::IntRect(224, 208, 16, 16));

			background.sprite.setPosition(j * 16, i * 16);//по сути раскидывает квадратики, превращая в карту. то есть задает каждому из них позицию. если убрать, то вся карта нарисуется в одном квадрате 32*32 и мы увидим один квадрат

			window.draw(background.sprite);//рисуем квадратики на экран
		}

	
	window.draw(player.sphp);
	window.draw(counter.sprite);
	DrawPlayer(window);
	DrawEnemy(window);
	
	window.display();

	
}

void Game::InitGame(sf::RenderWindow& window)
{
	
	endM = false;
	player.init();

		entities.push_back(new Enemy("1",450, 500));
		entities.push_back(new Enemy("2",350, 500));
		entities.push_back(new Enemy("3",500, 500));
		entities.push_back(new Enemy("4",600, 500));
		entities.push_back(new Enemy("5", 70, 280));
		entities.push_back(new Enemy("6", 127, 283));
		entities.push_back(new Enemy("7", 84, 64));
		entities.push_back(new Enemy("8", 142, 150));
		entities.push_back(new Enemy("9", 44, 150));
		entities.push_back(new Enemy("10", 65, 217));
		entities.push_back(new Enemy("11", 880, 27));
		entities.push_back(new Enemy("12", 880, 120));
		entities.push_back(new Enemy("13", 892, 390));
		entities.push_back(new Enemy("14", 892, 330));
		entities.push_back(new Enemy("15", 876, 573));
		entities.push_back(new Enemy("16", 876, 476));
		entities.push_back(new Enemy("17", 880, 120));
		entities.push_back(new Enemy("18", 77, 475));
		entities.push_back(new Enemy("19", 169, 475));
		entities.push_back(new Enemy("20", 876, 350));




	for (it = entities.begin(); it != entities.end(); it++) {
		(*it)->init(); //рисуем entities объекты (сейчас это только враги)
		counter.enemy_count++;
	}
	view.setSize(sf::Vector2f(400, 200));
	background.render_map1();
	player.health_bar();
	counter.render_counter();
	
}

void Game::DrawEnemy(sf::RenderWindow& window)
{
		for (it = entities.begin(); it != entities.end(); it++) {
			window.draw((*it)->sprite); //рисуем entities объекты (сейчас это только враги)
		}


}

void Game::DrawPlayer(sf::RenderWindow& window)
{
		window.draw(player.sprite);



}

void Enemy::move(float time)// добавлено
{
	x = sprite.getPosition().x;
	y = sprite.getPosition().y;
	if(player.sprite.getPosition().x - sprite.getPosition().x < 100 && player.sprite.getPosition().x - sprite.getPosition().x > -100)
		if (player.sprite.getPosition().y - sprite.getPosition().y < 100 && player.sprite.getPosition().y - sprite.getPosition().y > -100)
		{
			{

				if (sprite.getPosition().x < x && sprite.getPosition().y < y) {
					dir = LEFT_UP; x = 0; y = 0;
				}
				if (sprite.getPosition().x < x && sprite.getPosition().y > y) {
					dir = LEFT_DOWN; x = 0; y = 0;
				}
				if (sprite.getPosition().x > x && sprite.getPosition().y < y) {
					dir = RIGHT_DOWN; x = 0; y = 0;
				}
				if (sprite.getPosition().x > x && sprite.getPosition().y > y) {
					dir = RIGHT_UP; x = 0; y = 0;
				}
				if (player.sprite.getPosition().x < sprite.getPosition().x)
				{
					sprite.move(-move_speed * time, 0);
					dir = LEFT;
				}
				else
				{
					sprite.move(move_speed*time, 0); dir = RIGHT;
				}
				if (sprite.getPosition().x - player.sprite.getPosition().x <= 100)
				{
					if (player.sprite.getPosition().y < sprite.getPosition().y - sprite.getGlobalBounds().height + 20)
					{
						sprite.move(0, -move_speed * time);
						dir = UP;
					}
					else
					{
						sprite.move(0, move_speed*time); dir = DOWN;
					}
				}
			}
		}
}
void Player::collision()
{
	for (it = entities.begin(); it != entities.end();it++)
		{
		if (sprite.getGlobalBounds().intersects((*it)->sprite.getGlobalBounds())) {
			
			it = entities.erase(it);
			counter.enemy_count--;
		}
		if (it == entities.end()) break;
		

	}
}
void Player::Mapinteraction(float time)
{
	for (int i = sprite.getPosition().y / 16; i < (sprite.getPosition().y + sprite.getGlobalBounds().height) / 16; i++)
		for (int j = sprite.getPosition().x / 16; j < (sprite.getPosition().x + sprite.getGlobalBounds().width) / 16; j++)
		{
			if (TileMap[i][j] == '0' || TileMap[i][j] == '1' || TileMap[i][j] == '4' || TileMap[i][j] == '5' || TileMap[i][j] == '6' || TileMap[i][j] == '7' || TileMap[i][j] == 'b' || TileMap[i][j] == 'c' || TileMap[i][j] == 'w' || TileMap[i][j] == '3')
			{
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
				{
					if (isKeyPressed == true) sprite.move(move_speed*time, 0);
					else
						sprite.move(move_speed*time, 0);

				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
				{
					if (isKeyPressed == true) sprite.move(-move_speed * time, 0);
					else
						sprite.move(-move_speed * time, 0);
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
				{
					if (isKeyPressed == true) sprite.move(0, move_speed*time);
					else
						sprite.move(0, move_speed*time);

					if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && sf::Keyboard::isKeyPressed(sf::Keyboard::W))
					{
						if (isKeyPressed == true) sprite.move(0, move_speed*time);
						else
							sprite.move(0, move_speed*time);
					}
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && sf::Keyboard::isKeyPressed(sf::Keyboard::W))
					{
						if (isKeyPressed == true) sprite.move(0, move_speed*time);
						else
							sprite.move(0, move_speed*time);
					}

				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
				{
					if (isKeyPressed == true) sprite.move(0, -move_speed * time);
					else
						sprite.move(0, -move_speed * time);
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && sf::Keyboard::isKeyPressed(sf::Keyboard::S))
					{
						if (isKeyPressed == true) sprite.move(0, -move_speed * time);
						else
							sprite.move(0, -move_speed * time);
					}
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && sf::Keyboard::isKeyPressed(sf::Keyboard::S))
					{
						if (isKeyPressed == true) sprite.move(0, -move_speed * time);
						else
							sprite.move(0, -move_speed * time);
					}
				}

			}
		}

}
void Player::EnemyInteraction(float time)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::F)) {
		for (it = entities.begin(); it != entities.end(); it++)
		{
			if (sprite.getGlobalBounds().intersects((*it)->sprite.getGlobalBounds())) 
			{
				if((*it)->Hp > 0)
				{
				if (at == TOP_AT) (*it)->sprite.move(0, -15);
				if (at == DOWN_AT) (*it)->sprite.move(0, 15);
				if (at == LEFT_AT) (*it)->sprite.move(-15, 0);
				if (at == RIGHT_AT) (*it)->sprite.move(15, 0);
				(*it)->Hp--;
				}
				else { collision(); break; }

			}
		}
	}

	if (!sf::Keyboard::isKeyPressed(sf::Keyboard::F))
	{
		for (it = entities.begin(); it != entities.end(); it++)
		{
			if (sprite.getGlobalBounds().intersects((*it)->sprite.getGlobalBounds()))
			{
				Hp -= (*it)->attack;
				player.isDead(time);
				if (Hp-- && player.dir == UP) {
					sprite.move(0, 0);
					(*it)->sprite.move(0, -35);
					break;
				}
				if (Hp-- && player.dir == DOWN) {
					sprite.move(0, 0);
					(*it)->sprite.move(0, 35);
					break;
				}
				if (Hp-- && player.dir == LEFT) {
					sprite.move(0, 0);
					(*it)->sprite.move(-35, 0);
					break;
				}
				if (Hp-- && player.dir == RIGHT) {
					sprite.move(0, 0);
					(*it)->sprite.move(35, 0);
					break;
				}
				
			}
		}
	}

}
void Player::isDead (float time)
{
		if (Hp < 0){
		sprite.setTextureRect(sf::IntRect(50 * int(CurrentFrame), 599, 24, 24));
		Dead = true;
		
		}
		
	}
void Enemy::mapInteraction(float time)
{
	for (int i = sprite.getPosition().y / 16; i < (sprite.getPosition().y + sprite.getGlobalBounds().height) / 16; i++)
		for (int j = sprite.getPosition().x / 16; j < (sprite.getPosition().x + sprite.getGlobalBounds().width) / 16; j++)
		{
			if (TileMap[i][j] == '1' || TileMap[i][j] == '0' || TileMap[i][j] == '4' || TileMap[i][j] == '5' || TileMap[i][j] == '6' || TileMap[i][j] == '7' || TileMap[i][j] == 'b' || TileMap[i][j] == 'c' || TileMap[i][j] == 'w' || TileMap[i][j] == '3' || TileMap[i][j] == '2')
			{
				{
					if (dir == LEFT) { sprite.move(-move_speed * time, 0); }
					if (dir == RIGHT) { sprite.move(move_speed * time, 0); }
					if (dir == UP) {	sprite.move(0, move_speed * time); }
					if ((dir == DOWN)) { sprite.move(0, -move_speed * time); }
					if (dir == LEFT_UP) { sprite.move(move_speed * time, move_speed * time); }
					if (dir == LEFT_DOWN) { sprite.move(move_speed * time, -move_speed * time); }
					if (dir == RIGHT_UP) { sprite.move(move_speed * time, -move_speed * time); }
					if (dir == RIGHT_DOWN) { sprite.move(move_speed * time, move_speed * time); }


				}
			}
		}
}
/*
for (it = entities.begin(); it != entities.end();it++)
{
if (sprite.getGlobalBounds().intersects((*it)->sprite.getGlobalBounds())) {
std::cout << "HIT \n";
it = entities.erase(it);
}
if (it == entities.end()) break;

collision();
std::cout << dir << "die \n";
break;
}
*/

void Player::health_bar() {
	/*
	if (player.sprite.getPosition().x == 208)
	{
		sphp.setPosition(208, player.sprite.getPosition().y);
	}
	if (player.sprite.getPosition().x == 739)
	{
		sphp.setPosition(739, player.sprite.getPosition().y);
	}
	if (player.sprite.getPosition().y == 536)
	{
		sphp.setPosition(player.sprite.getPosition().x, 536);
	}
	if (player.sprite.getPosition().y == 105)
	{
		sphp.setPosition(player.sprite.getPosition().x, 105);
	}
	else
	{
		sphp.setPosition(player.sprite.getPosition().x - 20, player.sprite.getPosition().y - 20);
	}*/
	if (Hp == 5 || Hp == 6)
	{
		sphp.setTextureRect(sf::IntRect(0, 0, 30, 4));
	}
	if (Hp == 4 || Hp == 3)
	{
		sphp.setTextureRect(sf::IntRect(0, 4, 30, 4));
	}
	if (Hp == 2 || Hp == 1)
	{
		sphp.setTextureRect(sf::IntRect(0, 8, 30, 4));
	}
	if (Hp == 0 || Hp == -1)
	{
		sphp.setTextureRect(sf::IntRect(0, 12, 30, 4));
	}
}

void CountEnemy::Count_Enemy() 
{
	if (counter.enemy_count == 0)
	{	
		player.Dead = true;
	}
	else
	{
		player.Dead = false;
	}
	int count_test = enemy_count;
	
		counter.sprite.setTextureRect(sf::IntRect(0, 0, 73, 17));
		if (count_test--)
		{
			counter.sprite.setTextureRect(sf::IntRect(0, 36, 73, 17));
		}
}

void CountEnemy::schetchik()
{
	int frame = 18;
	

}
