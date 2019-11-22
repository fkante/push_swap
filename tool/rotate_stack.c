/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkante <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 16:21:06 by fkante            #+#    #+#             */
/*   Updated: 2019/11/22 11:28:58 by fkante           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int8_t		rotate_stack_a(st *s)
{
	int32_t ret;
	int32_t i;
	int32_t first_elem;

	ret = FAILURE;
	i = s->size;
	first_elem = s->a[s->size - 1];
	s->a[s->size - 1] = 0;
	while (i > 0)
	{
		swap_stack_a(&s->a[i], &s->a[i - 1]);
		i--;
	}
	s->a[0] = first_elem;
	ft_printf("|\tra\t|\n");
	return (ret);
}

int8_t		rotate_stack_b(st *s)
{
	int32_t ret;
	int32_t i;
	int32_t first_elem;

	ret = FAILURE;
	i = s->size;
	first_elem = s->b[s->size - 1];
	s->b[s->size - 1] = 0;
	while (i > 0)
	{
		swap_stack_b(&s->b[i], &s->b[i - 1]);
		i--;
	}
	s->b[0] = first_elem;
	ft_printf("|\trb\t|\n");
	return (ret);
}

int8_t		reverse_rotate_stack_a(st *s)
{
	int32_t ret;
	int32_t i;
	int32_t first_elem;

	ret = FAILURE;
	i = 0;
	first_elem = s->a[0];
	s->a[0] = 0;
	while (i < s->size - 1)
	{
		swap_stack_a(&s->a[i], &s->a[i + 1]);
		i++;
	}
	s->a[s->size - 1] = first_elem;
	ft_printf("|\trra\t|\n");
	return (ret);
}

int8_t		reverse_rotate_stack_b(st *s)
{
	int32_t ret;
	int32_t i;
	int32_t first_elem;

	ret = FAILURE;
	i = 0;
	first_elem = s->b[0];
	s->b[0] = 0;
	while (i < s->size - 1)
	{
		swap_stack_b(&s->b[i], &s->b[i + 1]);
		i++;
	}
	s->b[s->size - 1] = first_elem;
	ft_printf("|\trrb\t|\n");
	return (ret);
}
