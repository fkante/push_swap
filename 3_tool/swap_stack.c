/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkante <fkante@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 14:26:28 by fkante            #+#    #+#             */
/*   Updated: 2020/02/11 17:53:46 by fkante           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_stack_a(t_stack *s)
{
	int32_t	tmp;
	size_t	top;

	if (s->size_a > 0)
	{
		top = s->size_a - 1;
		tmp = s->a[top];
		s->a[top] = s->a[top - 1];
		s->a[top - 1] = tmp;
		s->color_nb = s->a[top];
	}
}

void	swap_stack_b(t_stack *s)
{
	int32_t	tmp;
	size_t	top;

	if (s->size_b > 0)
	{
		top = s->size_b - 1;
		tmp = s->b[top];
		s->b[top] = s->b[top - 1];
		s->b[top - 1] = tmp;
		s->color_nb = s->b[top];
	}
}

void	sa(t_stack *s)
{
	swap_stack_a(s);
	ft_putendl_fd("sa", s->fd);
}

void	sb(t_stack *s)
{
	swap_stack_b(s);
	ft_putendl_fd("sb", s->fd);
}
