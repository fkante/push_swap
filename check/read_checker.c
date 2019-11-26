/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkante <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 10:53:16 by fkante            #+#    #+#             */
/*   Updated: 2019/11/25 15:09:54 by fkante           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int8_t	store_stdin(char **line)
{
	static size_t	i;
	size_t			j;
	char			**operation;

	if ((operation = NULL) != NULL)
		i = 0;
	ft_printf("i = %d\n", i);
	if (line[0] != NULL)
		operation[i] = ft_strdup(line[0]);
	i++;
	return (0);
}

int8_t	read_checker()
{
	char	*line;
	int32_t	ret;

	line = NULL;
	ret = FAILURE;
	while ((ret = get_next_line(1, &line)) > 0)
	{
		store_stdin(&line);
		ft_strdel(&line);
	}
	return (ret);
}

int		main(int ac, char **av)
{
	if (ac > 1)
		read_checker();
	return (0);
}
