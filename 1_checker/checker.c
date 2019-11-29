/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 10:39:19 by amartino          #+#    #+#             */
/*   Updated: 2019/11/29 12:28:20 by fkante           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int8_t	read_checker(t_stack *s)
{
	operfunc	func_ptr[NB_OPE] = {swap_stack_a, swap_stack_b, swap_both,
							push_stack_a, push_stack_b, rotate_stack_a,
							rotate_stack_b, rotate_both, reverse_rotate_stack_a,
							reverse_rotate_stack_b, reverse_both};
	char		*oper[NB_OPE] = {SA, SB, SS, PA, PB, RA, RB, RR, RRA, RRB, RRR};
	char		*line;
	int32_t		ret;
	uint8_t		i;
	size_t 	count;

	count = 0;
	line = NULL;
	ret = FAILURE;
	while ((ret = get_next_line(0, &line)) > 0)
	{
		i = 0;
		while (i < NB_OPE)
		{
			if (ft_strequ(line, oper[i]) == TRUE)
			{
				func_ptr[i](s);
				break ;
			}
			i++;
		}
		if (s->verbose == TRUE)
			print_stack(s, i);
		ft_strdel(&line);
		count++;
		ft_printf("Count = %u\n\nSwap\t\tA: sa\tB: sb\tBoth: rr\n", count);
		ft_printf("Push\t\tA: pa\tB: pb\nRotate up\tA: ra\tB: rb\tBoth: rr\n");
		ft_printf("Rotate down\tA: rra\tB: rrb\tBoth: rrr\n");
	}
	return (ret);
}
