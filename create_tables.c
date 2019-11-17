/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_tables.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkante <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 13:42:49 by fkante            #+#    #+#             */
/*   Updated: 2019/11/17 15:55:58 by fkante           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int8_t	create_table_a(const int32_t fd)
{
	char	*line;
	int32_t ret;
	int32_t i;

	line = NULL;
	ret = FAILURE;
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		ft_strdel(&line);
	}
	return (ret);
}

/*
int8_t	create_table_b()
{

}
*/
