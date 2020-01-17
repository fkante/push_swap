/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_pushswap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 11:02:18 by amartino          #+#    #+#             */
/*   Updated: 2020/01/17 17:20:59 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

ssize_t		create_file_result()
{
	ssize_t	fd;

	fd = open("result.txt", O_WRONLY | O_CREAT | O_EXCL);
	//ft_printf("fd is : %zu\n", fd);
	return (fd);
}

int			main(int ac, char **av)
{
	t_stack		*s;
	t_stat		*stat;

	(void)s;
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
		s->fd = create_file_result();
		if (s->fd == FAILURE)
		{
			clean_struct(&s);
			return (ft_print_err_FALSE("when creating result file", STD_ERR));
		}
		pb_all_under_nb(s, stat->median_a);
		// pa_all_above_nb(s, -6);
		if (s->verbose == TRUE)
			print_stack(s, NO_OPE, 0);
		clean_struct(&s);
	}
	else
		ft_print_err_FALSE("Not enough arguments", STD_ERR);
	return (SUCCESS);
}
