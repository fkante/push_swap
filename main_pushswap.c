/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_pushswap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 11:02:18 by amartino          #+#    #+#             */
/*   Updated: 2020/01/15 15:50:58 by fkante           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		main(int ac, char **av)
{
	t_stack		*s;

	s = NULL;
	if (ac >= 2)
	{
		++av;
		--ac;
		s = init_struct(av, ac);
		if (s == NULL)
		{
			ft_printf("Error\n");
			return (0);
		}
		//scan_stack(s);
		all_under_med(s);
		clean_struct(&s);
		
	}
	else
		ft_printf("Error\n");
	return (0);
}
