/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_on_stack.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkante <fkante@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 18:34:04 by fkante            #+#    #+#             */
/*   Updated: 2020/02/19 16:41:48 by fkante           ###   ########.fr       */
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

size_t	pb_all_under_nb(t_stack *s, int32_t nth)
{
	size_t	last;
	size_t	counter;
	int32_t pivot_value;
	int32_t pivot_index;

	if (nth == 1)
		nth = 2;
	counter = 0;
	if (nth > 0)
	{
		pivot_index = ft_get_n_smallest(s->a, nth / 2, 0, s->size_a);
		pivot_value = s->a[pivot_index];
		while (any_value_under_nb(s, pivot_value) == SUCCESS)
		{
			last = s->size_a - 1;
			if (s->a[last] <= pivot_value)
			{
				pb(s);
				counter++;
			}
			else
			{
				ra(s);
				s->rotation_a++;
			}
		}
	}
	return (counter);
}

size_t	pa_all_above_nb(t_stack *s, int32_t nth)
{
	size_t	last;
	size_t	counter;
	int32_t	pivot_value;
	size_t	pivot_index;

	if (nth == 1)
		nth = 2;
	counter = 0;
	if (nth > 0)
	{
		pivot_index = ft_get_n_highest(s->b, nth / 2, 0, s->size_b);
		pivot_value = s->b[pivot_index];
		while (s->size_b > 0 && any_value_above_nb(s, pivot_value) == SUCCESS)
		{
			last = s->size_b - 1;
			if (s->b[last] >= pivot_value)
			{
				pa(s);
				counter++;
			}
			else
			{
				rb(s);
				s->rotation_b++;
			}
		}
	}
	return (counter);
}
