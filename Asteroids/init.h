#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/Audio.h>
#include <SFML/System.h>
#ifndef INIT_H
#define INIT_H
typedef struct window window;
struct window
{
	int wnd_size_width;
	int wnd_size_height;
	sfRenderWindow* wndO;
};

#endif // INIT_H
