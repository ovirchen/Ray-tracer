/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   figure_intersection.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ovirchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 14:54:51 by ovirchen          #+#    #+#             */
/*   Updated: 2018/09/19 14:54:52 by ovirchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/rtv1.h"

t_figure		*figure_intersect(t_sdl *map, t_figure *list, t_quadratic eq)
{
	eq.t1 = (-eq.k2 + sqrt(eq.discriminant)) / (2 * eq.k1);
	eq.t2 = (-eq.k2 - sqrt(eq.discriminant)) / (2 * eq.k1);
	if (map->closest != NULL)
	{
		if (eq.t1 >= map->t_min && eq.t1 < map->t_max && eq.t1 <
			map->closest->t && (map->closest = list))
			list->t = eq.t1;
		if (eq.t2 >= map->t_min && eq.t2 < map->t_max && eq.t2 <
			map->closest->t && (map->closest = list))
			list->t = eq.t2;
	}
	else
	{
		if (eq.t1 >= map->t_min && eq.t1 < map->t_max && (map->closest = list))
			list->t = eq.t1;
		if (eq.t2 >= map->t_min && eq.t2 < map->t_max && eq.t2 < eq.t1 &&
			(map->closest = list))
			list->t = eq.t2;
	}
	return (map->closest);
}

t_figure		*plane_intersect(t_sdl *map, t_figure *list, t_quadratic eq)
{
	if (eq.k2 == 0 || (eq.k1 < 0 && eq.k2 < 0) || (eq.k1 > 0 && eq.k2 > 0))
		return (map->closest);
	eq.t1 = -1.0 * eq.k1 / eq.k2;
	if (map->closest != NULL)
	{
		if (eq.t1 >= map->t_min && eq.t1 < map->t_max && eq.t1 <
			map->closest->t && (map->closest = list))
			list->t = eq.t1;
	}
	else
	{
		if (eq.t1 >= map->t_min && eq.t1 < map->t_max && (map->closest = list))
			list->t = eq.t1;
	}
	return (map->closest);
}
