/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 11:37:04 by amartino          #+#    #+#             */
/*   Updated: 2019/09/20 10:06:45 by fkante           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	ft_pow(double x, double y)
{
	double	i;
	double	tmp;
	int8_t	neg;

	i = 1;
	neg = 0;
	tmp = x;
	if (y < 0)
	{
		y *= -1;
		neg = 1;
	}
	while (i < y)
	{
		x *= tmp;
		i++;
	}
	if (neg == 0)
		return (x);
	return (x == 1 ? 1 / x : 1);
}
