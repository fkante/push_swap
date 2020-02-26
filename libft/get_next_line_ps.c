/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_ps.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkante <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 16:07:42 by fkante            #+#    #+#             */
/*   Updated: 2020/02/26 10:24:42 by fkante           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		get_next_line_ps(const int fd, char *line)
{
	char	buff[2];
	int8_t	ret;

	while ((ret = read(fd, buff, 1)) > 0)
	{
		buff[1] = '\0';
		if (buff[0] == '\n')
			break ;
		if (ft_isalpha(buff[0]) == 0)
			return (FAILURE);
		ft_strcat(line, buff);
	}
	if (ret == 0 && line[0] != '\0')
		return (FAILURE);
	return (ret);
}