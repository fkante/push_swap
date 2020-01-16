/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_err_NULL.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 15:34:27 by amartino          #+#    #+#             */
/*   Updated: 2020/01/16 16:13:18 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

void		*ft_print_err_NULL(char *str, int8_t fd)
{
	if (str && *str != '\0')
		ft_dprintf(fd, "Error: %s\n", str);
	return (NULL);
}
