#pragma once
#include "SFML\Graphics.hpp"
#include "Const.h"


class Game {
public:

	sf::Clock timer;
	sf::Window window;
	sf::View view;
	bool InMenu;
	float time;
	bool endM;
	void init();
	int cam_x, cam_y;
	void update();
	void render();
	
	void InitGame(sf::RenderWindow& window);
	void DrawWindow(sf::RenderWindow& window);
	void DrawPlayer(sf::RenderWindow& window);
	void Count_Enemy();
	void DrawEnemy(sf::RenderWindow& window);
	//void UpdateGame(sf::RenderWindow& window);

	void menu(sf::RenderWindow & window);

	void initPlayer();
	void initEnemies();
	void initChests();
	void end_menu(sf::RenderWindow & window);
	void start();
	void process(sf::RenderWindow& window);
	
	//std::vector<Enemy> enemies;
};

class Player {
public:
	Player() { Hp, x, y, sprite.setPosition(x, y); };
	float CurrentFrame, attack_frame;
	float move_speed;
	float animation_speed;
	
	int Hp;
	int x, y;
	bool isKeyPressed = false;
	bool flag_map = 0;
	bool right_attack, left_attack, up_attack, down_attack;
	bool Dead;
	sf::Image image, imghp;
	sf::Texture texture, texhp;

	sf::Sprite sprite, sphp;
	Direction dir;
	Attack_position at;

	void init();
	void move(float time);
	void diagonalMoving();
	void attack(float time);
	void isDead(float time);
	void render_hp();
	void health_bar();
	void collision();
	void setFrame(float time, int frames);
	void Attack_direction(Direction dir);
	void EnemyInteraction(float time);
	void DoorInteracts();
	void Mapinteraction(float time);
	//void animation();
 

};

class Enemy {
public:
	Enemy(std::string name, int x, int y)
	{	
		Name = name;
		sprite.setPosition(x, y);
	};
	std::string Name;
	sf::Image image;
	sf::Texture texture;
	sf::Sprite sprite;
	float CurrentFrame;
	float animation_speed;
	int Hp, attack;
	float x, y;
	Direction dir;
	
	float move_speed;
	void init();
	void animation_en( float time );
	void move(float time);
	void animation();
	void isDead();
	void mapInteraction(float time);
};


class Background {
public:
	sf::Image image, image2;
	sf::Texture texture, texture2;
	sf::Sprite sprite, sprite2;


	void render_map1() {

		image.loadFromFile("textures/background/tiles_dungeon_v1.png");//загружаем файл для карты

		texture.loadFromImage(image);//заряжаем текстуру картинкой

		sprite.setTexture(texture);//заливаем текстуру спрайтом
		

	}
	
};

class CountEnemy{
public:
	sf::Image image;
	sf::Texture texture;
	sf::Sprite sprite;
	int enemy_count;
	void render_counter() {

		image.loadFromFile("textures/menu/counter/numbers.png");
		texture.loadFromImage(image);
		sprite.setTexture(texture);
		
	}
	void Count_Enemy();
	void schetchik();
};