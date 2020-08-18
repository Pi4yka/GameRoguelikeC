#include "Game.h"
#include <iostream>
#include "Const.h"


void Player::init()
{
	Hp = 6;
	CurrentFrame = 0;
	animation_speed = 0.003;
	move_speed = 0.03;
	Dead = false;
	image.loadFromFile("textures/hero/chara_hero2.png");
	texture.loadFromImage(image);
	sprite.setTextureRect(sf::IntRect(48, 113, 16, 16));
	sprite.setTexture(texture);
	sprite.setPosition(636, 395);
	sprite.scale(1.3, 1.3);

	imghp.loadFromFile("textures/hp/hp3.png");
	texhp.loadFromImage(imghp);
	sphp.setTexture(texhp);
	sphp.setTextureRect(sf::IntRect(0, 0, 30, 4));
}

void Player::setFrame(float time, int frames)
{
	CurrentFrame += animation_speed * time;
	if (CurrentFrame > frames) CurrentFrame -= frames;
}
void Player::diagonalMoving()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && sf::Keyboard::isKeyPressed(sf::Keyboard::W) ||
		sf::Keyboard::isKeyPressed(sf::Keyboard::A) && sf::Keyboard::isKeyPressed(sf::Keyboard::S) ||
		sf::Keyboard::isKeyPressed(sf::Keyboard::D) && sf::Keyboard::isKeyPressed(sf::Keyboard::W) ||
		sf::Keyboard::isKeyPressed(sf::Keyboard::D) && sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		move_speed = 0.045;
		animation_speed = 0.0025;
	}
	else
	{
		move_speed = 0.1;
		animation_speed = 0.01;
	}
}
void Player::move(float time) 
{
	
	//attack(time);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {

		dir = LEFT;
		diagonalMoving();
		Attack_direction(dir);
		
		setFrame(time, 4);
		
		sprite.setTextureRect(sf::IntRect(48 * int(CurrentFrame), 533, 16, 16));
		
		sprite.move(move_speed*time*-1, 0);

	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		dir = RIGHT;
		diagonalMoving();
		Attack_direction(dir);
		setFrame(time, 4);
	
		sprite.setTextureRect(sf::IntRect(48 * int(CurrentFrame), 160, 16, 16));
		sprite.move(move_speed*time, 0);

	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
		dir = UP;
		diagonalMoving();
		Attack_direction(dir);
		setFrame(time, 4);
		
		sprite.setTextureRect(sf::IntRect(48 * int(CurrentFrame), 209, 16, 16));
		sprite.move(0, move_speed*time*-1); 

	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {

		dir = DOWN;
		diagonalMoving();
		Attack_direction(dir);
		setFrame(time, 4);
		
		sprite.setTextureRect(sf::IntRect(48 * int(CurrentFrame), 113, 16, 16));
		sprite.move(0, move_speed*time); 

	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && (sf::Keyboard::isKeyPressed(sf::Keyboard::S)))
	{
		dir = RIGHT_DOWN;
		diagonalMoving();
		Attack_direction(dir);
		setFrame(time, 4);
		sprite.setTextureRect(sf::IntRect(48 * int(CurrentFrame), 113, 16, 16));
		sprite.move(0, move_speed*time);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && (sf::Keyboard::isKeyPressed(sf::Keyboard::S)))
	{
		dir = LEFT_DOWN;
		diagonalMoving();
		Attack_direction(dir);
		setFrame(time, 4);
		sprite.setTextureRect(sf::IntRect(48 * int(CurrentFrame), 113, 16, 16));
		sprite.move(0, move_speed*time);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && (sf::Keyboard::isKeyPressed(sf::Keyboard::W)))
	{
		dir = LEFT_UP;
		diagonalMoving();
		Attack_direction(dir);
		setFrame(time, 4);
		sprite.setTextureRect(sf::IntRect(48 * int(CurrentFrame), 533, 16, 16));
		sprite.move(0, move_speed*time*-1);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && (sf::Keyboard::isKeyPressed(sf::Keyboard::W)))
	{
		dir = RIGHT_UP;
		
		diagonalMoving();
		Attack_direction(dir);
		setFrame(time, 4);
		sprite.setTextureRect(sf::IntRect(48 * int(CurrentFrame), 209, 16, 16));
		sprite.move(0, move_speed*time*-1);
	}	

}
void Player::attack(float time)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::F))
	
	isKeyPressed = true;
	if(isKeyPressed == true)
	{ 
	if  (at == RIGHT_AT)
	{
		for (int i = 0; i < 1; i++) {
			attack_frame += 0.001*time;
			if (attack_frame > 4) { attack_frame -= 4; isKeyPressed = false; }
			sprite.setTextureRect(sf::IntRect(48 * int(attack_frame), 304, 21, 16));
			attack_frame += 0.0075*time;
			
		}

		
	}

	if (at == LEFT_AT)
	{
		for (int i = 0; i < 1; i++) {
			attack_frame += 0.001*time;
			if (attack_frame > 4) { attack_frame -= 4; isKeyPressed = false; }
			sprite.setTextureRect(sf::IntRect(48 * int(attack_frame), 562, 23, 16));
			attack_frame += 0.0075*time;
			
		}
		 
	}

	if (at == TOP_AT)
	{
		for (int i = 0; i < 1; i++) {
			attack_frame += 0.001*time;
			if (attack_frame > 4) { attack_frame -= 4; isKeyPressed = false; }
			sprite.setTextureRect(sf::IntRect(48 * int(attack_frame), 342, 16, 21));
			attack_frame += 0.0075*time;
		}
	}

	if (at == DOWN_AT)
	{
		for (int i = 0; i < 1; i++) {
			attack_frame += 0.001*time;
			if (attack_frame > 4) { attack_frame -= 4; isKeyPressed = false; }
			sprite.setTextureRect(sf::IntRect(48 * int(attack_frame), 256, 16, 23));
			attack_frame += 0.0075*time;
		}
	}
	}
}

	
void Player::Attack_direction(Direction dir)
{
	//left_attack = 0;

	if (dir == LEFT || dir == LEFT_UP || dir == LEFT_DOWN) at = LEFT_AT;
	if (dir == RIGHT || dir == RIGHT_UP || dir == RIGHT_DOWN) at = RIGHT_AT;
	if (dir == UP) at = TOP_AT;
	if (dir == DOWN) at = DOWN_AT;

}




/*

void Hero::Interacts() {

if (sprite.getGlobalBounds().intersects(en.sprite_en.getGlobalBounds())) {
std::cout << "HIT";
hp--;
//bounce hero
if (hp-- && hero.top == 1) {
sprite.move(0, 0);
en.sprite_en.move(0, -35);
}
if (hp-- && hero.down == 1) {
sprite.move(0, 0);
en.sprite_en.move(0, 35);
}
if (hp-- && hero.left == 1) {
sprite.move(0, 0);
en.sprite_en.move(-35, 0);
}
if (hp-- && hero.right == 1) {

sprite.move(0, 0);
en.sprite_en.move(35, 0);

}
//hero attack enemy
if (right_attack == 1) {
en.hp_en--;
sprite.move(0, 0);
en.sprite_en.move(40, 0);
std::cout << " RIGHT ATTACK - TRUE";
}
if (left_attack == 1) {
en.hp_en--;
sprite.move(0, 0);
en.sprite_en.move(40, 0);
std::cout << " LEFT ATTACK - TRUE";
}
if (down_attack == 1) {
en.hp_en--;
sprite.move(0, 0);
en.sprite_en.move(40, 0);
std::cout << " DOWN ATTACK - TRUE";
}
if (top_attack == 1) {
en.hp_en--;
sprite.move(0, 0);
en.sprite_en.move(40, 0);
std::cout << " TOP ATTACK - TRUE";
}
if (en.hp_en == 0) {
std::cout << " ENEMY DIE!";
}

if (hp == 0) {
std::cout << "you died";
CurrentFrame += 0.00001*Ti;
if (CurrentFrame > 6)

CurrentFrame -= 6;
sprite.setTextureRect(sf::IntRect(47 * int(CurrentFrame), 953, 30, 50));
CurrentFrame += 0.0000075*Ti;


}


}
else {

}
}
*/