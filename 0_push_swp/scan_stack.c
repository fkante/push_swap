/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scan_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkante <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 14:07:55 by fkante            #+#    #+#             */
/*   Updated: 2019/12/02 11:07:10 by fkante           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int8_t	scan_stack(t_stack *s)
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
