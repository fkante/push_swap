/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_both.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkante <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 12:35:35 by fkante            #+#    #+#             */
/*   Updated: 2019/11/27 12:35:38 by fkante           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int8_t	rotate_both(t_stack *s)
{
	int32_t	ret;

	if ((rotate_stack_a(s) == SUCCESS) && (rotate_stack_b(s) == SUCCESS))
		ret = SUCCESS;
	else
		ret = FAILURE;
	return (ret);
}

int8_t	reverse_both(t_stack *s)
{
	int32_t	ret;

	if ((reverse_rotate_stack_a(s) == SUCCESS)
			&& (reverse_rotate_stack_b(s) == SUCCESS))
		ret = SUCCESS;
	else
		ret = FAILURE;
	return (ret);
}
