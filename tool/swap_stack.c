/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkante <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 14:26:28 by fkante            #+#    #+#             */
/*   Updated: 2019/11/22 13:44:08 by fkante           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int8_t	swap_stack_a(int *top_stack1, int *top_stack2)
{
	int32_t ret;
	int32_t tmp;

	ret = SUCCESS;

	tmp = *top_stack1;
	*top_stack1 = *top_stack2;
	*top_stack2 = tmp;
	return (ret);
}

int8_t	swap_stack_b(int *top_stack1, int *top_stack2)
{
	int32_t ret;
	int32_t tmp;

	ret = SUCCESS;

	tmp = *top_stack1;
	*top_stack1 = *top_stack2;
	*top_stack2 = tmp;
	return (ret);
}
