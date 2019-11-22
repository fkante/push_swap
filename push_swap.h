/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkante <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 14:18:27 by fkante            #+#    #+#             */
/*   Updated: 2019/11/22 11:21:22 by fkante           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "libft.h"
#include "ft_printf.h"

typedef struct	s_push
{
	int32_t	*a;
	int32_t	*b;
	int32_t	size;
}				st;

int8_t		create_table_a(const int32_t fd);
int8_t		init_struct(st *s, char **av);
int8_t		swap_stack_a(int *top_stack1, int *top_stack2);
int8_t		swap_stack_b(int *top_stack1, int *top_stack2);
int8_t		push_stack_a(st *s);
int8_t		push_stack_b(st *s);
int8_t		rotate_stack_a(st *s);
int8_t		rotate_stack_b(st *s);
int8_t		reverse_rotate_stack_a(st *s);
int8_t		reverse_rotate_stack_b(st *s);

#endif
