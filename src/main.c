/*
** EPITECH PROJECT, 2017
** main.c
** File description:
** main
*/

#include <stdlib.h>
#include <string.h>
#include <SFML/Graphics.h>
#include <stdbool.h>
#include "particle.h"

int loop(sfRenderWindow *win, particles *system)
{
	sfEvent event;

	while (sfRenderWindow_isOpen(win)) {
		while (sfRenderWindow_pollEvent(win, &event)) {
			if (event.type == sfEvtClosed) {
				sfRenderWindow_close(win);
			} else if (event.type == sfEvtMouseMoved) {
				system->pos =
				(sfVector2f){event.mouseMove.x, event.mouseMove.y};
			}
		}
		sfRenderWindow_clear(win, sfBlack);
		update_particles(system, 0.016);
		draw_particles(system, win);
		sfRenderWindow_display(win);
	}
	return (0);
}

int main(int argc, char *argv[])
{
	srand((unsigned long) &loop);
	sfVideoMode mode = {WIDTH, HEIGHT, 32};
	sfRenderWindow *win = 
	sfRenderWindow_create(mode, "Particle", sfResize | sfClose, NULL);
	
	sfRenderWindow_setFramerateLimit(win, 60);
	particles *part = create_particles(2000, sfRed, true, true);
	part->pos = (sfVector2f){500, 500};
	loop(win, part);
	return(0);
}
