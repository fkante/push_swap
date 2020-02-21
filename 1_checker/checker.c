/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 10:39:19 by amartino          #+#    #+#             */
/*   Updated: 2020/02/21 10:32:48 by fkante           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int8_t	read_checker(t_stack *s)
{
	static t_operfunc	func_ptr[NB_OPE] = {swap_stack_a, swap_stack_b,
										swap_both, push_stack_a, push_stack_b,
										rotate_stack_a, rotate_stack_b,
										rotate_both, reverse_rotate_stack_a,
										reverse_rotate_stack_b, reverse_both};
	char		*line;
	size_t		count;
	int8_t		ret;

	count = 0;
	line = NULL;
	while ((ret = get_next_line(0, &line)) > 0)
	{
		operation_checker(func_ptr, line, s, &count);
		ft_strdel(&line);
	}
	if (ret == FAILURE)
		ft_print_err_failure(INPUT_TOO_LONG, STD_ERR);
	return (ret);
}

void	operation_checker(t_operfunc *f_ptr, char *line, t_stack *s,
							size_t *count)
{
	static char	*oper[NB_OPE] = {SA, SB, SS, PA, PB, RA, RB, RR, RRA, RRB, RRR};
	uint8_t 	i;

	i = 0;
	while (i < NB_OPE)
	{
		if (ft_strequ(line, oper[i]) == TRUE)
		{
			f_ptr[i](s);
			(*count)++;
			break ;
		}
		i++;
	}
	if (s->verbose == TRUE)
		print_stack(s, i, *count);
	if (i == NB_OPE)
		ft_print_err_void("wrong operation", STD_ERR);
}
