/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_on_stack.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkante <fkante@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 18:34:04 by fkante            #+#    #+#             */
/*   Updated: 2020/02/07 12:16:53 by fkante           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb_lowest(t_stack *s, int32_t lowest)
{
	size_t	min_index;
	size_t	center;
	char	*line = NULL;


	center = s->size_a / 2;
	min_index = get_index(s->a, lowest);
	//min_index = ft_get_low_in_range(s->a, s->size_a - limit, s->size_a);
	while (get_next_line(1, &line) > 0)
//	while (min_index != s->size_a - 1)
	{
		if (min_index == s->size_a - 1)
			break ;		
		print_stack(s, NO_OPE, 0);
		ft_printf("min_index = %zu\ts->size_a - 1 = %d\n", min_index, s->size_a - 1);
		if (min_index > center)
		{
			ra(s);
			min_index++;
		}
		else
		{
			rra(s);
			min_index--;
		}
	}
	pb(s);
}

void	pa_highest(t_stack *s, int32_t limit)
{
	size_t	max_index;

	max_index = ft_get_high_in_range(s->b, s->size_b - limit, s->size_b);
	while (max_index < s->size_b - 1)
	{
		rb(s);
		max_index++;
	}
	pa(s);
}

void	pb_all_under_nb(t_stack *s, int32_t pivot_index)
{
	size_t	i;
	size_t	last;
	int32_t pivot_value;

	if (pivot_index >= 0 && pivot_index < (int32_t)s->size_a)
	{
		pivot_value = s->a[pivot_index];
		i = s->size_a > 0 ? s->size_a - 1 : 0;
		while (i > 0)
		{
			last = s->size_a - 1;
			s->a[last] <= pivot_value ? pb(s) : ra(s);
			i--;
		}
	}
}

void	pa_all_above_nb(t_stack *s, int32_t pivot_index)
{
	size_t	i;
	size_t	last;
	int32_t pivot_value;

	if (pivot_index >= 0 && pivot_index < (int32_t)s->size_b)
	{
		pivot_value = s->b[pivot_index];
		i = s->size_b - 1;
		while (i > 0)
		{
			last = s->size_b - 1;
			s->b[last] >= pivot_value ? pa(s) : rb(s);
			i--;
		}
	}
}

void	pb_one_above_nb(t_stack *s, int32_t pivot_index)
{
	size_t	i;
	size_t	last;
	int32_t pivot_value;

	pivot_value = s->a[pivot_index];
	i = s->size_a - 1;
	while (i > 0)
	{
		last = s->size_a - 1;
		if (s->a[last] > pivot_value)
		{
			pb(s);
			break ;
		}
		else
			ra(s);
		i--;
	}
}
