/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkante <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 15:25:33 by fkante            #+#    #+#             */
/*   Updated: 2019/11/22 13:42:38 by fkante           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int8_t	push_stack_a(t_stack *s)
{
	int32_t ret;
	int32_t i;

	ret = FAILURE;
	i = 0;
	if (s->b[0] != 0)
	{
		while (i < s->size_init)
		{
			if(swap_stack_a(&s->a[i], &s->a[i + 1]) != FAILURE)
			{
				i++;
				if (i == s->size_init)
					ret = SUCCESS;
			}
			else
				break ;
		}
		if (ret == SUCCESS)
		{
			i = i - 1;
			s->b[i] = s->a[i];
			s->a[i] = 0;
		}
	ft_printf("|\tpa\t|\n");
	}
	return (ret);
}

int8_t	push_stack_b(t_stack *s)
{
	int32_t ret;
	int32_t i;

	ret = FAILURE;
	i = 0;
	if (s->a[0] != 0)
	{
		while (i < s->size_init)
		{
			swap_stack_b(&s->b[i], &s->b[i + 1]);
			i++;
			if (i == s->size_init)
				ret = SUCCESS;
		}
		if (ret == SUCCESS)
		{
			i = i - 1;
			s->b[i] = s->a[i];
			s->a[i] = 0;
		}
	ft_printf("|\tpb\t|\n");
	}
	return (ret);
}
