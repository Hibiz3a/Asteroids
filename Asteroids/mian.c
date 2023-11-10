#include <SFML/Graphics.h>

#include <stdio.h>
#include "ref.h"

int main() {
    window w;
    SpriteShip s;
    variable_init(&w, &s);
    init(&w,&s); 

    while (sfRenderWindow_isOpen(w.wndO)) {
        sfEvent event;
        sfRenderWindow_clear(w.wndO, sfBlack);
        Sprite_Move_ship(&s);
        printf("%f\n", s.Locate.x);

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
