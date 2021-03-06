/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ovirchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 17:26:16 by ovirchen          #+#    #+#             */
/*   Updated: 2018/10/25 17:26:17 by ovirchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/rtv1.h"

static int	scene_3_0(t_sdl *map)
{
	t_figure *figure;

	if ((figure = (t_figure*)malloc(sizeof(t_figure))) == NULL)
		return (1);
	figure->type = SPHERE;
	figure->r = 1.2;
	figure->next = NULL;
	figure->specular = 10;
	fill_vector(&(figure->center), -4.5, -3, 10);
	fill_color(&(figure->color), 200, 200, 200);
	add_figure(map, figure);
	if ((figure = (t_figure*)malloc(sizeof(t_figure))) == NULL)
		return (1);
	figure->type = SPHERE;
	figure->r = 1.2;
	figure->next = NULL;
	figure->specular = 10;
	fill_vector(&(figure->center), -4.5, 3, 10);
	fill_color(&(figure->color), 200, 200, 200);
	add_figure(map, figure);
	return (0);
}

static int	scene_3_1(t_sdl *map)
{
	t_figure *figure;

	if ((figure = (t_figure*)malloc(sizeof(t_figure))) == NULL)
		return (1);
	figure->type = PLANE;
	figure->r = 0;
	figure->next = NULL;
	figure->specular = 10;
	fill_vector(&(figure->center), 0, -3.2, 12);
	fill_vector(&(figure->direct), 0, 4, 0);
	normalize_vector(&(figure->direct));
	fill_color(&(figure->color), 150, 150, 150);
	add_figure(map, figure);
	if ((figure = (t_figure*)malloc(sizeof(t_figure))) == NULL)
		return (1);
	figure->type = PLANE;
	figure->r = 0;
	figure->next = NULL;
	figure->specular = 10;
	fill_vector(&(figure->center), 0, -7, 30);
	fill_vector(&(figure->direct), 0, 0, -2);
	normalize_vector(&(figure->direct));
	fill_color(&(figure->color), 0, 0, 255);
	add_figure(map, figure);
	return (0);
}

static int	scene_3_2(t_sdl *map)
{
	t_figure *figure;

	if ((figure = (t_figure*)malloc(sizeof(t_figure))) == NULL)
		return (1);
	figure->type = CELINDER;
	figure->r = 0.8;
	figure->next = NULL;
	figure->specular = 100;
	fill_vector(&(figure->center), -4.5, 0, 20);
	fill_vector(&(figure->direct), 0, 4, 0);
	normalize_vector(&(figure->direct));
	fill_color(&(figure->color), 200, 200, 200);
	add_figure(map, figure);
	if ((figure = (t_figure*)malloc(sizeof(t_figure))) == NULL)
		return (1);
	figure->type = CELINDER;
	figure->r = 0.8;
	figure->next = NULL;
	figure->specular = 100;
	fill_vector(&(figure->center), 4.5, 0, 20);
	fill_vector(&(figure->direct), 0, 4, 0);
	normalize_vector(&(figure->direct));
	fill_color(&(figure->color), 200, 200, 200);
	add_figure(map, figure);
	return (0);
}

static int	scene_3_3(t_sdl *map)
{
	t_light *light;

	if ((light = (t_light*)malloc(sizeof(t_light))) == NULL)
		return (1);
	light->type = AMBIENT;
	light->intens = 0.2;
	light->next = NULL;
	add_light(map, light);
	if ((light = (t_light*)malloc(sizeof(t_light))) == NULL)
		return (1);
	light->type = POINT;
	light->intens = 0.4;
	light->next = NULL;
	fill_vector(&(light->center), 8, 2, 4);
	add_light(map, light);
	if ((light = (t_light*)malloc(sizeof(t_light))) == NULL)
		return (1);
	light->type = POINT;
	light->intens = 0.4;
	light->next = NULL;
	fill_vector(&(light->center), -8, 2, 4);
	add_light(map, light);
	return (0);
}

int			scene_3(t_sdl *map)
{
	t_figure *figure;

	if ((figure = (t_figure*)malloc(sizeof(t_figure))) == NULL)
		return (1);
	figure->type = SPHERE;
	figure->r = 0.6;
	figure->next = NULL;
	figure->specular = 100;
	fill_vector(&(figure->center), 0, -2, 10);
	fill_color(&(figure->color), 255, 0, 0);
	add_figure(map, figure);
	if ((figure = (t_figure*)malloc(sizeof(t_figure))) == NULL)
		return (1);
	figure->type = SPHERE;
	figure->r = 1.2;
	figure->next = NULL;
	figure->specular = 10;
	fill_vector(&(figure->center), 4.5, -3, 10);
	fill_color(&(figure->color), 200, 200, 200);
	add_figure(map, figure);
	if (scene_3_0(map) || scene_3_1(map) || scene_3_2(map) ||
		scene_3_3(map) || scene_3_4(map) || scene_3_5(map)
		|| scene_3_6(map) || scene_3_7(map))
		return (1);
	return (0);
}
