/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkante <fkante@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 13:57:10 by fkante            #+#    #+#             */
/*   Updated: 2020/02/26 10:40:02 by fkante           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		checker(t_stack *s, int ac, char **av)
{
	int8_t		ret;

	s = init_struct(av, ac);
	if (s != NULL)
	{
//		s->color = TRUE;
//		s->verbose = TRUE;
		ret = read_checker(s);
		if (s->verbose == TRUE && ret == SUCCESS)
			print_stack(s, NO_OPE, 0);
		if (ret == SUCCESS)
		{
			ret = is_sorted_checker(s);
			if (ret == SUCCESS)
			{
				if ((ret = write(STD_OUT, "OK\n", 3)) == FAILURE)
					ft_print_err_void(STD_OUT_ERROR, STD_ERR);
			}
			else if (ret == FAILURE)
			{
				if ((ret = write(STD_OUT, "KO\n", 3)) == FAILURE)
					ft_print_err_void(STD_OUT_ERROR, STD_ERR);
			}
		}
		clean_struct(&s);
	}
}

int			main(int ac, char **av)
{
	t_stack		*s;

	s = NULL;
	if (ac >= 2)
	{
		++av;
		--ac;
		checker(s, ac, av);
	}
	return (SUCCESS);
}
