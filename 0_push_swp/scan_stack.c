/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scan_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkante <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 14:07:55 by fkante            #+#    #+#             */
/*   Updated: 2020/01/15 19:06:11 by fkante           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int8_t	pb_lowest(t_stack *s, t_stat *stat, int32_t nb)
{
	size_t	middle_a;
	size_t	min_index;

	middle_a  = s->size_a / 2;
	print_stack(s, 0, 0);
	while (nb > 0 && s->size_a > 0)
	{
		min_index = ft_get_low(s->a, s->size_a);
		print_stack(s, 0, 0);
		if (min_index + 1 == s->size_a)
			pb(s);
		if (min_index > middle_a)
			ra(s);
		else
			rra(s);
		nb--;
	}
	return (FAILURE);
}

int8_t	pa_highest(t_stack *s, t_stat *stat, int32_t nb)
{
	size_t	middle_b;
	size_t	max_index;

	middle_b  = s->size_b / 2;
	print_stack(s, 0, 0);
	while (nb > 0 && s->size_b > 0)
	{
		min_index = ft_get_high(s->b, s->size_b);
		print_stack(s, 0, 0);
		if (min_index + 1 == s->size_b)
			pa(s);
		if (max_index > middle_b)
			rb(s);
		else
			rrb(s);
		nb--;
	}
	return (FAILURE);
}

int8_t	pb_all_under_nb(t_stack *s, int32_t nb, int32_t range)
{
	char	*line;

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
