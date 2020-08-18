#include "Game.h"

void Enemy::init() 
{
	Hp = 3;
	move_speed = 0.025;
	CurrentFrame = 0;
	attack = 1;
	image.loadFromFile("textures/enemy/chara_slime2.png");
	texture.loadFromImage(image);
	sprite.setTexture(texture);
	sprite.setTextureRect(sf::IntRect(47, 114, 16, 16));
	//sprite_en.setPosition(700, 250);// добавлено
	sprite.scale(1, 1); // добавлено


}

void Enemy::animation_en( float time ) 
{	
	
for(int i=0; i < 1; i++){
CurrentFrame += 0.001*time;
if (CurrentFrame > 3) CurrentFrame -= 3;
sprite.setTextureRect(sf::IntRect(45 * int(CurrentFrame), 113, 21, 21));
CurrentFrame += 0.0035*time;
	}
}



