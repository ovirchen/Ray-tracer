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

static int	scene_1_0(t_sdl *map)
{
	t_figure *figure;

	if ((figure = (t_figure*)malloc(sizeof(t_figure))) == NULL)
		return (1);
	figure->type = SPHERE;
	figure->r = 1;
	figure->next = NULL;
	figure->specular = 100;
	fill_vector(&(figure->center), 0.5, -0.3, 6);
	fill_color(&(figure->color), 0, 255, 0);
	add_figure(map, figure);
	if ((figure = (t_figure*)malloc(sizeof(t_figure))) == NULL)
		return (1);
	figure->type = SPHERE;
	figure->r = 0.9;
	figure->next = NULL;
	figure->specular = 10;
	fill_vector(&(figure->center), -0.5, -1.5, 6);
	fill_color(&(figure->color), 255, 0, 0);
	add_figure(map, figure);
	return (0);
}

static int	scene_1_1(t_sdl *map)
{
	t_figure *figure;

	if ((figure = (t_figure*)malloc(sizeof(t_figure))) == NULL)
		return (1);
	figure->type = PLANE;
	figure->r = 0;
	figure->next = NULL;
	figure->specular = 10;
	fill_vector(&(figure->center), 0, -4, 12);
	fill_vector(&(figure->direct), 0, 4, 1);
	normalize_vector(&(figure->direct));
	fill_color(&(figure->color), 255, 255, 0);
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
	fill_color(&(figure->color), 150, 150, 0);
	add_figure(map, figure);
	return (0);
}

static int	scene_1_2(t_sdl *map)
{
	t_figure *figure;

	if ((figure = (t_figure*)malloc(sizeof(t_figure))) == NULL)
		return (1);
	figure->type = CELINDER;
	figure->r = 1;
	figure->next = NULL;
	figure->specular = 10;
	fill_vector(&(figure->center), -4, 2, 12);
	fill_vector(&(figure->direct), -0.5, 4, 3);
	normalize_vector(&(figure->direct));
	fill_color(&(figure->color), 0, 0, 250);
	add_figure(map, figure);
	if ((figure = (t_figure*)malloc(sizeof(t_figure))) == NULL)
		return (1);
	figure->type = CELINDER;
	figure->r = 1;
	figure->next = NULL;
	figure->specular = 10;
	fill_vector(&(figure->center), 4, 2, 12);
	fill_vector(&(figure->direct), 0.5, 4, 3);
	normalize_vector(&(figure->direct));
	fill_color(&(figure->color), 0, 0, 250);
	add_figure(map, figure);
	return (0);
}

static int	scene_1_3(t_sdl *map)
{
	t_light *light;

	if ((light = (t_light*)malloc(sizeof(t_light))) == NULL)
		return (1);
	light->type = AMBIENT;
	light->intens = 0.3;
	light->next = NULL;
	add_light(map, light);
	if ((light = (t_light*)malloc(sizeof(t_light))) == NULL)
		return (1);
	light->type = POINT;
	light->intens = 0.5;
	light->next = NULL;
	fill_vector(&(light->center), -4, 8, 0);
	add_light(map, light);
	return (0);
}

int			scene_1(t_sdl *map)
{
	t_figure *figure;

	if ((figure = (t_figure*)malloc(sizeof(t_figure))) == NULL)
		return (1);
	figure->type = CELINDER;
	figure->r = 1;
	figure->next = NULL;
	figure->specular = 10;
	fill_vector(&(figure->center), -4, 2, 12);
	fill_vector(&(figure->direct), 4, 0, 0);
	normalize_vector(&(figure->direct));
	fill_color(&(figure->color), 200, 0, 0);
	add_figure(map, figure);
	if (scene_1_0(map) || scene_1_1(map) || scene_1_2(map) ||
		scene_1_3(map))
		return (1);
	return (0);
}
