/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 16:23:57 by amartino          #+#    #+#             */
/*   Updated: 2019/11/28 14:09:53 by fkante           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		print_stack(t_stack *s)
{
	size_t	i;
	size_t	j;
	size_t	size_max;

	i = s->size_a;
	j = s->size_b;
	size_max = s->size_a + s->size_b;
	system("clear");
	ft_printf("\t\t\t _______________________________   _____________________________\n");
	ft_printf("\t\t\t|\t\tSTACK A\t\t| |\t\tSTACK B\t\t|\n");
	ft_printf("\t\t\t ▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔   ▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔\n");
	ft_printf("\t\t\t _______________________________   _____________________________\n");
	while (i > 0)
	{
		i--;
		ft_printf("\t\t\t|\t[%d]\t%d\t\t| |\t", i, s->a[i]);
		if (j > 0)
		{
			j--;
			ft_printf("[%d]\t%d\t\t|\n", j, s->b[j]);
		}
		else
			ft_printf("\t\t\t|\n");
	}
	ft_printf("\t\t\t ▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔   ▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔\n");
}
