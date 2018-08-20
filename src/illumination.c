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
	double		dot_n_l;
	t_light		*list;
	t_vector	point;
	t_vector	ray;

	illumination = 0.0;
	list = map->light;
	while (list != NULL)
	{
		if (list->type == 'a')
			illumination += list->intens;
		else if (list->type == 'p')
		{
			point = plus_vector(map->camera, mult_vector(map->ray, figure->t));
			ray = minus_vector(list->center, point);
			map->t_min = 0.0000001;
			map->t_max = 1;
			if (ray_tracing(map, ray, point) == NULL)
			{
				if ((dot_n_l = dot(minus_vector(point, figure->center), ray)) > 0)
					illumination += list->intens * dot_n_l / (figure->r *
						vector_len(ray));
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