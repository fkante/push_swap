/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 10:39:19 by amartino          #+#    #+#             */
/*   Updated: 2020/02/25 17:00:47 by fkante           ###   ########.fr       */
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
	char				line[4];
	size_t				count;
	int8_t				ret;

	if (s->verbose == TRUE)
		print_stack(s, NO_OPE, 0);
	count = 0;
	ft_bzero((void*)&line, 4);
	while ((ret = get_next_line_ps(0, line)) > 0)
	{
		ret = operation_checker(func_ptr, line, s, &count);
		ft_bzero((void*)&line, 4);
		if (ret == FAILURE_OPE)
			break ;
	}
	ft_printf("ret = %d\n", ret);
	if (ret == FAILURE)
		ft_print_err_void(INPUT_TOO_LONG, STD_ERR);
	return (ret);
}

int8_t	operation_checker(t_operfunc *f_ptr, char *line, t_stack *s,
							size_t *count)
{
	static char	*oper[NB_OPE] = {SA, SB, SS, PA, PB, RA, RB, RR, RRA, RRB, RRR};
	uint8_t		i;

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
	if (i == NB_OPE)
	{
		ft_print_err_void(WRONG_OPERATION, STD_ERR);
		return (FAILURE_OPE);
	}
	if (s->verbose == TRUE)
		print_stack(s, i, *count);
	return(SUCCESS);
}
