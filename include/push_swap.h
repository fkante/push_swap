/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 11:16:29 by amartino          #+#    #+#             */
/*   Updated: 2019/12/01 15:48:35 by fkante           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include "ft_printf.h"
# include "define_ps.h"

typedef struct	s_stack
{
	int32_t	*a;
	int32_t	*b;
	size_t	size_init;
	size_t	size_a;
	size_t	size_b;
	int32_t	color_nb;
	uint8_t	verbose;
	uint8_t	color;
}				t_stack;

typedef struct 	s_stat
{
	int32_t		min_a;
	int32_t		max_a;
	int32_t		median_a;
	int32_t		min_b;
	int32_t		max_b;
	int32_t		median_b;
}				t_stat;

/*
** ############################################################################
** ################################# INIT #####################################
** ############################################################################
*/
t_stack			*init_struct(char **av, int ac);
t_stack			*create_stack(char **tab, size_t len);
t_stack			*fill_stack(t_stack *s, size_t start, char **tab, size_t len);
uint8_t			check_no_double(t_stack *s);
int8_t			parse_args(char **av, int32_t ac);
int8_t			check_err(char *str, size_t j);
uint8_t			check_for_bonus(char **tab, char *chr);

/*
** ############################################################################
** ################################ PUSH_SWAP #################################
** ############################################################################
*/
int8_t		scan_stack(t_stack *s);

/*
** ############################################################################
** ################################ CHECKER ###################################
** ############################################################################
*/
enum	e_operations
{
	E_SA,
	E_SB,
	E_SS,
	E_PA,
	E_PB,
	E_RA,
	E_RB,
	E_RR,
	E_RRA,
	E_RRB,
	E_RRR
};

typedef	int8_t	(*operfunc)(t_stack *s);
void			read_checker(t_stack *s);
int8_t			operation_checker(operfunc *f, char **op, char *ln, t_stack *s);

/*
** ############################################################################
** ################################# BONUS ####################################
** ############################################################################
*/
void			print_stack(t_stack *s, int8_t ope, size_t count);
void			print_command(size_t count, int8_t ope, uint8_t	color);
void			print_no_color(t_stack *s);
int8_t			check_ope(t_stack *s, size_t size, int8_t ope, int8_t stack);
void			handle_stack_a(t_stack *s, size_t size, int8_t ope, t_stat *st);
void			handle_stack_b(t_stack *s, size_t size, int8_t ope, t_stat *st);
void			print_with_color(t_stack *s, int8_t ope);
t_stat 			*get_stat(t_stack *s);

/*
** ############################################################################
** ################################# ERROR ####################################
** ############################################################################
*/
void			print_error(int8_t ope);

/*
** ############################################################################
** ################################# TOOL #####################################
** ############################################################################
*/
int8_t			swap_stack_a(t_stack *s);
int8_t			swap_stack_b(t_stack *s);
int8_t			push_stack_a(t_stack *s);
int8_t			push_stack_b(t_stack *s);
int8_t			shiftup_stack_a(t_stack *s);
int8_t			shiftup_stack_b(t_stack *s);
int8_t			shiftdown_stack_a(t_stack *s);
int8_t			shiftdown_stack_b(t_stack *s);
int8_t			rotate_stack_a(t_stack *s);
int8_t			rotate_stack_b(t_stack *s);
int8_t			reverse_rotate_stack_a(t_stack *s);
int8_t			reverse_rotate_stack_b(t_stack *s);
int8_t			loop_swap_stack(int32_t *stack1, int32_t *stack2);
int8_t			swap_both(t_stack *s);
int8_t			rotate_both(t_stack *s);
int8_t			reverse_both(t_stack *s);

/*
** ############################################################################
** ################################# CLEAN ####################################
** ############################################################################
*/
void			clean_struct(t_stack **s);
void			clean_tmp(char ***tmp, size_t i);

#endif
