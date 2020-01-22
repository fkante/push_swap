/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkante <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 18:04:58 by fkante            #+#    #+#             */
/*   Updated: 2020/01/22 16:46:34 by fkante           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t		how_many_sorted(t_stack *s)
{
	size_t	i;
	size_t	count;

	i = s->size_a - 1;
	count = 0;
	while (s->a[i] < s->a[i - 1])
	{
		i++;
		count++;
	}
	return (count);
}

int8_t		is_sorted(int32_t nb_prior, int32_t nb_ahead)
{
	ft_printf("nb_prior = %d\t\tnb_ahead = %d\n", nb_prior, nb_ahead);
	return (nb_prior < nb_ahead ? SUCCESS : FAILURE);
}
