/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repositionning_stack.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkante <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 15:56:29 by fkante            #+#    #+#             */
/*   Updated: 2020/02/19 16:41:49 by fkante           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	repositionning_stack_a(t_stack *s)
{
	if (s->rotation_a == 0)
		return ;
	while (s->rotation_a > 0)
	{
		rra(s);
		s->rotation_a--;
	}
}

void	repositionning_stack_b(t_stack *s)
{
	if (s->rotation_b == 0)
		return ;
	while (s->rotation_b > 0)
	{
		rrb(s);
		s->rotation_b--;
	}
}
