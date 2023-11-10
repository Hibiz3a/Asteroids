#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/Audio.h>
#include <SFML/System.h>
#include "ref.h"

void variable_init(window* wnd, SpriteShip * sprs, asteroid* ast) {

	wnd->wnd_size_height = 1920;
	wnd->wnd_size_width = 1080;
	sprs->rotation = 0;
	sprs->speedship = 0.0f;
	ast->asteroidspeed = 100.0f;
}
