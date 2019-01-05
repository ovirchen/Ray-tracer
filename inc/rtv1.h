/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ovirchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/31 14:47:44 by ovirchen          #+#    #+#             */
/*   Updated: 2018/07/31 14:47:45 by ovirchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H

# include "../frameworks/SDL2.framework/Headers/SDL.h"
# include <unistd.h>
# include <math.h>
# include "../libft/libft.h"

# define WIN_X 640
# define WIN_Y 480
# define PI 3.141592
# define PLANE 0
# define SPHERE 1
# define CELINDER 2
# define CONE 3
# define AMBIENT 0
# define POINT 1
# define DIRECT 2

typedef struct			s_vector
{
	double	x;
	double	y;
	double	z;
}						t_vector;

typedef struct			s_color
{
	int r;
	int g;
	int b;
}						t_color;

typedef struct			s_figure
{
	char				type;
	double				r;
	double				t;
	double				old_t;
	int					specular;
	t_vector			center;
	t_vector			direct;
	t_color				color;
	struct s_figure		*next;

}						t_figure;

typedef struct			s_light
{
	char			type;
	double			intens;
	t_vector		center;
	t_vector		direct;
	struct s_light	*next;
}						t_light;

typedef struct			s_sdl
{
	SDL_Window		*win;
	SDL_Renderer	*render;
	SDL_Texture		*texture;
	SDL_Event		event;
	t_figure		*figure;
	t_figure		*closest;
	t_light			*light;
	unsigned int	*image;
	t_vector		viewport;
	t_vector		ray;
	t_vector		camera;
	double			t_min;
	double			t_max;
	double			t;
	t_color			angle;
}						t_sdl;

typedef struct			s_quadratic
{
	double	k1;
	double	k2;
	double	k3;
	double	discriminant;
	double	t1;
	double	t2;
}						t_quadratic;

int						error(int num_error);
int						sdl_init(t_sdl *map);
void					apply_surface(int x, int y, SDL_Surface *src,
	SDL_Surface *dest);
void					sdl_text(t_sdl *map);
void					sdl_clean_up(t_sdl *map);

void					draw(t_sdl *map);
t_color					color_correction(t_figure *figure, double illumination);

t_figure				*ray_tracing(t_sdl *map, t_vector ray, t_vector camera);
unsigned int			check_figure(t_sdl *map);
double					dot(t_vector v1, t_vector v2);

void					choose_type(t_sdl *map, t_vector ray, t_vector camera,
t_figure *list);
void					sphere_ray_tracing(t_sdl *map, t_vector ray,
t_vector camera, t_figure *list);
void					plane_ray_tracing(t_sdl *map, t_vector ray,
t_vector camera, t_figure *list);
void					celinder_ray_tracing(t_sdl *map, t_vector ray,
t_vector camera, t_figure *list);
void					cone_ray_tracing(t_sdl *map, t_vector ray,
t_vector camera, t_figure *list);

t_figure				*figure_intersect(t_sdl *map, t_figure *list,
t_quadratic eq);
t_figure				*plane_intersect(t_sdl *map, t_figure *list,
t_quadratic eq);

int						scene_1(t_sdl *map);
int						scene_2(t_sdl *map);
int						scene_3(t_sdl *map);
int						scene_3_4(t_sdl *map);
int						scene_3_5(t_sdl *map);
int						scene_3_6(t_sdl *map);
int						scene_3_7(t_sdl *map);

void					normalize_vector(t_vector *v);
void					fill_vector(t_vector *v, double x, double y, double z);
void					fill_color(t_color *c, int r, int g, int b);
void					fill_light(t_light *l, double intens, t_vector center,
t_vector direct);

t_figure				*copy_figure(t_figure *f2);
void					add_figure(t_sdl *map, t_figure *new);
void					add_light(t_sdl *map, t_light *new);

t_vector				plus_vector(t_vector a, t_vector b);
t_vector				minus_vector(t_vector a, t_vector b);
t_vector				mult_vector(t_vector a, double b);
t_vector				div_vector(t_vector a, t_vector b);
double					vector_len(t_vector a);

double					find_illumination(t_sdl *map, t_figure *figure);

double					illum_sphere(t_sdl *map, t_figure *figure,
t_light *list, t_vector point);
double					illum_plane(t_sdl *map, t_figure *figure,
t_light *list, t_vector point);
double					illum_celinder(t_sdl *map, t_figure *figure,
t_light *list, t_vector point);
double					illum_cone(t_sdl *map, t_figure *figure,
t_light *list, t_vector point);

void					rotate(t_sdl *map, t_vector *v);
void					rotate_all(t_sdl *map);

#endif
