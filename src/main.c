/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ovirchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 17:06:34 by ovirchen          #+#    #+#             */
/*   Updated: 2018/07/25 17:06:35 by ovirchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/rtv1.h"

int			error(int num_error)
{
	if (num_error == 0)
		write(1, "Error in SDL init or create window\n", 35);
	return (1);
}

static int	usage(void)
{
	write(1, "Usage: ./RTv1 [1..3]\n", 21);
	return (1);
}

int			main(int argc, char **argv)
{
	int			trigger;
	t_sdl		map;

	if ((trigger = 1) && sdl_init(&map) == 1)
		return (0);
	if (argc != 2)
		return (usage());
	if (ft_strcmp(argv[1], "1") == 0)
		scene_1(&map);
	else if (ft_strcmp(argv[1], "2") == 0)
		scene_2(&map);
	else if (ft_strcmp(argv[1], "3") == 0)
		scene_3(&map);
	else
		return (usage());
	draw(&map);
	while (trigger)
		if (SDL_PollEvent(&(map.event)))
		{
			if (map.event.type == SDL_QUIT || (map.event.type ==
	SDL_KEYDOWN && map.event.key.keysym.sym == SDLK_ESCAPE))
				trigger = 0;
		}
	sdl_clean_up(&map);
	system("leaks rtv1");
	return (0);
}
