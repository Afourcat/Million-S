/*
** EPITECH PROJECT, 2017
** particles.c
** File description:
** particle
*/

#include <stdlib.h>
#include <string.h>
#include "particle.h"

particles *create_particles(size_t size, sfColor color, bool inf, bool grav)
{
	particles *system = malloc(sizeof(particles));

	system->vertex    = calloc(size * 4, sizeof(sfVertex));
	system->speed     = calloc(size, sizeof(sfVector2f));
	for (int i = 0; i < size; ++i)
		system->speed[i] = (sfVector2f){0, 0};
	system->color	  = color;
	system->size      = size;
	system->lifes     = calloc(size, sizeof(float));
	system->life_time = 1;
	system->infinite  = inf;
	system->gravity   = grav;
	system->pos	  = (sfVector2f){0, 0};
	system->size_part = 10;
	return (system);
}

void reset_particles(particles *this, size_t i)
{
	this->vertex[i * 4 + 0].position = this->pos;
	this->vertex[i * 4 + 1].position = 
	(sfVector2f){this->pos.x + this->size_part, this->pos.y};
	this->vertex[i * 4 + 2].position = 
	(sfVector2f){this->pos.x + this->size_part, this->pos.y + this->size_part};
	this->vertex[i * 4 + 3].position = 
	(sfVector2f){this->pos.x, this->pos.y + this->size_part};
	this->lifes[i] = 0;
}

void draw_particles(particles *this, sfRenderWindow *win)
{
	sfRenderWindow_drawPrimitives(win, this->vertex, this->size, sfQuads, NULL);
}

void update_particles(particles *system, float delta_time)
{
	float speed_x;
	float speed_y;

	for (int i = 0; i < system->size; ++i) {
		speed_x = system->speed[i].x;
		speed_y = system->speed[i].y;
		if (system->lifes[i] <= system->life_time) {
			for (int x = 0; x < 4; ++x)
				system->vertex[i * 4 + x].position.x += speed_x;
			for (int x = 0; x < 4; ++x)
				system->vertex[i * 4 + x].position.y += speed_y;
			system->lifes[i] += delta_time;
			system->speed[i].y += GRAVITY * delta_time * 5;
		} else if (system->infinite) {
			reset_particles(system, i);
		}
	}
}

void set_particles(particles *this, sfVector2f speed, int size, size_t id)
{
	this->size_part = size;
	this->vertex[id * 4 + 0].position = this->pos;
	this->vertex[id * 4 + 1].position = (sfVector2f){this->pos.x + size, this->pos.y};
	this->vertex[id * 4 + 2].position = (sfVector2f){this->pos.x + size, this->pos.y + size};
	this->vertex[id * 4 + 3].position = (sfVector2f){this->pos.x , this->pos.y + size};
	this->speed[id] = speed;
	for (int x = 0; x < 4; ++x)
		this->vertex[id * 4 + x].color = this->color;
}
