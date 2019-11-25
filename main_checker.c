/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkante <fkante@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 13:52:48 by fkante            #+#    #+#             */
/*   Updated: 2019/11/25 11:01:47 by amartino         ###   ########.fr       */
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
			ft_printf("Error\n");
			return (0);
		}
		if (s->verbose == TRUE)
			print_stack(s);
		clean_struct(&s);
	}
	else
		ft_printf("Error\n");
	return (0);
}
