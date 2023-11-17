#ifndef REF_H
#define REF_H
#include "init.h"
#include "sprite.h"
#include "asteroid.h"
#include "projectiles.h"
#include "screen.h"
void init(window* wnd, SpriteShip* sprs, asteroid* ast);
void Sprite_Move_ship(SpriteShip* sprs, Death* dt);
void return_map_ship(SpriteShip* sprs, window* wnd);
void variable_init(window* wnd, SpriteShip* sprs, asteroid* ast, Death* dt, laser* las);
void move_laser(laser* las, SpriteShip* sprs, Death* dt);
void Laser_create(laser* las, SpriteShip* sprs);
void return_map_laser(laser* las, window* wnd);

void sprite_ship_death(SpriteShip* sprs, Death* dt, int i, Asteroid* ast);

//asteroides
///////////////////////////////////////////////////////////////////////
void initasteroid(Asteroid* ast,int i, float scale);
void asteroidmove(Asteroid* ast, int i);
void wrap_around(Asteroid* ast, int i);
void colliderprojectiles(laser* las, Asteroid* ast, int i, score* scr);
///////////////////////////////////////////////////////////////////////

void showSplashScreen(window* wnd);
void showGameOverMenu(window* w, score* scr);
#endif // REF_H
 