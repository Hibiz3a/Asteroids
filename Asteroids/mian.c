#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/Audio.h>
#include <SFML/System.h>
#include <stdio.h>
#include "ref.h"
#include <math.h>
#include <stdbool.h>
#include <time.h>
#define PI 3.1415

int main() {
    window w;
    SpriteShip s;
    Death d;
    laser l;
    Asteroid ast;
    score scr;
    w.mode = sfVideoMode_getDesktopMode();
    w.wndO = sfRenderWindow_create(w.mode, "Asteroid", sfClose, NULL);
    sfRenderWindow_setFramerateLimit(w.wndO, 60);

    variable_init(&w, &s, NULL, &d, &l);
    init(&w, &s, NULL);

    ast.tailleliste = 5;
    
    scr.score = 0;
    for (int i = 0; i < ast.tailleliste; i++) {
        initasteroid(&ast, i, 4);
    }

    sfFont const* font = sfFont_createFromFile("arial.ttf");
    scr.scoretext = sfText_create();
    sfText_setFont(scr.scoretext, font);
    sfText_setCharacterSize(scr.scoretext, 24); 
    sfVector2f textPosition = { 10.0f, 10.0f };
    sfText_setPosition(scr.scoretext, textPosition);
    sfText_setFillColor(scr.scoretext, sfWhite);

    showSplashScreen(&w); 

    while (sfRenderWindow_isOpen(w.wndO)) {
        sfEvent event;

        if (d.death == 1) {
            showGameOverMenu(&w, &scr);
            variable_init(&w, &s, NULL, &d, &l);
            init(&w, &s, NULL);
            Laser_create(&l, &s);
            ast.tailleliste = 5;
            for (int i = 0; i < ast.tailleliste; i++) {
                initasteroid(&ast, i, 4);
            }
        }
        else {
            sfRenderWindow_clear(w.wndO, sfBlack);
            Sprite_Move_ship(&s, &d);

            return_map_ship(&s, &w);
            return_map_laser(&l, &w);

            move_laser(&l, &s, &d);




            sfSprite_setPosition(s.shipsprite, s.Locate);
            sfRenderWindow_drawSprite(w.wndO, s.shipsprite, NULL);

            for (int i = 0; i < ast.tailleliste; i++) {
                colliderprojectiles(&l, &ast, i, &scr);
                asteroidmove(&ast, i);
                sfRenderWindow_drawSprite(w.wndO, ast.asteroids[i].asteroidSprite, NULL);
                wrap_around(&ast, i);
                sprite_ship_death(&s, &d, i, &ast);


            }

            if (ast.tailleliste == 0) {
                ast.tailleliste = 5;
                for (int i = 0; i < ast.tailleliste; i++) {
                    initasteroid(&ast, i, 4);
                }
            }

            if (l.shoot == 1) {
                l.laserPos.x += l.laserspeer * cosf(l.rotation * PI / 180);
                l.laserPos.y += l.laserspeer * sinf(l.rotation * PI / 180);
                sfRenderWindow_drawSprite(w.wndO, l.spritelaser, NULL);
                sfSprite_setPosition(l.spritelaser, l.laserPos);
            }


            char scoreString[50];
            snprintf(scoreString, sizeof(scoreString), "Score: %i", scr.score);
            sfText_setString(scr.scoretext, scoreString);
            sfRenderWindow_drawText(w.wndO, scr.scoretext, NULL);

            if (sfRenderWindow_pollEvent(w.wndO, &event)) {
                if (event.type == sfEvtClosed)
                    sfRenderWindow_close(w.wndO);
            }
            sfRenderWindow_display(w.wndO);
        }
    }

    sfRenderWindow_destroy(w.wndO);
    return 0;
}
