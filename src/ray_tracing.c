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

	map->closest = NULL;
	list = map->figure;
	while (list != NULL)
	{
		choose_type(map, ray, camera, list);
		list = list->next;
	}
	return (map->closest);
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
