/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   figure_ray_tracing.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ovirchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 14:42:09 by ovirchen          #+#    #+#             */
/*   Updated: 2018/10/29 14:42:10 by ovirchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/rtv1.h"

void		sphere_ray_tracing(t_sdl *map, t_vector ray, t_vector camera,
	t_figure *list)
{
	t_quadratic	eq;

	eq.k1 = dot(ray, ray);
	eq.k2 = 2 * dot(minus_vector(camera, list->center), ray);
	eq.k3 = dot(minus_vector(camera, list->center),
		minus_vector(camera, list->center)) - list->r * list->r;
	eq.discriminant = eq.k2 * eq.k2 - 4 * eq.k1 * eq.k3;
	if (eq.discriminant < 0)
		return ;
	map->closest = figure_intersect(map, list, eq);
}

void		plane_ray_tracing(t_sdl *map, t_vector ray, t_vector camera,
	t_figure *list)
{
	t_quadratic	eq;

	eq.k1 = dot(minus_vector(camera, list->center), list->direct);
	eq.k2 = dot(ray, list->direct);
	map->closest = plane_intersect(map, list, eq);
}

void		celinder_ray_tracing(t_sdl *map, t_vector ray, t_vector camera,
	t_figure *list)
{
	t_quadratic	eq;

	eq.k1 = dot(ray, ray) - pow(dot(ray, list->direct), 2);
	eq.k2 = 2 * (dot(ray, minus_vector(camera, list->center)) - dot(ray,
		list->direct) * dot(minus_vector(camera, list->center), list->direct));
	eq.k3 = dot(minus_vector(camera, list->center), minus_vector(camera,
list->center)) - pow(dot(minus_vector(camera, list->center), list->direct), 2) -
list->r * list->r;
	eq.discriminant = eq.k2 * eq.k2 - 4 * eq.k1 * eq.k3;
	if (eq.discriminant < 0)
		return ;
	map->closest = figure_intersect(map, list, eq);
}

void		cone_ray_tracing(t_sdl *map, t_vector ray, t_vector camera,
	t_figure *list)
{
	t_quadratic	eq;

	eq.k1 = dot(ray, ray) - (1 + pow(list->r, 2)) *
		pow(dot(ray, list->direct), 2);
	eq.k2 = 2 * (dot(ray, minus_vector(camera, list->center)) -
(1 + pow(list->r, 2)) * dot(ray, list->direct) * dot(minus_vector(camera,
list->center), list->direct));
	eq.k3 = dot(minus_vector(camera, list->center), minus_vector(camera,
list->center)) - (1 + pow(list->r, 2)) * pow(dot(minus_vector(camera,
list->center), list->direct), 2);
	eq.discriminant = eq.k2 * eq.k2 - 4 * eq.k1 * eq.k3;
	if (eq.discriminant < 0)
		return ;
	map->closest = figure_intersect(map, list, eq);
}

void		choose_type(t_sdl *map, t_vector ray, t_vector camera,
	t_figure *list)
{
	if (list->type == SPHERE)
		sphere_ray_tracing(map, ray, camera, list);
	else if (list->type == PLANE)
		plane_ray_tracing(map, ray, camera, list);
	else if (list->type == CELINDER)
		celinder_ray_tracing(map, ray, camera, list);
	else if (list->type == CONE)
		cone_ray_tracing(map, ray, camera, list);
}
