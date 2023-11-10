#ifndef REF_H
#define REF_H
#include "init.h"
#include "sprite.h"
#include "asteroid.h"
void init(window* wnd, SpriteShip* sprs);
void Sprite_Move_ship(SpriteShip* sprs);
void variable_init(window* wnd, SpriteShip* sprs, asteroid* ast);
sfSprite* Asteroid_Create_Sprite(const char* imagePath, float x, float y,asteroid* ast);
void asteroid_pos(asteroid* ast, window* wnd);
#endif // REF_H

