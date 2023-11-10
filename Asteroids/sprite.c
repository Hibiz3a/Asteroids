#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/Audio.h>
#include <SFML/System.h>
#include <math.h>
#define PI 3.1415
#include "ref.h"


void Sprite_Move_ship(SpriteShip* sprs) {


		if (sfKeyboard_isKeyPressed(sfKeyZ) || sfKeyboard_isKeyPressed(sfKeyUp))
		{
			sprs->speedship += 1;
			sprs->direction.x = cosf(sprs->rotation * PI / 180);
			sprs->direction.y = sinf(sprs->rotation * PI / 180);
		}
		else 
		{
			sprs->speedship = sprs->speedship * 0.98;
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
		sprs->Locate.x = sprs->Locate.x + sprs->direction.x*sprs->speedship;
		sprs->Locate.y = sprs->Locate.y + sprs->direction.y * sprs->speedship;

		if (sprs->speedship >= 20) {
			sprs->speedship = 19;
		}
}