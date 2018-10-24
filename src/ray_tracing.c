/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_figure.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ovirchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 17:16:29 by ovirchen          #+#    #+#             */
/*   Updated: 2018/08/06 17:16:31 by ovirchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/rtv1.h"

static t_figure		*ray_trace_choose_type(t_sdl *map, t_vector ray,
	t_vector camera, t_figure *list, t_figure *closest)
{
	t_quadratic	eq;

	if (list->type == 's')
	{
		eq.k1 = dot(ray, ray);
		eq.k2 = 2 * dot(minus_vector(camera, list->center), ray);
		eq.k3 = dot(minus_vector(camera, list->center),
			minus_vector(camera, list->center)) - list->r * list->r;
		eq.discriminant = eq.k2 * eq.k2 - 4 * eq.k1 * eq.k3;
		if (eq.discriminant < 0)
			return (closest);
		closest = sphere_intersect(map, list, closest, eq);
	}
	else if (list->type == 'p')
	{
		eq.k1 = dot(minus_vector(camera, list->center), list->direct);
		eq.k2 = dot(ray, list->direct);
		closest = plane_intersect(map, list, closest, eq);
	}
	else if (list->type == 'c')
	{
		eq.k1 = dot(ray, ray) - pow(dot(ray, list->direct), 2);
		eq.k2 = 2 * (dot(ray, minus_vector(camera, list->center)) -
			dot(ray, list->direct) * dot(minus_vector(camera, list->center), list->direct));

		eq.k3 = dot(minus_vector(camera, list->center), minus_vector(camera, list->center))
			- pow(dot(minus_vector(camera, list->center), list->direct), 2) - list->r * list->r;

		eq.discriminant = eq.k2 * eq.k2 - 4 * eq.k1 * eq.k3;
		if (eq.discriminant < 0)
			return (closest);
		closest = celinder_intersect(map, list, closest, eq);
	}
	else if (list->type == 'k')
	{
		eq.k1 = dot(ray, ray) - (1 + pow(tan(list->r), 2)) * pow(dot(ray, list->direct), 2);
		eq.k2 = 2 * (dot(ray, minus_vector(camera, list->center)) - (1 + pow(tan(list->r), 2)) *
			dot(ray, list->direct) * dot(minus_vector(camera, list->center), list->direct));

		eq.k3 = dot(minus_vector(camera, list->center), minus_vector(camera, list->center))
			- (1 + pow(tan(list->r), 2)) * pow(dot(minus_vector(camera, list->center), list->direct), 2);

		eq.discriminant = eq.k2 * eq.k2 - 4 * eq.k1 * eq.k3;
		if (eq.discriminant < 0)
			return (closest);
		closest = celinder_intersect(map, list, closest, eq);
	}
	return (closest);
}

t_figure			*ray_tracing(t_sdl *map, t_vector ray, t_vector camera)
{
	t_figure	*list;
	t_figure	*closest;

	closest = NULL;
	list = map->figure;
	while (list != NULL)
	{
		closest = ray_trace_choose_type(map, ray, camera, list, closest);
		list = list->next;
	}
	return (closest);
}

unsigned int		check_figure(t_sdl *map)
{
	t_figure	*find_figure;
	t_color		color;
	double		illumination;

	map->ray = minus_vector(map->viewport, map->camera);
	normalize_vector(&(map->ray));
	if ((find_figure = ray_tracing(map, map->ray, map->camera)) == NULL)
		return (0x000000);
	illumination = find_illumination(map, find_figure);
	color = color_correction(find_figure, illumination);
	return ((color.r << 16) + (color.g << 8) + color.b);
}

double				dot(t_vector v1, t_vector v2)
{
	return (v1.x * v2.x + v1.y * v2.y + v1.z * v2.z);
}
