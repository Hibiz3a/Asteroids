#ifndef REF_H
#define REF_H
#include "init.h"
#include "sprite.h"
#include "asteroid.h"
void init(window* wnd, SpriteShip* sprs, asteroid* ast);
void Sprite_Move_ship(SpriteShip* sprs, Death* dt);
void return_map_ship(SpriteShip* sprs, window* wnd);
void variable_init(window* wnd, SpriteShip* sprs, asteroid* ast, Death* dt);
void initAsteroid(asteroid* ast);
void generateRandomPosition(asteroid* asteroid, int windowWidth, int windowHeight);
void asteroid_move(asteroid* ast);
#endif // REF_H

