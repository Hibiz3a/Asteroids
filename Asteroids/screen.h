#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/Audio.h>
#include <SFML/System.h>
#ifndef SCREEN_H
#define SCREEN_H
typedef struct screen screen;
struct screen
{
    sfRenderWindow* window;
    sfFont* font;
    sfText* text;
};


#endif // !SCREEN_H
