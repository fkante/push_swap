/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stat.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkante <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 14:11:17 by fkante            #+#    #+#             */
/*   Updated: 2019/12/01 14:13:36 by fkante           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stat 	*get_stat(t_stack *s)
{
	t_stat		*stat;

	stat = ft_memalloc(sizeof(t_stat));
	if (stat != NULL)
	{
		stat->min_a = ft_low(s->a, s->size_a);
		stat->max_a = ft_high(s->a, s->size_a);
		ft_median(s->a, s->size_a, &stat->median_a);
		stat->min_b = ft_low(s->b, s->size_b);
		stat->max_b = ft_high(s->b, s->size_b);
		ft_median(s->b, s->size_b, &stat->median_b);
	}
	return (stat);
}
