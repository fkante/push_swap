/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkante <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 16:31:04 by fkante            #+#    #+#             */
/*   Updated: 2019/04/25 12:12:05 by fkante           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

ssize_t	ft_putendl_ret_fd(char const *s, int fd)
{
	size_t	len;
	ssize_t	ret;

	ret = FAILURE;
	if (s != NULL)
	{
		len = ft_strlen(s);
		if ((ret = write(fd, s, len)) == FAILURE)
		{
			ret = FAILURE;
			return (ret);
		}
		ft_putchar_fd('\n', fd);
	}
	return (ret);
}

void	ft_putendl_fd(char const *s, int fd)
{
	size_t l;

	if (s == NULL)
		return ;
	l = ft_strlen(s);
	write(fd, s, l);
	ft_putchar_fd('\n', fd);
}
