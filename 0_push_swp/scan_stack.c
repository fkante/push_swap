/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scan_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkante <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 14:07:55 by fkante            #+#    #+#             */
/*   Updated: 2020/01/15 15:53:51 by fkante           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int8_t	lower_first_to_b(t_stack *s)
{
	t_stat	*stat;
	size_t	middle_a;
	size_t	min_index;
	size_t	count;
	char	*line;

	stat = get_stat(s);
	middle_a  = s->size_a / 2;
	count = 0;
	print_stack(s, 0, 0);
	while (s->size_a > 0)
//	while (get_next_line(0, &line) > 0)
	{
		min_index = ft_get_low(s->a, s->size_a);
		count++;
		print_stack(s, 0, count);
		ft_printf("min_index = %d\n", min_index);
		ft_printf("stat min_a = %d\n", stat->min_a);
		if (min_index + 1 == s->size_a)
		{
			push_stack_b(s);
			ft_putstr_fd("pb\n", 1);
		}
		if (min_index > middle_a)
		{
			ft_putstr_fd("ra\n", 1);
			rotate_stack_a(s);
		}
		else
		{
			ft_putstr_fd("rra\n", 1);
			reverse_rotate_stack_a(s);
		}
		ft_strdel(&line);
	}
	return (FAILURE);
}

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

int8_t	all_under_med(t_stack *s)
{
	t_stat	*stat;
	int32_t	median_all;
	size_t	count;
	char	*line;

	(void)line;
	stat = get_stat(s);
	median_all = stat->median_a;
	count = 0;
	print_stack(s, 0, 0);
//	while (s->size_a > (size_init / 2))
	ft_printf("first lower nb = %d\n",first_lower_med(s, median_all));
/*	while (get_next_line(0, &line) > 0)
	{
		print_stack(s, 0, count);
		ft_printf("s->a[size_a] = %d\n", s->a[s->size_a - 1]);
		ft_printf("median = %d\n", median_all);
		if (s->a[s->size_a - 1] < median_all)
		{
			push_stack_b(s);
			count++;
			ft_putstr_fd("pb\n", 1);
		}
		else
		{
			ft_putstr_fd("ra\n", 1);
			count++;
			rotate_stack_a(s);
		}
		ft_strdel(&line);
	}*/
	return (FAILURE);
}
