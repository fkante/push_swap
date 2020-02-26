/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_on_stack.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkante <fkante@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 18:34:04 by fkante            #+#    #+#             */
/*   Updated: 2020/02/26 15:09:34 by fkante           ###   ########.fr       */
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

ssize_t	pb_all_under_nb(t_stack *s, ssize_t nth)
{
	size_t	counter;
	int32_t pivot_value;
	int32_t index;

	nth = nth == 1 ? 2 : nth;
	counter = 0;
	if (nth <= 0)
		return (counter);
	if ((index = ft_get_n_smallest(s->a, nth / 2, 0, s->size_a)) == FAILURE)
		return (FAILURE);
	pivot_value = s->a[index];
	while (s->size_a > 0 && any_value_under_nb(s, pivot_value) == SUCCESS)
	{
		if (s->a[s->size_a - 1] <= pivot_value)
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
	return (counter);
}

void	pb_all_under_nb_iterative(t_stack *s, int32_t pivot_index)
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

ssize_t	pa_all_above_nb(t_stack *s, ssize_t nth)
{
	size_t	counter;
	int32_t	pivot_value;
	int32_t index;

	nth = nth == 1 ? 2 : nth;
	counter = 0;
	if (nth <= 0)
		return (counter);
	if ((index = ft_get_n_highest(s->b, nth / 2, 0, s->size_b)) == FAILURE)
		return (FAILURE);
	pivot_value = s->b[index];
	while (s->size_b > 0 && any_value_above_nb(s, pivot_value) == SUCCESS)
	{
		if (s->b[s->size_b - 1] >= pivot_value)
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
	return (counter);
}
