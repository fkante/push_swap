/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_pushswap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 11:02:18 by amartino          #+#    #+#             */
/*   Updated: 2020/01/20 16:13:45 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			main(int ac, char **av)
{
	t_stack		*s;
	t_stat		*stat;

	s = NULL;
	stat = NULL;
	if (ac >= 2)
	{
		++av;
		--ac;
		s = init_struct(av, ac);
		if (s == NULL)
			return (SUCCESS);
		stat = get_stat(s);
		mkdir("result", 0700);
		s->fd = open("result/tmp.txt", O_RDWR | O_CREAT, 0744);
		if (s->fd == FAILURE)
		{
			clean_struct(&s);
			return (ft_print_err_FALSE("when creating result file", STD_ERR));
		}
		pb_all_under_nb(s, stat->median_a);
		// pa_all_above_nb(s, -6);
		if (s->verbose == TRUE)
			print_stack(s, NO_OPE, 0);
		save_final_result_in_file(s);
		clean_struct(&s);
		ft_memdel((void**)&stat);
	}
	else
		ft_print_err_FALSE("Not enough arguments", STD_ERR);
	return (SUCCESS);
}
