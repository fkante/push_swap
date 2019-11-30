/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkante <fkante@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 16:21:06 by fkante            #+#    #+#             */
/*   Updated: 2019/11/30 18:58:01 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int8_t		rotate_stack_a(t_stack *s)
{
	int32_t	first_elem;
	int32_t	ret;
	size_t	i;

	ret = FAILURE;
	i = s->size_a;
	first_elem = s->a[s->size_a - 1];
	if (i > 0)
		if (shiftup_stack_a(s) == SUCCESS)
			ret = SUCCESS;
	s->a[0] = first_elem;
	s->color_nb = s->a[0];
	return (ret);
}

int8_t		rotate_stack_b(t_stack *s)
{
	int32_t	first_elem;
	int32_t	ret;
	size_t	i;

	ret = FAILURE;
	i = s->size_b;
	first_elem = s->b[s->size_b - 1];
	if (i > 0)
		if (shiftup_stack_b(s) == SUCCESS)
			ret = SUCCESS;
	s->b[0] = first_elem;
	s->color_nb = s->b[0];
	return (ret);
}

int8_t		reverse_rotate_stack_a(t_stack *s)
{
	int32_t	first_elem;
	int32_t	ret;
	size_t	i;

	ret = FAILURE;
	i = 0;
	first_elem = s->a[0];
	if (i < s->size_a)
		if (shiftdown_stack_a(s) == SUCCESS)
			ret = SUCCESS;
	s->a[s->size_a - 1] = first_elem;
	s->color_nb = s->a[s->size_a - 1];
	return (ret);
}

int8_t		reverse_rotate_stack_b(t_stack *s)
{
	int32_t	first_elem;
	int32_t	ret;
	size_t	i;

	ret = FAILURE;
	i = 0;
	first_elem = s->b[0];
	if (i < s->size_b)
		if (shiftdown_stack_b(s) == SUCCESS)
			ret = SUCCESS;
	s->b[s->size_b - 1] = first_elem;
	s->color_nb = s->b[s->size_b - 1];
	return (ret);
}
