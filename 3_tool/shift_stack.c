/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shift_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkante <fkante@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 14:36:48 by fkante            #+#    #+#             */
/*   Updated: 2020/01/15 19:37:23 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int8_t	swap_nb(int32_t *stack1, int32_t *stack2)
{
	int32_t ret;
	int32_t tmp;

	ret = SUCCESS;
	tmp = *stack1;
	*stack1 = *stack2;
	*stack2 = tmp;
	return (ret);
}

int8_t	shiftup_stack_a(t_stack *s)
{
	size_t	i;
	int32_t	ret;

	i = s->size_a;
	ret = FAILURE;
	while (i > 0)
	{
		swap_nb(&s->a[i], &s->a[i - 1]);
		i--;
		if (i == 0)
			ret = SUCCESS;
	}
	return (ret);
}

int8_t	shiftup_stack_b(t_stack *s)
{
	size_t	i;
	int32_t	ret;

	i = s->size_b;
	ret = FAILURE;
	while (i > 0)
	{
		swap_nb(&s->b[i], &s->b[i - 1]);
		i--;
		if (i == 0)
			ret = SUCCESS;
	}
	return (ret);
}

int8_t	shiftdown_stack_a(t_stack *s)
{
	size_t	i;
	int32_t	ret;

	i = 0;
	ret = FAILURE;
	while (i < s->size_a)
	{
		swap_nb(&s->a[i], &s->a[i + 1]);
		i++;
		if (i == s->size_a)
			ret = SUCCESS;
	}
	return (ret);
}

int8_t	shiftdown_stack_b(t_stack *s)
{
	size_t	i;
	int32_t	ret;

	i = 0;
	ret = FAILURE;
	while (i < s->size_b)
	{
		swap_nb(&s->b[i], &s->b[i + 1]);
		i++;
		if (i == s->size_b)
			ret = SUCCESS;
	}
	return (ret);
}
