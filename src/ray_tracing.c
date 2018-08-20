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

t_figure			*ray_tracing(t_sdl *map, t_vector ray, t_vector camera)
{
	t_figure	*list;
	t_figure	*closest;
	t_quadratic	eq;


// printf("\traytracing\n");
	closest = NULL;
	// printf("%f %f %f\n", ray.x, ray.y, ray.z);
	list = map->figure;
	while (list != NULL)
	{
		if (list->type == 's')
		{
			eq.k1 = dot(ray, ray);
			eq.k2 = 2 * dot(minus_vector(camera, list->center), ray);
			eq.k3 = dot(minus_vector(camera, list->center),
				minus_vector(camera, list->center)) - list->r * list->r;
			eq.discriminant = eq.k2 * eq.k2 - 4 * eq.k1 * eq.k3;
			if (eq.discriminant >= 0)
			{
				eq.t1 = (-eq.k2 + sqrt(eq.discriminant)) / (2 * eq.k1);
				eq.t2 = (-eq.k2 - sqrt(eq.discriminant)) / (2 * eq.k1);
				if (closest != NULL)
				{
					if (eq.t1 >= map->t_min && eq.t1 < map->t_max && eq.t1 < closest->t)
					{
						list->t = eq.t1;
						closest = list;
					}
					if (eq.t2 >= map->t_min && eq.t2 < map->t_max && eq.t2 < closest->t)
					{
						list->t = eq.t2;
						closest = list;
					}
				}
				else
				{
					if (eq.t1 >= map->t_min && eq.t1 < map->t_max)
					{
						list->t = eq.t1;
						closest = list;
					}
					if (eq.t2 >= map->t_min && eq.t2 < map->t_max && eq.t2 < eq.t1)
					{
						list->t = eq.t2;
						closest = list;
					}
				}
				// printf("%p %p\n", list, closest);
			}
		}
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
	if ((find_figure = ray_tracing(map, map->ray, map->camera)) == NULL)
		return (0xffffff);
	illumination = find_illumination(map, find_figure);
	color = color_correction(find_figure, illumination);
	return ((color.r << 16) + (color.g << 8) + color.b);
}

double				dot(t_vector v1, t_vector v2)
{
	return (v1.x * v2.x + v1.y * v2.y + v1.z * v2.z);
}
