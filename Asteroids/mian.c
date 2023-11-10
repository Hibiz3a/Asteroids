#include <SFML/Graphics.h>

#include <stdio.h>
#include "ref.h"

int main() {
    window w;
    SpriteShip s;
    asteroid a;
    variable_init(&w, &s, &a);
    init(&w,&s); 
     
    sfSprite* asteroid = Asteroid_Create_Sprite("texture/asteroid.png", -100.0f, 300.0f,&a);


    while (sfRenderWindow_isOpen(w.wndO)) {
        sfEvent event;
        sfRenderWindow_clear(w.wndO, sfBlack);
        Sprite_Move_ship(&s);
        asteroid_pos(&a, &w);

        sfSprite_setPosition(asteroid, a.asteroidpos);
        sfRenderWindow_drawSprite(w.wndO, asteroid, NULL);


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
