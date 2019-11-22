/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkante <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 13:52:48 by fkante            #+#    #+#             */
/*   Updated: 2019/11/22 13:42:18 by fkante           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		main(int ac, char **av)
{
	int32_t ret;
	int32_t i;
	int32_t index;
	t_stack	push;

	if (ac >= 2)
	{
		push.size_init = ac - 1;
		index = ac - 2;
		ret = init_struct(&push, av);
		ft_printf("---------------\n| s.size_init = %d |\n---------------\n", push.size_init);
		for (i = index; i >= 0; i--)
			ft_printf("stack a[%d] =\t%d\t\t|\tstack b[%d] =\t%d\n", i, push.a[i], i, push.b[i]);
		ft_printf("-----------------\n");
//		i = ac;
//		while (i > 0)
//		{
//			swap_stack_a(&push.a[i - 1], &push.a[i]);
//			i--;
//		}
//		push_stack_b(&push);
//		swap_stack_a(&push.a[index - 1], &push.a[index]);
//		push_stack_b(&push);
		rotate_stack_a(&push);
		reverse_rotate_stack_a(&push);
		ft_printf("-----------------\n");
		for (i = index; i >= 0; i--)
			ft_printf("stack a[%d] =\t%d\t\t|\tstack b[%d] =\t%d\n", i, push.a[i], i, push.b[i]);
	}
	return (ret);
}
