/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_pushswap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 11:02:18 by amartino          #+#    #+#             */
/*   Updated: 2020/01/20 11:18:10 by fkante           ###   ########.fr       */
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
		s->fd = creat("result.txt", S_IRUSR | S_IWUSR);
		if (s->fd == FAILURE)
		{
			clean_struct(&s);
			return (ft_print_err_FALSE("when creating result file", STD_ERR));
		}
		push_swp(s, stat);
		if (s->verbose == TRUE)
			print_stack(s, NO_OPE, 0);
		clean_struct(&s);
	}
	else
		ft_print_err_FALSE("Not enough arguments", STD_ERR);
	return (SUCCESS);
}
