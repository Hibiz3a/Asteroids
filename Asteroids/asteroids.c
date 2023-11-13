#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/Audio.h>
#include <SFML/System.h>
#include "ref.h"
#include <stdlib.h>
#include <stdio.h>

////////////////////////////////////////////////////////////////////////////////////////
    //Sprite asteroid create
////////////////////////////////////////////////////////////////////////////////////////
void initAsteroid(asteroid* ast) {
    ast->asteroidSprite = sfSprite_create();
    ast->asteroidTexture =  sfTexture_createFromFile("texture/asteroid.png", NULL);
    sfSprite_setTexture(ast->asteroidSprite, ast->asteroidTexture, sfTrue);

    // Position initiale en dehors de la fenêtre
    ast->asteroidpos.x = -100.0f;
    ast->asteroidpos.y = -100.0f;
    sfSprite_setPosition(ast->asteroidSprite, ast->asteroidpos);
}
////////////////////////////////////////////////////////////////////////////////////////

void return_map_asteroid(asteroid* ast, window* wnd) {
	if (ast->asteroidpos.x < 0) {
		ast->asteroidpos.x = wnd->wnd_size_height;
	}
	if (ast->asteroidpos.y < 0) {
		ast->asteroidpos.y = wnd->wnd_size_width;
	}
	if (ast->asteroidpos.x > wnd->wnd_size_height) {
		ast->asteroidpos.x = -5;
	}
	if (ast->asteroidpos.y > wnd->wnd_size_width) {
		ast->asteroidpos.y = -5;
	}
}

void asteroid_move(asteroid* ast) {
	ast->asteroidpos.x = ast->asteroidpos.x + 1;
	ast->asteroidpos.y = ast->asteroidpos.y + 1;
}