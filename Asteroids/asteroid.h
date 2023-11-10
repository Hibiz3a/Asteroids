#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/Audio.h>
#include <SFML/System.h>
#ifndef ASTEROID_H
#define ASTEROID_H
typedef struct asteroid asteroid;
struct asteroid
{
	sfTexture* asteroidTexture;
	sfSprite* asteroidSprite;
	sfVector2f asteroidpos;
	float asteroidspeed;
};
#endif // !ASTEROID_H
