/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkante <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 14:14:05 by fkante            #+#    #+#             */
/*   Updated: 2019/12/01 14:14:49 by fkante           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	handle_stack_a(t_stack *s, size_t size, int8_t ope, t_stat *stat)
{
	if ((check_ope(s, size, ope, STACK_A) == TRUE))
		return ;
	else if (s->a[size] == stat->min_a && s->size_a > 4)
		ft_printf("\t|\t\t{c_yellow}%d{c_end}\t\t| |\t", s->a[size]);
	else if (s->a[size] == stat->max_a && s->size_a > 4)
		ft_printf("\t|\t\t{c_red}%d{c_end}\t\t| |\t", s->a[size]);
	else if (s->a[size] == stat->median_a && s->size_a > 4)
		ft_printf("\t|\t\t{c_blue}%d{c_end}\t\t| |\t", s->a[size]);
	else
		ft_printf("\t|\t\t%d\t\t| |\t", s->a[size]);
}

void	handle_stack_b(t_stack *s, size_t size, int8_t ope, t_stat *stat)
{
	if ((check_ope(s, size, ope, STACK_B) == TRUE))
		return ;
	else if (s->b[size] == stat->min_b && s->size_b > 4)
		ft_printf("\t{c_yellow}%d{c_end}\t\t|\n", s->b[size]);
	else if (s->b[size] == stat->max_b && s->size_b > 4)
		ft_printf("\t{c_red}%d{c_end}\t\t|\n", s->b[size]);
	else if (s->b[size] == stat->median_b && s->size_b > 4)
		ft_printf("\t{c_blue}%d{c_end}\t\t|\n", s->b[size]);
	else
		ft_printf("\t%d\t\t|\n", s->b[size]);
}
