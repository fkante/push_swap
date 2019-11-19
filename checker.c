/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 10:39:19 by amartino          #+#    #+#             */
/*   Updated: 2019/11/19 13:15:34 by amartinod        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

// void		checker()
// {
//
// }
//
// void		print_stack(int32_t *stack_a, int32_t *stack_b)
// {
//
// }

uint8_t		check_err(char **av, int ac)
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
				if (ft_strequ(av[i], "-v") == TRUE
					|| ft_strequ(av[i], "-c") == TRUE)
				{
					ret++;
					break;
				}
				else
				   return (FALSE);
			}
			j++;
		}
		i++;
	}
	return (ret);
}

int32_t		*create_stack(char **av, int ac)
{
	int32_t		*stack_a;
	size_t		start;
	size_t		i;

	i = 0;
	stack_a = NULL;
	if ((start = check_err(av, ac)) == FALSE)
		ft_printf("parsing error\n");
	else
	{
		stack_a = (int32_t*)malloc(sizeof(int) * (ac - start));
		if (stack_a != NULL)
		{
			while (start < ac)
			{
				stack_a[i] = ft_atoi(av[start]);
				start++;
				i++;
			}
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
			ft_printf("Error\n");
		ft_printf("%d\n", stack_a[0]);
	}
	else
		ft_printf("Error\n");
	return (0);
}
