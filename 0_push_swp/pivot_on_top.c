/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pivot_on_top.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkante <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 15:59:17 by fkante            #+#    #+#             */
/*   Updated: 2020/01/20 16:02:15 by fkante           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pivot_on_top_a(t_stack *s, int32_t pivot)
{
	size_t	i;
	size_t	center;

	center = s->size_a / 2;
	i = 0;
	while (s->a[i] != pivot)
		i++;
	while (s->a[s->size_a - 1] != pivot)
	{
		if (i > center)
			ra(s);
		else
			rra(s);
	}
}

void	pivot_on_top_b(t_stack *s, int32_t pivot)
{
	size_t	i;
	size_t	center;

	center = s->size_b / 2;
	i = 0;
	while (s->b[i] != pivot)
		i++;
	while (s->b[s->size_b - 1] != pivot)
	{
		if (i > center)
			rb(s);
		else
			rrb(s);
	}
}
