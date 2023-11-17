#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/Audio.h>
#include <SFML/System.h>
#include "ref.h"

void variable_init(window* wnd, SpriteShip* sprs, asteroid* ast, Death* dt, laser* las) {
	wnd->wnd_size_height = 1950;
	wnd->wnd_size_width = 1100;
	sprs->rotation = 0;
	sprs->speedship = 0.0f;
	dt->death = 0;
	sprs->Locate = (sfVector2f){ wnd->wnd_size_height / 2,wnd->wnd_size_width / 2 };
	las->shoot = 0;
}




