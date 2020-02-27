/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 16:32:59 by amartino          #+#    #+#             */
/*   Updated: 2020/02/27 11:14:26 by fkante           ###   ########.fr       */
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

int8_t		check_for_duplicate_bonus(char **tb, size_t len)
{
	size_t		i;
	int8_t		ret;

	ret = SUCCESS;
	if (tb[0] != NULL)
	{
		i = ft_isdigit((int)tb[0][0]) == TRUE ? 1 : 2;
		while (i < len)
		{
			if ((ft_strequ(tb[i], "-v") == 1) || (ft_strequ(tb[i], "-c") == 1))
			{
				ret = FAILURE;
				break ;
			}
			i++;
		}
	}
	return (ret);
}

uint8_t		check_for_bonus(char **tab, char *chr)
{
	uint8_t		ret;

	ret = FALSE;
	if (tab[0] == NULL)
		return (ret);
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
			if (ft_all_isdigit(&str[1]) == FALSE)
			{
				if ((str[j] != 'v' && str[j] != 'c'))
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

ssize_t		parse_args(char **tab, int32_t len)
{
	size_t	i;
	size_t	j;
	ssize_t	ret;
	ssize_t	tmp;

	i = 0;
	ret = 0;
	while ((int32_t)i < len)
	{
		j = 0;
		while (tab[i][j] != '\0')
		{
			if (ft_isdigit((int)tab[i][j]) == FALSE)
			{
				if ((tmp = check_err(tab[i], j)) == FAILURE)
					return (FAILURE);
				else
					ret += tmp;
				break ;
			}
			j++;
		}
		i++;
	}
	return (ret);
}
