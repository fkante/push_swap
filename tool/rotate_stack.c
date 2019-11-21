/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkante <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 16:21:06 by fkante            #+#    #+#             */
/*   Updated: 2019/11/20 18:45:51 by fkante           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int8_t		rotate_stack_a(st *s)
{
	int32_t ret;
	int32_t i;
	int32_t *first_elem;

	ret = FAILURE;
	i = s->size;
	if (s->a[0] != 0 && s->a[i] != 0)
	{
		first_elem = &s->a[0];
		while (i > 0)
		{
			swap_stack_a(&s->a[i], &s->a[i - 1]);
			i--;
		}
	}
	return (ret);
}
