/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 16:25:12 by amartino          #+#    #+#             */
/*   Updated: 2019/11/22 16:25:24 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		clean_tmp(char ***tmp, size_t i)
{
	while (i > 0)
	{
		i--;
		ft_strdel((*tmp) + i);
	}
	ft_memdel((void**)tmp);
}

void		clean_struct(t_stack **s)
{
	ft_memdel((void**)&((*s)->a));
	ft_memdel((void**)&((*s)->b));
	ft_memdel((void**)s);
}
