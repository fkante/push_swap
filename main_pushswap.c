/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_pushswap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 11:02:18 by amartino          #+#    #+#             */
/*   Updated: 2020/04/27 09:40:52 by francis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			main(int ac, char **av)
{
	t_stack		*s;
	int8_t		ret;

	s = NULL;
	ret = SUCCESS;
	if (ac >= 2)
	{
		++av;
		--ac;
		push_swp(s, ac, av);
		if (write_in_std_out() == FAILURE)
			ft_print_err_void(STD_OUT_ERROR, STD_ERR);
	}
	return (ret);
}
