/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sceneee_3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ovirchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 20:00:54 by ovirchen          #+#    #+#             */
/*   Updated: 2018/10/29 20:00:55 by ovirchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/rtv1.h"

int	scene_3_4(t_sdl *map)
{
	t_figure *figure;

	if ((figure = (t_figure*)malloc(sizeof(t_figure))) == NULL)
		return (1);
	figure->type = SPHERE;
	figure->r = 1.2;
	figure->next = NULL;
	figure->specular = 10;
	fill_vector(&(figure->center), 4.5, 3, 10);
	fill_color(&(figure->color), 200, 200, 200);
	add_figure(map, figure);
	if ((figure = (t_figure*)malloc(sizeof(t_figure))) == NULL)
		return (1);
	figure->type = SPHERE;
	figure->r = 1.2;
	figure->next = NULL;
	figure->specular = 10;
	fill_vector(&(figure->center), -4.5, -3, 20);
	fill_color(&(figure->color), 200, 200, 200);
	add_figure(map, figure);
	return (0);
}

int	scene_3_5(t_sdl *map)
{
	t_figure *figure;

	if ((figure = (t_figure*)malloc(sizeof(t_figure))) == NULL)
		return (1);
	figure->type = SPHERE;
	figure->r = 1.2;
	figure->next = NULL;
	figure->specular = 10;
	fill_vector(&(figure->center), -4.5, 3, 20);
	fill_color(&(figure->color), 200, 200, 200);
	add_figure(map, figure);
	if ((figure = (t_figure*)malloc(sizeof(t_figure))) == NULL)
		return (1);
	figure->type = SPHERE;
	figure->r = 1.2;
	figure->next = NULL;
	figure->specular = 10;
	fill_vector(&(figure->center), 4.5, -3, 20);
	fill_color(&(figure->color), 200, 200, 200);
	add_figure(map, figure);
	return (0);
}

int	scene_3_6(t_sdl *map)
{
	t_figure *figure;

	if ((figure = (t_figure*)malloc(sizeof(t_figure))) == NULL)
		return (1);
	figure->type = CELINDER;
	figure->r = 0.8;
	figure->next = NULL;
	figure->specular = 100;
	fill_vector(&(figure->center), 4.5, 0, 10);
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
	fill_vector(&(figure->center), -4.5, 0, 10);
	fill_vector(&(figure->direct), 0, 4, 0);
	normalize_vector(&(figure->direct));
	fill_color(&(figure->color), 200, 200, 200);
	add_figure(map, figure);
	return (0);
}

int	scene_3_7(t_sdl *map)
{
	t_figure *figure;

	if ((figure = (t_figure*)malloc(sizeof(t_figure))) == NULL)
		return (1);
	figure->type = SPHERE;
	figure->r = 1.2;
	figure->next = NULL;
	figure->specular = 10;
	fill_vector(&(figure->center), 4.5, 3, 20);
	fill_color(&(figure->color), 200, 200, 200);
	add_figure(map, figure);
	if ((figure = (t_figure*)malloc(sizeof(t_figure))) == NULL)
		return (1);
	figure->type = PLANE;
	figure->r = 0;
	figure->next = NULL;
	figure->specular = 10;
	fill_vector(&(figure->center), 0, 3.2, 12);
	fill_vector(&(figure->direct), 0, 1, 0);
	normalize_vector(&(figure->direct));
	fill_color(&(figure->color), 150, 150, 150);
	add_figure(map, figure);
	return (0);
}
