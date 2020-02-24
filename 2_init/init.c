/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 16:32:43 by amartino          #+#    #+#             */
/*   Updated: 2020/02/24 14:11:51 by fkante           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		fill_in_static_variable(t_stack *s, char **tab, size_t size)
{
	s->size_a = size;
	s->rotation_a = 0;
	s->rotation_b = 0;
	s->verbose = check_for_bonus(tab, "-v");;
	s->color = check_for_bonus(tab, "-c");
}

int8_t		check_for_min_max(char *str)
{
	size_t	i;
	size_t	len;
	int8_t	ret;

	i = 0;
	ret = SUCCESS;
	len = ft_strlen(str);
	if (len > 11)
	{
		if (str[i] == '-')
			i++;
		while (str[i] != '\0' && str[i] == '0')
			i++;
		len = ft_strlen(str + i);
		if (len > 10)
			ret = FAILURE;
	}
	return (ret);
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
		if (tmp > INT_MAX || tmp < INT_MIN || check_for_min_max(tab[len]))
			clean_struct(&s);
		else
			s->a[i] = (int)tmp;
		i++;
	}
	if (s == NULL)
		return (ft_print_err_null(ONLY_INT, STD_ERR));
	if (check_no_double(s) == FALSE)
		clean_struct(&s);
	return (s == NULL ? ft_print_err_null(DUPLICATES, STD_ERR) : s);
}

t_stack		*create_stack(char **tab, size_t len)
{
	t_stack		*s;
	ssize_t		start;
	
	s = NULL;
	if (check_for_duplicate_bonus(tab, len) == FAILURE)
		return (ft_print_err_null(ERROR_BONUS, STD_ERR));
	start = parse_args(tab, len);
	if (start == FAILURE)
		return (ft_print_err_null("Wrong input format", STD_ERR));
	if ((s = ft_memalloc(sizeof(t_stack))) == NULL)
		return (ft_print_err_null("memory allocation failed", STD_ERR));
	fill_in_static_variable(s, tab, (len - (size_t)start));
	s->a = ft_memalloc(sizeof(int) * (len - start));
	s->b = ft_memalloc(sizeof(int) * (len - start));
	if (s->a == NULL || s->b == NULL)
	{
		clean_struct(&s);
		return (ft_print_err_null("memory allocation failed", STD_ERR));
	}
	s = fill_stack(s, start, tab, len);
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
		while (tmp[i] != NULL)
			i++;
		s = create_stack(tmp, i);
		clean_tmp(&tmp, i);
	}
	else
		s = create_stack(av, (size_t)ac);
	return (s);
}
