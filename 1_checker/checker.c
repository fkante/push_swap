/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 10:39:19 by amartino          #+#    #+#             */
/*   Updated: 2020/02/25 12:11:03 by fkante           ###   ########.fr       */
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
	char				*line;
	size_t				count;
	int8_t				ret;

	if (s->verbose == TRUE)
		print_stack(s, NO_OPE, 0);
	count = 0;
	line = NULL;
	while ((ret = get_next_line(0, &line)) > 0)
	{
		ret = operation_checker(func_ptr, line, s, &count);
		ft_strdel(&line);
		if (ret == FAILURE)
			break ;
	}
	return (ret);
}

int8_t	operation_checker(t_operfunc *f_ptr, char *line, t_stack *s,
							size_t *count)
{
	static char	*oper[NB_OPE] = {SA, SB, SS, PA, PB, RA, RB, RR, RRA, RRB, RRR};
	uint8_t		i;
	size_t		len;

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
	len = ft_strlen(line);
	if (i == NB_OPE || (i < 8 && len > 2) || (i > 7 && len > 3))
	{
		ft_print_err_void(WRONG_OPERATION, STD_ERR);
		return (FAILURE);
	}
	if (s->verbose == TRUE)
		print_stack(s, i, *count);
	return(SUCCESS);
}
