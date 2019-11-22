/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 10:39:19 by amartino          #+#    #+#             */
/*   Updated: 2019/11/22 13:28:43 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int64_t		ft_atol(const char *str)
{
	int			i;
	int			neg;
	uint64_t	tmp;

	tmp = 0;
	i = 0;
	neg = 1;
	while ((str[i] >= 8 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-')
		neg = -neg;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		tmp = tmp * 10 + (str[i] - '0');
		i++;
	}
	return ((int64_t)tmp * neg);
}

void		print_stack(t_stack *s)
{
	size_t	i;
	size_t	size_max;

	i = 0;
	size_max = s->size_a + s->size_b;
	system("clear");

	ft_printf(" _______________________________   _____________________________\n");
	ft_printf("|\t\tSTACK A\t\t| |\t\tSTACK B\t\t|\n");
	ft_printf(" ▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔   ▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔\n");
	ft_printf(" _______________________________   _____________________________\n");
	while (i < size_max)
	{
		ft_printf("|\t\t%d\t\t| |\t\t%d\t\t|\n", s->a[i], s->b[i]);
		i++;
	}
	ft_printf(" ▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔   ▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔\n");
}

uint8_t		check_err(char *str, int8_t ret, size_t j)
{
	if ((ft_strequ(str, "-v") == TRUE) || (ft_strequ(str, "-c") == TRUE))
		ret++;
	else if (str[j] == '-' && str[j + 1] != '\0')
	{
		j++;
		while (str[j] != '\0')
		{
			if (ft_isdigit((int)str[j]) == FALSE)
				return (FALSE);
			j++;
		}
	}
	else
		return (FALSE);
	return (ret);
}

uint8_t		parse_args(char **av, int32_t ac)
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
				ret = check_err(av[i], ret, j);
				if (ret == FALSE)
					return (ret);
				break ;
			}
			j++;
		}
		i++;
	}
	return (ret);
}

uint8_t		check_no_double(t_stack *s)
{
	size_t		i;
	size_t		j;

	i = 0;
	while (i < s->size_a)
	{
		j = 0;
		while (j < s->size_a)
		{
			if (j != i && s->a[i] == s->a[j])
				return (FALSE);
			j++;

		}
		i++;
	}
	return (TRUE);
}

t_stack		*fill_stack(t_stack *s, size_t start, char **av, int ac)
{
	int64_t		tmp;
	size_t		i;

	i = 0;
	while ((int32_t)start < ac)
	{
		tmp = ft_atol(av[start]);
		if (tmp > INT_MAX || tmp < INT_MIN)
			return (NULL);
		s->a[i] = (int)tmp;
		start++;
		i++;
	}
	if (check_no_double(s) == FALSE)
		ft_memdel((void**)&s);
	return (s);
}

t_stack		*create_stack(char **av, int ac)
{
	t_stack		*s;
	char		**tab;
	size_t		start;
	size_t		i;

	s = NULL;
	tab = NULL;
	i = 0;
	++av;
	--ac;
	if (ac == 1)
	{
		tab = ft_strsplit(av[0], ' ');
		if (tab == NULL)
			return (FALSE);
		while (tab[i] != '\0')
			i++;
	}
	start = ac > 1 ? parse_args(av, ac) : parse_args(tab, i);
	ac = i == 0 ? ac : i;
	if (start != FALSE)
	{
		s = ft_memalloc(sizeof(t_stack));
		if (s != NULL)
		{
			s->a = ft_memalloc(sizeof(int) * (ac - start));
			s->b = ft_memalloc(sizeof(int) * (ac - start));
			s->size_a = ac - start;
			s->size_b = 0;
			s->color = (ft_strequ(av[0], "-c") == TRUE || ft_strequ(av[1], "-c") == TRUE) ? TRUE : FALSE;
			s->verbose = (ft_strequ(av[0], "-v") == TRUE || ft_strequ(av[1], "-v") == TRUE) ? TRUE : FALSE;
			if (s->a == NULL && s->b == NULL)
				ft_memdel((void**)&s);
			else
				s = i == 0 ? fill_stack(s, start, av, ac) : fill_stack(s, start, tab, ac);
		}
	}
	return (s);
}

int			main(int ac, char **av)
{
	t_stack		*s;

	s = NULL;
	if (ac >= 2)
	{
		s = create_stack(av, ac);
		if (s == NULL)
		{
			ft_printf("Error\n");
			return (0);
		}
		if (s->verbose == TRUE)
			print_stack(s);
	}
	else
		ft_printf("Error\n");
	return (0);
}
