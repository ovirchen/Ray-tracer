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

double		find_illumination(t_sdl *map, t_figure *figure)
{
	double		illumination;
	double		dot_n_ray;
	double		m;
	t_light		*list;
	t_vector	point;
	t_vector	ray;
	t_vector	reflect;

	point = plus_vector(map->camera, mult_vector(map->ray, figure->t));
	illumination = 0.0;
	list = map->light;
	while (list != NULL)
	{
		if (list->type == 'a')
			illumination += list->intens;
		else if (list->type == 'p')
		{
			ray = minus_vector(list->center, point);
			map->t_min = 0.0000001;
			map->t_max = 1;
			if (ray_tracing(map, ray, point) == NULL)
			{
				if (figure->type == 's')
				{
					if ((dot_n_ray = dot(minus_vector(point, figure->center), ray)) > 0)
						illumination += list->intens * dot_n_ray / (figure->r * vector_len(ray));
					if (figure->specular > 0)
					{
						reflect = minus_vector(mult_vector(minus_vector(point, figure->center), 2 * dot_n_ray), ray);
						if ((dot_n_ray = dot(reflect, mult_vector(map->ray, -1.0))) > 0)
						{
							illumination += list->intens * pow(dot_n_ray / (vector_len(reflect) * vector_len(map->ray)),
								figure->specular);
						}
					}
				}
				else if (figure->type == 'p')
				{
					// normalize_vector(&ray);
					dot_n_ray = dot(figure->direct, ray);
					if (dot(ray, figure->direct) < 0)
						dot_n_ray = dot(mult_vector(figure->direct, -1.0), ray);
					if (dot_n_ray > 0)
						illumination += list->intens * dot_n_ray / (vector_len(figure->direct) * vector_len(ray));
					if (figure->specular > 0)
					{
						reflect = minus_vector(mult_vector(figure->direct, 2 * dot_n_ray), ray); // figure->direct -1.0
						if (dot(ray, figure->direct) < 0)
							reflect = minus_vector(mult_vector(mult_vector(figure->direct, -1.0), 2 * dot_n_ray), ray);
						if ((dot_n_ray = dot(reflect, mult_vector(map->ray, -1.0))) > 0)
						{
							illumination += list->intens * pow(dot_n_ray / (vector_len(reflect) * vector_len(map->ray)),
								figure->specular);
						}
					}
				}
				else if (figure->type == 'c')
				{
					// normalize_vector(&ray);
					m = dot(map->ray, mult_vector(figure->direct, figure->t)) + dot(minus_vector(map->camera, figure->center), figure->direct);
					if ((dot_n_ray = dot(minus_vector(minus_vector(point, figure->center), mult_vector(figure->direct, m)), ray)) > 0)
						illumination += list->intens * dot_n_ray / (vector_len(figure->direct) * vector_len(ray));
					if (figure->specular > 0)
					{
						reflect = minus_vector(mult_vector(minus_vector(minus_vector(point, figure->center), mult_vector(figure->direct, m)), 2 * dot_n_ray), ray);
						if ((dot_n_ray = dot(reflect, mult_vector(map->ray, -1.0))) > 0)
						{
							illumination += list->intens * pow(dot_n_ray / (vector_len(reflect) * vector_len(map->ray)),
								figure->specular);
						}
					}
				}
				else if (figure->type == 'k')
				{
					m = dot(map->ray, mult_vector(figure->direct, figure->t)) + dot(minus_vector(map->camera, figure->center), figure->direct);
					if ((dot_n_ray = dot(minus_vector(minus_vector(point, figure->center), mult_vector(figure->direct, m * (1 + tan(figure->r) * tan(figure->r)))), ray)) > 0)
						illumination += list->intens * dot_n_ray / (vector_len(figure->direct) * vector_len(ray));
					if (figure->specular > 0)
					{
						reflect = minus_vector(mult_vector(minus_vector(minus_vector(point, figure->center), mult_vector(figure->direct, m)), 2 * dot_n_ray), ray);
						if ((dot_n_ray = dot(reflect, mult_vector(map->ray, -1.0))) > 0)
						{
							illumination += list->intens * pow(dot_n_ray / (vector_len(reflect) * vector_len(map->ray)),
								figure->specular);
						}
					}
				}
			}
		}
		list = list->next;
	}
	if (illumination > 1.0)
		illumination = 1.0;
	else if (illumination < 0.0)
		illumination = 0.0;
	return (illumination);
}

static int	check_color(int color)
{
	if (color < 0)
		color = 0;
	else if (color > 255)
		color = 255;
	return (color);
}

t_color		color_correction(t_figure *figure, double illumination)
{
	t_color color;

	color.r = check_color((int)(figure->color.r * illumination));
	color.g = check_color((int)(figure->color.g * illumination));
	color.b = check_color((int)(figure->color.b * illumination));
	return (color);
}
