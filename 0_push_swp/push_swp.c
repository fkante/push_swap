/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 10:28:51 by amartino          #+#    #+#             */
/*   Updated: 2020/01/20 17:00:26 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	solve(t_stack *s, t_stat *stat)
{
	char	*line = NULL;

	print_stack(s, NO_OPE, 0);
	while (get_next_line(0, &line) > 0)
	{
		pivot_on_top_a(s, stat->median_a);
	}
	print_stack(s, NO_OPE, 0);
}

void	push_swp(t_stack *s, int ac, char **av)
{
	t_stat		*stat;

	stat = NULL;
	s = init_struct(av, ac);
	if (s == NULL)
		return ;
	stat = get_stat(s);
	mkdir("result", 0700);
	s->fd = open("result/tmp.txt", O_RDWR | O_CREAT, 0744);
	if (s->fd == FAILURE)
	{
		clean_struct(&s);
		return (ft_print_err_void("when creating result file", STD_ERR));
	}
	solve(s, stat);
	if (s->verbose == TRUE)
		print_stack(s, NO_OPE, 0);
	save_final_result_in_file(s);
	clean_struct(&s);
	ft_memdel((void**)&stat);
}
