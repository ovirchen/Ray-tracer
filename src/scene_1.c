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

	// figure = (t_figure*)malloc(sizeof(t_figure));
	// figure->type = 's';
	// figure->r = 1;
	// figure->next = NULL;
	// fill_vector(&(figure->center), 2, 0, 7);
	// fill_color(&(figure->color), 0, 0 , 255);
	// add_figure(map, figure);
	figure = (t_figure*)malloc(sizeof(t_figure));
	figure->type = 's';
	figure->r = 1;
	figure->next = NULL;
	fill_vector(&(figure->center), -0.5, -0.5, 5);
	fill_color(&(figure->color), 255, 0 , 0);
	add_figure(map, figure);
	// figure = (t_figure*)malloc(sizeof(t_figure));
	// figure->type = 's';
	// figure->r = 1;
	// figure->next = NULL;
	// fill_vector(&(figure->center), 0.5, 1, 5);
	// fill_color(&(figure->color), 0, 255, 0);
	// add_figure(map, figure);
	// figure = (t_figure*)malloc(sizeof(t_figure));
	// figure->type = 's';
	// figure->r = 0.5;
	// figure->next = NULL;
	// fill_vector(&(figure->center),  2, 1, 5);
	// fill_color(&(figure->color), 0, 255, 0);
	// add_figure(map, figure);

	light = (t_light*)malloc(sizeof(t_light));
	light->type = 'a';
	light->intens = 0.2;
	light->next = NULL;
	add_light(map, light);
	light = (t_light*)malloc(sizeof(t_light));
	light->type = 'p';
	light->intens = 0.5;
	light->next = NULL;
	fill_vector(&(light->center), 0, 4, 5);
	add_light(map, light);
	light = (t_light*)malloc(sizeof(t_light));
	light->type = 'p';
	light->intens = 0.5;
	light->next = NULL;
	fill_vector(&(light->center), 4, 4, 5);
	add_light(map, light);

	return (0);
}
