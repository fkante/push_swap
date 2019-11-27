/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkante <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 10:53:16 by fkante            #+#    #+#             */
/*   Updated: 2019/11/27 12:39:35 by fkante           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int8_t	read_checker(t_stack *s)
{
	operfunc	func_ptr[NB_OF_OPER] = {swap_stack_a, swap_stack_b, swap_both,
							push_stack_a, push_stack_b, rotate_stack_a,
							rotate_stack_b, rotate_both, reverse_rotate_stack_a,
							reverse_rotate_stack_b, reverse_both};
	char		*oper[NB_OF_OPER] = {SA, SB, SS, PA, PB, RA, RB, RR, RRA, RRB, RRR};
	char		*line;
	int32_t		ret;
	uint8_t		i;

	line = 0;
	ret = FAILURE;
	while ((ret = get_next_line(0, &line)) > 0)
	{
		i = 0;
		while (i < NB_OF_OPER)
		{
i			if (ft_strequ(line, oper[i]) == TRUE)
				func_ptr[i](s);
		}
		ft_strdel(&line);
	}
	return (ret);
}
