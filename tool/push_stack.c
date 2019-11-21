/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkante <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 15:25:33 by fkante            #+#    #+#             */
/*   Updated: 2019/11/20 18:46:24 by fkante           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int8_t	push_stack_a(st *s)
{
	int32_t ret;
	int32_t i;

	ret = FAILURE;
	i = s->size;
	if (s->b[0] != 0)
	{
		while (i > 0)
		{
			if(swap_stack_a(&s->a[i], &s->a[i - 1]) != FAILURE)
			{
				i--;
				if (i == 0)
					ret = SUCCESS;
			}
			else
				break ;
		}
		if (ret == SUCCESS)
		{
			s->a[0] = s->b[0];
			s->b[0] = 0;
		}
	}
	return (ret);
}

int8_t	push_stack_b(st *s)
{
	int32_t ret;
	int32_t i;

	ret = FAILURE;
	i = s->size + 1;
	if (s->a[0] != 0)
	{
		while (i > 0)
		{
			swap_stack_b(&s->b[i - 1], &s->b[i]);
			i--;
			if (i == 0)
				ret = SUCCESS;
		}
		if (ret == SUCCESS)
		{
			s->b[0] = s->a[0];
			s->a[0] = 0;
		}
	}
	return (ret);
}
