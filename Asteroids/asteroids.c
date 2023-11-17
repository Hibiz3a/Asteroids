#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/Audio.h>
#include <SFML/System.h>
#include <stdio.h>
#include "ref.h"
#include <math.h>
#include <stdbool.h>
#include <time.h>

float random(int min, int max)
{
    return (float)(rand() % (max + 1 - min)) + min;
}


void initasteroid(Asteroid* ast, int i, float scale) {
    ast->asteroids[i].asteroidSprite = sfSprite_create();
    ast->asteroids[i].asteroidTexture = sfTexture_createFromFile("texture/asteroid.png", NULL);
    ast->asteroids[i].asteroidpos.x = random(0, 1920);
    ast->asteroids[i].asteroidpos.y = random(0, 1080); 
    sfSprite_setTexture(ast->asteroids[i].asteroidSprite, ast->asteroids[i].asteroidTexture, sfFalse);
    sfSprite_setOrigin(ast->asteroids[i].asteroidSprite, (sfVector2f){16, 16});
    sfSprite_setPosition(ast->asteroids[i].asteroidSprite, ast->asteroids[i].asteroidpos);
    ast->asteroids[i].taille = scale;
    sfSprite_setScale(ast->asteroids[i].asteroidSprite, (sfVector2f){ast->asteroids[i].taille, ast->asteroids[i].taille });
    ast->asteroids[i].orientation = random(0, 360);

}

void asteroidmove(Asteroid* ast, int i) {
    ast->asteroids[i].asteroidpos.x += cosf(ast->asteroids->orientation * 3.14159265 / 180) * ast->asteroids[i].asteroidspeed.x;
    ast->asteroids[i].asteroidpos.y += sinf(ast->asteroids->orientation * 3.14159265 / 180) * ast->asteroids[i].asteroidspeed.y;
    sfSprite_setPosition(ast->asteroids[i].asteroidSprite, ast->asteroids[i].asteroidpos); 

}

void wrap_around(Asteroid* ast, int i) {
    float windowWidth = 2020; 
    float windowHeight = 1180; 

    if (ast->asteroids[i].asteroidpos.x > windowWidth) {
        ast->asteroids[i].asteroidpos.x = -100.0f;
        ast->asteroids[i].asteroidspeed.x = random(2, 5);
        ast->asteroids[i].asteroidspeed.y = random(2, 5);
        ast->asteroids[i].orientation = random(0, 360);
    }
    else if (ast->asteroids[i].asteroidpos.x < -100.0f) {
        ast->asteroids[i].asteroidpos.x = windowWidth;
        ast->asteroids[i].asteroidspeed.x = random(2, 5);
        ast->asteroids[i].asteroidspeed.y = random(2, 5);
        ast->asteroids[i].orientation = random(0, 360);
    }

    if (ast->asteroids[i].asteroidpos.y > windowHeight) {
        ast->asteroids[i].asteroidpos.y = -100.0f;
        ast->asteroids[i].asteroidspeed.x = random(2, 5);
        ast->asteroids[i].asteroidspeed.y = random(2, 5);
        ast->asteroids[i].orientation = random(0, 360);
    }
    else if (ast->asteroids[i].asteroidpos.y < -100.0f) {
        ast->asteroids[i].asteroidpos.y = windowHeight;
        ast->asteroids[i].asteroidspeed.x = random(2, 5);
        ast->asteroids[i].asteroidspeed.y = random(2, 5);
        ast->asteroids[i].orientation = random(0, 360);
    }
}

