#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/Audio.h>
#include <SFML/System.h>
#include <stdlib.h>
#include <stdio.h>
#include "ref.h"


void init(window* wnd, SpriteShip* sprs) {
    wnd->wnd_size_height = 1920;
    wnd->wnd_size_width = 1080;
    
    sfVideoMode mode = { wnd->wnd_size_height, wnd->wnd_size_width, 32 };
    wnd->wndO = sfRenderWindow_create(mode, "Asteroid", sfResize | sfClose, NULL);
    sfRenderWindow_setFramerateLimit(wnd->wndO, 60);
    sprs->shipTexture = sfTexture_createFromFile("texture/spaceship.png", NULL);
    sprs->shipsprite = sfSprite_create();
    sfSprite_setTexture(sprs->shipsprite, sprs->shipTexture, sfFalse);
    sprs->Locate = (sfVector2f){ 0,0 };
    sfSprite_setPosition(sprs->shipsprite, sprs->Locate);

    while (sfRenderWindow_isOpen(wnd->wndO)) {
        sfEvent event;
        sfRenderWindow_clear(wnd->wndO, sfBlack);
       

        sfRenderWindow_drawSprite(wnd->wndO, sprs->shipsprite, NULL);

        if (sfRenderWindow_pollEvent(wnd->wndO, &event)) {
            if (event.type == sfEvtClosed)
                sfRenderWindow_close(wnd->wndO);
        }
         sfRenderWindow_display(wnd->wndO);
    }

    sfRenderWindow_destroy(wnd->wndO);

}
