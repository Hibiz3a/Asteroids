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
	sfVector2f asteroidspeed;
	float taille;
	int orientation;
	
};

typedef struct Asteroid Asteroid;
struct Asteroid
{
	asteroid asteroids[50];
	int tailleliste;
	int tailleliste2;
};
#endif // !ASTEROID_H
