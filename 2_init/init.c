/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 16:32:43 by amartino          #+#    #+#             */
/*   Updated: 2020/01/15 12:52:16 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack		*fill_stack(t_stack *s, size_t start, char **tab, size_t len)
{
	int64_t		tmp;
	size_t		i;

	i = 0;
	while (len > start)
	{
		len--;
		tmp = ft_atol(tab[len]);
		if (tmp > INT_MAX || tmp < INT_MIN)
			return (NULL);
		s->a[i] = (int)tmp;
		i++;
	}
	if (check_no_double(s) == FALSE)
		clean_struct(&s);
	return (s);
}

t_stack		*create_stack(char **tab, size_t len)
{
	t_stack		*s;
	ssize_t		start;

	s = NULL;
	start = parse_args(tab, len);
	if (start != FAILURE)
	{
		s = ft_memalloc(sizeof(t_stack));
		if (s != NULL)
		{
			s->a = ft_memalloc(sizeof(int) * (len - start));
			s->b = ft_memalloc(sizeof(int) * (len - start));
			s->size_a = len - start;
			s->verbose = check_for_bonus(tab, "-v");;
			s->color = check_for_bonus(tab, "-c");
			if (s->a == NULL || s->b == NULL)
				clean_struct(&s);
			else
				s = fill_stack(s, start, tab, len);
			if (s != NULL)
				s->sorted_s = ft_sort(s->a, s->size_a);
		}
	}
	return (s);
}

t_stack		*init_struct(char **av, int ac)
{
	t_stack		*s;
	char		**tmp;
	size_t		i;

	s = NULL;
	tmp = NULL;
	i = 0;
	if (ac == 1)
	{
		tmp = ft_strsplit(av[0], ' ');
		if (tmp == NULL)
			return (NULL);
		while (tmp[i] != '\0')
			i++;
		s = create_stack(tmp, i);
		clean_tmp(&tmp, i);
	}
	else
		s = create_stack(av, (size_t)ac);
	return (s);
}
