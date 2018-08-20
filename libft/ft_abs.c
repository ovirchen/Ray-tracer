/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ovirchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 14:44:27 by ovirchen          #+#    #+#             */
/*   Updated: 2018/02/22 14:45:28 by ovirchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		abs_int(int i)
{
	return (i > 0 ? i : -i);
}

double	abs_double(double i)
{
	return (i > 0 ? i : -i);
}