/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkante <fkante@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 14:26:28 by fkante            #+#    #+#             */
/*   Updated: 2019/11/30 21:48:09 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int8_t	swap_stack_a(t_stack *s)
{
	int32_t	ret;
	int32_t	tmp;
	size_t	top;

	ret = SUCCESS;
	top = s->size_a - 1;
	tmp = s->a[top];
	s->a[top] = s->a[top - 1];
	s->a[top - 1] = tmp;
	s->color_nb = s->a[top];
	return (ret);
}

int8_t	swap_stack_b(t_stack *s)
{
	int32_t	ret;
	int32_t	tmp;
	size_t	top;

	ret = SUCCESS;
	top = s->size_b - 1;
	tmp = s->b[top];
	s->b[top] = s->b[top - 1];
	s->b[top - 1] = tmp;
	s->color_nb = s->b[top];
	return (ret);
}

int8_t	swap_both(t_stack *s)
{
	int32_t	ret;

	if ((swap_stack_a(s) == SUCCESS) && (swap_stack_b(s) == SUCCESS))
		ret = SUCCESS;
	else
		ret = FAILURE;
	return (ret);
}
