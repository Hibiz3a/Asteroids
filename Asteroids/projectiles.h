#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/Audio.h>
#include <SFML/System.h>
#ifndef PROJECTILES_H
#define PROJECTILES_H
typedef struct laser laser;
struct laser
{
	sfVector2f laserPos;
	sfSprite* spritelaser;
	sfTexture* textureLaser;
	float laserspeer;
	int shoot;
	float rotation;
	sfVector2f direction;
};
#endif // !PROJECTILES_H

