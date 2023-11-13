#include <SFML/Graphics.h>

#include <stdio.h>
#include "ref.h"



int main() {
    window w;
    SpriteShip s;
    asteroid a;
    Death d;
    variable_init(&w, &s, &a,&d);
    init(&w,&s, &a); 

    initAsteroid(&a);



    while (sfRenderWindow_isOpen(w.wndO)) {
        sfEvent event;
        sfRenderWindow_clear(w.wndO, sfBlack);
        Sprite_Move_ship(&s, &d);
        return_map_ship(&s,&w);

        asteroid_move(&a);

        sfSprite_setPosition(a.asteroidSprite, a.asteroidpos);
        sfRenderWindow_drawSprite(w.wndO, a.asteroidSprite, NULL);


        sfSprite_setPosition(s.shipsprite, s.Locate);
        sfRenderWindow_drawSprite(w.wndO, s.shipsprite, NULL);


        if (sfRenderWindow_pollEvent(w.wndO, &event)) {
            if (event.type == sfEvtClosed)
                sfRenderWindow_close(w.wndO);
        }
        sfRenderWindow_display(w.wndO);
    }
    sfRenderWindow_destroy(w.wndO);
}
