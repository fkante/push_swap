/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkante <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 18:04:58 by fkante            #+#    #+#             */
/*   Updated: 2020/01/20 18:59:56 by fkante           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int8_t		is_sorted(t_stack *s)
{
	int8_t	ret;
	size_t	i;

	ret = FAILURE;
	i = 0;
		ft_printf("s[size_a] = %d\n", s->a[s->size_a]);
	while (s->a[i] > s->a[s->size_a])
	{ 
		ft_printf("i = %d, s[i] = %d\n", i, s->a[i]);
		if (i == s->size_a - 1)
		{
			ret = SUCCESS;
			break ;
		}
		i++;
	}
	return (ret);
}
