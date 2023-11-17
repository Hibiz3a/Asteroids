#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/Audio.h>
#include <SFML/System.h>
#include <stdio.h>
#include "ref.h"

void Laser_create(laser* las, SpriteShip* sprs) {
	las->spritelaser = sfSprite_create();
	las->textureLaser = sfTexture_createFromFile("texture/laser.png", NULL);
	sfSprite_setTexture(las->spritelaser, las->textureLaser, sfTrue);

	las->laserPos.x = sprs->Locate.x;
	las->laserPos.y = sprs->Locate.y;

	sfSprite_setPosition(las->spritelaser, las->laserPos);
}


void move_laser(laser* las, SpriteShip* sprs,Death* dt) {
	if (dt->death == 0) {
		las->laserPos.x = sprs->Locate.x;
		las->laserPos.y = sprs->Locate.y;
		las->laserspeer = 10;
		if (las->shoot == 0) {
			if (sfKeyboard_isKeyPressed(sfKeySpace)) {
				las->rotation = sprs->rotation;
				las->shoot = 1;
				las->laserPos.x += las->laserspeer;
				las->laserPos.y += las->laserspeer;
				sfSprite_setRotation(las->spritelaser, las->rotation);
				printf("true");
			}
		}
		float dx = sprs->Locate.x - las->laserPos.x;
		float dy = sprs->Locate.y - las->laserPos.y;

		if (dx > 320 || dy > 320 || dx < -320 || dy < -320) {
			
			las->shoot = 0;
		}
	}
}

void return_map_laser(laser* las, window* wnd) {
	if (las->laserPos.x < 0) {
		las->laserPos.x = wnd->wnd_size_height;
	}
	if (las->laserPos.y < 0) {
		las->laserPos.y = wnd->wnd_size_width;
	}
	if (las->laserPos.x > wnd->wnd_size_height) {
		las->laserPos.x = -5;
	}
	if (las->laserPos.y > wnd->wnd_size_width) {
		las->laserPos.y = -5;
	}
}


