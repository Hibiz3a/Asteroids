#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/Audio.h>
#include <SFML/System.h>
#include "ref.h"
#include <stdbool.h>

void showSplashScreen(window* w) {
    sfFont const* font = sfFont_createFromFile("arial.ttf");

    sfText* titleText = sfText_create();
    sfText_setFont(titleText, font);
    sfText_setCharacterSize(titleText, 60);
    sfText_setString(titleText, "ASTEROID");
    sfText_setFillColor(titleText, sfWhite);

    sfText* playText = sfText_create();
    sfText_setFont(playText, font);
    sfText_setCharacterSize(playText, 30);
    sfText_setString(playText, "Jouer");
    sfText_setFillColor(playText, sfWhite);

    sfVector2f titlePosition;
    titlePosition.x = w->mode.width / 2.0f - 150.0f;
    titlePosition.y = w->mode.height / 2.0f - 50.0f;
    sfText_setPosition(titleText, titlePosition);

    sfVector2f playPosition;
    playPosition.x = w->mode.width / 2.0f - 60.0f;
    playPosition.y = w->mode.height / 2.0f + 20.0f;
    sfText_setPosition(playText, playPosition);

    sfClock* clock = sfClock_create();
    bool showMenu = true;

    while (sfRenderWindow_isOpen(w->wndO)) {
        sfEvent event;
        while (sfRenderWindow_pollEvent(w->wndO, &event)) {
            if (event.type == sfEvtClosed)
                sfRenderWindow_close(w->wndO);
            else if (event.type == sfEvtMouseButtonPressed && event.mouseButton.button == sfMouseLeft) {
                sfFloatRect playBounds = sfText_getGlobalBounds(playText);
                sfVector2f mousePos = { (float)event.mouseButton.x, (float)event.mouseButton.y };
                if (sfFloatRect_contains(&playBounds, mousePos.x, mousePos.y)) {
                    sfText_destroy(titleText);
                    sfText_destroy(playText);
                    sfClock_destroy(clock);
                    return;
                }
            }
        }

        if (showMenu) {
            sfRenderWindow_clear(w->wndO, sfBlack);
            sfRenderWindow_drawText(w->wndO, titleText, NULL);
            sfRenderWindow_drawText(w->wndO, playText, NULL);  
            sfRenderWindow_display(w->wndO);
            showMenu = false;
        }
    }

    sfText_destroy(titleText);
    sfText_destroy(playText);
    sfClock_destroy(clock);
}


void showGameOverMenu(window* w, score* scr) {
    sfFont const* font = sfFont_createFromFile("arial.ttf");

    sfText* gameOverText = sfText_create();
    sfText_setFont(gameOverText, font);
    sfText_setCharacterSize(gameOverText, 40);
    sfText_setString(gameOverText, "Game Over, Click anywear to replay");
    sfText_setFillColor(gameOverText, sfRed);

    sfText* scoreText = sfText_create();
    sfText_setFont(scoreText, font);
    sfText_setCharacterSize(scoreText, 20);
    char scoreString[50];
    snprintf(scoreString, sizeof(scoreString), "Score: %i", scr->score);
    sfText_setString(scoreText, scoreString);
    sfText_setFillColor(scoreText, sfWhite);

    sfVector2f gameOverPosition;
    gameOverPosition.x = w->mode.width / 2.0f - 100.0f;
    gameOverPosition.y = w->mode.height / 2.0f - 50.0f;
    sfText_setPosition(gameOverText, gameOverPosition);

    sfVector2f scorePosition;
    scorePosition.x = w->mode.width / 2.0f - 50.0f;
    scorePosition.y = w->mode.height / 2.0f + 20.0f;
    sfText_setPosition(scoreText, scorePosition);

    sfClock* clock = sfClock_create();
    bool showMenu = true;

    while (sfRenderWindow_isOpen(w->wndO)) {
        sfEvent event;
        while (sfRenderWindow_pollEvent(w->wndO, &event)) {
            if (event.type == sfEvtClosed)
                sfRenderWindow_close(w->wndO);
            else if (event.type == sfEvtMouseButtonPressed && event.mouseButton.button == sfMouseLeft) {
                showMenu = false;
                break;
            }
        }

        if (showMenu) {
            sfRenderWindow_clear(w->wndO, sfBlack);
            sfRenderWindow_drawText(w->wndO, gameOverText, NULL);
            sfRenderWindow_drawText(w->wndO, scoreText, NULL);
            sfRenderWindow_display(w->wndO);
        }
        else {
            scr->score = 0;
            return;
        }
    }

    sfText_destroy(gameOverText);
    sfText_destroy(scoreText);
    sfClock_destroy(clock);
}