/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ovirchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/01 16:09:35 by ovirchen          #+#    #+#             */
/*   Updated: 2018/08/01 16:09:37 by ovirchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/rtv1.h"

void	draw(t_sdl *map)
{
	int i;
	int j;

	j = -1;
	if (map->angle.r != 0 || map->angle.g != 0 || map->angle.b != 0)
		rotate_all(map);
	while (++j < WIN_Y)
	{
		i = -1;
		while (++i < WIN_X)
		{
			fill_vector(&(map->viewport), map->camera.x + (i - WIN_X / 2.0) *
				((double)WIN_X / WIN_Y) / WIN_X, map->camera.y + (WIN_Y / 2.0
					- j) / WIN_Y, map->camera.z + 1);
			map->t_min = map->viewport.z;
			map->t_max = INFINITY;
			map->image[j * WIN_X + i] = check_figure(map);
		}
	}
	fill_color(&(map->angle), 0, 0, 0);
	// SDL_RenderClear(map->render);
	SDL_UpdateTexture(map->texture, NULL, map->image, WIN_X * 4);
	SDL_RenderCopy(map->render, map->texture, NULL, NULL);
	SDL_RenderPresent(map->render);
}
