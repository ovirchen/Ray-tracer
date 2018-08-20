/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_vector.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ovirchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 18:00:44 by ovirchen          #+#    #+#             */
/*   Updated: 2018/08/06 18:00:45 by ovirchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/rtv1.h"

t_vector	plus_vector(t_vector a, t_vector b)
{
	a.x = a.x + b.x;
	a.y = a.y + b.y;
	a.z = a.z + b.z;
	return (a);
}

t_vector	minus_vector(t_vector a, t_vector b)
{
	a.x = a.x - b.x;
	a.y = a.y - b.y;
	a.z = a.z - b.z;
	return (a);
}

t_vector	mult_vector(t_vector a, double b)
{
	a.x = a.x * b;
	a.y = a.y * b;
	a.z = a.z * b;
	return (a);
}

t_vector	div_vector(t_vector a, t_vector b)
{
	a.x = a.x / b.x;
	a.y = a.y / b.y;
	a.z = a.z / b.z;
	return (a);
}

double		vector_len(t_vector a)
{
	return (sqrt(a.x * a.x + a.y * a.y + a.z * a.z));
}
