/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_push_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkante <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 16:43:12 by fkante            #+#    #+#             */
/*   Updated: 2019/11/22 14:06:34 by fkante           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int8_t	init_struct(t_stack *s, char **av)
{
	int32_t	ret;
	int32_t i;
	int32_t j;
	
	i = s->size_global - 1;
	j = 0;
	ret = SUCCESS;
	if ((s->a = ft_memalloc((s->size_global) * sizeof(int))) == NULL)
		ret = FAILURE;
	while (i > -1)
	{
		s->a[i] = ft_atoi(av[j + 1]);
		i--;
		j++;
	}
	if ((s->b = ft_memalloc((s->size_global) * sizeof(int))) == NULL)
		ret = FAILURE;
	return (ret);
}
