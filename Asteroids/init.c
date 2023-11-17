#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/Audio.h>
#include <SFML/System.h>
#include <stdlib.h>
#include <stdio.h>
#include "ref.h"

void init(window* wnd, SpriteShip* sprs, asteroid* ast)
{
	
	///////////////////////////////////////////////////////////////////
	////                        Window create                      ////
	///////////////////////////////////////////////////////////////////


	////////////////////////////////////////////////////////////////////////////////////////
		//Sprite ship create
	////////////////////////////////////////////////////////////////////////////////////////
	sprs->shipTexture = sfTexture_createFromFile("texture/spaceship.png", NULL);
	sprs->shipsprite = sfSprite_create();

	sfSprite_setTexture(sprs->shipsprite, sprs->shipTexture, sfFalse);
	sfSprite_setRotation(sprs->shipsprite, sprs->rotation);
	sfSprite_setPosition(sprs->shipsprite, sprs->Locate);
	sfSprite_setOrigin(sprs->shipsprite, (sfVector2f) { 16, 16 });
	////////////////////////////////////////////////////////////////////////////////////////

	

}	

