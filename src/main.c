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

int error(int num_error)
{
	if (num_error == 0)
		write(1, "Error in SDL init or create window\n", 35);
	return (1);
}

int main(int argc __attribute__((unused)), char **argv __attribute__((unused)))
{
	int			trigger;
	t_sdl		map;

	if (sdl_init(&map) == 1)
		return (1);
	trigger = 1;
	scene_1(&map);
	draw(&map);
	SDL_Delay(2000);
	while (trigger)
	{
		// scene_1(&map);
		if(SDL_PollEvent(&(map.event)))
		{
			if (map.event.type == SDL_QUIT)
			{
				//Quit the program
				trigger = 0;
			}
			else if (map.event.type == SDL_KEYDOWN &&
				map.event.key.keysym.sym == SDLK_ESCAPE)
			{
				trigger = 0;
			}
		}
		// draw(&map);
		// SDL_Delay(2000);
	}
	// Update Screen
	// SDL_Flip( screen );

	// Pause
	// SDL_Delay( 2000 );

	// apply_surface( 0, 0, image, screen );
	sdl_clean_up(&map);

	return (0);
}