/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkante <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 13:52:48 by fkante            #+#    #+#             */
/*   Updated: 2019/11/20 18:46:35 by fkante           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		main(int ac, char **av)
{
	int32_t ret;
	int32_t i;
	st		push;

	if (ac >= 2)
	{
		push.size = ac - 1;
		ret = init_struct(&push, av);
		ft_printf("s.size = %d\n", push.size);
		for (i = 0; i < ac - 1; i++)
			ft_printf("stack a[%d] = %d\tstack b[%d] = %d\n", i, push.a[i], i, push.b[i]);
//		i = ac;
//		while (i > 0)
//		{
//			swap_stack_a(&push.a[i - 1], &push.a[i]);
//			i--;
//		}
//		push_stack_b(&push);
//		swap_stack_a(&push.a[0], &push.a[1]);
//		push_stack_b(&push);
		rotate_stack_a(&push);
		ft_printf("\n");
		for (i = 0; i < ac - 1; i++)
			ft_printf("stack a[%d] = %d\tstack b[%d] = %d\n", i, push.a[i], i, push.b[i]);
	}
	return (ret);
}
