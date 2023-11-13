#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/Audio.h>
#include <SFML/System.h>
#include "ref.h"

void variable_init(window* wnd, SpriteShip * sprs, asteroid* ast, Death* dt) {

	wnd->wnd_size_height = 1920;
	wnd->wnd_size_width = 1080;
	sprs->rotation = 0;
	sprs->speedship = 0.0f;
	ast->asteroidspeed = 10;
	dt->death = 0;
	sprs->Locate = (sfVector2f){ wnd->wnd_size_height / 2,wnd->wnd_size_width / 2 };

}
void generateRandomPosition(asteroid* asteroid, int windowWidth, int windowHeight) {
	asteroid->asteroidpos.x = rand() % windowWidth;
	asteroid->asteroidpos.y = rand() % windowHeight;
	sfSprite_setPosition(asteroid->asteroidSprite, asteroid->asteroidpos);
}
