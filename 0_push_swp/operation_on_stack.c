/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_on_stack.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkante <fkante@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 18:34:04 by fkante            #+#    #+#             */
/*   Updated: 2020/02/13 18:04:47 by fkante           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb_lowest(t_stack *s, int32_t lowest)
{
	size_t	min_index;
	size_t	center;

	center = s->size_a / 2;
	min_index = get_index(s->a, lowest);
	while (min_index != s->size_a - 1)
	{
		if (min_index == s->size_a - 1)
			break ;		
		if (min_index > center)
		{
			ra(s);
			min_index++;
		}
		else
		{
			rra(s);
			if (min_index == 0)
				min_index = s->size_a - 1;
			else
				min_index--;
		}
	}
	pb(s);
}

void	pa_highest(t_stack *s, int32_t highest)
{
	size_t	max_index;
	size_t	center;

	center = s->size_b / 2;
	max_index = get_index(s->b, highest);
	while (max_index < s->size_b - 1)
	{
		if (max_index == s->size_b - 1)
			break ;
		if (max_index > center)
		{
			rb(s);
			max_index++;
		}
		else
		{
			rrb(s);
			if (max_index == 0)
				max_index = s->size_b - 1;
			else
				max_index--;
		}
	}
	pa(s);
}

size_t	pb_all_under_nb(t_stack *s, int32_t pivot_index)
{
	size_t	last;
	size_t	counter;
	int32_t pivot_value;

	counter = 0;
	if (pivot_index >= 0 && pivot_index < (int32_t)s->size_a)
	{
		pivot_value = s->a[pivot_index];
		while (any_value_under_nb(s, pivot_value) == SUCCESS)
		{
			last = s->size_a - 1;
			if (s->a[last] <= pivot_value)
			{
				pb(s);
				ft_printf("pb\n");
				counter++;
			}
			else
			{
				ra(s);
				ft_printf("ra\n");
			}
		
		}
	}
	return (counter);
}

size_t	pa_all_above_nb(t_stack *s, int32_t pivot_index, size_t limit)
{
	size_t	last;
	size_t	counter;
	int32_t pivot_value;

	counter = 0;
	if (pivot_index >= 0 && pivot_index < (int32_t)s->size_b)
	{
		pivot_value = s->b[pivot_index];
		while (any_value_above_nb(s, pivot_value) == SUCCESS && limit > 0)
		{
			last = s->size_b - 1;
			if (s->b[last] >= pivot_value)
			{
				pa(s);
				ft_printf("pa\n");
				counter++;
				limit--;
			}
			else
			{
				rb(s);
				ft_printf("rb\n");
			}
		}
	}
	return (counter);
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
