/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 16:32:43 by amartino          #+#    #+#             */
/*   Updated: 2020/01/27 15:15:10 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		fill_in_static_variable(t_stack *s, char **tab, size_t size)
{
	s->size_a = size;
	s->verbose = check_for_bonus(tab, "-v");;
	s->color = check_for_bonus(tab, "-c");
	s->exponent_max = 0;
	while ((SUBLIST_MIN_SIZE * ft_pow_positive(2, s->exponent_max + 1)) <= size)
		s->exponent_max++;
}

t_stack		*fill_stack(t_stack *s, size_t start, char **tab, size_t len)
{
	int64_t		tmp;
	size_t		i;

	i = 0;
	if (s->a == NULL || s->b == NULL)
		clean_struct(&s);
	while (len > start && s != NULL)
	{
		len--;
		tmp = ft_atol(tab[len]);
		if (tmp > INT_MAX || tmp < INT_MIN)
			clean_struct(&s);
		else
			s->a[i] = (int)tmp;
		i++;
	}
	if (s != NULL && check_no_double(s) == FALSE)
		clean_struct(&s);
	return (s == NULL ? ft_print_err_null("Double nb / INT MAX/MIN", STD_ERR) : s);
}

t_stack		*create_stack(char **tab, size_t len)
{
	t_stack		*s;
	ssize_t		start;

	s = NULL;
	start = parse_args(tab, len);
	if (start == FAILURE)
		return (ft_print_err_null("Wrong input format", STD_ERR));
	s = ft_memalloc(sizeof(t_stack));
	if (s == NULL)
		return (ft_print_err_null("memory allocation failed", STD_ERR));
	s->a = ft_memalloc(sizeof(int) * (len - start));
	s->b = ft_memalloc(sizeof(int) * (len - start));
	fill_in_static_variable(s, tab, (len - (size_t)start));
	s = fill_stack(s, start, tab, len);
	if (s == NULL)
		return (ft_print_err_null("memory allocation failed", STD_ERR));
	s->sorted_s = ft_sort(s->a, s->size_a);
	if (s->sorted_s == NULL)
		clean_struct(&s);
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
			return (ft_print_err_null("memory allocation failed", STD_ERR));
		while (tmp[i] != '\0')
			i++;
		s = create_stack(tmp, i);
		clean_tmp(&tmp, i);
	}
	else
		s = create_stack(av, (size_t)ac);
	return (s);
}
