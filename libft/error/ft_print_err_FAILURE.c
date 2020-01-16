/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_err_FAILURE.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 15:35:04 by amartino          #+#    #+#             */
/*   Updated: 2020/01/16 16:13:06 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

int8_t		print_err_FAILURE(char *str, int8_t fd)
{
	if (str && *str != '\0')
		ft_dprintf(fd, "Error: %s\n", str);
	return (FAILURE);
}
