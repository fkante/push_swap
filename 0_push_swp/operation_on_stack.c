/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_on_stack.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkante <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 18:34:04 by fkante            #+#    #+#             */
/*   Updated: 2020/01/17 15:51:53 by fkante           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb_lowest(t_stack *s, int32_t limit)
{
	size_t	min_index;

	min_index = ft_get_low_in_range(s->a, s->size_a - limit, s->size_a);
	while (min_index  < s->size_a - 1)
	{
		ra(s);
		min_index++;
	}
	pb(s);
}

void	pa_highest(t_stack *s, int32_t limit)
{
	size_t	center_b;
	size_t	max_index;

	print_stack(s, 0, 0);
	while (limit > 0 && s->size_b > 0)
	{
		max_index = ft_get_high(s->b, s->size_b);
		center_b  = s->size_b / 2;
		print_stack(s, 0, 0);
		if (max_index + 1 == s->size_b)
			pa(s);
		if (max_index > center_b)
			rb(s);
		else
			rrb(s);
		limit--;
	}
}

int8_t	pb_all_under_nb(t_stack *s, int32_t nb, int32_t range)
{
	char	*line;

	(void)range;
	line = NULL;
	print_stack(s, 0, 0);
//	while (range > 0)
	while (get_next_line(0, &line) > 0)
	{
		if (s->a[s->size_a - 1] < nb)
			pb(s);
		else
			ra(s);
		ft_strdel(&line);
	}
	return (FAILURE);
}

int8_t	pa_all_above_nb(t_stack *s, int32_t nb, int32_t range)
{
	char	*line;

	(void)range;
	line = NULL;
	print_stack(s, 0, 0);
//	while (range > 0)
	while (get_next_line(0, &line) > 0)
	{
		if (s->b[s->size_b - 1] > nb)
			pa(s);
		else
			rb(s);
		ft_strdel(&line);
	}
	return (FAILURE);
}

/*
int32_t	first_lower_med(t_stack *s, int32_t med)
{
	int32_t	first_lowest;
	size_t	max_iter;
	size_t	i;

	first_lowest = 0;
	i = 0;
	max_iter = s->size_a;
	while (max_iter > 0)
	{
		if (s->a[i] < med)
		{
			first_lowest = s->a[i];
			break ;
		}
		else if (s->a[max_iter] < med)
		{
			first_lowest = s->a[max_iter];
			break ;
		}
		else
		{
			i++;
			max_iter--;
		}
	}
	return (first_lowest);
}
*/
