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
		las->laserspeer = 10;
		if (las->shoot == 0) {
			if (sfKeyboard_isKeyPressed(sfKeySpace)) {
				Laser_create(las, sprs);
				las->rotation = sprs->rotation;
				las->shoot = 1;
				sfSprite_setRotation(las->spritelaser, las->rotation);
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
void destroyAsteroid(Asteroid* ast, int index) {
	for (int j = index; j < ast->tailleliste - 1; ++j) {
		ast->asteroids[j] = ast->asteroids[j + 1];
	}
	ast->tailleliste--;
}

void colliderprojectiles(laser* las, Asteroid* ast, int i, score* scr) {
	if (las->shoot == 1) {
		sfFloatRect laserbounds = sfSprite_getGlobalBounds(las->spritelaser);
		sfFloatRect asteroidbounds = sfSprite_getGlobalBounds(ast->asteroids[i].asteroidSprite);

		if (sfFloatRect_intersects(&asteroidbounds, &laserbounds, NULL)) {
			las->shoot = 0;
			scr->score += 100;
			ast->asteroids[i].taille = ast->asteroids[i].taille / 2;
			sfSprite_setScale(ast->asteroids[i].asteroidSprite, (sfVector2f) { ast->asteroids[i].taille, ast->asteroids[i].taille });

			if (ast->asteroids[i].taille < 2) {
				destroyAsteroid(ast, i);
				scr->score = scr->score + 200;

			}
		}
	}
}