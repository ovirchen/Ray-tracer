/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ovirchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/03 15:33:38 by ovirchen          #+#    #+#             */
/*   Updated: 2018/08/03 15:33:39 by ovirchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/rtv1.h"

void add_figure(t_sdl *map, t_figure *new)
{
	t_figure *tmp;

	if (map->figure)
	{
		tmp = map->figure;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
	}
	else
		map->figure = new;
}

void add_light(t_sdl *map, t_light *new)
{
	// t_figure *tmp;
	// t_figure *new;

	// new = (t_figure*)malloc(sizeof(t_figure));
	// new->type = type;
	// new->intens = intens;
	// new->center = center;
	// if (map->figure)
	// {
	// 	tmp = map->figure;
	// 	while (tmp != NULL)
	// 	{
			
	// 	}
	// }
	// else
	// {
	// 	map->figure = new;
	// }
	t_light *tmp;

	if (map->light)
	{
		tmp = map->light;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
	}
	else
		map->light = new;
}
