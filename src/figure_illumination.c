/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   figure_illumination.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ovirchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 14:28:03 by ovirchen          #+#    #+#             */
/*   Updated: 2018/10/29 14:28:05 by ovirchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/rtv1.h"

double	illum_sphere(t_sdl *map, t_figure *figure, t_light *list,
	t_vector point)
{
	double		illum;
	double		dot_n_ray;
	t_vector	norm;
	t_vector	reflect;
	t_vector	ray;

	ray = minus_vector(list->center, point);
	if (list->type == DIRECT)
		ray = minus_vector(list->direct, point);
	illum = 0.0;
	norm = minus_vector(point, figure->center);
	normalize_vector(&norm);
	if ((dot_n_ray = dot(norm, ray)) > 0)
		illum += list->intens * dot_n_ray / (vector_len(norm) *
			vector_len(ray));
	if (figure->specular <= 0)
		return (illum);
	reflect = minus_vector(mult_vector(norm, 2 * dot_n_ray), ray);
	if ((dot_n_ray = dot(reflect, mult_vector(map->ray, -1.0))) > 0)
	{
		illum += list->intens * pow(dot_n_ray / (vector_len(reflect) *
			vector_len(map->ray)),
		figure->specular);
	}
	return (illum);
}

double	illum_plane(t_sdl *map, t_figure *figure, t_light *list,
	t_vector point)
{
	double		illum;
	double		dot_n_ray;
	t_vector	reflect;
	t_vector	ray;

	ray = minus_vector(list->center, point);
	if (list->type == DIRECT)
		ray = minus_vector(list->direct, point);
	illum = 0.0;
	dot_n_ray = dot(figure->direct, ray);
	if (dot(ray, figure->direct) < 0)
		dot_n_ray = dot(mult_vector(figure->direct, -1.0), ray);
	if (dot_n_ray > 0)
		illum += list->intens * dot_n_ray / vector_len(ray);
	if (figure->specular <= 0)
		return (illum);
	reflect = minus_vector(mult_vector(figure->direct, 2 * dot_n_ray), ray);
	if (dot(ray, figure->direct) < 0)
		reflect = minus_vector(mult_vector(mult_vector(figure->direct,
			-1.0), 2 * dot_n_ray), ray);
	if ((dot_n_ray = dot(reflect, mult_vector(map->ray, -1.0))) > 0)
		illum += list->intens * pow(dot_n_ray / (vector_len(reflect) *
			vector_len(map->ray)), figure->specular);
	return (illum);
}

double	illum_celinder(t_sdl *map, t_figure *figure, t_light *list,
	t_vector point)
{
	double		illum;
	double		dot_n_ray;
	t_vector	norm;
	t_vector	reflect;
	t_vector	ray;

	ray = minus_vector(list->center, point);
	if (list->type == DIRECT)
		ray = minus_vector(list->direct, point);
	illum = dot(map->ray, figure->direct) * figure->old_t +
		dot(minus_vector(map->camera, figure->center), figure->direct);
	norm = minus_vector(minus_vector(point, figure->center),
		mult_vector(figure->direct, illum));
	normalize_vector(&norm);
	illum = 0.0;
	if ((dot_n_ray = dot(norm, ray)) > 0)
		illum += list->intens * dot_n_ray / (vector_len(norm) *
			vector_len(ray));
	if (figure->specular <= 0)
		return (illum);
	reflect = minus_vector(mult_vector(norm, 2 * dot_n_ray), ray);
	if ((dot_n_ray = dot(reflect, mult_vector(map->ray, -1.0))) > 0)
		illum += list->intens * pow(dot_n_ray / (vector_len(reflect) *
			vector_len(map->ray)), figure->specular);
	return (illum);
}

double	illum_cone(t_sdl *map, t_figure *figure, t_light *list,
	t_vector point)
{
	double		illum;
	double		dot_n_ray;
	t_vector	norm;
	t_vector	reflect;
	t_vector	ray;

	ray = minus_vector(list->center, point);
	if (list->type == DIRECT)
		ray = minus_vector(list->direct, point);
	illum = 0.0;
	norm = minus_vector(minus_vector(point, figure->center),
mult_vector(figure->direct, dot(map->ray, mult_vector(figure->direct,
figure->old_t)) + dot(minus_vector(map->camera, figure->center),
figure->direct) * (1 + pow(figure->r, 2))));
	normalize_vector(&norm);
	if ((dot_n_ray = dot(norm, ray)) > 0)
		illum += list->intens * dot_n_ray / (vector_len(norm) *
			vector_len(ray));
	if (figure->specular <= 0)
		return (illum);
	reflect = minus_vector(mult_vector(norm, 2 * dot_n_ray), ray);
	if ((dot_n_ray = dot(reflect, mult_vector(map->ray, -1.0))) > 0)
		illum += list->intens * pow(dot_n_ray / (vector_len(reflect) *
			vector_len(map->ray)), figure->specular);
	return (illum);
}
