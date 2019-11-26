/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 11:16:29 by amartino          #+#    #+#             */
/*   Updated: 2019/11/26 17:29:33 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "libft.h"
#include "ft_printf.h"
#include "define.h"

typedef struct	s_stack
{
	int32_t	*a;
	int32_t	*b;
	size_t	size_init;
	size_t	size_a;
	size_t	size_b;
	uint8_t	verbose;
	uint8_t	color;
}				t_stack;


/*
** ############################################################################
** ################################# INIT #####################################
** ############################################################################
*/
t_stack		*init_struct(char **av, int ac);
t_stack		*create_stack(char **tab, size_t len);
t_stack		*fill_stack(t_stack *s, size_t start, char **tab, size_t len);
uint8_t		check_no_double(t_stack *s);
int8_t		parse_args(char **av, int32_t ac);
int8_t		check_err(char *str, size_t j);
uint8_t		check_for_bonus(char **tab, char *chr);

/*
** ############################################################################
** ################################ CHECKER ###################################
** ############################################################################
*/


/*
** ############################################################################
** ################################# BONUS ####################################
** ############################################################################
*/
void		print_stack(t_stack *s);

/*
** ############################################################################
** ################################# TOOL #####################################
** ############################################################################
*/
int8_t		swap_stack_a(int *top_stack1, int *top_stack2);
int8_t		swap_stack_b(int *top_stack1, int *top_stack2);
int8_t		push_stack_a(t_stack *s);
int8_t		push_stack_b(t_stack *s);
int8_t		rotate_stack_a(t_stack *s);
int8_t		rotate_stack_b(t_stack *s);
int8_t		reverse_rotate_stack_a(t_stack *s);
int8_t		reverse_rotate_stack_b(t_stack *s);

/*
** ############################################################################
** ################################# CLEAN ####################################
** ############################################################################
*/
void		clean_struct(t_stack **s);
void		clean_tmp(char ***tmp, size_t i);

#endif
