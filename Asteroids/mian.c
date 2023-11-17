#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/Audio.h>
#include <SFML/System.h>
#include <stdio.h>
#include "ref.h"
#include <math.h>
#include <stdbool.h>
#include <time.h>

int main() {
    window w;
    SpriteShip s;
    Death d;
    laser l;
    Asteroid ast;

    variable_init(&w, &s, NULL, &d, &l);
    init(&w, &s, NULL);

    Laser_create(&l, &s);
    ast.tailleliste = 5;
    

    for (int i = 0; i < ast.tailleliste; i++) {
        initasteroid(&ast, i, 4);
        
    }


    while (sfRenderWindow_isOpen(w.wndO)) {
        sfEvent event;
        sfRenderWindow_clear(w.wndO, sfBlack);
        Sprite_Move_ship(&s, &d);

        return_map_ship(&s, &w);
        return_map_laser(&l, &w);

        move_laser(&l, &s, &d);
       

        sfSprite_setPosition(s.shipsprite,s.Locate);
        sfRenderWindow_drawSprite(w.wndO, s.shipsprite, NULL);

        for (int i = 0; i < ast.tailleliste; i++) {
            asteroidmove(&ast, i);
            sfRenderWindow_drawSprite(w.wndO, ast.asteroids[i].asteroidSprite, NULL);
            wrap_around(&ast, i);
        }

        if (sfRenderWindow_pollEvent(w.wndO, &event)) {
            if (event.type == sfEvtClosed)
                sfRenderWindow_close(w.wndO);
        }
        sfRenderWindow_display(w.wndO);
    }

    sfRenderWindow_destroy(w.wndO);

    return 0;
}
