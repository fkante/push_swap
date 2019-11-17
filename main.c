/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkante <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 13:52:48 by fkante            #+#    #+#             */
/*   Updated: 2019/11/17 15:55:59 by fkante           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		main(int ac, char **av)
{
	int32_t ret;
	int32_t fd;

	ret = FAILURE;
	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		ft_printf("fd = %d\n", fd);
		ret = create_table_a(fd);
		close(fd);
	}
	return (ret);
}
