/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_generator.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkante <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 11:04:17 by fkante            #+#    #+#             */
/*   Updated: 2019/11/15 11:22:10 by fkante           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "define.h"

int8_t	test_gen(int test_nb)
{

}

int		main(int ac, char **av)
{
	uint32_t	nb_test;
	int8_t		ret;

	ret = FAILURE;
	if (ac == 2)
	{
		nb_test = ft_atoi(av[1]);
		if (test_gen(nb_test) == SUCCESS)
		{
			ft_printf("Success, file test created with %d numbers", nb_test);
			ret = SUCCESS;
		}
		else
			ft_printf("Failure");
	}
	else
		ft_printf("Usage: .test_generator [int]");
	return (ret);
}
