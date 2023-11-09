#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/Audio.h>
#include <SFML/System.h>
#include <stdlib.h>
#include <stdio.h>
#include "ref.h"

void init(wnd* wnd) {
    wnd->wnd_size_height = 1920;
    wnd->wnd_size_width = 1080;

    sfVideoMode mode = { wnd->wnd_size_height, wnd->wnd_size_width, 32 };
    sfRenderWindow* wndO = sfRenderWindow_create(mode, "Asteroid", sfResize | sfClose, NULL);
    sfRenderWindow_setFramerateLimit(wnd, 60);


    while (sfRenderWindow_isOpen(wndO)) {
        sfEvent event;
        sfRenderWindow_clear(wndO, sfBlack);
        sfRenderWindow_display(wndO);
        Create_Sprite_Ship();


        if (sfRenderWindow_pollEvent(wndO, &event)) {
            if (event.type == sfEvtClosed)
                sfRenderWindow_close(wndO);
        }

    }

    sfRenderWindow_destroy(wndO);

}
