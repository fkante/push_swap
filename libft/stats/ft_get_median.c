/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_median.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 15:49:05 by amartino          #+#    #+#             */
/*   Updated: 2019/12/01 14:45:54 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_get_median(int32_t *tab, size_t size)
{
	int32_t		median;
	size_t		i;

	i = 0;
	ft_median(tab, size, &median);
	while (i < size)
	{
		if (tab[i] == median)
			break ;
		i++;
	}
	return (i);
}
