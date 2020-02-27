/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_ps.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkante <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 16:07:42 by fkante            #+#    #+#             */
/*   Updated: 2020/02/27 18:01:20 by fkante           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		get_next_line_ps(int fd, char *line)
{
	char	buff[1024];
	size_t	i;
	int8_t	ret;
	int8_t	count;

	i = 0;
	count = 0;
	if ((ret = read(fd, buff, 1024)) > 0)
	{
		if (buff[0] == '\0')
			return (FAILURE);
		buff[4] = '\0';
		if (ft_isalpha (buff[0]) == FALSE)
			return (FAILURE);
		ft_strcat(line, buff);
		while (line[i] != '\n' || line[i] != '\0')
			i++;
		line[i] = '\0';
	}
	if (ret == 0 && line[0] != '\0')
		return (FAILURE);
	return (ret);
}
