/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_ps.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkante <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 16:07:42 by fkante            #+#    #+#             */
/*   Updated: 2020/02/27 16:18:47 by fkante           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		get_next_line_ps(const int fd, char *line)
{
	char	buff[2];
	int8_t	ret;
	int8_t	count;
	int32_t	max_buff;

	count = 0;
	max_buff = 0;
	while ((ret = read(fd, buff, 1)) > 0 && max_buff < 30000)
	{
		max_buff++;
		buff[1] = '\0';
		if (count == 4)
		{
			if (buff[0] == '\n')
				return (FAILURE);
			continue ;
		}
		count++;
		if (buff[0] == '\n')
			break ;
		ft_strcat(line, buff);
	}
	if (ret == 0 && line[0] != '\0')
		return (FAILURE);
	return (ret);
}
