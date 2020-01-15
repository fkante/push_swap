/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scan_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkante <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 14:07:55 by fkante            #+#    #+#             */
/*   Updated: 2019/12/01 15:52:02 by fkante           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int8_t	scan_stack(t_stack *s)
{
	t_stat	*stat;
	int8_t	middle_a;
	int8_t	middle_b;
	int8_t	min_index;
	
	(void)middle_b;
	stat = get_stat(s);
	middle_a  = s->size_a / 2;
//	while (s->size_a > 0)
//	{
		min_index = 0;
		while (s->a[min_index] != stat->min_a)
			min_index++;
		if (min_index > middle_a)
		{
			rotate_stack_a(s);
			ft_putstr_fd("ra\n", 1);
		}
		else
		{
			reverse_rotate_stack_a(s);
			ft_putstr_fd("rra\n", 1);
		}
		if (min_index == 0)
		{
			push_stack_b(s);
			ft_putstr_fd("pb\n", 1);
		}
//	}
	return (FAILURE);
}
