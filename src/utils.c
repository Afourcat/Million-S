/*
** EPITECH PROJECT, 2017
** utils.c
** File description:
** utils.c
*/

#include <SFML/Graphics.h>
#include <stdlib.h>

sfVector2f rand_vector(int disp)
{
	sfVector2f vec;
	vec.x = rand() % disp - (disp / 2);
	vec.y = rand() % disp - (disp / 2);
	return (vec);
}
