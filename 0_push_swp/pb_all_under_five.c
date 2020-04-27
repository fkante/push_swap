/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pb_all_under_five.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/27 09:42:20 by francis           #+#    #+#             */
/*   Updated: 2020/04/27 09:42:31 by francis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int8_t	val_under_nb(t_stack *s, int32_t pivot_value)
{
	int8_t	ret;
	size_t	i;

	ret = FAILURE;
	i = s->size_a - 1;
	while (i > 0)
	{
		if (s->a[i] < pivot_value)
		{
			ret = SUCCESS;
			break ;
		}
		i--;
	}
	if (s->a[0] == pivot_value)
		ret = SUCCESS;
	return (ret);
}

void			pb_all_under_nb_five(t_stack *s, int32_t pivot_index)
{
	size_t	last;
	int32_t pivot_value;

	if (pivot_index >= 0 && pivot_index < (int32_t)s->size_a)
	{
		pivot_value = s->a[pivot_index];
		while (s->size_a > 0 && val_under_nb(s, pivot_value) == SUCCESS)
		{
			last = s->size_a - 1;
			if (s->a[last] < pivot_value)
				pb(s);
			else
				ra(s);
		}
	}
}
