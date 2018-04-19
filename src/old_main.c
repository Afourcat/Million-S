/*
** EPITECH PROJECT, 2017
** main.c
** File description:
** main function
*/

#include <stdlib.h>
#include <string.h>
#include <SFML/Graphics.h>
#include "test.h"

void update_part_buffer(part_buffer_t *this)
{
	for (uint id = 0; id < this->size; ++id) {
		this->vertex[(id * 4) + 0].position.y += 1;
		this->vertex[(id * 4) + 1].position.y += 1;
		this->vertex[(id * 4) + 2].position.y += 1;  
		this->vertex[(id * 4) + 3].position.y += 1;  
	}
}

void update(sfRenderWindow *win, part_buffer_t *buffer)
{
	sfRenderWindow_clear(win, sfBlack);
	draw_part_buffer(buffer, win);
	update_part_buffer(buffer);
	sfRenderWindow_display(win);
}

part_buffer_t *create_part_buffer(uint size)
{
	uint size_malloc = sizeof(part_buffer_t) + sizeof(sfVertex) * size * 4;
	part_buffer_t *buffer = malloc(size_malloc);

	memset(buffer, 0, size_malloc);
	buffer = (part_buffer_t *) buffer;
	buffer->size = size;
	buffer->vertex = (sfVertex *) (buffer + sizeof(part_buffer_t));
	return (buffer);
}

void draw_part_buffer(part_buffer_t *this, sfRenderWindow *win)
{
	sfRenderWindow_drawPrimitives(win, this->vertex, this->size * 4, sfQuads, NULL);
}

void set_part(part_buffer_t *this, sfVector2f pos, uint id, sfColor color)
{
	this->vertex[(id * 4) + 0].position = (sfVector2f){pos.x + 0  , pos.y + 0};
	this->vertex[(id * 4) + 1].position = (sfVector2f){pos.x + 100, pos.y + 0};
	this->vertex[(id * 4) + 2].position = (sfVector2f){pos.x + 100, pos.y + 100};
	this->vertex[(id * 4) + 3].position = (sfVector2f){pos.x + 0  , pos.y + 100};
	this->vertex[(id * 4) + 0].color = color;
	this->vertex[(id * 4) + 1].color = color;
	this->vertex[(id * 4) + 2].color = color;
	this->vertex[(id * 4) + 3].color = color;
}

int particle_loop(sfRenderWindow *win, part_buffer_t *buffer)
{
	sfEvent event;

	while (sfRenderWindow_isOpen(win)) {
		while (sfRenderWindow_pollEvent(win, &event)) {
			if (event.type == sfEvtClosed) {
				sfRenderWindow_close(win);
			}
		}
		update(win, buffer);
	}
	return (0);
}

int main(int argc, char *argv[])
{
	int w = 1920;
	int h = 1080;

	srand((unsigned long) &particle_loop);
	sfVideoMode mode = {WIDTH, HEIGHT, 32};
	sfRenderWindow *win = 
	sfRenderWindow_create(mode, "Particle", sfResize | sfClose, NULL);
	
	sfRenderWindow_setFramerateLimit(win, 120);
	part_buffer_t *buffer = create_part_buffer(400000);
	for (uint i = 0; i <= 420; ++i) {
		set_part(buffer , (sfVector2f){rand() % w, rand() % h}, i,
		(sfColor){rand() % 255, rand() % 255, rand() % 255, 255});
	}
	particle_loop(win, buffer);
	return(0);
}
