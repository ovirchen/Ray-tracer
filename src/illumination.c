/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   illumination.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ovirchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 14:36:06 by ovirchen          #+#    #+#             */
/*   Updated: 2018/08/09 14:36:09 by ovirchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/rtv1.h"

static double	figure_illumination(t_sdl *map, t_figure *figure, t_light *list,
	t_vector point)
{
	double		illum;
	t_vector	ray;

	illum = 0.0;
	map->t_min = 0.0001;
	map->t_max = 1;
	if (list->type == POINT)
		ray = minus_vector(list->center, point);
	else
		ray = minus_vector(list->direct, point);
	if (ray_tracing(map, ray, point) == NULL)
	{
		if (figure->type == SPHERE)
			illum += illum_sphere(map, figure, list, point);
		else if (figure->type == PLANE)
			illum += illum_plane(map, figure, list, point);
		else if (figure->type == CELINDER)
			illum += illum_celinder(map, figure, list, point);
		else if (figure->type == CONE)
			illum += illum_cone(map, figure, list, point);
	}
	return (illum);
}

double			find_illumination(t_sdl *map, t_figure *figure)
{
	double		illumination;
	t_light		*list;
	t_vector	point;

	figure->old_t = figure->t;
	point = plus_vector(map->camera, mult_vector(map->ray, figure->old_t));
	illumination = 0.0;
	list = map->light;
	while (list != NULL)
	{
		if (list->type == AMBIENT)
			illumination += list->intens;
		else if (list->type == POINT || list->type == DIRECT)
			illumination += figure_illumination(map, figure, list, point);
		list = list->next;
	}
	return (illumination);
}
