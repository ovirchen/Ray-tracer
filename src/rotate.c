/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ovirchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 16:03:14 by ovirchen          #+#    #+#             */
/*   Updated: 2018/10/26 16:03:15 by ovirchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/rtv1.h"

static t_vector	rotate_x(t_vector zes, int angle_x)
{
	double		ax;
	t_vector	res;

	ax = angle_x * PI / 180;
	res.x = zes.x;
	res.y = zes.y * cos(ax) + zes.z * sin(ax);
	res.z = -zes.y * sin(ax) + zes.z * cos(ax);
	return (res);
}

static t_vector	rotate_y(t_vector zes, int angle_y)
{
	double		ay;
	t_vector	res;

	ay = angle_y * PI / 180;
	res.x = zes.x * cos(ay) + zes.z * sin(ay);
	res.y = zes.y;
	res.z = -zes.x * sin(ay) + zes.z * cos(ay);
	return (res);
}

static t_vector	rotate_z(t_vector zes, int angle_z)
{
	double		az;
	t_vector	res;

	az = angle_z * PI / 180;
	res.x = zes.x * cos(az) - zes.y * sin(az);
	res.y = zes.x * sin(az) + zes.y * cos(az);
	res.z = zes.z;
	return (res);
}

void			rotate(t_sdl *map, t_vector *v)
{
	t_vector res;

	fill_vector(&res, v->x, v->y, v->z);
	if (map->angle.r != 0)
		res = rotate_x(*v, map->angle.r);
	if (map->angle.g != 0)
		res = rotate_y(res, map->angle.g);
	if (map->angle.b != 0)
		res = rotate_z(res, map->angle.b);
	fill_vector(v, res.x, res.y, res.z);
}

void		rotate_all(t_sdl *map)
{
	t_figure	*figure;
	t_light		*light;

	figure = map->figure;
	while (figure != NULL)
	{
		rotate(map, &(figure->center));
		rotate(map, &(figure->direct));
		figure = figure->next;
	}
	light = map->light;
	while (light != NULL)
	{
		rotate(map, &(light->center));
		rotate(map, &(light->direct));
		light = light->next;
	}
}
