#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/Audio.h>
#include <SFML/System.h>
#include <stdlib.h>
#include <stdio.h>
#include "ref.h"


void init(window* wnd, SpriteShip* sprs) 
{
    ///////////////////////////////////////////////////////////////////
    ////                        Window create                      ////
    ///////////////////////////////////////////////////////////////////
    sfVideoMode mode = { wnd->wnd_size_height, wnd->wnd_size_width, 32 };
    wnd->wndO = sfRenderWindow_create(mode, "Asteroid", sfResize | sfClose, NULL);
    sfRenderWindow_setFramerateLimit(wnd->wndO, 60);

////////////////////////////////////////////////////////////////////////////////////////
    //Sprite ship create
////////////////////////////////////////////////////////////////////////////////////////
    sprs->shipTexture = sfTexture_createFromFile("texture/spaceship.png", NULL);
    sprs->shipsprite = sfSprite_create();
    sprs->Locate = (sfVector2f){ wnd->wnd_size_height / 2,wnd->wnd_size_width / 2 };
    sfSprite_setTexture(sprs->shipsprite, sprs->shipTexture, sfFalse);
    sfSprite_setPosition(sprs->shipsprite, sprs->Locate);
    sfSprite_setOrigin(sprs->shipsprite, (sfVector2f){32,32});
    sfSprite_setRotation(sprs->shipsprite, sprs->rotation);
}
