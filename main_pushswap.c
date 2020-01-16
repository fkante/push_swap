/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_pushswap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkante <fkante@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 13:52:48 by fkante            #+#    #+#             */
/*   Updated: 2020/01/16 15:37:51 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			main(int ac, char **av)
{
	t_stack		*s;

	s = NULL;
	if (ac >= 2)
	{
		++av;
		--ac;
		s = init_struct(av, ac);
		if (s == NULL)
			return (SUCCESS);
		s->fd = creat("result.txt", S_IRUSR | S_IWUSR);
		if (s->fd == FAILURE)
		{
			clean_struct(&s);
			return (ft_print_err_FALSE("when creating result file", STD_ERR));
		}
		if (s->verbose == TRUE)
			print_stack(s, NO_OPE, 0);
		clean_struct(&s);
	}
	else
		ft_print_err_FALSE("Not enough arguments", STD_ERR);
	return (SUCCESS);
}
