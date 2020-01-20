/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_on_stack.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkante <fkante@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 18:34:04 by fkante            #+#    #+#             */
/*   Updated: 2020/01/20 16:02:18 by fkante           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb_lowest(t_stack *s, int32_t limit)
{
	size_t	min_index;

	min_index = ft_get_low_in_range(s->a, s->size_a - limit, s->size_a);
	while (min_index < s->size_a - 1)
	{
		ra(s);
		min_index++;
	}
	pb(s);
}

void	pa_highest(t_stack *s, int32_t limit)
{
	size_t	max_index;

	max_index = ft_get_high_in_range(s->b, s->size_b - limit, s->size_a);
	while (max_index < s->size_b - 1)
	{
		rb(s);
		max_index++;
	}
	pa(s);
}

void	pb_all_under_nb(t_stack *s, int32_t pivot)
{
	size_t	i;
	size_t	last;

	i = s->size_a;
	while (i > 0)
	{
		last = s->size_a - 1;
		s->a[last] < pivot ? pb(s) : ra(s);
		i--;
	}
}

void	pa_all_above_nb(t_stack *s, int32_t pivot)
{
	size_t	i;
	size_t	last;

	i = s->size_b;
	while (i > 0)
	{
		last = s->size_b - 1;
		s->b[last] > pivot ? pa(s) : rb(s);
		i--;
	}
}
