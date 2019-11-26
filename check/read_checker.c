/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkante <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 10:53:16 by fkante            #+#    #+#             */
/*   Updated: 2019/11/26 18:22:29 by fkante           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int8_t	read_checker()
{
	char	*line;
	int32_t	ret;

	line = 0;
	ret = FAILURE;
	while ((ret = get_next_line(0, &line)) > 0)
	{
		ft_putendl_fd(line, 1);
		ft_strdel(&line);
	}
	return (ret);
}

int		main(int ac, char **av)
{
	(void)ac;
	(void)av;
	read_checker();
	return (0);
}
