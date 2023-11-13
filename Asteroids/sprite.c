#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/Audio.h>
#include <SFML/System.h>
#include <stdio.h>
#include <math.h>
#define PI 3.1415
#include "ref.h"


void Sprite_Move_ship(SpriteShip* sprs, Death * dt) {

	if (dt->death != 1) {
		if (sfKeyboard_isKeyPressed(sfKeyZ) || sfKeyboard_isKeyPressed(sfKeyUp))
		{
			sprs->speedship += 0.5;
			sprs->direction.x = cosf(sprs->rotation * PI / 180);
			sprs->direction.y = sinf(sprs->rotation * PI / 180);
		}
		else
		{
			sprs->speedship = sprs->speedship * 0.99;
		}
		if (sfKeyboard_isKeyPressed(sfKeyQ) || sfKeyboard_isKeyPressed(sfKeyLeft))
		{
			sprs->rotation -= 10;
			sfSprite_setRotation(sprs->shipsprite, sprs->rotation);
		}
		if (sfKeyboard_isKeyPressed(sfKeyD) || sfKeyboard_isKeyPressed(sfKeyRight))
		{
			sprs->rotation += 10;
			sfSprite_setRotation(sprs->shipsprite, sprs->rotation);
		}
		sprs->Locate.x = sprs->Locate.x + sprs->direction.x * sprs->speedship;
		sprs->Locate.y = sprs->Locate.y + sprs->direction.y * sprs->speedship;

		if (sprs->speedship >= 30) {
			sprs->speedship = 29;
		}
	}
}

void return_map_ship(SpriteShip* sprs, window* wnd) {
	if (sprs->Locate.x < 0) {
		sprs->Locate.x = wnd->wnd_size_height;
	}
	if (sprs->Locate.y < 0) {
		sprs->Locate.y = wnd->wnd_size_width;
	}
	if (sprs->Locate.x > wnd->wnd_size_height) {
		sprs->Locate.x = -5;
	}
	if (sprs->Locate.y > wnd->wnd_size_width) {
		sprs->Locate.y = -5;
	}
}

int sprite_ship_death(SpriteShip* sprs, Death * dt) {
	asteroid a;
	SpriteShip s;
	if (collider_asteroid_sprite(&s,&a) == 1) {
		dt->death = 1;
	}
}


int collider_asteroid_sprite(SpriteShip *sprs, asteroid* ast) {
	sfFloatRect SpriteBounds = sfSprite_getGlobalBounds(sprs->shipsprite);
	sfFloatRect AsteroidsBounds = sfSprite_getGlobalBounds(sprs->shipsprite);
	if (sfFloatRect_intersects(&SpriteBounds, &AsteroidsBounds, NULL))
	{
		return 1;
		printf("f");
	} 
	else return 0;
}