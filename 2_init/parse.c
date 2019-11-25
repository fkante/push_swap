/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 16:32:59 by amartino          #+#    #+#             */
/*   Updated: 2019/11/22 16:34:43 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

uint8_t		check_no_double(t_stack *s)
{
	size_t		i;
	size_t		j;

	i = 0;
	while (i < s->size_a)
	{
		j = i + 1;
		while (j < s->size_a)
		{
			if (s->a[i] == s->a[j])
				return (FALSE);
			j++;
		}
		i++;
	}
	return (TRUE);
}

uint8_t		check_for_bonus(char **tab, char *chr)
{
	uint8_t		ret;

	ret = FALSE;
	if ((ft_strequ(tab[0], chr) == TRUE) || (ft_strequ(tab[1], chr) == TRUE))
		ret = TRUE;
	return (ret);
}

int8_t		check_err(char *str, size_t j)
{
	int8_t		count;

	count = 0;
	if (str[j] == '-' && str[j + 1] != '\0')
	{
		j++;
		while (str[j] != '\0')
		{
			if (ft_isdigit((int)str[j]) == FALSE)
			{
				if (str[j] != 'v' && str[j] != 'c')
					return (FAILURE);
				else
					count++;
			}
			j++;
		}
	}
	else
		return (FAILURE);
	return (count);
}

int8_t		parse_args(char **av, int32_t ac)
{
	size_t	i;
	size_t	j;
	int8_t	ret;

	i = 0;
	ret = 0;
	while ((int32_t)i < ac)
	{
		j = 0;
		while (av[i][j] != '\0')
		{
			if (ft_isdigit((int)av[i][j]) == FALSE)
			{
				ret += check_err(av[i], j);
				if (ret == FAILURE)
					return (ret);
				break ;
			}
			j++;
		}
		i++;
	}
	return (ret);
}
