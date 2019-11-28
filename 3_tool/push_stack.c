/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkante <fkante@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 15:25:33 by fkante            #+#    #+#             */
/*   Updated: 2019/11/28 15:57:05 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int8_t	push_stack_a(t_stack *s)
{
	int32_t	ret;
	size_t	i;

	ret = FAILURE;
	if (s->size_b != 0)
	{
		i = s->size_a;
		s->size_b = s->size_b - 1;
		s->size_a = s->size_a + 1;
		s->a[i] = s->b[s->size_b];
		s->b[s->size_b] = 0;
		s->color_nb = s->a[i];
		ret = SUCCESS;
	}
	return (ret);
}

int8_t	push_stack_b(t_stack *s)
{
	int32_t	ret;
	size_t	j;

	ret = FAILURE;
	if (s->size_a != 0)
	{
		j = s->size_b;
		s->size_a = s->size_a - 1;
		s->size_b = s->size_b + 1;
		s->b[j] = s->a[s->size_a];
		s->a[s->size_a] = 0;
		s->color_nb = s->b[j];
		ret = SUCCESS;
	}
	return (ret);
}
