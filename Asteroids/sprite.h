#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/Audio.h>
#include <SFML/System.h>
#ifndef SPRITE_H
#define SPRITE_H

typedef struct SpriteShip SpriteShip;
struct SpriteShip
{   
    float rotation;
    sfVector2f direction;
    const sfSprite* shipsprite;
    sfTexture* shipTexture;
    sfVector2f Locate;
    float speedship;
};

#endif // SPRITE_H
