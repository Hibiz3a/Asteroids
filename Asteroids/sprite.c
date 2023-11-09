#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/Audio.h>
#include <SFML/System.h>
#include<stdlib.h>
#include<stdio.h>
#include "sprite.h"

void Create_Sprite_Ship() {
	SpriteShip sprs;
	sprs.shipTexture = sfTexture_createFromFile("spaceship.png", NULL);
	sprs.shipsprite = sfSprite_create();
	sfSprite_setTexture(sprs.shipsprite,sprs.shipTexture, sfFalse);	
}

void Spawn_Sprite_Ship() {

	
}



int Sprite_Ship_Move() {

}l