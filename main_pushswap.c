/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_pushswap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 11:02:18 by amartino          #+#    #+#             */
/*   Updated: 2020/01/28 17:23:41 by fkante           ###   ########.fr       */
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
		push_swp(s, ac, av);
	}
	else
		ft_print_err_false("Not enough arguments", STD_ERR);
	return (SUCCESS);
}
