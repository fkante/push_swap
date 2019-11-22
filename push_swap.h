/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 11:16:29 by amartino          #+#    #+#             */
/*   Updated: 2019/11/22 13:20:48 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "libft.h"
#include "ft_printf.h"
#include "define.h"

# define FALSE				0
# define TRUE				1
# define VERBOSE 			0
# define COLOR				0

typedef struct	s_stack
{
	int32_t	*a;
	int32_t	*b;
	size_t	size_a;
	size_t	size_b;
	uint8_t	color;
	uint8_t	verbose;
}				t_stack;

t_stack		*create_stack(char **av, int ac);
t_stack		*fill_stack(t_stack *s, size_t start, char **av, int ac);
uint8_t		check_no_double(t_stack *s);
uint8_t		parse(char **av, int32_t ac);
void		print_stack(t_stack *s);

int8_t		init_struct(t_stack *s, char **av);
int8_t		swap_stack_a(int *top_stack1, int *top_stack2);
int8_t		swap_stack_b(int *top_stack1, int *top_stack2);
int8_t		push_stack_a(t_stack *s);
int8_t		push_stack_b(t_stack *s);
int8_t		rotate_stack_a(t_stack *s);
int8_t		rotate_stack_b(t_stack *s);
int8_t		reverse_rotate_stack_a(t_stack *s);
int8_t		reverse_rotate_stack_b(t_stack *s);

#endif
