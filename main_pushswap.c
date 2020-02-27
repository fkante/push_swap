/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_pushswap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 11:02:18 by amartino          #+#    #+#             */
/*   Updated: 2020/02/27 11:49:51 by fkante           ###   ########.fr       */
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
		if ((ret = write(STD_OUT, "", 0)) == FAILURE)
		{
			ft_print_err_void(STD_OUT_ERROR, STD_ERR);
			return (FAILURE);
		}
		push_swp(s, ac, av);
	}
	return (ret);
}
