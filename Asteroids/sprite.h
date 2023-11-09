#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/Audio.h>
#include <SFML/System.h>
#ifndef SPRITE_H
#define SPRITE_H

typedef struct SpriteShip
{
    sfSprite* shipsprite;
    sfTexture* shipTexture;
    sfVector2f Locate;
}SpriteShip;

#endif // SPRITE_H
