/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkante <fkante@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 13:52:48 by fkante            #+#    #+#             */
/*   Updated: 2019/11/27 12:39:34 by fkante           ###   ########.fr       */
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
		{
			ft_printf("KO\n");
			return (0);
		}
		read_checker(s);
		if (s->verbose == TRUE)
			print_stack(s);
		clean_struct(&s);
	}
	else
		ft_printf("KO\n");
	return (0);
}
