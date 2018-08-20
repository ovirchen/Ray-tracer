/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ovirchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/31 16:48:01 by ovirchen          #+#    #+#             */
/*   Updated: 2018/07/31 16:48:02 by ovirchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/rtv1.h"

int	sdl_init(t_sdl *map)
{
	if (SDL_Init(SDL_INIT_VIDEO) == -1 || (map->win = SDL_CreateWindow("rtv1",
		0, 0, WIN_X, WIN_Y, SDL_WINDOW_SHOWN)) == NULL)
		return (error(0));
	if ((map->render = SDL_CreateRenderer(map->win, -1,
		SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC)) == NULL)
		return (error(0));
	if ((map->texture = SDL_CreateTexture(map->render, SDL_PIXELFORMAT_RGB888,
		SDL_TEXTUREACCESS_TARGET, WIN_X, WIN_Y)) == NULL)
		return (error(0));
	map->image = (unsigned int *)malloc(sizeof(unsigned int) * (WIN_X * WIN_Y + 1));
	ft_memset(map->image, 0, WIN_X * WIN_Y + 1);
	map->figure = NULL;
	map->light = NULL;
	fill_vector(&(map->camera), 0.0, 0.0, 1.0);
	return (0);
}

// void sdl_text(t_sdl *map)
// {
// 	string = TTF_RenderText_Solid( map->font, "Render is ready", map->text_color );
// 	apply_surface( 20, 20, string, map->screen );
// }

void sdl_clean_up(t_sdl *map)
{
    //Free the image
    free(map->image);
    SDL_DestroyTexture(map->texture);
	SDL_DestroyRenderer(map->render);
	SDL_DestroyWindow(map->win);
    SDL_Quit();    
}

// void apply_surface( int x, int y, SDL_Surface *src, SDL_Surface *dest)
// {
// 	//Holds offsets
//     SDL_Rect offset;
//     //Get offsets
// 	offset.x = x;
// 	offset.y = y;
    
// 	//Blit
// 	SDL_BlitSurface( src, NULL, dest, &offset );
// }
