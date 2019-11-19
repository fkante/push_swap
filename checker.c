/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 10:39:19 by amartino          #+#    #+#             */
/*   Updated: 2019/11/19 17:54:30 by amartinod        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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

// void		checker()
// {
//
// }
//
void		print_stack(int32_t *stack_a, int32_t *stack_b)
{
	ft_printf("%d\n", stack_a[0]);
	ft_printf("%d\n", stack_a[1]);
	ft_printf("%d\n", stack_a[2]);
	ft_printf("%d\n", stack_a[3]);
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

uint8_t		parse(char **av, int ac)
{
	size_t	i;
	size_t	j;
	int8_t	ret;

	i = 1;
	ret = 1;
	while (i < ac)
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

uint8_t		check_double(int32_t *stack_a)
{
	int32_t		tmp;
	
	return (TRUE);
}

int32_t		*fill_stack(int32_t *stack_a, size_t start, char **av, int ac)
{
	int64_t		tmp;
	size_t		i;

	i = 0;
	while (start < ac)
	{
		tmp = ft_atol(av[start]);
		if (tmp > INT_MAX || tmp < INT_MIN)
			return (NULL);
		stack_a[i] = (int)tmp;
		start++;
		i++;
	}
	return (check_double(stack_a) == FALSE ? NULL : stack_a);
}

int32_t		*create_stack(char **av, int ac)
{
	int32_t		*stack_a;
	size_t		start;

	stack_a = NULL;
	start = parse(av, ac);
	if (start != FALSE)
	{
		stack_a = (int32_t*)malloc(sizeof(int) * (ac - start));
		if (stack_a != NULL)
		{
			stack_a = fill_stack(stack_a, start, av, ac);
			if (stack_a == NULL)
				ft_memdel((void**)&stack_a);
		}
	}
	return (stack_a);
}

int			main(int ac, char **av)
{
	int32_t	*stack_a;
	int32_t	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (ac >= 2)
	{
		stack_a = create_stack(av, ac);
		if (stack_a == NULL)
		{
			ft_printf("Error\n");
			return (0);
		}
		if (ft_strequ(av[1], "-v") == TRUE
				|| ft_strequ(av[2], "-v") == TRUE)
			print_stack(stack_a, stack_b);
	}
	else
		ft_printf("Error\n");
	return (0);
}
