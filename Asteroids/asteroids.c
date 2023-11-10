#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/Audio.h>
#include <SFML/System.h>
#include "ref.h"

sfSprite* Asteroid_Create_Sprite(const char* imagePath, float x, float y,asteroid* ast) {

    sfTexture* asteroidtexture = sfTexture_createFromFile(imagePath, NULL);
    sfSprite* asteroidsprite = sfSprite_create();
    sfSprite_setTexture(asteroidsprite, asteroidtexture, sfTrue);

    sfSprite_setPosition(asteroidsprite, ast->asteroidpos);
    sfSprite_setScale(asteroidsprite, (sfVector2f) { 5, 5 });
    
    return asteroidsprite;
}

void asteroid_pos(asteroid* ast, window* wnd) {
    ast->asteroidpos.x = ast->asteroidspeed *0.5;
    ast->asteroidpos.y = ast->asteroidspeed *0.5;
}

