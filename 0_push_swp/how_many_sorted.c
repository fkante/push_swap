/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkante <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 18:04:58 by fkante            #+#    #+#             */
/*   Updated: 2020/02/12 15:27:15 by fkante           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t		how_many_sorted(t_stack *s)
{
	size_t	i;
	size_t	count;

	i = s->size_a - 1;
	count = 1;
	while (s->a[i] < s->a[i - 1])
	{
		i++;
		count++;
	}
	return (count);
}

int8_t		is_sorted(t_stack *s)
{
	size_t	i;
	int8_t	ret;

	i = 1;
	ret = FAILURE;
	while (s->a[i - 1] > s->a[i])
	{
		if (i == s->size_a - 1)
		{
			ret = SUCCESS;
			break ;
		}
		i++;
	}
	return (ret);
}
