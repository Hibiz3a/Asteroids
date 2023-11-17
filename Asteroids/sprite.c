#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/Audio.h>
#include <SFML/System.h>
#include <stdio.h>
#include <math.h>
#define PI 3.1415f
#include "ref.h"

void Sprite_Move_ship(SpriteShip* sprs, Death* dt) {
	if (dt->death == 0) {
		if (sfKeyboard_isKeyPressed(sfKeyZ) || sfKeyboard_isKeyPressed(sfKeyUp))
		{

			sprs->speedship += 0.5f;
			sprs->direction.x = cosf(sprs->rotation * PI / 180.0f);
			sprs->direction.y = sinf(sprs->rotation * PI / 180.0f);
		}
		else
		{
			sprs->speedship = sprs->speedship * 0.99f;
		}
		if (sfKeyboard_isKeyPressed(sfKeyQ) || sfKeyboard_isKeyPressed(sfKeyLeft))
		{
			sprs->rotation -= 5;
			sfSprite_setRotation(sprs->shipsprite, sprs->rotation);
		}
		if (sfKeyboard_isKeyPressed(sfKeyD) || sfKeyboard_isKeyPressed(sfKeyRight))
		{
			sprs->rotation += 5;
			sfSprite_setRotation(sprs->shipsprite, sprs->rotation);
		}
		sprs->Locate.x = sprs->Locate.x + sprs->direction.x * sprs->speedship;
		sprs->Locate.y = sprs->Locate.y + sprs->direction.y * sprs->speedship;

		if (sprs->speedship >= 10) {
			sprs->speedship = 9;
		}
	}
	
}

void return_map_ship(SpriteShip* sprs, window* wnd) {
	if (sprs->Locate.x < - 50.0f) {
		sprs->Locate.x = wnd->wnd_size_height + 50.0f;
	}
	if (sprs->Locate.y < - 50.0f) {
		sprs->Locate.y = wnd->wnd_size_width + 50.0f;
	}
	if (sprs->Locate.x > wnd->wnd_size_height + 50.0f) {
		sprs->Locate.x =  - 50.0f;
	}
	if (sprs->Locate.y > wnd->wnd_size_width + 50.0f) {
		sprs->Locate.y = - 50.0f;
	}
}

