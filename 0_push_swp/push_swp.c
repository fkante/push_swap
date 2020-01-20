/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 10:28:51 by amartino          #+#    #+#             */
/*   Updated: 2020/01/20 11:49:57 by fkante           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swp(t_stack *s, t_stat *stat)
{
	char	*line = NULL;

	print_stack(s, NO_OPE, 0);
	while (get_next_line(0, &line) > 0)
	{
		pivot_on_top_a(s, stat->median_a);
	}
	print_stack(s, NO_OPE, 0);
}
