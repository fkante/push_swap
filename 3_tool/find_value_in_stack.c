/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_value_in_stack.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkante <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 16:28:42 by fkante            #+#    #+#             */
/*   Updated: 2020/02/13 16:41:41 by fkante           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int8_t	any_value_under_nb(t_stack *s, int32_t pivot_value)
{
	int8_t	ret;
	size_t	i;

	ret = FAILURE;
	i = s->size_a - 1;
	while (i > 0)
	{
		if (s->a[i] <= pivot_value)
		{
			ret = SUCCESS;
			break ;
		}
		i--;
	}
	return (ret);
}

int8_t	any_value_above_nb(t_stack *s, int32_t pivot_value)
{
	int8_t	ret;
	size_t	i;

	ret = FAILURE;
	i = s->size_b - 1;
	while (i > 0)
	{
		if (s->b[i] >= pivot_value)
		{
			ret = SUCCESS;
			break ;
		}
		i--;
	}
	return (ret);
}
