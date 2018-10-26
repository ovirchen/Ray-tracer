/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ovirchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/03 15:25:15 by ovirchen          #+#    #+#             */
/*   Updated: 2018/08/03 15:25:16 by ovirchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/rtv1.h"

int scene_1(t_sdl *map)
{
	t_light *light;
	t_figure *figure;

	figure = (t_figure*)malloc(sizeof(t_figure));
	figure->type = SPHERE;
	figure->r = 1;
	figure->next = NULL;
	figure->specular = 100;
	fill_vector(&(figure->center), 2, 0, 7);
	fill_color(&(figure->color), 0, 0 , 255);
	add_figure(map, figure);
	figure = (t_figure*)malloc(sizeof(t_figure));
	figure->type = SPHERE;
	figure->r = 0.9;
	figure->next = NULL;
	figure->specular = 10;
	fill_vector(&(figure->center), -0.5, -0.5, 6);
	fill_color(&(figure->color), 255, 0 , 0);
	add_figure(map, figure);
	figure = (t_figure*)malloc(sizeof(t_figure));
	figure->type = SPHERE;
	figure->r = 1;
	figure->next = NULL;
	figure->specular = 100;
	fill_vector(&(figure->center), 0.5, 1, 6);
	fill_color(&(figure->color), 0, 255, 0);
	add_figure(map, figure);
	figure = (t_figure*)malloc(sizeof(t_figure));
	figure->type = SPHERE;
	figure->r = 0.5;
	figure->next = NULL;
	figure->specular = 10;
	fill_vector(&(figure->center),  2, 1, 5);
	fill_color(&(figure->color), 200, 100, 250);
	add_figure(map, figure);

	figure = (t_figure*)malloc(sizeof(t_figure));
	figure->type = PLANE;
	figure->r = 0;
	figure->next = NULL;
	figure->specular = 10;
	fill_vector(&(figure->center), 0, -4, 12);
	fill_vector(&(figure->direct), 0, 4, 1);
	normalize_vector(&(figure->direct));
	fill_color(&(figure->color), 0, 250, 0);
	add_figure(map, figure);

	figure = (t_figure*)malloc(sizeof(t_figure));
	figure->type = CONE;
	figure->r = 0.2;
	figure->next = NULL;
	figure->specular = 10;
	fill_vector(&(figure->center), 4, 4, 20);
	fill_vector(&(figure->direct), -0.5, 8, 12);
	normalize_vector(&(figure->direct));
	fill_color(&(figure->color), 255, 255, 0);
	add_figure(map, figure);

	figure = (t_figure*)malloc(sizeof(t_figure));
	figure->type = CELINDER;
	figure->r = 1;
	figure->next = NULL;
	figure->specular = 10;
	fill_vector(&(figure->center), -3, 1, 12);
	fill_vector(&(figure->direct), -0.5, 4, 6);
	normalize_vector(&(figure->direct));
	fill_color(&(figure->color), 200, 100, 250);
	add_figure(map, figure);


	light = (t_light*)malloc(sizeof(t_light));
	light->type = AMBIENT;
	light->intens = 0.2;
	light->next = NULL;
	add_light(map, light);
	light = (t_light*)malloc(sizeof(t_light));
	light->type = POINT;
	light->intens = 0.5;
	light->next = NULL;
	fill_vector(&(light->center), 4, 4, 4);
	add_light(map, light);
	light = (t_light*)malloc(sizeof(t_light));
	light->type = DIRECT;
	light->intens = 0.2;
	light->next = NULL;
	fill_vector(&(light->direct), -4, 4, 4);
	normalize_vector(&(figure->direct));
	add_light(map, light);
	// light = (t_light*)malloc(sizeof(t_light));
	// light->type = POINT;
	// light->intens = 0.5;
	// light->next = NULL;
	// fill_vector(&(light->center), -2, 4, 0);
	// add_light(map, light);

	return (0);
}
